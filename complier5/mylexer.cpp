/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 75 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/23/15
* Time: 01:35:59
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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



#line 62 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 37 ".\\mylexer.l"

	// place any extra initialisation code here

#line 86 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 42 ".\\mylexer.l"

	// place any extra cleanup code here

#line 98 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 58 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 169 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 64 ".\\mylexer.l"
return IF;
#line 176 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 65 ".\\mylexer.l"
return ELSE;
#line 183 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 66 ".\\mylexer.l"
return WHILE;
#line 190 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 67 ".\\mylexer.l"
return FOR;
#line 197 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 68 ".\\mylexer.l"
return RETURN;
#line 204 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 69 ".\\mylexer.l"
return SEMICOLON;
#line 211 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 70 ".\\mylexer.l"
return COMMA;
#line 218 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 71 ".\\mylexer.l"
return SHL;
#line 225 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 72 ".\\mylexer.l"
return SHR;
#line 232 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 73 ".\\mylexer.l"
return EQ;
#line 239 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 74 ".\\mylexer.l"
return LE;
#line 246 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 75 ".\\mylexer.l"
return GE;
#line 253 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 76 ".\\mylexer.l"
return NE;
#line 260 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 77 ".\\mylexer.l"
return OR;
#line 267 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 78 ".\\mylexer.l"
return AND;
#line 274 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 79 ".\\mylexer.l"
return ASSIGN;
#line 281 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 80 ".\\mylexer.l"
return BOR;
#line 288 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 81 ".\\mylexer.l"
return BXOR;
#line 295 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 82 ".\\mylexer.l"
return BAND;
#line 302 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 83 ".\\mylexer.l"
return LT;
#line 309 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 84 ".\\mylexer.l"
return GT;
#line 316 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 85 ".\\mylexer.l"
return PLUS;
#line 323 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 86 ".\\mylexer.l"
return MINUS;
#line 330 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 87 ".\\mylexer.l"
return MUL;
#line 337 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 88 ".\\mylexer.l"
return DIV;
#line 344 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 89 ".\\mylexer.l"
return MOD;
#line 351 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 90 ".\\mylexer.l"
return LPAREN;
#line 358 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 91 ".\\mylexer.l"
return RPAREN;
#line 365 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 92 ".\\mylexer.l"
return LBRACE;
#line 372 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 93 ".\\mylexer.l"
return RBRACE;
#line 379 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 94 ".\\mylexer.l"
return LBRACKET;
#line 386 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 95 ".\\mylexer.l"
return RBRACKET;
#line 393 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 96 ".\\mylexer.l"
return NOT;
#line 400 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 97 ".\\mylexer.l"
return BNOT;
#line 407 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 98 ".\\mylexer.l"
return MEMBER;
#line 414 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 99 ".\\mylexer.l"

				yylval = new node(ID, yytext);
				if (strcmp(yytext, "int") == 0 || 
					strcmp(yytext, "char") == 0 ||
					strcmp(yytext, "void") == 0) return TYPE;
				else return ID;	
			
#line 427 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 106 ".\\mylexer.l"

				yylval = new node(NUMBER, yytext);
				return NUMBER;	
			
#line 437 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 110 ".\\mylexer.l"
yylval = new node(CHARTEXT, yytext); return CHARTEXT;
#line 444 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 111 ".\\mylexer.l"
yylval = new node(STRTEXT, yytext); return STRTEXT;
#line 451 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 112 ".\\mylexer.l"

#line 458 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 113 ".\\mylexer.l"

#line 465 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 194;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 36, 5 },
		{ 39, 8 },
		{ 3, 3 },
		{ 3, 3 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 60, 54 },
		{ 41, 16 },
		{ 43, 19 },
		{ 44, 19 },
		{ 35, 4 },
		{ 55, 54 },
		{ 42, 16 },
		{ 3, 1 },
		{ 4, 1 },
		{ 5, 1 },
		{ 48, 26 },
		{ 3, 3 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 49, 27 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 46, 21 },
		{ 47, 21 },
		{ 40, 8 },
		{ 50, 28 },
		{ 51, 29 },
		{ 52, 30 },
		{ 37, 5 },
		{ 53, 32 },
		{ 0, 37 },
		{ 0, 40 },
		{ 55, 42 },
		{ 56, 48 },
		{ 57, 49 },
		{ 58, 51 },
		{ 59, 52 },
		{ 38, 7 },
		{ 61, 56 },
		{ 62, 58 },
		{ 63, 59 },
		{ 64, 60 },
		{ 65, 62 },
		{ 66, 63 },
		{ 54, 64 },
		{ 67, 65 },
		{ 45, 20 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 23, 1 },
		{ 0, 0 },
		{ 24, 1 },
		{ 25, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 26, 1 },
		{ 27, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 28, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 29, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 30, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 22, 67 },
		{ 0, 0 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 },
		{ 22, 67 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 67, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -4, 40 },
		{ 0, -40, 33 },
		{ 37, -31, 0 },
		{ 0, 0, 26 },
		{ 0, 32, 19 },
		{ 40, -35, 0 },
		{ 0, 0, 27 },
		{ 0, 0, 28 },
		{ 0, 0, 24 },
		{ 0, 0, 22 },
		{ 0, 0, 7 },
		{ 0, 0, 23 },
		{ 0, 0, 35 },
		{ 0, -24, 25 },
		{ 0, -41, 37 },
		{ 0, 0, 6 },
		{ 0, -41, 20 },
		{ 0, 18, 16 },
		{ 0, -6, 21 },
		{ 67, 0, 36 },
		{ 0, 0, 31 },
		{ 0, 0, 32 },
		{ 0, 0, 18 },
		{ 67, -81, 36 },
		{ 67, -61, 36 },
		{ 67, -44, 36 },
		{ 67, -42, 36 },
		{ 67, -44, 36 },
		{ 0, 0, 29 },
		{ 0, -62, 17 },
		{ 0, 0, 30 },
		{ 0, 0, 34 },
		{ 0, 0, 13 },
		{ 0, 0, 39 },
		{ -5, 53, 0 },
		{ 0, 0, 15 },
		{ 0, 0, 38 },
		{ -8, 54, 0 },
		{ 64, 0, 0 },
		{ -42, 55, 0 },
		{ 0, 0, 8 },
		{ 0, 0, 11 },
		{ 0, 0, 10 },
		{ 0, 0, 12 },
		{ 0, 0, 9 },
		{ 67, -49, 36 },
		{ 67, -47, 36 },
		{ 67, 0, 1 },
		{ 67, -48, 36 },
		{ 67, -36, 36 },
		{ 0, 0, 14 },
		{ -41, -25, 0 },
		{ 0, 0, 41 },
		{ 67, -30, 36 },
		{ 67, 0, 4 },
		{ 67, -45, 36 },
		{ 67, -35, 36 },
		{ 64, 27, 0 },
		{ 67, 0, 2 },
		{ 67, -39, 36 },
		{ 67, -25, 36 },
		{ -41, 35, 41 },
		{ 67, -32, 36 },
		{ 67, 0, 3 },
		{ 0, 71, 5 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 114 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

