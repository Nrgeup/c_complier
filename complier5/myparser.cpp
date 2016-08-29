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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/23/15
* Time: 01:36:00
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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


#line 63 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 39 ".\\myparser.y"

	// place any extra initialisation code here

#line 87 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 44 ".\\myparser.y"

	// place any extra cleanup code here

#line 101 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 73 ".\\myparser.y"
root = yyattribute(1 - 1);
#line 211 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 76 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(DEFINELIST, "", yyattribute(2 - 2), yyattribute(1 - 2));
#line 224 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#line 77 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 232 "myparser.cpp"
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 79 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 244 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 80 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 257 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 81 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "define", yyattribute(1 - 3), yyattribute(2 - 3));
#line 270 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 82 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 283 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 84 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(FUNCTION, "", yyattribute(1 - 4), yyattribute(3 - 4));
#line 296 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 85 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(FUNCTION, "", yyattribute(1 - 3), 0);
#line 309 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 87 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(FUNCTIONTYPE, "", yyattribute(1 - 2), yyattribute(2 - 2));
#line 322 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 89 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "*", yyattribute(2 - 2));
#line 335 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 90 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 348 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 92 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "[]", yyattribute(1 - 4), yyattribute(3 - 4));
#line 361 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 93 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 374 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 95 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "()", yyattribute(1 - 4), yyattribute(3 - 4));
#line 387 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 96 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 400 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 98 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(PARAMLIST, "", yyattribute(3 - 3), yyattribute(1 - 3));
#line 413 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 99 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(PARAMLIST, "", 0, yyattribute(1 - 1));
#line 426 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#line 100 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 434 "myparser.cpp"
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 102 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(PARAM, "", yyattribute(1 - 2), yyattribute(2 - 2));
#line 446 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 104 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENTLIST, "", yyattribute(2 - 2), yyattribute(1 - 2));
#line 459 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 105 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENTLIST, "", 0, yyattribute(1 - 1));
#line 472 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 108 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 485 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 110 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "while", yyattribute(3 - 5), yyattribute(5 - 5));
#line 498 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 112 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "for", yyattribute(3 - 9), yyattribute(5 - 9), yyattribute(7 - 9), yyattribute(9 - 9));
#line 511 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 114 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "if", yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 524 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 116 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "if", yyattribute(3 - 5), yyattribute(5 - 5));
#line 537 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 118 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "return", yyattribute(2 - 3));
#line 550 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 120 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(STATEMENT, "define", yyattribute(1 - 3), yyattribute(2 - 3));
#line 563 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 121 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 576 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 122 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 589 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 123 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 602 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 125 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 615 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#line 126 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 623 "myparser.cpp"
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 128 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", yyattribute(3 - 3), yyattribute(1 - 3));
#line 635 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 129 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", 0, yyattribute(1 - 1));
#line 648 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 131 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 661 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 132 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "=", yyattribute(1 - 5), yyattribute(4 - 5));
#line 674 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 133 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 687 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 135 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "*", yyattribute(2 - 2));
#line 700 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 136 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 713 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 138 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "[]", yyattribute(1 - 4), yyattribute(3 - 4));
#line 726 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 139 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 739 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 141 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 752 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 142 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 765 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 144 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", yyattribute(3 - 3), yyattribute(1 - 3));
#line 778 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 145 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", 0, yyattribute(1 - 1));
#line 791 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 147 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 804 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 148 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 817 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 150 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 830 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 152 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 843 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 153 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 856 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 155 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "||", yyattribute(1 - 3), yyattribute(3 - 3));
#line 869 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 156 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 882 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 158 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "&&", yyattribute(1 - 3), yyattribute(3 - 3));
#line 895 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 159 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 908 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 161 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "|", yyattribute(1 - 3), yyattribute(3 - 3));
#line 921 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 934 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 164 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "^", yyattribute(1 - 3), yyattribute(3 - 3));
#line 947 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 165 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 960 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 167 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "&", yyattribute(1 - 3), yyattribute(3 - 3));
#line 973 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 168 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 986 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 171 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "==", yyattribute(1 - 3), yyattribute(3 - 3));
#line 999 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 172 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "!=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1012 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 173 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1025 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 175 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "<" , yyattribute(1 - 3), yyattribute(3 - 3));
#line 1038 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 176 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "<=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1051 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 177 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, ">" , yyattribute(1 - 3), yyattribute(3 - 3));
#line 1064 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 178 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, ">=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1077 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1090 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 181 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "<<", yyattribute(1 - 3), yyattribute(2 - 3));
#line 1103 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, ">>", yyattribute(1 - 3), yyattribute(2 - 3));
#line 1116 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 183 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1129 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 185 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "+", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1142 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "-", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1155 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 187 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1168 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 189 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "*", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1181 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 190 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "/", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1194 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 191 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "%", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1207 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 192 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1220 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "!", yyattribute(2 - 2));
#line 1233 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "~", yyattribute(2 - 2));
#line 1246 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "*", yyattribute(2 - 2));
#line 1259 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "&", yyattribute(2 - 2));
#line 1272 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 198 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "-", yyattribute(2 - 2));
#line 1285 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 199 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1298 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 201 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "[]", yyattribute(1 - 4), yyattribute(3 - 4));
#line 1311 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 202 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, "()", yyattribute(1 - 4), yyattribute(3 - 4));
#line 1324 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPR, ".", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1337 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 204 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1350 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 206 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", yyattribute(3 - 3), yyattribute(1 - 3));
#line 1363 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 207 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new node(EXPRLIST, "", 0, yyattribute(1 - 1));
#line 1376 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#line 208 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = 0;
#line 1384 "myparser.cpp"
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 210 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1396 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1409 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1422 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 214 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1435 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 215 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1448 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 216 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 1461 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "TYPE", 257 },
		{ "IF", 258 },
		{ "ELSE", 259 },
		{ "WHILE", 260 },
		{ "FOR", 261 },
		{ "ID", 262 },
		{ "NUMBER", 263 },
		{ "CHARTEXT", 264 },
		{ "STRTEXT", 265 },
		{ "RETURN", 266 },
		{ "AND", 267 },
		{ "OR", 268 },
		{ "NOT", 269 },
		{ "EQ", 270 },
		{ "LT", 271 },
		{ "LE", 272 },
		{ "GT", 273 },
		{ "GE", 274 },
		{ "NE", 275 },
		{ "SHL", 276 },
		{ "SHR", 277 },
		{ "BOR", 278 },
		{ "BXOR", 279 },
		{ "BAND", 280 },
		{ "BNOT", 281 },
		{ "PLUS", 282 },
		{ "ASSIGN", 283 },
		{ "MINUS", 284 },
		{ "MUL", 285 },
		{ "DIV", 286 },
		{ "MOD", 287 },
		{ "LPAREN", 288 },
		{ "RPAREN", 289 },
		{ "LBRACE", 290 },
		{ "RBRACE", 291 },
		{ "LBRACKET", 292 },
		{ "RBRACKET", 293 },
		{ "SEMICOLON", 294 },
		{ "COMMA", 295 },
		{ "MEMBER", 296 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: define_list",
		"define_list: define define_list",
		"define_list:",
		"define: func_type SEMICOLON",
		"define: function",
		"define: type def_list SEMICOLON",
		"define: SEMICOLON",
		"function: func_type LBRACE statement_list RBRACE",
		"function: func_type LBRACE RBRACE",
		"func_type: type func_l_op",
		"func_l_op: MUL func_l_op",
		"func_l_op: func_r_op",
		"func_r_op: func_r_op LBRACKET NUMBER RBRACKET",
		"func_r_op: func_term",
		"func_term: ID LPAREN param_list RPAREN",
		"func_term: LPAREN func_l_op RPAREN",
		"param_list: param COMMA param_list",
		"param_list: param",
		"param_list:",
		"param: type def_l_op",
		"statement_list: statement statement_list",
		"statement_list: statement",
		"statement: expr SEMICOLON",
		"statement: WHILE LPAREN expr RPAREN statement",
		"statement: FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement",
		"statement: IF LPAREN expr RPAREN statement ELSE statement",
		"statement: IF LPAREN expr RPAREN statement",
		"statement: RETURN _expr SEMICOLON",
		"statement: type def_list SEMICOLON",
		"statement: LBRACE statement_list RBRACE",
		"statement: LBRACE RBRACE",
		"statement: SEMICOLON",
		"_expr: expr",
		"_expr:",
		"def_list: def_expr COMMA def_list",
		"def_list: def_expr",
		"def_expr: def_l_op ASSIGN expr",
		"def_expr: def_l_op ASSIGN LBRACE init_list RBRACE",
		"def_expr: def_l_op",
		"def_l_op: MUL def_l_op",
		"def_l_op: def_r_op",
		"def_r_op: def_r_op LBRACKET NUMBER RBRACKET",
		"def_r_op: def_term",
		"def_term: LPAREN def_l_op RPAREN",
		"def_term: ID",
		"init_list: init_expr COMMA init_list",
		"init_list: init_expr",
		"init_expr: LBRACE init_list RBRACE",
		"init_expr: expr",
		"expr: assign",
		"assign: or ASSIGN assign",
		"assign: or",
		"or: or OR and",
		"or: and",
		"and: and AND b_or",
		"and: b_or",
		"b_or: b_or BOR b_xor",
		"b_or: b_xor",
		"b_xor: b_xor BXOR b_and",
		"b_xor: b_and",
		"b_and: b_and BAND equal",
		"b_and: equal",
		"equal: equal EQ less",
		"equal: equal NE less",
		"equal: less",
		"less: less LT shift",
		"less: less LE shift",
		"less: less GT shift",
		"less: less GE shift",
		"less: plus",
		"shift: shift SHL plus",
		"shift: shift SHR plus",
		"shift: plus",
		"plus: plus PLUS mul",
		"plus: plus MINUS mul",
		"plus: mul",
		"mul: mul MUL l_op",
		"mul: mul DIV l_op",
		"mul: mul MOD l_op",
		"mul: l_op",
		"l_op: NOT l_op",
		"l_op: BNOT l_op",
		"l_op: MUL l_op",
		"l_op: BAND l_op",
		"l_op: MINUS l_op",
		"l_op: r_op",
		"r_op: r_op LBRACKET expr RBRACKET",
		"r_op: r_op LPAREN expr_list RPAREN",
		"r_op: r_op MEMBER ID",
		"r_op: term",
		"expr_list: expr COMMA expr_list",
		"expr_list: expr",
		"expr_list:",
		"type: TYPE",
		"term: ID",
		"term: NUMBER",
		"term: CHARTEXT",
		"term: STRTEXT",
		"term: LPAREN expr RPAREN"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 2, 2, 1 },
		{ 2, 0, 2 },
		{ 3, 2, 3 },
		{ 3, 1, 4 },
		{ 3, 3, 5 },
		{ 3, 1, 6 },
		{ 4, 4, 7 },
		{ 4, 3, 8 },
		{ 5, 2, 9 },
		{ 6, 2, 10 },
		{ 6, 1, 11 },
		{ 7, 4, 12 },
		{ 7, 1, 13 },
		{ 8, 4, 14 },
		{ 8, 3, 15 },
		{ 9, 3, 16 },
		{ 9, 1, 17 },
		{ 9, 0, 18 },
		{ 10, 2, 19 },
		{ 11, 2, 20 },
		{ 11, 1, 21 },
		{ 12, 2, 22 },
		{ 12, 5, 23 },
		{ 12, 9, 24 },
		{ 12, 7, 25 },
		{ 12, 5, 26 },
		{ 12, 3, 27 },
		{ 12, 3, 28 },
		{ 12, 3, 29 },
		{ 12, 2, 30 },
		{ 12, 1, 31 },
		{ 13, 1, 32 },
		{ 13, 0, 33 },
		{ 14, 3, 34 },
		{ 14, 1, 35 },
		{ 15, 3, 36 },
		{ 15, 5, 37 },
		{ 15, 1, 38 },
		{ 16, 2, 39 },
		{ 16, 1, 40 },
		{ 17, 4, 41 },
		{ 17, 1, 42 },
		{ 18, 3, 43 },
		{ 18, 1, 44 },
		{ 19, 3, 45 },
		{ 19, 1, 46 },
		{ 20, 3, 47 },
		{ 20, 1, 48 },
		{ 21, 1, 49 },
		{ 22, 3, 50 },
		{ 22, 1, 51 },
		{ 23, 3, 52 },
		{ 23, 1, 53 },
		{ 24, 3, 54 },
		{ 24, 1, 55 },
		{ 25, 3, 56 },
		{ 25, 1, 57 },
		{ 26, 3, 58 },
		{ 26, 1, 59 },
		{ 27, 3, 60 },
		{ 27, 1, 61 },
		{ 28, 3, 62 },
		{ 28, 3, 63 },
		{ 28, 1, 64 },
		{ 29, 3, 65 },
		{ 29, 3, 66 },
		{ 29, 3, 67 },
		{ 29, 3, 68 },
		{ 29, 1, 69 },
		{ 30, 3, 70 },
		{ 30, 3, 71 },
		{ 30, 1, 72 },
		{ 31, 3, 73 },
		{ 31, 3, 74 },
		{ 31, 1, 75 },
		{ 32, 3, 76 },
		{ 32, 3, 77 },
		{ 32, 3, 78 },
		{ 32, 1, 79 },
		{ 33, 2, 80 },
		{ 33, 2, 81 },
		{ 33, 2, 82 },
		{ 33, 2, 83 },
		{ 33, 2, 84 },
		{ 33, 1, 85 },
		{ 34, 4, 86 },
		{ 34, 4, 87 },
		{ 34, 3, 88 },
		{ 34, 1, 89 },
		{ 35, 3, 90 },
		{ 35, 1, 91 },
		{ 35, 0, 92 },
		{ 36, 1, 93 },
		{ 37, 1, 94 },
		{ 37, 1, 95 },
		{ 37, 1, 96 },
		{ 37, 1, 97 },
		{ 37, 3, 98 }
	};
	yyreduction = reduction;

	yytokenaction_size = 210;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 179, YYAT_SHIFT, 1 },
		{ 179, YYAT_SHIFT, 23 },
		{ 178, YYAT_SHIFT, 179 },
		{ 179, YYAT_SHIFT, 24 },
		{ 179, YYAT_SHIFT, 25 },
		{ 179, YYAT_SHIFT, 26 },
		{ 179, YYAT_SHIFT, 27 },
		{ 179, YYAT_SHIFT, 28 },
		{ 179, YYAT_SHIFT, 29 },
		{ 179, YYAT_SHIFT, 30 },
		{ 41, YYAT_SHIFT, 81 },
		{ 5, YYAT_SHIFT, 1 },
		{ 179, YYAT_SHIFT, 31 },
		{ 166, YYAT_ERROR, 0 },
		{ 166, YYAT_ERROR, 0 },
		{ 0, YYAT_SHIFT, 1 },
		{ 166, YYAT_ERROR, 0 },
		{ 166, YYAT_ERROR, 0 },
		{ 142, YYAT_SHIFT, 94 },
		{ 142, YYAT_SHIFT, 95 },
		{ 142, YYAT_SHIFT, 96 },
		{ 142, YYAT_SHIFT, 97 },
		{ 166, YYAT_ERROR, 0 },
		{ 179, YYAT_SHIFT, 32 },
		{ 179, YYAT_SHIFT, 33 },
		{ 41, YYAT_SHIFT, 82 },
		{ 169, YYAT_SHIFT, 176 },
		{ 179, YYAT_SHIFT, 34 },
		{ 179, YYAT_SHIFT, 35 },
		{ 167, YYAT_SHIFT, 175 },
		{ 109, YYAT_SHIFT, 102 },
		{ 179, YYAT_SHIFT, 36 },
		{ 164, YYAT_SHIFT, 173 },
		{ 179, YYAT_SHIFT, 37 },
		{ 14, YYAT_SHIFT, 12 },
		{ 44, YYAT_SHIFT, 1 },
		{ 44, YYAT_SHIFT, 23 },
		{ 179, YYAT_SHIFT, 39 },
		{ 44, YYAT_SHIFT, 24 },
		{ 44, YYAT_SHIFT, 25 },
		{ 44, YYAT_SHIFT, 26 },
		{ 44, YYAT_SHIFT, 27 },
		{ 44, YYAT_SHIFT, 28 },
		{ 44, YYAT_SHIFT, 29 },
		{ 44, YYAT_SHIFT, 30 },
		{ 162, YYAT_ERROR, 0 },
		{ 166, YYAT_SHIFT, 149 },
		{ 44, YYAT_SHIFT, 31 },
		{ 5, YYAT_SHIFT, 2 },
		{ 135, YYAT_SHIFT, 98 },
		{ 166, YYAT_ERROR, 0 },
		{ 7, YYAT_SHIFT, 10 },
		{ 0, YYAT_SHIFT, 2 },
		{ 109, YYAT_SHIFT, 103 },
		{ 135, YYAT_SHIFT, 99 },
		{ 7, YYAT_SHIFT, 11 },
		{ 109, YYAT_SHIFT, 104 },
		{ 14, YYAT_SHIFT, 13 },
		{ 44, YYAT_SHIFT, 32 },
		{ 44, YYAT_SHIFT, 33 },
		{ 14, YYAT_SHIFT, 14 },
		{ 49, YYAT_SHIFT, 90 },
		{ 44, YYAT_SHIFT, 34 },
		{ 44, YYAT_SHIFT, 35 },
		{ 152, YYAT_SHIFT, 166 },
		{ 49, YYAT_SHIFT, 91 },
		{ 44, YYAT_SHIFT, 36 },
		{ 150, YYAT_SHIFT, 165 },
		{ 44, YYAT_SHIFT, 37 },
		{ 49, YYAT_SHIFT, 92 },
		{ 140, YYAT_SHIFT, 161 },
		{ 140, YYAT_SHIFT, 162 },
		{ 44, YYAT_SHIFT, 39 },
		{ 176, YYAT_SHIFT, 26 },
		{ 176, YYAT_SHIFT, 27 },
		{ 176, YYAT_SHIFT, 28 },
		{ 176, YYAT_SHIFT, 29 },
		{ 144, YYAT_SHIFT, 87 },
		{ 144, YYAT_SHIFT, 88 },
		{ 144, YYAT_SHIFT, 89 },
		{ 176, YYAT_SHIFT, 31 },
		{ 53, YYAT_SHIFT, 98 },
		{ 158, YYAT_SHIFT, 26 },
		{ 158, YYAT_SHIFT, 27 },
		{ 158, YYAT_SHIFT, 28 },
		{ 158, YYAT_SHIFT, 29 },
		{ 53, YYAT_SHIFT, 99 },
		{ 146, YYAT_SHIFT, 1 },
		{ 172, YYAT_SHIFT, 100 },
		{ 158, YYAT_SHIFT, 31 },
		{ 172, YYAT_SHIFT, 101 },
		{ 176, YYAT_SHIFT, 32 },
		{ 176, YYAT_SHIFT, 33 },
		{ 139, YYAT_SHIFT, 161 },
		{ 139, YYAT_SHIFT, 162 },
		{ 176, YYAT_SHIFT, 34 },
		{ 176, YYAT_SHIFT, 35 },
		{ 138, YYAT_SHIFT, 161 },
		{ 138, YYAT_SHIFT, 162 },
		{ 176, YYAT_SHIFT, 36 },
		{ 158, YYAT_SHIFT, 32 },
		{ 158, YYAT_SHIFT, 33 },
		{ 137, YYAT_SHIFT, 161 },
		{ 137, YYAT_SHIFT, 162 },
		{ 158, YYAT_SHIFT, 34 },
		{ 158, YYAT_SHIFT, 35 },
		{ 133, YYAT_SHIFT, 160 },
		{ 132, YYAT_SHIFT, 159 },
		{ 158, YYAT_SHIFT, 36 },
		{ 157, YYAT_SHIFT, 26 },
		{ 157, YYAT_SHIFT, 27 },
		{ 157, YYAT_SHIFT, 28 },
		{ 157, YYAT_SHIFT, 29 },
		{ 143, YYAT_SHIFT, 87 },
		{ 143, YYAT_SHIFT, 88 },
		{ 143, YYAT_SHIFT, 89 },
		{ 157, YYAT_SHIFT, 31 },
		{ 131, YYAT_SHIFT, 158 },
		{ 90, YYAT_SHIFT, 26 },
		{ 90, YYAT_SHIFT, 27 },
		{ 90, YYAT_SHIFT, 28 },
		{ 90, YYAT_SHIFT, 29 },
		{ 48, YYAT_SHIFT, 87 },
		{ 48, YYAT_SHIFT, 88 },
		{ 48, YYAT_SHIFT, 89 },
		{ 90, YYAT_SHIFT, 31 },
		{ 127, YYAT_SHIFT, 80 },
		{ 157, YYAT_SHIFT, 32 },
		{ 157, YYAT_SHIFT, 33 },
		{ 126, YYAT_SHIFT, 86 },
		{ 124, YYAT_SHIFT, 85 },
		{ 157, YYAT_SHIFT, 34 },
		{ 157, YYAT_SHIFT, 35 },
		{ 123, YYAT_SHIFT, 93 },
		{ 119, YYAT_SHIFT, 157 },
		{ 157, YYAT_SHIFT, 36 },
		{ 90, YYAT_SHIFT, 32 },
		{ 90, YYAT_SHIFT, 33 },
		{ 118, YYAT_SHIFT, 156 },
		{ 117, YYAT_SHIFT, 155 },
		{ 90, YYAT_SHIFT, 34 },
		{ 90, YYAT_SHIFT, 35 },
		{ 116, YYAT_SHIFT, 154 },
		{ 115, YYAT_SHIFT, 153 },
		{ 90, YYAT_SHIFT, 36 },
		{ 69, YYAT_SHIFT, 26 },
		{ 69, YYAT_SHIFT, 27 },
		{ 69, YYAT_SHIFT, 28 },
		{ 69, YYAT_SHIFT, 29 },
		{ 171, YYAT_SHIFT, 100 },
		{ 108, YYAT_SHIFT, 147 },
		{ 171, YYAT_SHIFT, 101 },
		{ 69, YYAT_SHIFT, 31 },
		{ 107, YYAT_SHIFT, 146 },
		{ 30, YYAT_SHIFT, 26 },
		{ 30, YYAT_SHIFT, 27 },
		{ 30, YYAT_SHIFT, 28 },
		{ 30, YYAT_SHIFT, 29 },
		{ 136, YYAT_SHIFT, 100 },
		{ 105, YYAT_SHIFT, 145 },
		{ 136, YYAT_SHIFT, 101 },
		{ 30, YYAT_SHIFT, 31 },
		{ 92, YYAT_SHIFT, 134 },
		{ 69, YYAT_SHIFT, 32 },
		{ 69, YYAT_SHIFT, 33 },
		{ 79, YYAT_SHIFT, 122 },
		{ 77, YYAT_SHIFT, 121 },
		{ 69, YYAT_SHIFT, 34 },
		{ 69, YYAT_SHIFT, 35 },
		{ 71, YYAT_SHIFT, 120 },
		{ 65, YYAT_SHIFT, 116 },
		{ 69, YYAT_SHIFT, 36 },
		{ 30, YYAT_SHIFT, 32 },
		{ 30, YYAT_SHIFT, 33 },
		{ 64, YYAT_SHIFT, 115 },
		{ 62, YYAT_SHIFT, 112 },
		{ 30, YYAT_SHIFT, 34 },
		{ 30, YYAT_SHIFT, 35 },
		{ 61, YYAT_SHIFT, 111 },
		{ 60, YYAT_SHIFT, 110 },
		{ 30, YYAT_SHIFT, 36 },
		{ 141, YYAT_SHIFT, 94 },
		{ 141, YYAT_SHIFT, 95 },
		{ 141, YYAT_SHIFT, 96 },
		{ 141, YYAT_SHIFT, 97 },
		{ 51, YYAT_SHIFT, 94 },
		{ 51, YYAT_SHIFT, 95 },
		{ 51, YYAT_SHIFT, 96 },
		{ 51, YYAT_SHIFT, 97 },
		{ 54, YYAT_SHIFT, 100 },
		{ 57, YYAT_SHIFT, 1 },
		{ 54, YYAT_SHIFT, 101 },
		{ 56, YYAT_SHIFT, 106 },
		{ 50, YYAT_SHIFT, 93 },
		{ 46, YYAT_SHIFT, 86 },
		{ 45, YYAT_SHIFT, 85 },
		{ 42, YYAT_SHIFT, 83 },
		{ 40, YYAT_SHIFT, 80 },
		{ 37, YYAT_SHIFT, 78 },
		{ 25, YYAT_SHIFT, 69 },
		{ 24, YYAT_SHIFT, 68 },
		{ 23, YYAT_SHIFT, 67 },
		{ 21, YYAT_SHIFT, 66 },
		{ 20, YYAT_SHIFT, 65 },
		{ 18, YYAT_SHIFT, 64 },
		{ 16, YYAT_SHIFT, 63 },
		{ 15, YYAT_SHIFT, 62 },
		{ 12, YYAT_SHIFT, 57 },
		{ 10, YYAT_SHIFT, 38 },
		{ 3, YYAT_ACCEPT, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -242, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 209, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -246, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -239, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 14 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -83, 1, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -81, 1, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_DEFAULT, 14 },
		{ -228, 1, YYAT_ERROR, 0 },
		{ -77, 1, YYAT_REDUCE, 39 },
		{ -90, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -88, 1, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -89, 1, YYAT_REDUCE, 12 },
		{ -92, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -87, 1, YYAT_ERROR, 0 },
		{ -88, 1, YYAT_ERROR, 0 },
		{ -89, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ -108, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -93, 1, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -82, 1, YYAT_REDUCE, 58 },
		{ -258, 1, YYAT_REDUCE, 52 },
		{ -98, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ -222, 1, YYAT_REDUCE, 22 },
		{ -72, 1, YYAT_REDUCE, 54 },
		{ -84, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ -163, 1, YYAT_REDUCE, 76 },
		{ -227, 1, YYAT_REDUCE, 86 },
		{ -87, 1, YYAT_REDUCE, 60 },
		{ -86, 1, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -189, 1, YYAT_REDUCE, 62 },
		{ -93, 1, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ -99, 1, YYAT_ERROR, 0 },
		{ -67, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -110, 1, YYAT_ERROR, 0 },
		{ -111, 1, YYAT_ERROR, 0 },
		{ -115, 1, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ -89, 1, YYAT_ERROR, 0 },
		{ -93, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -117, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -125, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ -123, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ -126, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -144, 1, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -100, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ 0, 0, YYAT_DEFAULT, 109 },
		{ -135, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -142, 1, YYAT_REDUCE, 18 },
		{ -139, 1, YYAT_ERROR, 0 },
		{ -232, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ -150, 1, YYAT_ERROR, 0 },
		{ -151, 1, YYAT_ERROR, 0 },
		{ -150, 1, YYAT_ERROR, 0 },
		{ -151, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -147, 1, YYAT_REDUCE, 59 },
		{ -137, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ -149, 1, YYAT_REDUCE, 55 },
		{ -153, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ -178, 1, YYAT_REDUCE, 92 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ -221, 1, YYAT_REDUCE, 61 },
		{ -124, 1, YYAT_REDUCE, 73 },
		{ -174, 1, YYAT_REDUCE, 66 },
		{ -179, 1, YYAT_REDUCE, 67 },
		{ -183, 1, YYAT_REDUCE, 68 },
		{ -206, 1, YYAT_REDUCE, 69 },
		{ -90, 1, YYAT_REDUCE, 63 },
		{ -253, 1, YYAT_REDUCE, 64 },
		{ -172, 1, YYAT_REDUCE, 74 },
		{ -208, 1, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -170, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -224, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -231, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ -153, 1, YYAT_REDUCE, 34 },
		{ -180, 1, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -245, 1, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -259, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ -244, 1, YYAT_DEFAULT, 179 },
		{ -230, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -268, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ -133, 1, YYAT_REDUCE, 71 },
		{ -194, 1, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ -189, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ -287, 1, YYAT_ERROR, 0 },
		{ -257, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 25 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 101;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 5, 9 },
		{ 5, 5 },
		{ 5, 6 },
		{ 5, 7 },
		{ 179, 180 },
		{ 175, 177 },
		{ 146, 163 },
		{ 146, 107 },
		{ 176, -1 },
		{ 176, 178 },
		{ 161, 171 },
		{ 158, 131 },
		{ 13, 59 },
		{ 179, 42 },
		{ 179, 43 },
		{ 179, 41 },
		{ 179, 45 },
		{ 176, 70 },
		{ 162, 172 },
		{ 162, 48 },
		{ 162, 52 },
		{ 162, 49 },
		{ 13, 58 },
		{ 157, 169 },
		{ 162, 47 },
		{ 158, 170 },
		{ 156, 168 },
		{ 91, -1 },
		{ 179, 55 },
		{ 8, 19 },
		{ 8, 20 },
		{ 8, 22 },
		{ 176, -1 },
		{ 146, 109 },
		{ 5, 8 },
		{ 91, 133 },
		{ 155, 167 },
		{ 8, 21 },
		{ 166, 174 },
		{ 166, 152 },
		{ 166, 151 },
		{ 109, 148 },
		{ 109, 18 },
		{ 109, 17 },
		{ 63, 114 },
		{ 63, 16 },
		{ 63, 15 },
		{ 14, 61 },
		{ 14, 20 },
		{ 14, 22 },
		{ 99, 142 },
		{ 149, 164 },
		{ 99, 54 },
		{ 101, -1 },
		{ 101, 144 },
		{ 97, 140 },
		{ 97, 136 },
		{ 93, 135 },
		{ 93, 51 },
		{ 89, -1 },
		{ 89, 130 },
		{ 86, 127 },
		{ 86, 50 },
		{ 85, 126 },
		{ 85, 40 },
		{ 82, -1 },
		{ 82, 125 },
		{ 81, 124 },
		{ 81, 46 },
		{ 80, 123 },
		{ 80, 53 },
		{ 44, 84 },
		{ 44, 44 },
		{ 0, 3 },
		{ 0, 4 },
		{ 112, 150 },
		{ 104, 60 },
		{ 103, 58 },
		{ 100, 143 },
		{ 98, 141 },
		{ 96, 139 },
		{ 95, 138 },
		{ 94, 137 },
		{ 90, 132 },
		{ 88, 129 },
		{ 87, 128 },
		{ 69, 119 },
		{ 68, 118 },
		{ 67, 117 },
		{ 62, 113 },
		{ 57, 108 },
		{ 55, 105 },
		{ 37, 79 },
		{ 36, 77 },
		{ 35, 76 },
		{ 34, 75 },
		{ 33, 74 },
		{ 32, 73 },
		{ 31, 72 },
		{ 30, 71 },
		{ 10, 56 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 72, 5 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 63 },
		{ 0, -1 },
		{ 89, 44 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, 14 },
		{ 41, 104 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 86, 176 },
		{ 65, 89 },
		{ 64, 89 },
		{ 63, 89 },
		{ 62, 89 },
		{ 61, 89 },
		{ 72, 91 },
		{ 81, 44 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 60, 179 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, 63 },
		{ 0, -1 },
		{ 81, 146 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 68, 91 },
		{ 30, 109 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, 91 },
		{ 66, 91 },
		{ 73, 176 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 93 },
		{ 43, 85 },
		{ 44, 91 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 86 },
		{ 35, 80 },
		{ 52, 89 },
		{ 51, 89 },
		{ 27, 101 },
		{ 48, 158 },
		{ 14, 176 },
		{ 0, -1 },
		{ 29, 99 },
		{ 52, 97 },
		{ 51, 97 },
		{ 50, 97 },
		{ 25, 162 },
		{ 50, 99 },
		{ 21, 162 },
		{ 46, 101 },
		{ 22, 162 },
		{ 0, -1 },
		{ 61, 109 },
		{ 60, 109 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 25, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 56, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 32, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 179 },
		{ 14, 179 },
		{ 10, 176 },
		{ -10, 91 },
		{ 0, -1 },
		{ 0, -1 },
		{ -21, 162 },
		{ -13, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 19, 91 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -7, 179 },
		{ -4, 179 },
		{ 0, -1 },
		{ 0, -1 },
		{ -8, 81 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 218 ".\\myparser.y"


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


