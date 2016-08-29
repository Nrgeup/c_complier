#pragma warning(disable : 4786)
#include <ctype.h>
#include <cassert>
#include <vector>
#include <set>
#include "tree.h"
#include "myparser.h"
#define ALIGN(a, b) (((a) + (b) - 1) / (b) * (b))

map<string, struct_node*> type_table;		//存放数据类型
map<string, var_node*> var;			//符号表
map<string, struct_node*> param;	//参数表
map<string, bool> if_defined_table;		//标明标示符是否还有效
map<string, string> strtable;	//存放STRTEXT与转换之后的字符串对应表
vector<string> temp_stack;		//临时名堆栈（以temp_stack_id标示）

int strid = 0;
int temp_stack_id = 0;
int funcid = 0;			//函数的计数量
int label = 0;
int funcesp = 0;	//记录函数的偏移
int exesp;			//记录表达式的偏移

string Get_str_type_name(int type) 
{
	switch(type)
	{
		case DEFINELIST: return "define list";
		case EXPR: return "expr";
		case EXPRLIST: return "expr list";
		case STATEMENT: return "statement";
		case STATEMENTLIST: return "statement list";
		case FUNCTION: return "function";
		case FUNCTIONTYPE: return "type";;
		case PARAM: return "param";
		case PARAMLIST: return "param list";
		case NUMBER: return "number";
		case CHARTEXT: return "char";
		case STRTEXT: return "string";
		case ID: return "id";
		default: return "undefined";
	}	
}

//生成中间变量名
string creat_string(int val)
{
	char ans[10] = {0};
	ans[0] = '@';
	for (int i = 0; i < 8; i++)
		ans[8 - i] = "0123456789ABCDEF"[val & (0xF << i * 4)];
	return ans;
}

//生成一个类型的标示符字符串
string creat_string(type_node* value)
{
	if (!value) return "";
	if (value->value == "[]")	//数组
	{
		char temp[20] = {0};
		sprintf(temp, "%d", value->size / value->base->size);
		return creat_string(value->base) + '[' + temp + ']';
	}
	if (value->value == "*")	//指针
		return creat_string(value->base) + "*";
	
	if (param.find(value->value) != param.end())	//函数参数列表
	{
		string temp;
		int size = param[value->value]->init_order.size();
		if (size) temp = creat_string(param[value->value]->init_order[0].second->type_info);
		for (int i = 1; i < size; i++)
			temp += ", " + creat_string(param[value->value]->init_order[i].second->type_info);
		//temp 是一连串子类型的连接
		return creat_string(value->base) + '(' + temp + ')';
	}
	if (!value->base) return value->value;
	return "undefined";
}

//类型检查
bool is_pointer(type_node* value) {return value && (value->value == "*" || value->value == "[]");}
bool is_integer(type_node* value) {return value && (value->value == "int" || value->value == "char");}
bool is_int(type_node* value) 	{return value && value->value == "int";}
bool is_char(type_node* value) 	{return value && value->value == "char";}
bool is_void(type_node* value) 	{return value && value->value == "void";}
bool is_list(int type)	{return type == DEFINELIST || type == EXPRLIST || type == STATEMENTLIST || type == PARAMLIST;}
bool is_type(string name) {return name == "int" || name == "void" || name == "char"|| type_table.find(name) !=type_table.end();}
bool is_same(type_node* a, type_node* b) {return creat_string(a) == creat_string(b);}
bool is_zero(node* value) {return value->type == NUMBER && atoi(value->value.c_str()) == 0;}
bool is_function(type_node* value) {return value && value->size == 0 && param.find(value->value) != param.end();}

void print(node* tree, int deep)
{
	if (!tree) return;
	int i;	
	if (is_list(tree->type))
	{
		print(tree->child[2], deep);
		print(tree->child[1], deep);
		print(tree->child[0], deep);
	}
	else 
	{
		for (i = 0; i < deep; i++) printf("%s", "    ");
		if (tree->type != STATEMENT) printf("%s ", Get_str_type_name(tree->type).c_str());
		printf("%s", tree->value.c_str());
		if (tree->type_info) printf(" type: %s", creat_string(tree->type_info).c_str());
		if (var.find(tree->value) != var.end()) printf(" address: %08X", var[tree->value]->offset);
		puts("");
		for (i = 0; i < 4; i++) print(tree->child[i], deep + 1);
	}
}

