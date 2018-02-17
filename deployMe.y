%{
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
%}
%token NODE_TYPE
%token REPO_LINK
%token INDEX_FILE
%token PORT
%union{
	char githubUrl[1000];
	char indexFile[1000];
	int port;
}
%start deploy
%%

deploy :  NODE_TYPE REPO_LINK INDEX_FILE PORT 	{
							printf("Repo Link = %s indexFile = %s port = %d",$2.githubUrl,$3.indexFile,$4.port);
						}
	;
%%

#include"lex.yy.c"

void yyerror(char *s){
	printf("\n Syntax Error Detected : %s",s);
}

int main(){
	yyparse();
	return 0;
}
