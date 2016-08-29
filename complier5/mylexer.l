%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2015Äê12ÔÂ9ÈÕ
****************************************************************************/

#include "myparser.h"
#include "tree.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>


using namespace std;


%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

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

// place any declarations here
id [a-zA-Z_][0-9a-zA-Z_]*
number [0-9]+
space [\t\n ]+
annotation ("/*"([^*]|(\*[^/]))*\*?"*/")|("//".*\n)
char_text \'((\\.)|([^\\'\n]))*\'
str_text \"((\\.)|([^\\"\n]))*\"
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
"if"        {return IF;}
"else"      {return ELSE;}
"while"     {return WHILE;}
"for"       {return FOR;}
"return"	{return RETURN;}
";"         {return SEMICOLON;}
","         {return COMMA;}
"<<"		{return SHL;}
">>"		{return SHR;}
"=="        {return EQ;}
"<="        {return LE;}
">="        {return GE;}
"!="        {return NE;}
"||"        {return OR;}
"&&"        {return AND;}
"="         {return ASSIGN;}
"|"			{return BOR;}
"^"			{return BXOR;}
"&"			{return BAND;}
"<"         {return LT;}
">"         {return GT;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"			{return MOD;}
"("         {return LPAREN;}
")"         {return RPAREN;}
"{"         {return LBRACE;}
"}"         {return RBRACE;}
"["         {return LBRACKET;}
"]"         {return RBRACKET;}
"!"         {return NOT;}
"~"			{return BNOT;}
"."			{return MEMBER;}
{id}        {
				yylval = new node(ID, yytext);
				if (strcmp(yytext, "int") == 0 || 
					strcmp(yytext, "char") == 0 ||
					strcmp(yytext, "void") == 0) return TYPE;
				else return ID;	
			}
{number}	{
				yylval = new node(NUMBER, yytext);
				return NUMBER;	
			}
{char_text}	{yylval = new node(CHARTEXT, yytext); return CHARTEXT;}
{str_text}	{yylval = new node(STRTEXT, yytext); return STRTEXT;}
{space}		{}
{annotation} {}
%%

/////////////////////////////////////////////////////////////////////////////
// programs section
