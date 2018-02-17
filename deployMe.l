%{
	#include<stdio.h>
	#include "y.tab.h"
	#include<string.h>
	char githubLink[1000];
	char yytextCopy[1000];
	char indexFile[1000];
	char portString[100];
	int i,j,k,port;
	void yyerror(char *);
%}
delim [ \t\n]
%%
type:node{delim}	{
				//return node_id from y.tab.h
				return NODE_TYPE;
			}
githubUrl:\".*\"{delim}	{
				//set yylval to the githublink and return the git token
				strcpy(yytextCopy,yytext);
				for(i=0;yytextCopy[i]!='"';i++);
				for(j=0,k=i+1;yytextCopy[k]!='"';k++){
					githubLink[j]=yytextCopy[k];
					j++;
				}
				githubLink[++j]='\0';
				strcpy(yylval.githubUrl,githubLink);
				return REPO_LINK;
				//return token_git_link
			}

indexFile:\".*\"{delim}	{
				strcpy(yytextCopy,yytext);
				for(i=0;yytextCopy[i]!='"';i++);
				for(j=0,k=i+1;yytextCopy[k]!='"';k++){
					indexFile[j]=yytextCopy[k];		
					j++;
				}
				indexFile[++j] = '\0';
				//return indexFile Token
				strcpy(yylval.indexFile,indexFile);
				return INDEX_FILE;
			}

port:[0-9]+		{
				strcpy(yytextCopy,yytext);
				for(i=0;yytextCopy[i]!=':';i++);
				for(j=0,k=i+1;yytextCopy[k]!='\0';k++){
					portString[j]=yytextCopy[k];
					j++;
				}
				portString[++j]='\0';
				port=atoi(portString);
				//set yylval to port and return port token
				yylval.port = port;
				return PORT;
			}

%%
int yywrap(){
	return 1;
}

