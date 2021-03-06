%{
	#include<stdlib.h>
	#include<fcntl.h>
	#include<unistd.h>
	int fileDescriptor;
	char totalCommands[100000];
	void yyerror(char *);
	int yylex(void);
	char baseServerUrl[1000];
%}
%token NODE_TYPE
%token REPO_LINK
%token INDEX_FILE
%token REPO_NAME
%token PORT
%token HTML_BASIC
%token ANGULAR
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
									fileDescriptor = open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
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
										printf("\nAccess Your Node server via %s:%d/<YourApiRoutes>",baseServerUrl,$4.port);
										//invoke Exec System Call
										char *args[]={"./runMe.sh",NULL};
        									//execvp(args[0],args);
										//printf("\n Script Runtime Error.");				
									}
								}
	| HTML_BASIC REPO_LINK INDEX_FILE REPO_NAME		{
									printf("\n Deploying HTML basic webpage with \n Repo Link=%s\n indexFile=%s \n Repository Name= %s\n",$2.githubUrl,$3.indexFile,$4.repoName);
									fileDescriptor=open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
									if(fileDescriptor == -1){
										printf("\n Error opening Script\n");
									}else{
										//request Sudo access
										strcat(totalCommands,"\ncd ../../../../../xampp/htdocs/\n");
										strcat(totalCommands,"git clone ");
										strcat(totalCommands,$2.githubUrl);
										write(fileDescriptor,totalCommands,sizeof(totalCommands));
										printf("\n Access your website via %s:80/%s/%s",baseServerUrl,$4.repoName,$3.indexFile);
										//invoke exec system call
										char *args[]={"./runMe.sh",NULL};
                                                                                //execvp(args[0],args);
                                                                                //printf("\n Script Runtime error..");
									}
									
								}
	|ANGULAR REPO_LINK INDEX_FILE PORT REPO_NAME			{
									printf("\n Deploying Angular Project with \n Repo Link =%s\n Index File= %s\n Repository Name=%s\n Port=%d\n",$2.githubUrl,$3.indexFile,$5.repoName,$4.port);
									 fileDescriptor = open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
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
                                                                                printf("\n Access Your angular project via %s:%d/<YourRoutes>\n",baseServerUrl,$4.port);
                                                                                //invoke Exec System Call
										char *args[]={"./runMe.sh",NULL};
                                                                                //execvp(args[0],args);
                                                                                //printf("\n Script runtime error..");
                                                                        }	

								}
	;
%%

#include"lex.yy.c"

void yyerror(char *s){
	printf("\n Syntax Error Detected : %s",s);
}

int main(){
	strcpy(baseServerUrl,"http://localhost");
	yyparse();
	return 0;
}
