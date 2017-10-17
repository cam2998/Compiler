Letter	[A-Za-z]
Digit   [0-9]

%{
#include "ScanTokens.h"
#include "IOMngr.h"

#define YY_INPUT(buf,result,max_size) \
	{ int c = GetSourceChar(); \
		result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
	}

bool shouldLog = true;
bool IN_COMMENT = false;
int nLevel=0;

#define RETURN(val) \
  { if (shouldLog) fprintf(stderr,"Token#=%d, Length=%zu, Text=\"%s\"\n",val,yyleng,yytext); \
    return(val); \
  }

%}

%%

\@INIT                          { if (!IN_COMMENT) RETURN(INIT_TOK); }
\@DUMP                          { if (!IN_COMMENT) RETURN(DUMP_TOK); }
{Letter}({Letter}|{Digit})*			{ if (!IN_COMMENT) RETURN(IDENT_TOK); }

\=															{if (!IN_COMMENT) RETURN(EQUAL_TOK);}
-?{Digit}+											{if (!IN_COMMENT) RETURN(INT_TOK);}
-?(({Digit}+)\.{Digit}+)				{if (!IN_COMMENT) RETURN(FLOAT_TOK);}

\/\*														{nLevel++; IN_COMMENT=true;}
\*\/														{nLevel--; if(nLevel==0){IN_COMMENT=false;}}
\/\/														{IN_COMMENT=true;}
[\n]                            {IN_COMMENT=false; }
[ \t]                           { }
.                               { }





%%
