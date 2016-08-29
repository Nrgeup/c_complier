#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 75 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/23/15
# Time: 01:36:00
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : define_list

    2  define_list : define define_list
    3              |

    4  define : func_type SEMICOLON
    5         | function
    6         | type def_list SEMICOLON
    7         | SEMICOLON

    8  function : func_type LBRACE statement_list RBRACE
    9           | func_type LBRACE RBRACE

   10  func_type : type func_l_op

   11  func_l_op : MUL func_l_op
   12            | func_r_op

   13  func_r_op : func_r_op LBRACKET NUMBER RBRACKET
   14            | func_term

   15  func_term : ID LPAREN param_list RPAREN
   16            | LPAREN func_l_op RPAREN

   17  param_list : param COMMA param_list
   18             | param
   19             |

   20  param : type def_l_op

   21  statement_list : statement statement_list
   22                 | statement

   23  statement : expr SEMICOLON
   24            | WHILE LPAREN expr RPAREN statement
   25            | FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement
   26            | IF LPAREN expr RPAREN statement ELSE statement
   27            | IF LPAREN expr RPAREN statement
   28            | RETURN _expr SEMICOLON
   29            | type def_list SEMICOLON
   30            | LBRACE statement_list RBRACE
   31            | LBRACE RBRACE
   32            | SEMICOLON

   33  _expr : expr
   34        |

   35  def_list : def_expr COMMA def_list
   36           | def_expr

   37  def_expr : def_l_op ASSIGN expr
   38           | def_l_op ASSIGN LBRACE init_list RBRACE
   39           | def_l_op

   40  def_l_op : MUL def_l_op
   41           | def_r_op

   42  def_r_op : def_r_op LBRACKET NUMBER RBRACKET
   43           | def_term

   44  def_term : LPAREN def_l_op RPAREN
   45           | ID

   46  init_list : init_expr COMMA init_list
   47            | init_expr

   48  init_expr : LBRACE init_list RBRACE
   49            | expr

   50  expr : assign

   51  assign : or ASSIGN assign
   52         | or

   53  or : or OR and
   54     | and

   55  and : and AND b_or
   56      | b_or

   57  b_or : b_or BOR b_xor
   58       | b_xor

   59  b_xor : b_xor BXOR b_and
   60        | b_and

   61  b_and : b_and BAND equal
   62        | equal

   63  equal : equal EQ less
   64        | equal NE less
   65        | less

   66  less : less LT shift
   67       | less LE shift
   68       | less GT shift
   69       | less GE shift
   70       | plus

   71  shift : shift SHL plus
   72        | shift SHR plus
   73        | plus

   74  plus : plus PLUS mul
   75       | plus MINUS mul
   76       | mul

   77  mul : mul MUL l_op
   78      | mul DIV l_op
   79      | mul MOD l_op
   80      | l_op

   81  l_op : NOT l_op
   82       | BNOT l_op
   83       | MUL l_op
   84       | BAND l_op
   85       | MINUS l_op
   86       | r_op

   87  r_op : r_op LBRACKET expr RBRACKET
   88       | r_op LPAREN expr_list RPAREN
   89       | r_op MEMBER ID
   90       | term

   91  expr_list : expr COMMA expr_list
   92            | expr
   93            |

   94  type : TYPE

   95  term : ID
   96       | NUMBER
   97       | CHARTEXT
   98       | STRTEXT
   99       | LPAREN expr RPAREN


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end
	define_list : .  (3)

	TYPE  shift 1
	SEMICOLON  shift 2
	.  reduce 3

	program  goto 3
	define_list  goto 4
	define  goto 5
	function  goto 6
	func_type  goto 7
	type  goto 8


state 1
	type : TYPE .  (94)

	.  reduce 94


state 2
	define : SEMICOLON .  (7)

	.  reduce 7


state 3
	$accept : program . $end  (0)

	$end  accept


state 4
	program : define_list .  (1)

	.  reduce 1


