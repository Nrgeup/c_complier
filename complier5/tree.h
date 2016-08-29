#ifndef COMP
#define COMP
#pragma warning(disable : 4786)
#include <vector>
#include <string>
#include <map>
using namespace std;

enum 
{
	DEFINELIST=0,	//定义语句
	EXPR,			//表达式
	EXPRLIST,		//表达式集合
	STATEMENT,		//语句
	STATEMENTLIST,	//语句集合
	FUNCTION,		//函数
	FUNCTIONTYPE,	//函数类型
	PARAM,			//参数
	PARAMLIST		//参数集合
};

struct type_node	//类型节点
{
	string value;		//数据类型描述
	type_node* base;	//子类型
	int size;			//大小
	int align;			//共分配的内存大小
	type_node() : base(0), size(0), align(0) {}
	type_node(string value, type_node* base, int size, int align) 
		: value(value), base(base), size(size), align(align) {}

};


struct var_node		//变量节点
{
	type_node* type_info;	//类型描述
	int offset;			//内存的地址值
	var_node(type_node* type_info = 0, int offset = 0) : type_info(type_info), offset(offset) {}
};



struct struct_node		//复合数据类型
{
	map<string, var_node*> element;
	vector<pair<string, var_node*> > init_order;
	int size;
	int align;
	struct_node() : size(0), align(0) {}
	struct_node(int size, int align) : size(size) ,align(align) {}
};

struct node		//节点
{
	int type;	//类型
	string value; 	//子类型信息
	node* child[4];	
	type_node* type_info;	//类型信息
	bool if_get_addr;			//是否需要查询地址
	node(int type, string val, node* c0 = 0, node* c1 = 0, node* c2 = 0, node* c3 = 0) 
		: type(type), value(val), type_info(0), if_get_addr(false)
	{
		child[0] = c0; child[1] = c1; child[2] = c2; child[3] = c3;
	}
};

bool type_check(node* tree);	//类型检查
void complie(node* tree);		//翻译
void print(node* tree, int deep = 0);	//显示树结构

#endif