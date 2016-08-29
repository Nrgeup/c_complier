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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/23/15
# Time: 01:35:59
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "if"

    2  "else"

    3  "while"

    4  "for"

    5  "return"

    6  ";"

    7  ","

    8  "<<"

    9  ">>"

   10  "=="

   11  "<="

   12  ">="

   13  "!="

   14  "||"

   15  "&&"

   16  "="

   17  "|"

   18  "^"

   19  "&"

   20  "<"

   21  ">"

   22  "+"

   23  "-"

   24  "*"

   25  "/"

   26  "%"

   27  "("

   28  ")"

   29  "{"

   30  "}"

   31  "["

   32  "]"

   33  "!"

   34  "~"

   35  "."

   36  [a-zA-Z_][0-9a-zA-Z_]*

   37  [0-9]+

   38  \'((\\.)|([^\\'\n]))*\'

   39  \"((\\.)|([^\\"\n]))*\"

   40  [\t\n ]+

   41  ("/*"([^*]|(\*[^/]))*\*?"*/")|("//".*\n)


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x22               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2e               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5b               goto 23
	0x5d               goto 24
	0x5e               goto 25
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 22
	0x69               goto 28
	0x6a - 0x71 (8)    goto 22
	0x72               goto 29
	0x73 - 0x76 (4)    goto 22
	0x77               goto 30
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33
	0x7e               goto 34


state 2
	^INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x22               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2e               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3b               goto 18
	0x3c               goto 19
	0x3d               goto 20
	0x3e               goto 21
	0x41 - 0x5a (26)   goto 22
	0x5b               goto 23
	0x5d               goto 24
	0x5e               goto 25
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 22
	0x69               goto 28
	0x6a - 0x71 (8)    goto 22
	0x72               goto 29
	0x73 - 0x76 (4)    goto 22
	0x77               goto 30
	0x78 - 0x7a (3)    goto 22
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33
	0x7e               goto 34


state 3
	0x09 - 0x0a (2)    goto 3
	0x20               goto 3

	match 40


state 4
	0x3d               goto 35

	match 33


state 5
	0x00 - 0x09 (10)   goto 5
	0x0b - 0x21 (23)   goto 5
	0x22               goto 36
	0x23 - 0x5b (57)   goto 5
	0x5c               goto 37
	0x5d - 0xff (163)  goto 5


state 6
	match 26


state 7
	0x26               goto 38

	match 19


state 8
	0x00 - 0x09 (10)   goto 8
	0x0b - 0x26 (28)   goto 8
	0x27               goto 39
	0x28 - 0x5b (52)   goto 8
	0x5c               goto 40
	0x5d - 0xff (163)  goto 8


state 9
	match 27


state 10
	match 28


state 11
	match 24


state 12
	match 22


state 13
	match 7


state 14
	match 23


state 15
	match 35


state 16
	0x2a               goto 41
	0x2f               goto 42

	match 25


state 17
	0x30 - 0x39 (10)   goto 17

	match 37


state 18
	match 6


state 19
	0x3c               goto 43
	0x3d               goto 44

	match 20


state 20
	0x3d               goto 45

	match 16


state 21
	0x3d               goto 46
	0x3e               goto 47

	match 21


state 22
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 36


state 23
	match 31


state 24
	match 32


state 25
	match 18


state 26
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 48
	0x6d - 0x7a (14)   goto 22

	match 36


state 27
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6e (14)   goto 22
	0x6f               goto 49
	0x70 - 0x7a (11)   goto 22

	match 36


state 28
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x65 (5)    goto 22
	0x66               goto 50
	0x67 - 0x7a (20)   goto 22

	match 36


state 29
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 51
	0x66 - 0x7a (21)   goto 22

	match 36


state 30
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x67 (7)    goto 22
	0x68               goto 52
	0x69 - 0x7a (18)   goto 22

	match 36


state 31
	match 29


state 32
	0x7c               goto 53

	match 17


state 33
	match 30


state 34
	match 34


state 35
	match 13


state 36
	match 39


state 37
	0x00 - 0x09 (10)   goto 5
	0x0b - 0xff (245)  goto 5


state 38
	match 15


state 39
	match 38


state 40
	0x00 - 0x09 (10)   goto 8
	0x0b - 0xff (245)  goto 8


state 41
	0x00 - 0x29 (42)   goto 41
	0x2a               goto 54
	0x2b - 0xff (213)  goto 41


state 42
	0x00 - 0x09 (10)   goto 42
	0x0a               goto 55
	0x0b - 0xff (245)  goto 42


state 43
	match 8


state 44
	match 11


state 45
	match 10


state 46
	match 12


state 47
	match 9


state 48
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x72 (18)   goto 22
	0x73               goto 56
	0x74 - 0x7a (7)    goto 22

	match 36


state 49
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 57
	0x73 - 0x7a (8)    goto 22

	match 36


state 50
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 1


state 51
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x73 (19)   goto 22
	0x74               goto 58
	0x75 - 0x7a (6)    goto 22

	match 36


state 52
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x68 (8)    goto 22
	0x69               goto 59
	0x6a - 0x7a (17)   goto 22

	match 36


state 53
	match 14


state 54
	0x00 - 0x29 (42)   goto 41
	0x2a               goto 60
	0x2b - 0x2e (4)    goto 41
	0x2f               goto 55
	0x30 - 0xff (208)  goto 41


state 55
	match 41


state 56
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 61
	0x66 - 0x7a (21)   goto 22

	match 36


state 57
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 4


state 58
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x74 (20)   goto 22
	0x75               goto 62
	0x76 - 0x7a (5)    goto 22

	match 36


state 59
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6b (11)   goto 22
	0x6c               goto 63
	0x6d - 0x7a (14)   goto 22

	match 36


state 60
	0x00 - 0x29 (42)   goto 41
	0x2a               goto 54
	0x2b - 0x2e (4)    goto 41
	0x2f               goto 64
	0x30 - 0xff (208)  goto 41


state 61
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 2


state 62
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x71 (17)   goto 22
	0x72               goto 65
	0x73 - 0x7a (8)    goto 22

	match 36


state 63
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x64 (4)    goto 22
	0x65               goto 66
	0x66 - 0x7a (21)   goto 22

	match 36


state 64
	0x00 - 0x29 (42)   goto 41
	0x2a               goto 54
	0x2b - 0xff (213)  goto 41

	match 41


state 65
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x6d (13)   goto 22
	0x6e               goto 67
	0x6f - 0x7a (12)   goto 22

	match 36


state 66
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 3


state 67
	0x30 - 0x39 (10)   goto 22
	0x41 - 0x5a (26)   goto 22
	0x5f               goto 22
	0x61 - 0x7a (26)   goto 22

	match 5


#############################################################################
# Summary
#############################################################################

1 start state(s)
41 expression(s), 67 state(s)


#############################################################################
# End of File
#############################################################################