pair<string, var_node*> var_define(node* expr, node* base)		//expr:表达式  base:type
{
	pair<string, var_node*> null = make_pair(string(), (var_node*)0);
	if (!expr || !base) return null;
	type_node* type_info;
	if(!type_table[base->value]) type_info = new type_node(base->value, 0, -1, -1);
	else
	{
		//此时是struct_node数据类型定义
		struct_node* temp = type_table[base->value];
		type_info = new type_node(base->value, 0, temp->size, temp->align);
	}
	node* it;
	for (it = expr; it->child[0]; it = it->child[0])	//循环给表达式的兄第节点检查
	{
		it->type_info = type_info;
		if (it->value == "()")	//函数
		{
			if (type_info->value == "[]")
				return cerr << "function can not return array" << endl, null;
			type_info = new type_node(creat_string(funcid++), type_info, 0, 0);
			struct_node* pm = param[type_info->value] = new struct_node;	
			//添加函数参数进param列表
			int offset = 8 ;
			for (node* p = it->child[1]; p; p = p->child[0])
			{
				pair<string, var_node*> temp = var_define(p->child[1]->child[1], p->child[1]->child[0]);
				if (!temp.second || !temp.second->type_info) return null;
				if (temp.second->type_info->value == "[]")
				{
					//指针类型
					temp.second->type_info->value = "*";
					temp.second->type_info->size = 4;
					temp.second->type_info->align = 4;
				}
				offset = ALIGN(offset, 4);
				temp.second->offset = offset;
				offset += temp.second->type_info->size;
				if (pm->element.insert(temp).second == false)
					return cerr << "param " << temp.first << " has defined before" << endl, null;
				pm->init_order.push_back(temp);
			}
		}
		else 
		{
			if (it->value == "[]" && type_info->size <= 0)	//数组
				return cerr << "can not define var with type " << type_info->value << endl, null;
			type_info = new type_node(it->value, type_info, 
				it->value == "[]" ? type_info->size * atoi(it->child[1]->value.c_str()) : 4,
				it->value == "[]" ? type_info->align : 4);
		}
	}
	if (type_info->size == -1)		//void 类型
	{
		if (type_table[type_info->value])
			return cerr << "can not define var with type " << type_info->value << endl, null;
		else
			return cerr << "struct " << type_info->value << " has not defined" << endl, null;
	}
	it->type_info = type_info;
	return make_pair(it->value, new var_node(type_info));
}

//根据类型value 和 操作符oper 判断返回的类型
type_node* operater_type(string oper, type_node* value)
{
	if (!value) return 0;
	if (oper == "*" && is_pointer(value)) return value->base;
	if (oper == "~" && is_integer(value)) return value;
	if (oper == "!" && (is_pointer(value) || is_integer(value)))
		return new type_node("*", value, 4, 4);
	if (oper == "&") return new type_node("*", value, 4, 4);
	if (oper == "-" && is_integer(value)) return value;
	return cerr << "no operator " << oper << " with " << creat_string(value), 0;
}


//判断a、b两种数据类型能否相互赋值
bool is_assignable(type_node* a, type_node* b)
{
	return !a->base && !b->base && a->value == b->value || is_integer(a) && is_integer(b) || 
		a->value == "*" && is_pointer(b) && (is_same(a->base, b->base) || is_void(a->base));
}

//根据类型a 、b 和 操作符oper 操作后 判断返回的类型
type_node* operater_type(string oper, type_node* a, type_node* b)
{
	if (!a || !b) return 0;
	if (oper == "[]")
		if (is_pointer(a) && is_integer(b)) return a->base;
		else goto er;
	if (oper == "+")
	{
		if (is_pointer(a) && is_pointer(b)) goto er;
		if (is_pointer(b)) swap(a, b);
	}
	if (oper == "-")
		if (is_pointer(a) && is_pointer(b) && is_same(a->base, b->base)) 
			return new type_node("*", a->base, 4, 4);
	if (oper == "+" || oper == "-")
		if (is_pointer(a) && !is_void(a->base) && is_integer(b)) 
			return new type_node("*", a->base, 4, 4);
	if (oper == "=")
		if (is_assignable(a, b)) return a;
		else goto er;
	if (oper == "&&" || oper == "||")
		if ((is_pointer(a) || is_integer(a)) && is_pointer(b) || is_integer(b))
			return new type_node("int", 0, 4, 4);
	if (oper == "==" || oper == "!=" || oper == "<=" || oper == ">=" || oper == "<" || oper == ">")
		if (is_integer(a) && is_integer(b) || is_pointer(a) && is_pointer(b) && is_same(a->base, b->base)) 
			return new type_node("int", 0, 4, 4);
	if (is_integer(a) && is_integer(b)) 
		return is_int(a) ? a : b;
er:
	return cerr << "no operator " << oper << " with " << creat_string(a) << " and " << creat_string(b), 0;
}