state 5
	define_list : define . define_list
	define_list : .  (3)

	TYPE  shift 1
	SEMICOLON  shift 2
	.  reduce 3

	define_list  goto 9
	define  goto 5
	function  goto 6
	func_type  goto 7
	type  goto 8


state 6
	define : function .  (5)

	.  reduce 5


state 7
	define : func_type . SEMICOLON
	function : func_type . LBRACE statement_list RBRACE
	function : func_type . LBRACE RBRACE

	LBRACE  shift 10
	SEMICOLON  shift 11


state 8
	define : type . def_list SEMICOLON
	func_type : type . func_l_op

	ID  shift 12
	MUL  shift 13
	LPAREN  shift 14

	def_l_op  goto 15
	def_expr  goto 16
	def_term  goto 17
	def_r_op  goto 18
	func_l_op  goto 19
	func_r_op  goto 20
	def_list  goto 21
	func_term  goto 22


state 9
	define_list : define define_list .  (2)

	.  reduce 2


state 10
	function : func_type LBRACE . statement_list RBRACE
	function : func_type LBRACE . RBRACE

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	RBRACE  shift 38
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 44
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55
	statement_list  goto 56


state 11
	define : func_type SEMICOLON .  (4)

	.  reduce 4


state 12
	def_term : ID .  (45)
	func_term : ID . LPAREN param_list RPAREN

	LPAREN  shift 57
	.  reduce 45


state 13
	def_l_op : MUL . def_l_op
	func_l_op : MUL . func_l_op

	ID  shift 12
	MUL  shift 13
	LPAREN  shift 14

	def_l_op  goto 58
	def_term  goto 17
	def_r_op  goto 18
	func_l_op  goto 59
	func_r_op  goto 20
	func_term  goto 22


state 14
	def_term : LPAREN . def_l_op RPAREN
	func_term : LPAREN . func_l_op RPAREN

	ID  shift 12
	MUL  shift 13
	LPAREN  shift 14

	def_l_op  goto 60
	def_term  goto 17
	def_r_op  goto 18
	func_l_op  goto 61
	func_r_op  goto 20
	func_term  goto 22


state 15
	def_expr : def_l_op . ASSIGN LBRACE init_list RBRACE
	def_expr : def_l_op . ASSIGN expr
	def_expr : def_l_op .  (39)

	ASSIGN  shift 62
	.  reduce 39


state 16
	def_list : def_expr . COMMA def_list
	def_list : def_expr .  (36)

	COMMA  shift 63
	.  reduce 36


state 17
	def_r_op : def_term .  (43)

	.  reduce 43


state 18
	def_r_op : def_r_op . LBRACKET NUMBER RBRACKET
	def_l_op : def_r_op .  (41)

	LBRACKET  shift 64
	.  reduce 41


state 19
	func_type : type func_l_op .  (10)

	.  reduce 10


state 20
	func_r_op : func_r_op . LBRACKET NUMBER RBRACKET
	func_l_op : func_r_op .  (12)

	LBRACKET  shift 65
	.  reduce 12


state 21
	define : type def_list . SEMICOLON

	SEMICOLON  shift 66


state 22
	func_r_op : func_term .  (14)

	.  reduce 14


state 23
	statement : IF . LPAREN expr RPAREN statement
	statement : IF . LPAREN expr RPAREN statement ELSE statement

	LPAREN  shift 67


state 24
	statement : WHILE . LPAREN expr RPAREN statement

	LPAREN  shift 68


state 25
	statement : FOR . LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement

	LPAREN  shift 69


state 26
	term : ID .  (95)

	.  reduce 95


state 27
	term : NUMBER .  (96)

	.  reduce 96


state 28
	term : CHARTEXT .  (97)

	.  reduce 97


state 29
	term : STRTEXT .  (98)

	.  reduce 98


state 30
	statement : RETURN . _expr SEMICOLON
	_expr : .  (34)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 34

	b_xor  goto 40
	or  goto 41
	expr  goto 70
	assign  goto 43
	and  goto 45
	_expr  goto 71
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 31
	l_op : NOT . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 72


state 32
	l_op : BAND . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 73


