all:compiler
lex.yy.c:compiler.l
	./flex compiler.l
rule.tab.c : rule.y
	~/bison/bin/bison -d -v rule.y
compiler:lex.yy.c rule.tab.c 
	gcc -o compiler lex.yy.c rule.tab.c libfl.a ~/bison/lib/liby.a
