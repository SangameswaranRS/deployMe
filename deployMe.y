%{
	#include<stdlib.h>
	#include<fcntl.h>
	#include<unistd.h>
	int fileDescriptor;
	char totalCommands[100000];
	void yyerror(char *);
	int yylex(void);
%}
%token NODE_TYPE
%token REPO_LINK
%token INDEX_FILE
%token REPO_NAME
%token PORT
%union{
	char repoName[1000];
	char githubUrl[1000];
	char indexFile[1000];
	int port;
}
%start deploy
%%

deploy :  NODE_TYPE REPO_LINK INDEX_FILE PORT REPO_NAME		{
									printf("Deploying node server with \nRepo Link = %s \nindexFile = %s \nport = %d",$2.githubUrl,$3.indexFile,$4.port);
									fileDescriptor = open("deployMe_nodeType.sh",O_RDWR|O_CREAT|O_APPEND);
									if(fileDescriptor == -1){
										printf("\n Error opening Script \n");
									}else{
										strcat(totalCommands,"git clone ");
										strcat(totalCommands,$2.githubUrl);
										strcat(totalCommands,"\n");
										strcat(totalCommands,"cd ");
										strcat(totalCommands,$5.repoName);
										strcat(totalCommands,"\n");
										strcat(totalCommands,"node ");
										strcat(totalCommands,$3.indexFile);
										strcat(totalCommands,"\n");
										write(fileDescriptor,totalCommands,sizeof(totalCommands));
										//invoke Exec System Call				
									}
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