state 33
	l_op : BNOT . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 74


state 34
	l_op : MINUS . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 75


state 35
	l_op : MUL . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 76


state 36
	term : LPAREN . expr RPAREN

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	or  goto 41
	expr  goto 77
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 37
	statement : LBRACE . statement_list RBRACE
	statement : LBRACE . RBRACE

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	RBRACE  shift 78
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 44
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55
	statement_list  goto 79


state 38
	function : func_type LBRACE RBRACE .  (9)

	.  reduce 9


state 39
	statement : SEMICOLON .  (32)

	.  reduce 32


state 40
	b_or : b_xor .  (58)
	b_xor : b_xor . BXOR b_and

	BXOR  shift 80
	.  reduce 58


state 41
	or : or . OR and
	assign : or . ASSIGN assign
	assign : or .  (52)

	OR  shift 81
	ASSIGN  shift 82
	.  reduce 52


state 42
	statement : expr . SEMICOLON

	SEMICOLON  shift 83


state 43
	expr : assign .  (50)

	.  reduce 50


state 44
	statement_list : statement .  (22)
	statement_list : statement . statement_list

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	SEMICOLON  shift 39
	.  reduce 22

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 44
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55
	statement_list  goto 84


state 45
	or : and .  (54)
	and : and . AND b_or

	AND  shift 85
	.  reduce 54


state 46
	and : b_or .  (56)
	b_or : b_or . BOR b_xor

	BOR  shift 86
	.  reduce 56


state 47
	r_op : term .  (90)

	.  reduce 90


state 48
	plus : mul .  (76)
	mul : mul . DIV l_op
	mul : mul . MUL l_op
	mul : mul . MOD l_op

	MUL  shift 87
	DIV  shift 88
	MOD  shift 89
	.  reduce 76


state 49
	l_op : r_op .  (86)
	r_op : r_op . MEMBER ID
	r_op : r_op . LBRACKET expr RBRACKET
	r_op : r_op . LPAREN expr_list RPAREN

	LPAREN  shift 90
	LBRACKET  shift 91
	MEMBER  shift 92
	.  reduce 86


state 50
	b_and : b_and . BAND equal
	b_xor : b_and .  (60)

	BAND  shift 93
	.  reduce 60


state 51
	equal : less .  (65)
	less : less . GE shift
	less : less . LT shift
	less : less . LE shift
	less : less . GT shift

	LT  shift 94
	LE  shift 95
	GT  shift 96
	GE  shift 97
	.  reduce 65


state 52
	mul : l_op .  (80)

	.  reduce 80


state 53
	equal : equal . EQ less
	equal : equal . NE less
	b_and : equal .  (62)

	EQ  shift 98
	NE  shift 99
	.  reduce 62


state 54
	less : plus .  (70)
	plus : plus . PLUS mul
	plus : plus . MINUS mul

	PLUS  shift 100
	MINUS  shift 101
	.  reduce 70


state 55
	statement : type . def_list SEMICOLON

	ID  shift 102
	MUL  shift 103
	LPAREN  shift 104

	def_l_op  goto 15
	def_expr  goto 16
	def_term  goto 17
	def_r_op  goto 18
	def_list  goto 105


state 56
	function : func_type LBRACE statement_list . RBRACE

	RBRACE  shift 106


state 57
	func_term : ID LPAREN . param_list RPAREN
	param_list : .  (19)

	TYPE  shift 1
	.  reduce 19

	param  goto 107
	param_list  goto 108
	type  goto 109


state 58
	def_l_op : MUL def_l_op .  (40)

	.  reduce 40


state 59
	func_l_op : MUL func_l_op .  (11)

	.  reduce 11


state 60
	def_term : LPAREN def_l_op . RPAREN

	RPAREN  shift 110


state 61
	func_term : LPAREN func_l_op . RPAREN

	RPAREN  shift 111