//检查var类型、expr表达式 的内存大小分配是否正确
bool init_type_check(type_node* var, node* expr)
{
	if (expr->type == EXPRLIST)
	{
		if (var->value == "[]")
		{
			//检查内存大小
			int size = var->size / var->base->size;
			for (node* it = expr; it; it = it->child[0])
			{
				if (!size--) return cerr << "too many param" << endl, false;
				if (!init_type_check(var->base, it->child[1])) return false;
			}
			return true;
		}
		return cerr << "not expect an init list" << endl, false;
	}
	else if (expr->type == STRTEXT && var->value == "[]")
	{
		int size = var->size / var->base->size;
		if (expr->type == STRTEXT)
		{
			if (!is_char(var->base)) return cerr << "not expect an string text" << endl, false;
			if (size < expr->type_info->size)  return cerr << "string is too long" << endl, false;
		}
		return true;
	}
	if (var->value == "*" && is_zero(expr)) expr->type_info = var;
	if (!is_assignable(var, expr->type_info))
			return cerr << "it must be convertible" << endl, false;
	return true;
}


//参数列表类型检查
bool param_type_check(struct_node* var, node* list) 
{
	if (!list) return true;
	if (list->type != EXPRLIST)
		return cerr << "expect an init list" << endl, false;
	int i = 0;
	for (node* it = list; it; it = it->child[0])
	{
		if (i == var->init_order.size()) 
			return cerr << "too many param" << endl, false; 
		if (!init_type_check(var->init_order[i++].second->type_info, it->child[1]))
			return false;
	}
	if (i < var->init_order.size()) 
		return cerr << "too little param" << i << var->init_order.size() <<  endl, false;
	return true;
}


//正确识别一个字符串并将src字符串的里的转义字符识别出来放到result中
bool trans(string& result, string src)
{
	string ret;
	src = src.substr(1, src.size() - 2);
	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] == '\\')
		{
			i++;
			if (i >= src.size())
				return cerr << "string text error" << endl, false;
			switch (src[i])
			{
			case 'a': ret += '\a'; break;
			case 'b': ret += '\b'; break;
			case 'f': ret += '\f'; break;
			case 'r': ret += '\r'; break;
			case 'n': ret += '\n'; break;
			case 't': ret += '\t'; break;
			case 'v': ret += '\v'; break;
			case '0': ret += '\0'; break;
			case '?': ret += '\?'; break;
			case '\\': ret += '\\'; break;
			case '\'': ret += '\''; break;
			case '\"': ret += '\"'; break;
			default:
				return cerr << "string text error" << endl, false;
			}
		}
		else ret += src[i];
	}
	result = ret;
	return true;
}

