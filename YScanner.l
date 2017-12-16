Letter	[A-Za-z]
Digit   [0-9]
Cha     [\:\;\.\,\"\'\(\)\{\}\|\-\_\=\+\/\*\&\^\%\#\$\@\!\~\`\\\>\<\?\[\] ]

%{
#include "IOMngr.h"
#define YY_INPUT(buf,result,max_size) \
  { int c = GetSourceChar(); \
		result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
  }

bool shouldLog = false;

int nestLevel=0;
int lineComment=0;

#define IN_COMMENT (lineComment||nestLevel > 0)
#define RETURN(val) \
  { if (shouldLog) fprintf(stderr,"Token#=%d, Length=%zu, Text=\"%s\"\n",val,yyleng,yytext); \
    return(val); \
  }


#include "YSemantics.h"
#include "y.tab.h"
%}

%%
decl                            { if (!IN_COMMENT) RETURN(DECL_TOK); }
impl                            { if (!IN_COMMENT) RETURN(IMPL_TOK); }
int                             { if (!IN_COMMENT) RETURN(INT_TOK); }
chr                             { if (!IN_COMMENT) RETURN(CHR_TOK); }
put                             { if (!IN_COMMENT) RETURN(PUT_TOK); }
get                             { if (!IN_COMMENT) RETURN(GET_TOK); }
if                              { if (!IN_COMMENT) RETURN(IF_TOK); }
while                           { if (!IN_COMMENT) RETURN(WHILE_TOK); }
else                            { if (!IN_COMMENT) RETURN(ELSE_TOK); }

\'({Letter}|\>|\<|\=|\\{Letter})\'   { if (!IN_COMMENT) RETURN( CHRLIT_TOK ); }
{Letter}({Letter}|{Digit})*			{ if (!IN_COMMENT) RETURN(IDENT_TOK); }
\{                              { if (!IN_COMMENT) RETURN(LB_TOK); }
\}                              { if (!IN_COMMENT) RETURN(RB_TOK); }
{Digit}+                        { if (!IN_COMMENT) RETURN( INTLIT_TOK ); }
\-                              { if (!IN_COMMENT) RETURN(MINUS_TOK); }
\+                              { if (!IN_COMMENT) RETURN(PLUS_TOK); }
\*                              { if (!IN_COMMENT) RETURN(TIMES_TOK); }
\/                              { if (!IN_COMMENT) RETURN(DIV_TOK); }
\#\#                            { if (!IN_COMMENT) RETURN(NOTEQ_TOK); }
\=\=                            { if (!IN_COMMENT) RETURN(EQ_TOK); }
\>                              { if (!IN_COMMENT) RETURN(GT_TOK); }
\<                              { if (!IN_COMMENT) RETURN(LT_TOK); }
\>\=                            { if (!IN_COMMENT) RETURN(GTOE_TOK); }
\<\=                            { if (!IN_COMMENT) RETURN(LTOE_TOK); }
\"({Letter}|{Cha}|\\{Letter})*\"                   { if (!IN_COMMENT) RETURN(STRINGLIT_TOK); }
\&                              { if (!IN_COMMENT) RETURN(BAND_TOK); }
\|                              { if (!IN_COMMENT) RETURN(BOR_TOK); }

\!                              { if (!IN_COMMENT) RETURN('!');}
\=                              { if (!IN_COMMENT) RETURN('='); }
\;                              { if (!IN_COMMENT) RETURN(';'); }
\(                              { if (!IN_COMMENT) RETURN('('); }
\)                              { if (!IN_COMMENT) RETURN(')'); }
\:                              { if (!IN_COMMENT) RETURN(':'); }
\,                              { if (!IN_COMMENT) RETURN(','); }

\/\*														{ nestLevel=1; }
\*\/														{ nestLevel=0; }
\/\/														{ lineComment=1; }



[ \t]                           { }
[\n]                            { lineComment = 0; }
.                               { }
%%