state 62
	def_expr : def_l_op ASSIGN . LBRACE init_list RBRACE
	def_expr : def_l_op ASSIGN . expr

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 112

	b_xor  goto 40
	or  goto 41
	expr  goto 113
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 63
	def_list : def_expr COMMA . def_list

	ID  shift 102
	MUL  shift 103
	LPAREN  shift 104

	def_l_op  goto 15
	def_expr  goto 16
	def_term  goto 17
	def_r_op  goto 18
	def_list  goto 114


state 64
	def_r_op : def_r_op LBRACKET . NUMBER RBRACKET

	NUMBER  shift 115


state 65
	func_r_op : func_r_op LBRACKET . NUMBER RBRACKET

	NUMBER  shift 116


state 66
	define : type def_list SEMICOLON .  (6)

	.  reduce 6


state 67
	statement : IF LPAREN . expr RPAREN statement
	statement : IF LPAREN . expr RPAREN statement ELSE statement

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	or  goto 41
	expr  goto 117
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 68
	statement : WHILE LPAREN . expr RPAREN statement

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	or  goto 41
	expr  goto 118
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 69
	statement : FOR LPAREN . _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement
	_expr : .  (34)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 34

	b_xor  goto 40
	or  goto 41
	expr  goto 70
	assign  goto 43
	and  goto 45
	_expr  goto 119
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 70
	_expr : expr .  (33)

	.  reduce 33


state 71
	statement : RETURN _expr . SEMICOLON

	SEMICOLON  shift 120


state 72
	l_op : NOT l_op .  (81)

	.  reduce 81


state 73
	l_op : BAND l_op .  (84)

	.  reduce 84


state 74
	l_op : BNOT l_op .  (82)

	.  reduce 82


state 75
	l_op : MINUS l_op .  (85)

	.  reduce 85


state 76
	l_op : MUL l_op .  (83)

	.  reduce 83


state 77
	term : LPAREN expr . RPAREN

	RPAREN  shift 121


state 78
	statement : LBRACE RBRACE .  (31)

	.  reduce 31


state 79
	statement : LBRACE statement_list . RBRACE

	RBRACE  shift 122


state 80
	b_xor : b_xor BXOR . b_and

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 123
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 81
	or : or OR . and

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	and  goto 124
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 82
	assign : or ASSIGN . assign

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	or  goto 41
	assign  goto 125
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 83
	statement : expr SEMICOLON .  (23)

	.  reduce 23


state 84
	statement_list : statement statement_list .  (21)

	.  reduce 21


state 85
	and : and AND . b_or

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	b_or  goto 126
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 86
	b_or : b_or BOR . b_xor

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 127
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 87
	mul : mul MUL . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 128


state 88
	mul : mul DIV . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 129


state 89
	mul : mul MOD . l_op

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	r_op  goto 49
	l_op  goto 130


state 90
	r_op : r_op LPAREN . expr_list RPAREN
	expr_list : .  (93)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 93

	b_xor  goto 40
	or  goto 41
	expr  goto 131
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	expr_list  goto 132


state 91
	r_op : r_op LBRACKET . expr RBRACKET

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	b_xor  goto 40
	or  goto 41
	expr  goto 133
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 92
	r_op : r_op MEMBER . ID

	ID  shift 134


state 93
	b_and : b_and BAND . equal

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	less  goto 51
	l_op  goto 52
	equal  goto 135
	plus  goto 54


state 94
	less : less LT . shift

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 136
	shift  goto 137


state 95
	less : less LE . shift

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 136
	shift  goto 138


state 96
	less : less GT . shift

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 136
	shift  goto 139


state 97
	less : less GE . shift

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 136
	shift  goto 140


state 98
	equal : equal EQ . less

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	less  goto 141
	l_op  goto 52
	plus  goto 54


state 99
	equal : equal NE . less

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	less  goto 142
	l_op  goto 52
	plus  goto 54


state 100
	plus : plus PLUS . mul

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 143
	r_op  goto 49
	l_op  goto 52


state 101
	plus : plus MINUS . mul

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 144
	r_op  goto 49
	l_op  goto 52


state 102
	def_term : ID .  (45)

	.  reduce 45