bool expr_type_check(node* expr)
{
	if (!expr) return true;
	if (is_list(expr->type))	//如果是LIST型则检查每一个孩子节点
	{
		for (node* it = expr; it; it = it->child[0])
			if (!expr_type_check(it->child[1])) return 0;
			return true;
	}
	else if (expr->value == "." )	//指针类型则检查孩子节点
	{
		if (!expr_type_check(expr->child[0])) return 0;
	}
	else {
		for (int i = 0; i < 4; i++)
			if (expr->child[i] && !expr_type_check(expr->child[i])) return 0;		
	}
	if (expr->type == ID)
	{
		expr->if_get_addr = true;
		for (int i = temp_stack.size() - 1; i >= 0; i--)
			if (var.find(temp_stack[i] + expr->value) != var.end())	//在堆栈中找到
			{
				expr->value = temp_stack[i] + expr->value;
				if (var[expr->value]->type_info->value != "[]") expr->if_get_addr = true;
				return expr->type_info = var[expr->value]->type_info, true;
			}
		cerr << "var " << expr->value << " has not defined" << endl;
		return  0;
	}
	if (expr->type == NUMBER)
		return expr->type_info = new type_node("int", 0 ,4, 4), true;
	if (expr->type == CHARTEXT)
	{
		if (!trans(expr->value, expr->value)) return false;
		if (expr->value.size() != 1) return cerr << "char text error" << endl, false;
		return expr->type_info = new type_node("char", 0 ,1, 1), true;	
	}
	if (expr->type == STRTEXT)
	{
		//将expr->value的字符串的转换之后的字符串放到strtable里面
		if (!trans(strtable[creat_string(strid)], expr->value)) return false;
		expr->value = creat_string(strid++);
		return expr->type_info = new type_node("[]", 
			new type_node("char", 0, 1, 1), strtable[expr->value].size() + 1, 1), true;
	}
	if (expr->value == "." ||  expr->value == "*" && !expr->child[1] || expr->value == "[]")
		expr->if_get_addr = true;
	if (expr->value == ".")
	{
		expr->type_info =  0;
		return  true;
	}
	if (expr->value == "&" && !expr->child[1] || expr->value == "=")
		if (!expr->child[0]->if_get_addr)
			return cerr << "it must be left value" << endl, false;
	if (expr->value == "=" && expr->child[0]->type_info->value == "*" && is_zero(expr->child[1]))
		return expr->type_info = expr->child[1]->type_info = expr->child[0]->type_info, true;
	if (expr->value == "()")
	{
		if (expr->child[0]->value == "printf" || expr->child[0]->value == "scanf")
			return expr->type_info = var[expr->child[0]->value]->type_info->base, true;
		if (!is_function(expr->child[0]->type_info))
			return cerr << "it must be function" << endl, false;
		if (!param_type_check(param[expr->child[0]->type_info->value], expr->child[1])) return false;
		expr->type_info = expr->child[0]->type_info->base;
		return true;
	}
	if (expr->child[1]) expr->type_info = operater_type(expr->value, expr->child[0]->type_info, expr->child[1]->type_info);
	else expr->type_info = operater_type(expr->value, expr->child[0]->type_info);
	if (!expr->type_info) return false;
	return true;
}

bool statement_type_check(node* list, string func, int offset);
bool _statement_type_check(node* nd, string func, int& offset)
{
	if (!nd) return false;
	if (is_list(nd->type))
		return statement_type_check(nd, func, offset);
	if (nd->type == EXPR || nd->type == ID || nd->type == NUMBER)
		return expr_type_check(nd) ? true : false;
	if (nd->type != STATEMENT)
		return cerr << "assert fault statement " << Get_str_type_name(nd->type) << endl, false; 
	if (nd->value == "if" || nd->value == "while")
	{
		if (!expr_type_check(nd->child[0])) return false;
		if (!is_integer(nd->child[0]->type_info) && !is_pointer(nd->child[0]->type_info))
			return cerr << "it must be bool value" << endl, false;
		if (!statement_type_check(nd->child[1], func, offset)) return false;
		if (!statement_type_check(nd->child[2], func, offset)) return false;
	}
	if (nd->value == "for")
	{
		for (int i = 0; i < 3; i++)
			if (!expr_type_check(nd->child[i])) return false;
			if (!statement_type_check(nd->child[3], func, offset)) return false;
	}
	if (nd->value == "return")
	{
		if (!expr_type_check(nd->child[0])) return false;
		if (nd->child[0]) 
		{
			if (is_zero(nd->child[0]) && is_pointer(var[func]->type_info->base))
				nd->child[0]->type_info = var[func]->type_info->base;
			if (is_void(var[func]->type_info->base)) {
				cerr << "the function has no return value" << endl;
				return  false;
			}
			else if (!(is_assignable(var[func]->type_info->base, nd->child[0]->type_info))){
				cerr << "return type is not same" << endl;
				return false;
			}
		}
		else if (!is_void(var[func]->type_info->base)) {
				cerr << "the function must return value" << endl;
				return  false;
			}
	}
	if (nd->value == "define")
	{
		for (node* p = nd->child[1]; p; p = p->child[0])
		{
			node* q = (p->child[1]->value == "=" ? p->child[1]->child[0] : p->child[1]);
			pair<string, var_node*> temp = var_define(q, nd->child[0]);
			if (!temp.second) return false;
			if (var.find(temp_stack.back() + temp.first) != var.end()){
				cerr << "var " << temp.first << " has defined before" << endl;
				return  false;
			}
			offset += temp.second->type_info->size;
			offset = ALIGN(offset, 4);
			temp.second->offset = -offset;
			var[temp_stack.back() + temp.first] = temp.second;
			if (p->child[1]->value == "=")
			{
				if (!expr_type_check(p->child[1]->child[1])) return false;
				if (!init_type_check(temp.second->type_info, p->child[1]->child[1])) return false;
			}
			node* newnode = new node(ID, temp_stack.back() + temp.first);
			newnode->type_info = temp.second->type_info;
			if (p->child[1]->value != "=") p->child[1] = newnode;
			else p->child[1]->child[0] = newnode;
			p->child[1]->type_info = temp.second->type_info;
		}
	}
	return true;
}

