#pragma warning(disable : 4786)
#include <ctype.h>
#include <cassert>
#include <vector>
#include <set>
#include "tree.h"
#include "myparser.h"



extern map<string, struct_node*> type;		//存放数据类型
extern map<string, var_node*> var;			//符号表
extern map<string, struct_node*> param;	//参数表
extern map<string, bool> if_defined_table;		
extern map<string, string> strtable;	
extern vector<string> ID_stack;		//表示符堆栈

extern int strid = 0;
extern int ID_stackid = 0;
extern int funcid = 0;			//函数的计数量
extern int label = 0;
extern int funcesp = 0;
extern int exesp;

void complie_DataSegement()
{
	for (map<string, var_node*>::iterator it = var.begin(); it != var.end(); it++)
		if (it->first.size() && it->first[0] != '@' && it->second->type_info->size)
			printf("_%s dword %d dup(0)\n", it->first.c_str(), (it->second->type_info->size + 3) / 4);
	for (map<string, string>::iterator st = strtable.begin(); st != strtable.end(); st++)
	{
		printf("%s byte ", st->first.c_str());
		for (int i = 0; i < st->second.size(); i++)
			printf("%d ,", (unsigned int)st->second[i]);
		puts("0");
	}
}
void complie_expr(node* expr);
void get_value(node* expr);
void get_address(node* expr);
void call_func(node* expr)
{
	assert(expr);
	assert(expr->value == "()");
	assert(expr->child[0]->type == ID);
	assert(if_defined_table[expr->child[0]->value]);
	vector<node*> stack;
	for (node* it = expr->child[1]; it; it = it->child[0])
		stack.push_back(it->child[1]);
	int size = 0;
	if (is_struct(expr->type_info))
	{
		printf("sub esp, %d\n", ALIGN(expr->type_info->size, 4));
		exesp += ALIGN(expr->type_info->size, 4);
		puts("push esp");
	}	
	int save = exesp;
	for (int i = stack.size() - 1; i >= 0; i--)
	{
		exesp = 0;
		if (is_struct(stack[i]->type_info))
		{
			get_address(stack[i]);
			if (exesp) printf("add esp, %d\n", exesp);
			int sz = ALIGN(stack[i]->type_info->size, 4);
			for (int j = sz - 4; j >= 0; j -= 4)
				printf("push dword ptr [eax + %d]\n", j);
			size += sz;
		}
		else
		{
			get_value(stack[i]);
			if (exesp) printf("add esp, %d\n", exesp);
			if (is_char(stack[i]->type_info))
				puts("movsx eax, al");
			puts("push eax");
			size += 4;
		}
		
	}
	exesp = save;
	if (is_struct(expr->type_info))
		printf("push [esp + %d]\n", size);
	if (expr->child[0]->value == "printf" || expr->child[0]->value == "scanf")
		printf("call %s\n", expr->child[0]->value.c_str());
	else printf("call _%s\n", expr->child[0]->value.c_str());
	printf("add esp, %d\n", is_struct(expr->type_info) ? size + 8 : size);
}

void copy_struct(type_node* type_info)
{
	assert(is_struct(type_info));
	for (int i = 0; i <type_info->size; i += type_info->align)
	{
		if (type_info->align == 1)
		{
			printf("mov dl, [ecx + %d]\n", i);
			printf("mov [eax + %d], dl\n", i);
		}
		else if (type_info->align == 4)
		{
			printf("mov edx, [ecx + %d]\n", i);
			printf("mov [eax + %d], edx\n", i);
		}
		else assert(false);
	}
}