state 103
	def_l_op : MUL . def_l_op

	ID  shift 102
	MUL  shift 103
	LPAREN  shift 104

	def_l_op  goto 58
	def_term  goto 17
	def_r_op  goto 18


state 104
	def_term : LPAREN . def_l_op RPAREN

	ID  shift 102
	MUL  shift 103
	LPAREN  shift 104

	def_l_op  goto 60
	def_term  goto 17
	def_r_op  goto 18


state 105
	statement : type def_list . SEMICOLON

	SEMICOLON  shift 145


state 106
	function : func_type LBRACE statement_list RBRACE .  (8)

	.  reduce 8


state 107
	param_list : param . COMMA param_list
	param_list : param .  (18)

	COMMA  shift 146
	.  reduce 18


state 108
	func_term : ID LPAREN param_list . RPAREN

	RPAREN  shift 147


state 109
	param : type . def_l_op

	ID  shift 102
	MUL  shift 103
	LPAREN  shift 104

	def_l_op  goto 148
	def_term  goto 17
	def_r_op  goto 18


state 110
	def_term : LPAREN def_l_op RPAREN .  (44)

	.  reduce 44


state 111
	func_term : LPAREN func_l_op RPAREN .  (16)

	.  reduce 16


state 112
	def_expr : def_l_op ASSIGN LBRACE . init_list RBRACE

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 149

	b_xor  goto 40
	init_list  goto 150
	or  goto 41
	expr  goto 151
	assign  goto 43
	init_expr  goto 152
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 113
	def_expr : def_l_op ASSIGN expr .  (37)

	.  reduce 37


state 114
	def_list : def_expr COMMA def_list .  (35)

	.  reduce 35


state 115
	def_r_op : def_r_op LBRACKET NUMBER . RBRACKET

	RBRACKET  shift 153


state 116
	func_r_op : func_r_op LBRACKET NUMBER . RBRACKET

	RBRACKET  shift 154


state 117
	statement : IF LPAREN expr . RPAREN statement
	statement : IF LPAREN expr . RPAREN statement ELSE statement

	RPAREN  shift 155


state 118
	statement : WHILE LPAREN expr . RPAREN statement

	RPAREN  shift 156


state 119
	statement : FOR LPAREN _expr . SEMICOLON _expr SEMICOLON _expr RPAREN statement

	SEMICOLON  shift 157


state 120
	statement : RETURN _expr SEMICOLON .  (28)

	.  reduce 28


state 121
	term : LPAREN expr RPAREN .  (99)

	.  reduce 99


state 122
	statement : LBRACE statement_list RBRACE .  (30)

	.  reduce 30


state 123
	b_and : b_and . BAND equal
	b_xor : b_xor BXOR b_and .  (59)

	BAND  shift 93
	.  reduce 59


state 124
	or : or OR and .  (53)
	and : and . AND b_or

	AND  shift 85
	.  reduce 53


state 125
	assign : or ASSIGN assign .  (51)

	.  reduce 51


state 126
	and : and AND b_or .  (55)
	b_or : b_or . BOR b_xor

	BOR  shift 86
	.  reduce 55


state 127
	b_or : b_or BOR b_xor .  (57)
	b_xor : b_xor . BXOR b_and

	BXOR  shift 80
	.  reduce 57


state 128
	mul : mul MUL l_op .  (77)

	.  reduce 77


state 129
	mul : mul DIV l_op .  (78)

	.  reduce 78


state 130
	mul : mul MOD l_op .  (79)

	.  reduce 79


state 131
	expr_list : expr . COMMA expr_list
	expr_list : expr .  (92)

	COMMA  shift 158
	.  reduce 92


state 132
	r_op : r_op LPAREN expr_list . RPAREN

	RPAREN  shift 159


state 133
	r_op : r_op LBRACKET expr . RBRACKET

	RBRACKET  shift 160


state 134
	r_op : r_op MEMBER ID .  (89)

	.  reduce 89


state 135
	b_and : b_and BAND equal .  (61)
	equal : equal . EQ less
	equal : equal . NE less

	EQ  shift 98
	NE  shift 99
	.  reduce 61