bool statement_type_check(node* list, string func, int offset)
{
	temp_stack.push_back(creat_string(temp_stack_id++));
	if (!list) return temp_stack.pop_back(), true;
	if (!is_list(list->type))
	{
		if (!_statement_type_check(list, func, offset)) goto error;
	}
	else for (node* it = list; it; it = it->child[0])
	{
		if (it->child[1] && !_statement_type_check(it->child[1], func, offset)) goto error;
	}
	temp_stack.pop_back();
	return true;
error:
	temp_stack.pop_back();
	return false;
}

bool type_check(node* tree)
{
	type_table["int"] = new struct_node(4, 4);
	type_table["char"] = new struct_node(1, 1);
	type_table["void"] = new struct_node(-1, -1);
	var["printf"] = new var_node(new type_node("@stdio", new type_node("int", 0, 4, 4), 0, 0));
	var["scanf"] = new var_node(new type_node("@stdio", new type_node("int", 0, 4, 4), 0, 0));
	var["main"] = new var_node(new type_node("@main", new type_node("int", 0, 4, 4), 0, 0));
	param["@main"] = new struct_node;
	if_defined_table["printf"] = true;
	if_defined_table["scanf"] = true;
	temp_stack.push_back("");
	temp_stack_id = funcid = 0;
	if (!tree) return true;
	if (tree->type != DEFINELIST) return false;
	int offset = 0;
	for (node* it = tree; it; it = it->child[0])	//遍历兄弟节点
	{
		node* nd = it->child[1];
		if (!nd) continue;
		if (nd->type == FUNCTION)
		{
			pair<string, var_node*> temp = var_define(nd->child[0]->child[1], nd->child[0]->child[0]);
			if (!temp.second) return false;
			//temp.first是函数名字，scanf、printf
			if (if_defined_table[temp.first]) 	//函数已经被定义
				return cerr << "function " << temp.first << " has defined" << endl, false;
			if_defined_table[temp.first] = true;		//添加进函数列表
			if (var.find(temp.first) != var.end())	//如果已经在标示符表中存在此标示符的声明
			{
				//检查标示符表中“ID（此处是函数名）”的描述数据类型与之后声明的数据类型是否不一样
				if (!is_same(var[temp.first]->type_info, temp.second->type_info))
					return cerr << "function declare " << temp.first << " is not same" << endl, false;
			}
			else var[temp.first] = temp.second;		//标示符表中不存在则添加进标示符表
			//然后检查函数的参数
			struct_node* p = param[temp.second->type_info->value];
			node* expr = nd->child[0]->child[1];
			while (expr && expr->type != PARAMLIST)
			{
				if (expr->value == "[]" || expr->value == "*") expr = expr->child[0];
				else if (expr->value == "()") expr = expr->child[1];
				else return(false);
			}
			//循环检查参数列表的每一项数据类型
			for (int i = 0; i < p->init_order.size(); i++, expr = expr->child[0])
			{
				//添加标示符
				var[creat_string(temp_stack_id) + p->init_order[i].first] = p->init_order[i].second;
				expr->child[1] = new node(ID, creat_string(temp_stack_id) + p->init_order[i].first);
			}
			nd->child[0] = new node(ID, temp.first);
			if (!statement_type_check(nd->child[1], temp.first, 0)) return false;
		}
		if (nd->type == FUNCTIONTYPE)
		{
			pair<string, var_node*> temp = var_define(nd->child[1], nd->child[0]);
			if (!temp.second) return false;
			if (var.find(temp.first) != var.end())
			{
				if (!is_same(var[temp.first]->type_info, temp.second->type_info))
					return cerr << "function declare " << temp.first << " is not same" << endl, false;
			}
			else var[temp.first] = temp.second;
			it->child[1] = new node(ID, temp.first);
		}
		if (nd->type == STATEMENT)
			if (!_statement_type_check(nd, "", offset)) return false;
	}
	temp_stack.pop_back();
	return true;
}

