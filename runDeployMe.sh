lex deployMe.l
yacc -d deployMe.y
gcc y.tab.c
./a.out