state 136
	shift : plus .  (73)
	plus : plus . PLUS mul
	plus : plus . MINUS mul

	PLUS  shift 100
	MINUS  shift 101
	.  reduce 73


state 137
	shift : shift . SHR plus
	less : less LT shift .  (66)
	shift : shift . SHL plus

	SHL  shift 161
	SHR  shift 162
	.  reduce 66


state 138
	shift : shift . SHR plus
	less : less LE shift .  (67)
	shift : shift . SHL plus

	SHL  shift 161
	SHR  shift 162
	.  reduce 67


state 139
	shift : shift . SHR plus
	shift : shift . SHL plus
	less : less GT shift .  (68)

	SHL  shift 161
	SHR  shift 162
	.  reduce 68


state 140
	less : less GE shift .  (69)
	shift : shift . SHR plus
	shift : shift . SHL plus

	SHL  shift 161
	SHR  shift 162
	.  reduce 69


state 141
	equal : equal EQ less .  (63)
	less : less . GE shift
	less : less . LT shift
	less : less . LE shift
	less : less . GT shift

	LT  shift 94
	LE  shift 95
	GT  shift 96
	GE  shift 97
	.  reduce 63


state 142
	equal : equal NE less .  (64)
	less : less . GE shift
	less : less . LT shift
	less : less . LE shift
	less : less . GT shift

	LT  shift 94
	LE  shift 95
	GT  shift 96
	GE  shift 97
	.  reduce 64


state 143
	mul : mul . DIV l_op
	plus : plus PLUS mul .  (74)
	mul : mul . MUL l_op
	mul : mul . MOD l_op

	MUL  shift 87
	DIV  shift 88
	MOD  shift 89
	.  reduce 74


state 144
	mul : mul . DIV l_op
	plus : plus MINUS mul .  (75)
	mul : mul . MUL l_op
	mul : mul . MOD l_op

	MUL  shift 87
	DIV  shift 88
	MOD  shift 89
	.  reduce 75


state 145
	statement : type def_list SEMICOLON .  (29)

	.  reduce 29


state 146
	param_list : param COMMA . param_list
	param_list : .  (19)

	TYPE  shift 1
	.  reduce 19

	param  goto 107
	param_list  goto 163
	type  goto 109


state 147
	func_term : ID LPAREN param_list RPAREN .  (15)

	.  reduce 15


state 148
	param : type def_l_op .  (20)

	.  reduce 20


state 149
	init_expr : LBRACE . init_list RBRACE

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 149

	b_xor  goto 40
	init_list  goto 164
	or  goto 41
	expr  goto 151
	assign  goto 43
	init_expr  goto 152
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 150
	def_expr : def_l_op ASSIGN LBRACE init_list . RBRACE

	RBRACE  shift 165


state 151
	init_expr : expr .  (49)

	.  reduce 49


state 152
	init_list : init_expr . COMMA init_list
	init_list : init_expr .  (47)

	COMMA  shift 166
	.  reduce 47


state 153
	def_r_op : def_r_op LBRACKET NUMBER RBRACKET .  (42)

	.  reduce 42


state 154
	func_r_op : func_r_op LBRACKET NUMBER RBRACKET .  (13)

	.  reduce 13


state 155
	statement : IF LPAREN expr RPAREN . statement
	statement : IF LPAREN expr RPAREN . statement ELSE statement

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 167
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55


state 156
	statement : WHILE LPAREN expr RPAREN . statement

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 168
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55


state 157
	statement : FOR LPAREN _expr SEMICOLON . _expr SEMICOLON _expr RPAREN statement
	_expr : .  (34)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 34

	b_xor  goto 40
	or  goto 41
	expr  goto 70
	assign  goto 43
	and  goto 45
	_expr  goto 169
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 158
	expr_list : expr COMMA . expr_list
	expr_list : .  (93)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 93

	b_xor  goto 40
	or  goto 41
	expr  goto 131
	assign  goto 43
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	expr_list  goto 170


