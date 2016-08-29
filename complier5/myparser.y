%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2015年12月9日
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <iomanip>
#include "tree.h"
#include <string>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>


using namespace std;

node* root;

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here

}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}
%token TYPE IF ELSE WHILE FOR ID NUMBER CHARTEXT STRTEXT  RETURN
%token AND OR NOT EQ LT LE GT GE NE SHL SHR BOR BXOR BAND BNOT PLUS ASSIGN MINUS MUL DIV MOD LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA MEMBER

// attribute type
%include {
#include "tree.h"
#include <string>
using namespace std;

extern node* root;
#ifndef YYSTYPE
#define YYSTYPE node*
#endif
}

// place any declarations here


%%

/////////////////////////////////////////////////////////////////////////////
// rules section



// place your YACC rules here (there must be at least one)
program		: define_list {root = $1;}
			;

define_list	: define define_list 		{$$ = new node(DEFINELIST, "", $2, $1);}	
			|							{$$ = 0;}
			;
define		: func_type	SEMICOLON		{$$ = $1;}
			| function					{$$ = $1;}
			| type def_list SEMICOLON   {$$ = new node(STATEMENT, "define", $1, $2);}
			| SEMICOLON					{$$ = 0;}
			; 
function	: func_type	LBRACE statement_list RBRACE {$$ = new node(FUNCTION, "", $1, $3);}
			| func_type	LBRACE RBRACE	{$$ = new node(FUNCTION, "", $1, 0);}
			;			
func_type	: type func_l_op			{$$ = new node(FUNCTIONTYPE, "", $1, $2);}
			;	
func_l_op	: MUL func_l_op				{$$ = new node(EXPR, "*", $2);}
			| func_r_op					{$$ = $1;}
			;
func_r_op	: func_r_op LBRACKET NUMBER RBRACKET {$$ = new node(EXPR, "[]", $1, $3);}
			| func_term					{$$ = $1;}
			;
func_term	: ID LPAREN param_list RPAREN {$$ = new node(EXPR, "()", $1, $3);}
			| LPAREN func_l_op RPAREN	{$$ = $2;}
			;
param_list	: param COMMA param_list 	{$$ = new node(PARAMLIST, "", $3, $1);}
			| param						{$$ = new node(PARAMLIST, "", 0, $1);}
			|							{$$ = 0;}
			;
param		: type def_l_op				{$$ = new node(PARAM, "", $1, $2);}
			;
statement_list	: statement statement_list	{$$ = new node(STATEMENTLIST, "", $2, $1);}
				| statement					{$$ = new node(STATEMENTLIST, "", 0, $1);}
				;
statement	: expr SEMICOLON
			{$$ = $1;}
			| WHILE LPAREN expr RPAREN statement		
			{$$ = new node(STATEMENT, "while", $3, $5);}
			| FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement
			{$$ = new node(STATEMENT, "for", $3, $5, $7, $9);}
			| IF LPAREN expr RPAREN statement ELSE statement 
			{$$ = new node(STATEMENT, "if", $3, $5, $7);}
			| IF LPAREN expr RPAREN statement				
			{$$ = new node(STATEMENT, "if", $3, $5);}
			| RETURN _expr SEMICOLON
			{$$ = new node(STATEMENT, "return", $2);}
			| type def_list SEMICOLON
			{$$ = new node(STATEMENT, "define", $1, $2);}
			| LBRACE statement_list RBRACE	{$$ = $2;}
			| LBRACE RBRACE				{$$ = 0;}
			| SEMICOLON					{$$ = 0;}
			;
_expr		: expr	{$$ = $1;}
			|		{$$ = 0;}
			;
def_list	: def_expr COMMA def_list	{$$ = new node(EXPRLIST, "", $3, $1);}
			| def_expr					{$$ = new node(EXPRLIST, "", 0, $1);}
			;
def_expr	: def_l_op ASSIGN expr		{$$ = new node(EXPR, "=", $1, $3);}
			| def_l_op ASSIGN LBRACE init_list RBRACE{$$ = new node(EXPR, "=", $1, $4);}
			| def_l_op					{$$ = $1;}
			;
def_l_op	: MUL def_l_op				{$$ = new node(EXPR, "*", $2);}
			| def_r_op					{$$ = $1;}
			;
def_r_op	: def_r_op LBRACKET NUMBER RBRACKET {$$ = new node(EXPR, "[]", $1, $3);}
			| def_term					{$$ = $1;}
			;
def_term	: LPAREN def_l_op RPAREN	{$$ = $2;}
			| ID 						{$$ = $1;}
			;
init_list	: init_expr COMMA init_list	{$$ = new node(EXPRLIST, "", $3, $1);}
			| init_expr					{$$ = new node(EXPRLIST, "", 0, $1);}
			;