//编译程序数据段
void complie_DataSegement()
{
	for (map<string, var_node*>::iterator it = var.begin(); it != var.end(); it++)	//为全局变量分配空间
		if (it->first.size() && it->first[0] != '@'/*与局部变量区分开*/&& it->second->type_info->size)
			printf("_%s dword %d dup(0)\n", it->first.c_str(), (it->second->type_info->size + 3) / 4);
	for (map<string, string>::iterator st = strtable.begin(); st != strtable.end(); st++)
	{	/*为字符串分配空间*/
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
	if(!((expr==NULL
	||(expr->value == "()")
	||(expr->child[0]->type == ID)
	||(if_defined_table[expr->child[0]->value])
		)))
	{
		cerr<<"function call error!";
		return;
	}
	vector<node*> stack;	//把列表的参数放到stack中
	for (node* it = expr->child[1]; it; it = it->child[0])
		stack.push_back(it->child[1]);
	int size = 0;
	int save = exesp;
	for (int i = stack.size() - 1; i >= 0; i--)
	{
		exesp = 0;
		get_value(stack[i]);
		if (exesp) printf("add esp, %d\n", exesp);	//依次给列表的参数存放到栈中
		if (is_char(stack[i]->type_info))
			puts("movsx eax, al");
		puts("push eax");
		size += 4;
	}
	exesp = save;
	if (expr->child[0]->value == "printf" || expr->child[0]->value == "scanf")
		printf("call %s\n", expr->child[0]->value.c_str());
	else printf("call _%s\n", expr->child[0]->value.c_str());
	printf("add esp, %d\n", size);
}

void copy_init_list(type_node* var, node* expr)
{
	struct_node * st = 0;
	assert(var->value == "[]");
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
			get_value(it->child[1]);
			if (is_int(base) && is_char(it->child[1]->type_info)) 
				puts("movsx eax, al");
			puts("mov ecx, eax");
			puts("pop eax");
			printf("mov [eax + %d], %s\n", offset , is_char(base) ? "cl" : "ecx");
		}
	}
	for (; i < size; i++)
	{
		type_node* base = st ? st->init_order[i].second->type_info : var->base;
		int offset = st ? st->init_order[i].second->offset : i * var->base->size;
		printf("mov %s ptr [eax + %d], 0\n", is_char(base) ? "byte" : "dword", offset);
	}
}

//获得当前表达式的地址值并返回到eax寄存器里
void get_address(node* expr)
{
	assert(expr);
	if (expr->type == ID)
		if (expr->value[0] == '@')
			printf("lea eax, [ebp + %d]\n", var[expr->value]->offset);
		else
			printf("lea eax, _%s\n", expr->value.c_str());
	else if (expr->value == "."){
		get_address(expr->child[0]);
		printf("add eax, 0\n");
	}
	else if (expr->value == "->"){
		get_value(expr->child[0]);
		printf("add eax, %d\n");
	}
	else if (expr->value == "*" && !expr->child[1]){
		get_value(expr->child[0]);
	}
	else if (expr->value == "[]"){
		get_value(expr->child[1]);
		if (is_char(expr->type_info))
			puts("movsx eax, al");
		printf("imul eax, %d\n", expr->type_info->size);
		puts("push eax");
		get_value(expr->child[0]);
		puts("pop ecx");
		puts("add eax, ecx");
	}
	else if (expr->value == "="){
		if (expr->child[1]->type == EXPRLIST){
			get_address(expr->child[0]);
			copy_init_list(expr->child[0]->type_info, expr->child[1]); 
		}
		else{
			get_value(expr->child[1]);
			puts("push eax");
			get_address(expr->child[0]);
			puts("pop ecx");
			if (expr->type_info->size == 1) puts("mov [eax], cl");
			else if (expr->type_info->size == 4) puts("mov [eax], ecx");
			else assert(false);
		}
	}
	else assert(false);
}

