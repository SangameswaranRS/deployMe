/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "deployMe.y"
	#include<stdlib.h>
	#include<fcntl.h>
	#include<unistd.h>
	int fileDescriptor;
	char totalCommands[100000];
	void yyerror(char *);
	int yylex(void);
	char baseServerUrl[1000];
#line 18 "deployMe.y"
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
#line 44 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NODE_TYPE 257
#define REPO_LINK 258
#define INDEX_FILE 259
#define REPO_NAME 260
#define PORT 261
#define HTML_BASIC 262
#define ANGULAR 263
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,
};
static const YYINT yylen[] = {                            2,
    5,    4,    5,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    0,    1,    3,
};
static const YYINT yydgoto[] = {                          4,
};
static const YYINT yysindex[] = {                      -257,
 -256, -255, -254,    0, -258, -252, -251, -250, -248, -247,
 -245,    0, -244,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
};
#define YYTABLESIZE 16
static const YYINT yytable[] = {                          1,
    8,    5,    6,    7,    2,    3,    9,   10,    0,    0,
   11,   12,    0,   13,   14,   15,
};
static const YYINT yycheck[] = {                        257,
  259,  258,  258,  258,  262,  263,  259,  259,   -1,   -1,
  261,  260,   -1,  261,  260,  260,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#define YYUNDFTOKEN 266
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NODE_TYPE","REPO_LINK",
"INDEX_FILE","REPO_NAME","PORT","HTML_BASIC","ANGULAR",0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : deploy",
"deploy : NODE_TYPE REPO_LINK INDEX_FILE PORT REPO_NAME",
"deploy : HTML_BASIC REPO_LINK INDEX_FILE REPO_NAME",
"deploy : ANGULAR REPO_LINK INDEX_FILE PORT REPO_NAME",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 95 "deployMe.y"

#include"lex.yy.c"

void yyerror(char *s){
	printf("\n Syntax Error Detected : %s",s);
}

int main(){
	strcpy(baseServerUrl,"http://localhost");
	yyparse();
	return 0;
}
#line 191 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 27 "deployMe.y"
	{
									printf("Deploying node server with \nRepo Link = %s \nindexFile = %s \nport = %d",yystack.l_mark[-3].githubUrl,yystack.l_mark[-2].indexFile,yystack.l_mark[-1].port);
									fileDescriptor = open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
									if(fileDescriptor == -1){
										printf("\n Error opening Script \n");
									}else{
										strcat(totalCommands,"git clone ");
										strcat(totalCommands,yystack.l_mark[-3].githubUrl);
										strcat(totalCommands,"\n");
										strcat(totalCommands,"cd ");
										strcat(totalCommands,yystack.l_mark[0].repoName);
										strcat(totalCommands,"\n");
										strcat(totalCommands,"node ");
										strcat(totalCommands,yystack.l_mark[-2].indexFile);
										strcat(totalCommands,"\n");
										write(fileDescriptor,totalCommands,sizeof(totalCommands));
										printf("\nAccess Your Node server via %s:%d/<YourApiRoutes>",baseServerUrl,yystack.l_mark[-1].port);
										/*invoke Exec System Call*/
										char *args[]={"./runMe.sh",NULL};
        									/*execvp(args[0],args);*/
										/*printf("\n Script Runtime Error.");				*/
									}
								}
break;
case 2:
#line 50 "deployMe.y"
	{
									printf("\n Deploying HTML basic webpage with \n Repo Link=%s\n indexFile=%s \n Repository Name= %s\n",yystack.l_mark[-2].githubUrl,yystack.l_mark[-1].indexFile,yystack.l_mark[0].repoName);
									fileDescriptor=open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
									if(fileDescriptor == -1){
										printf("\n Error opening Script\n");
									}else{
										/*request Sudo access*/
										strcat(totalCommands,"\ncd ../../../../../xampp/htdocs/\n");
										strcat(totalCommands,"git clone ");
										strcat(totalCommands,yystack.l_mark[-2].githubUrl);
										write(fileDescriptor,totalCommands,sizeof(totalCommands));
										printf("\n Access your website via %s:80/%s/%s",baseServerUrl,yystack.l_mark[0].repoName,yystack.l_mark[-1].indexFile);
										/*invoke exec system call*/
										char *args[]={"./runMe.sh",NULL};
                                                                                /*execvp(args[0],args);*/
                                                                                /*printf("\n Script Runtime error..");*/
									}
									
								}
break;
case 3:
#line 69 "deployMe.y"
	{
									printf("\n Deploying Angular Project with \n Repo Link =%s\n Index File= %s\n Repository Name=%s\n Port=%d\n",yystack.l_mark[-3].githubUrl,yystack.l_mark[-2].indexFile,yystack.l_mark[0].repoName,yystack.l_mark[-1].port);
									 fileDescriptor = open("runMe.sh",O_RDWR|O_CREAT|O_TRUNC);
                                                                        if(fileDescriptor == -1){
                                                                                printf("\n Error opening Script \n");
                                                                        }else{
                                                                                strcat(totalCommands,"git clone ");
                                                                                strcat(totalCommands,yystack.l_mark[-3].githubUrl);
                                                                                strcat(totalCommands,"\n");
                                                                                strcat(totalCommands,"cd ");
                                                                                strcat(totalCommands,yystack.l_mark[0].repoName);
                                                                                strcat(totalCommands,"\n");
                                                                                strcat(totalCommands,"node ");
                                                                                strcat(totalCommands,yystack.l_mark[-2].indexFile);
                                                                                strcat(totalCommands,"\n");
                                                                                write(fileDescriptor,totalCommands,sizeof(totalCommands));
                                                                                printf("\n Access Your angular project via %s:%d/<YourRoutes>\n",baseServerUrl,yystack.l_mark[-1].port);
                                                                                /*invoke Exec System Call*/
										char *args[]={"./runMe.sh",NULL};
                                                                                /*execvp(args[0],args);*/
                                                                                /*printf("\n Script runtime error..");*/
                                                                        }	

								}
break;
#line 468 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
