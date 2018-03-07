lex deployMe.l
yacc -d deployMe.y
gcc y.tab.c
if [ $# -eq 1 ]
then
./a.out < $1
else
echo "Invalid Number of arguments specify just the file in the argument";
fi