//获得表达式的值并放到内存中
void get_value(node* expr)
{
	assert(expr);
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
		if (expr->value == "()"){	//函数
			call_func(expr);
		}
		else if (expr->value == "="){
			get_address(expr);
			printf("mov %s, [eax]\n", reg0);
		}
		else if (expr->value == "." || expr->value == "[]" ||
			expr->value == "*" && !expr->child[1]){
			get_address(expr);
			if (expr->type_info->value != "[]")
				printf("mov %s, [eax]\n", reg0);
		}
		else if (expr->value == "&" && !expr->child[1])
			get_address(expr->child[0]);
		else if (expr->value == "&&" || expr->value == "||"){
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
	get_value(expr);
	if (exesp) printf("add esp, %d\n", exesp);
}

void _complie_statement(string func, node* tree, int& desp);

void complie_statement(string func, node* tree)
{
	int desp = 0;	
	if (!tree) return;
	if (tree->type == STATEMENTLIST)	//如果是statelist则依次执行所有的兄第节点
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
		complie_expr(tree->child[0]);	//先执行
		char* reg = is_char(tree->child[0]->type_info) ? "al" : "eax";
		printf("cmp %s, 0\n", reg);
		int lbl0 = label++;
		printf("je label%x\n", lbl0);
		complie_statement(func, tree->child[1]);
		if (tree->child[2])
		{
			int lbl1 = label++;
			printf("jmp label%x\n", lbl1);
			printf("label%x:\n", lbl0);
			complie_statement(func, tree->child[2]);
			printf("label%x:\n", lbl1);
		}
		else printf("label%x:\n", lbl0);
	}
	else if (tree->value == "while")
	{
		int lbl0 = label++;
		int lbl1 = label++;
		printf("label%x:\n", lbl0);
		complie_expr(tree->child[0]);
		char* reg = is_char(tree->child[0]->type_info) ? "al" : "eax";
		printf("cmp %s, 0\n", reg);
		printf("je label%x\n", lbl1);
		complie_statement(func, tree->child[1]);
		printf("jmp label%x\n", lbl0);
		printf("label%x:\n", lbl1);
	}
	else if (tree->value == "for")
	{
		int lbl0 = label++;
		int lbl1 = label++;
		if (tree->child[0]) complie_expr(tree->child[0]);
		printf("label%x:\n", lbl0);
		if (tree->child[1])	{
			complie_expr(tree->child[1]);
			char* reg = is_char(tree->child[1]->type_info) ? "al" : "eax";
			printf("cmp %s, 0\n", reg);
			printf("je label%x\n", lbl1);
		}
		complie_statement(func, tree->child[3]);
		if (tree->child[2]) complie_expr(tree->child[2]);
		printf("jmp label%x\n", lbl0);
		printf("label%x:\n", lbl1);
	}
	else if (tree->value == "return")
	{
		if (tree->child[0]){
			complie_expr(tree->child[0]);
			if (is_char(tree->child[0]->type_info))
				printf("movsx eax, al\n");
		}
		else puts("mov eax, 0");
		if (funcesp) printf("add esp, %d\n", funcesp);	//把返回值填入栈中
		puts("pop ebp");
		puts("ret");
	}
	else if (tree->value == "define")
	{
		for (node* it = tree->child[1]; it; it = it->child[0])	{
			node* nd = it->child[1];
			int size;
			if (nd->value == "=") size = ALIGN(nd->child[0]->type_info->size, 4);
			else size = ALIGN(nd->type_info->size, 4);
			printf("sub esp, %d\n", size);
			if (nd->value == "=") complie_expr(nd);
			desp += size; funcesp += size;
		}
	}
	else  cerr<<"ERROR!";
}


void complie_function(node* func)
{
	/*EBP是当前函数的存取指针，即存储或者读取数时的指针基地址；
	 *ESP就是当前函数的栈顶指针;
	 */
	printf("_%s:\n", func->child[0]->value.c_str());
	funcesp = 0;	//记录当前函数的偏移
	puts("push ebp");		/*把当前函数（主函数）的EBP压栈*/
	puts("mov ebp, esp");	/*设置新的基址*/
	complie_statement(func->child[0]->value, func->child[1]);
	if(funcesp) printf("add, esp %d\n", funcesp);	//如果
	puts("pop ebp");
	puts("ret");
	puts("");
}

void complie(node* tree)
{
	puts(".586");
	puts(".model flat, stdcall");
	puts("option casemap:none");
	puts("includelib msvcrt.lib");
	//调用scanf 、 printf 宏
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
			assert(it->child[1]->value == "define");	//只能是定义语句
			for (node* p = it->child[1]->child[1]; p; p = p->child[0])
				if (p->child[1]->value == "=") complie_expr(p->child[1]);
		}
	}
	puts("call _main");	//调用main()函数；
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