void copy_init_list(type_node* var, node* expr)
{
	struct_node * st = 0;
	if (is_struct(var)) st = type[var->value];
	else assert(var->value == "[]");
	int i = 0;
	int size = st ? st->init_order.size() : var->size / var->base->size;
	for (node* it = expr; it; it = it->child[0], i++)
	{
		type_node* base = st ? st->init_order[i].second->type_info : var->base;
		int offset = st ? st->init_order[i].second->offset : i * var->base->size;
		if (it->child[1]->type == EXPRLIST)
		{
			puts("push eax");
			printf("add eax, %d\n", offset);
			copy_init_list(base, it->child[1]);
			puts("pop eax");
		}
		else
		{
			puts("push eax");
			is_struct(base) ? get_address(it->child[1]) : get_value(it->child[1]);
			if (is_int(base) && is_char(it->child[1]->type_info)) 
				puts("movsx eax, al");
			puts("mov ecx, eax");
			puts("pop eax");
			if (is_struct(base))
			{
				puts("push eax");
				printf("add eax, %d\n", offset);
				copy_struct(base);
				puts("pop eax");
			}
			else printf("mov [eax + %d], %s\n", offset , is_char(base) ? "cl" : "ecx");
		}
	}
	for (; i < size; i++)
	{
		type_node* base = st ? st->init_order[i].second->type_info : var->base;
		int offset = st ? st->init_order[i].second->offset : i * var->base->size;
		if (is_struct(base))
		{
			for (int j = 0; j < base->size; j += base->align)
				printf("mov %s ptr [eax + %d], 0\n", base->align == 1 ? "byte" : "dword", offset + j);
		}
		else printf("mov %s ptr [eax + %d], 0\n", is_char(base) ? "byte" : "dword", offset);
	}

}
void get_address(node* expr)
{
	assert(expr);
	if (expr->type == ID)
		if (expr->value[0] == '@')
			printf("lea eax, [ebp + %d]\n", var[expr->value]->offset);
		else
			printf("lea eax, _%s\n", expr->value.c_str());
	else if (expr->value == ".")
	{
		get_address(expr->child[0]);
		printf("add eax, %d\n", get_member(expr->child[0]->type_info, expr->child[1]->value)->offset);
	}
	else if (expr->value == "->")
	{
		get_value(expr->child[0]);
		printf("add eax, %d\n", get_member(expr->child[0]->type_info->base, expr->child[1]->value)->offset);
	}
	else if (expr->value == "*" && !expr->child[1])
	{
		get_value(expr->child[0]);
	}
	else if (expr->value == "[]")
	{
		get_value(expr->child[1]);
		if (is_char(expr->type_info))
			puts("movsx eax, al");
		printf("imul eax, %d\n", expr->type_info->size);
		puts("push eax");
		get_value(expr->child[0]);
		puts("pop ecx");
		puts("add eax, ecx");
	}
	else if (expr->value == "()")
	{
		assert(is_struct(expr->type_info));
		call_func(expr);
	}
	else if (expr->value == "=")
	{
		if (expr->child[1]->type == EXPRLIST)
		{
			get_address(expr->child[0]);
			copy_init_list(expr->child[0]->type_info, expr->child[1]); 
		}
		else
		{
			if (is_struct(expr->child[1]->type_info))
				get_address(expr->child[1]);
			else get_value(expr->child[1]);
			puts("push eax");
			get_address(expr->child[0]);
			puts("pop ecx");
			if (is_struct(expr->child[1]->type_info))
				copy_struct(expr->child[1]->type_info);
			else 
				if (expr->type_info->size == 1) puts("mov [eax], cl");
				else if (expr->type_info->size == 4) puts("mov [eax], ecx");
				else assert(false);
		}
	}
	else assert(false);
}
void get_value(node* expr)
{
	assert(expr);
	assert(!is_struct(expr->type_info));
	char* reg0 = is_char(expr->type_info) ? "al" : "eax";
	if (expr->type == ID)
	{
		if (expr->type_info->value == "[]")
			get_address(expr);
		else if (expr->value[0] == '@')
			printf("mov %s, [ebp + %d]\n", reg0, var[expr->value]->offset);
		else 
			printf("mov %s, _%s\n", reg0, expr->value.c_str());
	}
	else if (expr->type == NUMBER)
		printf("mov eax, %s\n", expr->value.c_str());
	else if (expr->type == CHARTEXT)
		printf("mov al, %d\n", (unsigned int)expr->value[0]);
	else if (expr->type == STRTEXT)
		printf("lea eax, %s\n", expr->value.c_str());
	else 
	{
		assert(expr->type == EXPR);
		if (expr->value == "()")
		{
			assert(!is_struct(expr->type_info));
			call_func(expr);
		}
		else if (expr->value == "=")
		{
			assert(!is_struct(expr->type_info));
			get_address(expr);
			printf("mov %s, [eax]\n", reg0);
		}
		else if (expr->value == "." || expr->value == "->" || expr->value == "[]" ||
			expr->value == "*" && !expr->child[1])
		{
			get_address(expr);
			if (expr->type_info->value != "[]")
				printf("mov %s, [eax]\n", reg0);
		}
		else if (expr->value == "&" && !expr->child[1])
			get_address(expr->child[0]);
		else if (expr->value == "&&" || expr->value == "||")
		{
			get_value(expr->child[0]);
			if (strcmp(reg0, "eax") == 0 && is_char(expr->child[0]->type_info))
				puts("movsx eax, al");		
			printf("cmp %s, 0\n", reg0);
			int lbl = label++;
			printf("%s l%x\n", expr->value == "&&" ? "je" : "jne", lbl ,reg0);
			get_value(expr->child[1]);
			if (strcmp(reg0, "eax") == 0 && is_char(expr->child[1]->type_info))
				puts("movsx eax, al");
			printf("l%x:\n", lbl);
			printf("neg %s\n", reg0);
			printf("sbb %s, %s\n", reg0, reg0);
			printf("neg %s\n", reg0);
		}
		else if (expr->child[1])
		{
			get_value(expr->child[1]);
			if (strcmp(reg0, "eax") == 0 && is_char(expr->child[1]->type_info))
				puts("movsx eax, al");
			puts("push eax");
			get_value(expr->child[0]);
			if (strcmp(reg0, "eax") == 0 && is_char(expr->child[0]->type_info))
				puts("movsx eax, al");
			puts("pop ecx");
			char* reg1 = strcmp(reg0, "al") == 0 ? "cl" : "ecx";
			if (expr->value == "&") printf("and %s, %s\n", reg0, reg1);
			else if (expr->value == "|") printf("or %s, %s\n", reg0, reg1);
			else if (expr->value == "^") printf("xor %s, %s\n", reg0, reg1);
			else if (expr->value == "<<") printf("sal %s, %s\n", reg0, reg1);
			else if (expr->value == ">>") printf("sar %s, %s\n", reg0, reg1);
			else if (expr->value == "*") printf("imul %s, %s\n", reg0, reg1);
			else if (expr->value == "/" || expr->value == "%")
			{
				printf("mov %s, 0\n", strcmp(reg0, "al") == 0 ? "ah" : "edx");
				printf("idiv %s\n", reg1);
				if (expr->value == "%")
					printf("mov %s, %s\n", reg0, strcmp(reg0, "al") == 0 ? "ah" : "edx");
			}
			else if (expr->value == "+" || expr->value == "-")
			{
				if (is_pointer(expr->child[0]->type_info) && is_integer(expr->child[1]->type_info))
					printf("imul %s, %d\n", reg1, expr->child[0]->type_info->base->size);
				if (is_pointer(expr->child[1]->type_info) && is_integer(expr->child[0]->type_info))
					printf("imul %s, %d\n", reg0, expr->child[1]->type_info->base->size);
				printf("%s %s, %s\n", expr->value == "+" ? "add" : "sub", reg0, reg1);
				if (is_pointer(expr->child[0]->type_info) && is_pointer(expr->child[1]->type_info))
				{
					puts("mov edx, 0");
					printf("idiv %d\n", expr->child[1]->type_info->base->size);
				}
			}
			else 
			{
				printf("cmp %s, %s\n", reg0, reg1);
				if (expr->value == "!=")
					puts("setne al");
				else if (expr->value == "==")
					puts("sete al");
				else
				{
					if (is_pointer(expr->type_info))
					{
						if (expr->value == "<")
							puts("setl al");
						else if (expr->value == ">")
							puts("setg al");
						else if (expr->value == "<=")
							puts("setle al");
						else if (expr->value == ">=")
							puts("setge al");
						else assert("false");
					}
					else
					{
						if (expr->value == "<")
							puts("setb al");
						else if (expr->value == ">")
							puts("seta al");
						else if (expr->value == "<=")
							puts("setbe al");
						else if (expr->value == ">=")
							puts("setae al");
						else assert("false");
					}
				}
				puts("movsx eax, al");
			}
		}
		else
		{
			get_value(expr->child[0]);
			if (expr->value == "~")
				printf("not %s\n", reg0);
			else if (expr->value == "-")
				printf("neg %s\n", reg0);
			else if (expr->value == "!")
			{
				printf("cmp %s, 0\n", reg0);
				printf("sete %s\n", reg0);
			}
			else assert(false);
		}
	}
}
void complie_expr(node* expr)
{
	assert(expr);
	exesp = 0;
	if (is_struct(expr->type_info)) get_address(expr);
	else get_value(expr);
	if (exesp) printf("add esp, %d\n", exesp);
}
void _complie_statement(string func, node* tree, int& desp);

