#define NODE_TYPE 257
#define REPO_LINK 258
#define INDEX_FILE 259
#define REPO_NAME 260
#define PORT 261
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	char repoName[1000];
	char githubUrl[1000];
	char indexFile[1000];
	int port;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