init_expr	: LBRACE init_list RBRACE{$$ = $2;}
			| expr				{$$ = $1;}
			;
expr		: assign			{$$ = $1;}
			;
assign		: or ASSIGN assign	{$$ = new node(EXPR, "=", $1, $3);}
			| or				{$$ = $1;}
			;	
or			: or  OR  and		{$$ = new node(EXPR, "||", $1, $3);}
			| and				{$$ = $1;}
			;
and			: and AND b_or		{$$ = new node(EXPR, "&&", $1, $3);}
			| b_or				{$$ = $1;}
			;
b_or		: b_or  BOR  b_xor	{$$ = new node(EXPR, "|", $1, $3);}
			| b_xor				{$$ = $1;}
			;
b_xor		: b_xor BXOR b_and	{$$ = new node(EXPR, "^", $1, $3);}
			| b_and				{$$ = $1;}
			;
b_and		: b_and BAND equal	{$$ = new node(EXPR, "&", $1, $3);}
			| equal				{$$ = $1;}
			;

equal		: equal EQ less		{$$ = new node(EXPR, "==", $1, $3);}
			| equal NE less		{$$ = new node(EXPR, "!=", $1, $3);}
			| less				{$$ = $1;}
			;
less		: less LT shift		{$$ = new node(EXPR, "<" , $1, $3);}
			| less LE shift		{$$ = new node(EXPR, "<=", $1, $3);}
			| less GT shift		{$$ = new node(EXPR, ">" , $1, $3);}
			| less GE shift		{$$ = new node(EXPR, ">=", $1, $3);}
			| plus				{$$ = $1;}
			;
shift		: shift SHL plus	{$$ = new node(EXPR, "<<", $1, $2);}
			| shift SHR plus	{$$ = new node(EXPR, ">>", $1, $2);}
			| plus				{$$ = $1;}
			;
plus		: plus PLUS  mul	{$$ = new node(EXPR, "+", $1, $3);}
			| plus MINUS mul	{$$ = new node(EXPR, "-", $1, $3);}
			| mul				{$$ = $1;}
			;
mul			: mul MUL l_op		{$$ = new node(EXPR, "*", $1, $3);}
			| mul DIV l_op		{$$ = new node(EXPR, "/", $1, $3);}
			| mul MOD l_op		{$$ = new node(EXPR, "%", $1, $3);}
			| l_op				{$$ = $1;}
			;	
l_op		:  NOT l_op			{$$ = new node(EXPR, "!", $2);}
			| BNOT l_op			{$$ = new node(EXPR, "~", $2);}
			|  MUL l_op			{$$ = new node(EXPR, "*", $2);}
			| BAND l_op			{$$ = new node(EXPR, "&", $2);}
			| MINUS l_op		{$$ = new node(EXPR, "-", $2);}
			| r_op				{$$ = $1;}
			;
r_op		: r_op LBRACKET expr RBRACKET{$$ = new node(EXPR, "[]", $1, $3);}
			| r_op LPAREN expr_list RPAREN{$$ = new node(EXPR, "()", $1, $3);}
			| r_op MEMBER ID		{$$ = new node(EXPR, ".", $1, $3);}
			| term					{$$ = $1;}
			;
expr_list	: expr COMMA expr_list	{$$ = new node(EXPRLIST, "", $3, $1);}
			| expr					{$$ = new node(EXPRLIST, "", 0, $1);}
			|						{$$ = 0;}
			;
type		: TYPE				{$$ = $1;}
			;
term		: ID				{$$ = $1;} 
			| NUMBER			{$$ = $1;}
			| CHARTEXT			{$$ = $1;}
			| STRTEXT			{$$ = $1;}
			| LPAREN expr RPAREN{$$ = $2;}
			;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section


int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
		
		lexer.yyin = new ifstream("Data\\input.txt");
		
		//lexer.yyin = new ifstream("Data\\input_fib.txt");	/*测试文件，运行老师例子*/
		//lexer.yyin = new ifstream("Data\\input1.txt");	/*测试文件，测试输入输出、数组、指针功能*/
		//lexer.yyin = new ifstream("Data\\input2.txt");	/*测试文件，测试函数功能*/
		//lexer.yyin = new ifstream("Data\\input3.txt");	/*测试文件，测试递归功能*/
		
			n = parser.yyparse();
			delete lexer.yyin;
			lexer.yyin = 0;
			if (type_check(root)){
				freopen("Data\\print.txt", "w", stdout);
				print(root);
				freopen("Data\\output.asm", "w", stdout);
				complie(root);
			}
		}
	}
	//getchar();
	return n;
}