void complie_statement(string func, node* tree)
{
	int desp = 0;	
	if (!tree) return;
	if (tree->type == STATEMENTLIST)
		for (node* it = tree; it; it = it->child[0])
			_complie_statement(func, it->child[1], desp);
	else _complie_statement(func, tree, desp);
	if (desp) printf("add esp, %d\n", desp);
	funcesp -= desp;
}

void _complie_statement(string func, node* tree, int& desp)
{
	if (!tree) return;
	if (tree->type == EXPR) {complie_expr(tree); return;}
	if (tree->type == STATEMENTLIST) {complie_statement(func, tree); return;}
	assert(tree->type == STATEMENT);
	if (tree->value == "if")
	{
		complie_expr(tree->child[0]);
		char* reg = is_char(tree->child[0]->type_info) ? "al" : "eax";
		printf("cmp %s, 0\n", reg);
		int lbl0 = label++;
		printf("je l%x\n", lbl0);
		complie_statement(func, tree->child[1]);
		if (tree->child[2])
		{
			int lbl1 = label++;
			printf("jmp l%x\n", lbl1);
			printf("l%x:\n", lbl0);
			complie_statement(func, tree->child[2]);
			printf("l%x:\n", lbl1);
		}
		else printf("l%x:\n", lbl0);
	}
	else if (tree->value == "while")
	{
		int lbl0 = label++;
		int lbl1 = label++;
		printf("l%x:\n", lbl0);
		complie_expr(tree->child[0]);
		char* reg = is_char(tree->child[0]->type_info) ? "al" : "eax";
		printf("cmp %s, 0\n", reg);
		printf("je l%x\n", lbl1);
		complie_statement(func, tree->child[1]);
		printf("jmp l%x\n", lbl0);
		printf("l%x:\n", lbl1);
	}
	else if (tree->value == "for")
	{
		int lbl0 = label++;
		int lbl1 = label++;
		if (tree->child[0]) complie_expr(tree->child[0]);
		printf("l%x:\n", lbl0);
		if (tree->child[1])	
		{
			complie_expr(tree->child[1]);
			char* reg = is_char(tree->child[1]->type_info) ? "al" : "eax";
			printf("cmp %s, 0\n", reg);
			printf("je l%x\n", lbl1);
		}
		complie_statement(func, tree->child[3]);
		if (tree->child[2]) complie_expr(tree->child[2]);
		printf("jmp l%x\n", lbl0);
		printf("l%x:\n", lbl1);
	}
	else if (tree->value == "return")
	{
		if (tree->child[0])
		{
			complie_expr(tree->child[0]);
			if (is_struct(var[func]->type_info->base))
			{
				puts("mov ecx, eax");
				puts("mov eax, [ebp + 8]\n");
				copy_struct(var[func]->type_info->base);			
			}
			else
			{
				if (is_char(tree->child[0]->type_info))
					printf("movsx eax, al\n");
			}
		}
		else puts("mov eax, 0");
		if (funcesp) printf("add esp, %d\n", funcesp);
		puts("pop ebp");
		puts("ret");
	}
	else if (tree->value == "define")
	{
		for (node* it = tree->child[1]; it; it = it->child[0])	
		{
			node* nd = it->child[1];
			int size;
			if (nd->value == "=") size = ALIGN(nd->child[0]->type_info->size, 4);
			else size = ALIGN(nd->type_info->size, 4);
			printf("sub esp, %d\n", size);
			if (nd->value == "=") complie_expr(nd);
			desp += size; funcesp += size;
		}
	}
	else assert(false);
}
void complie_function(node* func)
{
	printf("_%s:\n", func->child[0]->value.c_str());
	funcesp = 0;
	puts("push ebp");
	puts("mov ebp, esp");
	complie_statement(func->child[0]->value, func->child[1]);
	if (funcesp) printf("add, esp %d\n", funcesp);
	puts("pop ebp");
	puts("ret");
	puts("");
}
void complie(node* tree)
{
	puts(".586");
	puts(".model flat, stdcall");
	puts("option casemap:none");
	//puts("include c:\\masm32\\include\\windows.inc");
	//puts("include c:\\masm32\\include\\user32.inc");
	//puts("include c:\\masm32\\include\\kernel32.inc");
	//puts("include c:\\masm32\\include\\masm32.inc");
	//puts("includelib c:\\masm32\\lib\\user32.lib");
	//puts("includelib c:\\masm32\\lib\\kernel32.lib");
	//puts("includelib c:\\masm32\\lib\\masm32.lib");
	puts("includelib msvcrt.lib");
	
	puts("printf proto c: ptr sbyte, : vararg");
	puts("scanf proto c: ptr sbyte, : vararg");
	
	
	puts(".data");
	complie_DataSegement();
	puts(".code");
	puts("start:");
	node* it;
	for (it = tree; it; it = it->child[0])
	{	//编译函数外面的语句
		if (!it->child[1]) continue;
		if (it->child[1]->type == STATEMENT)
		{
			assert(it->child[1]->value == "define");
			for (node* p = it->child[1]->child[1]; p; p = p->child[0])
				if (p->child[1]->value == "=") complie_expr(p->child[1]);
		}
	}
	puts("call _main");	//执行main()函数；
	puts("ret");
	puts("");
	
	//生成函数汇编代码
	for (it = tree; it; it = it->child[0])
	{
		if (!it->child[1]) continue;
		if (it->child[1]->type == FUNCTION)
			complie_function(it->child[1]);
	}
	puts("end start");
}