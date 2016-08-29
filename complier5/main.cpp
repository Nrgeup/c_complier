#include <iostream>
#include <fstream>
#include "mylexer.h"
#include "myparser.h"
#include "complie.h"
struct test{int a; int b; int c;};
test ttt(int a, int b){return test();}
int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = new ifstream("input.c");
			n = parser.yyparse();
			delete lexer.yyin;
			lexer.yyin = 0;
			print(root);
			if (type_check(root)) 
			{
				print(root);
				freopen("output\\output.asm", "w", stdout); 
				complie(root);
			}
		}
	}
	return n;
}