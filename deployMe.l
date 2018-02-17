%{
	#include<stdio.h>
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
			}

port:[0-9]+		{
				strcpy(yytextCopy,yytext);
				for(i=0;yytextCopy[i]!=':';i++);
				printf("i=%d",i);
				for(j=0,k=i+1;yytextCopy[k]!='\0';k++){
					portString[j]=yytextCopy[k];
					j++;
				}
				portString[++j]='\0';
				port=atoi(portString);
				//set yylval to port and return port token
			}

%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	printf("\n Lexer Called");
}