state 159
	r_op : r_op LPAREN expr_list RPAREN .  (88)

	.  reduce 88


state 160
	r_op : r_op LBRACKET expr RBRACKET .  (87)

	.  reduce 87


state 161
	shift : shift SHL . plus

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 171


state 162
	shift : shift SHR . plus

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36

	term  goto 47
	mul  goto 48
	r_op  goto 49
	l_op  goto 52
	plus  goto 172


state 163
	param_list : param COMMA param_list .  (17)

	.  reduce 17


state 164
	init_expr : LBRACE init_list . RBRACE

	RBRACE  shift 173


state 165
	def_expr : def_l_op ASSIGN LBRACE init_list RBRACE .  (38)

	.  reduce 38


state 166
	init_list : init_expr COMMA . init_list

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 149

	b_xor  goto 40
	init_list  goto 174
	or  goto 41
	expr  goto 151
	assign  goto 43
	init_expr  goto 152
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


167: shift-reduce conflict (shift 175, reduce 27) on ELSE
state 167
	statement : IF LPAREN expr RPAREN statement .  (27)
	statement : IF LPAREN expr RPAREN statement . ELSE statement

	ELSE  shift 175
	.  reduce 27


state 168
	statement : WHILE LPAREN expr RPAREN statement .  (24)

	.  reduce 24


state 169
	statement : FOR LPAREN _expr SEMICOLON _expr . SEMICOLON _expr RPAREN statement

	SEMICOLON  shift 176


state 170
	expr_list : expr COMMA expr_list .  (91)

	.  reduce 91


state 171
	plus : plus . PLUS mul
	plus : plus . MINUS mul
	shift : shift SHL plus .  (71)

	PLUS  shift 100
	MINUS  shift 101
	.  reduce 71


state 172
	shift : shift SHR plus .  (72)
	plus : plus . PLUS mul
	plus : plus . MINUS mul

	PLUS  shift 100
	MINUS  shift 101
	.  reduce 72


state 173
	init_expr : LBRACE init_list RBRACE .  (48)

	.  reduce 48


state 174
	init_list : init_expr COMMA init_list .  (46)

	.  reduce 46


state 175
	statement : IF LPAREN expr RPAREN statement ELSE . statement

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 177
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55


state 176
	statement : FOR LPAREN _expr SEMICOLON _expr SEMICOLON . _expr RPAREN statement
	_expr : .  (34)

	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	.  reduce 34

	b_xor  goto 40
	or  goto 41
	expr  goto 70
	assign  goto 43
	and  goto 45
	_expr  goto 178
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54


state 177
	statement : IF LPAREN expr RPAREN statement ELSE statement .  (26)

	.  reduce 26


state 178
	statement : FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr . RPAREN statement

	RPAREN  shift 179


state 179
	statement : FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN . statement

	TYPE  shift 1
	IF  shift 23
	WHILE  shift 24
	FOR  shift 25
	ID  shift 26
	NUMBER  shift 27
	CHARTEXT  shift 28
	STRTEXT  shift 29
	RETURN  shift 30
	NOT  shift 31
	BAND  shift 32
	BNOT  shift 33
	MINUS  shift 34
	MUL  shift 35
	LPAREN  shift 36
	LBRACE  shift 37
	SEMICOLON  shift 39

	b_xor  goto 40
	or  goto 41
	expr  goto 42
	assign  goto 43
	statement  goto 180
	and  goto 45
	b_or  goto 46
	term  goto 47
	mul  goto 48
	r_op  goto 49
	b_and  goto 50
	less  goto 51
	l_op  goto 52
	equal  goto 53
	plus  goto 54
	type  goto 55


state 180
	statement : FOR LPAREN _expr SEMICOLON _expr SEMICOLON _expr RPAREN statement .  (25)

	.  reduce 25


##############################################################################
# Summary
##############################################################################

State 167 contains 1 shift-reduce conflict(s)


42 token(s), 38 nonterminal(s)
100 grammar rule(s), 181 state(s)


##############################################################################
# End of File
##############################################################################
