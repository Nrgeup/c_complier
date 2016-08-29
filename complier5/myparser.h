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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/23/15
* Time: 01:36:00
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 33 ".\\myparser.y"

	// place any extra class members here


#line 70 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#define TYPE 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define ID 262
#define NUMBER 263
#define CHARTEXT 264
#define STRTEXT 265
#define RETURN 266
#define AND 267
#define OR 268
#define NOT 269
#define EQ 270
#define LT 271
#define LE 272
#define GT 273
#define GE 274
#define NE 275
#define SHL 276
#define SHR 277
#define BOR 278
#define BXOR 279
#define BAND 280
#define BNOT 281
#define PLUS 282
#define ASSIGN 283
#define MINUS 284
#define MUL 285
#define DIV 286
#define MOD 287
#define LPAREN 288
#define RPAREN 289
#define LBRACE 290
#define RBRACE 291
#define LBRACKET 292
#define RBRACKET 293
#define SEMICOLON 294
#define COMMA 295
#define MEMBER 296
#line 51 ".\\myparser.y"

#include "tree.h"
#include <string>
using namespace std;

extern node* root;
#ifndef YYSTYPE
#define YYSTYPE node*
#endif

#line 128 "myparser.h"
#endif
