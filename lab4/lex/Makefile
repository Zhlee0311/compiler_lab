all : lex

lex.yy.c : lex.l
	flex lex.l

lex : lex.yy.c
	gcc lex.yy.c -lfl -o lex

clean :
	rm lex lex.yy.c 	


