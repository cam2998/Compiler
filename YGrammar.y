%{
  #include "IOMngr.h"
  #include "Scanner.h"
  #include "YSemantics.h"
  #include <stdio.h>
  #include <string.h>

  void yyerror(char *s);
%}

/* Union structure of data that can be attached to non-terminals   */
%union     {
  int Integer;
  char * Text;
  struct IdList * IdList;
  enum BaseTypes BaseType;
  struct InstrSeq * InstrSeq;
  struct ExprResult * ExprResult;
  struct CondResult * CondResult;
}

/* Type declaration for data attched to non-terminals. Allows      */
/* $# notation to be correctly type casted for function arguments. */
/* %type <union-field-name> non-terminal                           */
%type <Text> Id
%type <IdList> DeclList
%type <IdList> DeclItem
%type <InstrSeq> DeclImpls
%type <BaseType> Type
%type <InstrSeq> FuncBody
%type <InstrSeq> FuncStmts
%type <InstrSeq> Stmt
%type <InstrSeq> AssignStmt
%type <BaseType> AddOp
%type <BaseType> MultOp
%type <ExprResult> Expr
%type <ExprResult> Factor
%type <ExprResult> Term
%type <InstrSeq> PutF
%type <ExprResult> GetF
%type <Text> ChrLit
%type <Text> StringLit
%type <CondResult> Cond
%type <BaseType> CondOp

/* List of token grammar name and corresponding numbers */
/* y.tab.h will be generated from these for use by scanner*/
%token IDENT_TOK  	 1
%token DECL_TOK   	 2
%token IMPL_TOK   	 3
%token INT_TOK    	 4
%token CHR_TOK     	 5
%token CHRLIT_TOK    6
%token INTLIT_TOK    7
%token RB_TOK        8
%token LB_TOK        9
%token PLUS_TOK      10
%token MINUS_TOK     11
%token TIMES_TOK     12
%token DIV_TOK       13
%token PUT_TOK       14
%token GET_TOK       15
%token NOTEQ_TOK     16
%token EQ_TOK        17
%token GT_TOK        18
%token LT_TOK        19
%token GTOE_TOK      21
%token LTOE_TOK      22
%token IF_TOK        23
%token WHILE_TOK     24
%token ELSE_TOK      25
%token STRINGLIT_TOK 26
%token BAND_TOK      27
%token BOR_TOK       28



// can't go past 31 without conflicting with single char tokens
// could use larger token numbers


%%

Module        : DeclImpls                                                { Finish(); };

DeclImpls     : Decl DeclImpls                                           { };
DeclImpls     : Impl DeclImpls                                           { };
DeclImpls     :                                                          { };

Decl          : DECL_TOK DeclList ':' Type ';'                           { ProcDecls($2,$4); };

DeclList      : DeclItem ',' DeclList                                    { $$ = AppendIdList($1,$3); };
DeclList      : DeclItem                                                 { $$ = $1; };

DeclItem      : Id                                                       { $$ = ProcName($1,PrimType); };
DeclItem      : Id FuncArgTypes                                          { $$ = ProcName($1,FuncType); };

Id            : IDENT_TOK                                                { $$ = strdup(yytext); };
FuncArgTypes  : '('  ')'                                                 {  };

Type          : INT_TOK                                                  { $$ = IntBaseType; };
Type          : CHR_TOK                                                  { $$ = ChrBaseType; };

Impl          : IMPL_TOK Id FuncArgNames FuncBody ';'                    { ProcFunc($2,$4); };

FuncArgNames  : '('  ')'                                                 {  };

FuncBody      : LB_TOK FuncStmts RB_TOK                                  { $$ = $2; };
FuncBody      : LB_TOK  RB_TOK                                           {  };

FuncStmts     : Stmt ';' FuncStmts                                       { $$ = AppendSeq($1,$3); };
FuncStmts     :                                                          { $$ = NULL; };

Stmt          : AssignStmt                                               { $$ = $1; };
Stmt          : PutF                                                     { $$ = $1; };
Stmt          : WHILE_TOK '(' Cond ')' FuncBody                          { $$ = MakeWhile($3,$5); };
Stmt          : IF_TOK '(' Cond ')' FuncBody ELSE_TOK FuncBody           { $$ = MakeIf($3,$5, IfElseType, $7); };
Stmt          : IF_TOK '(' Cond ')' FuncBody                             { $$ = MakeIf($3,$5, IfType, NULL); };
Stmt          : Id PLUS_TOK PLUS_TOK                                     { $$ = IncDec($1,PlusType);};
Stmt          : Id MINUS_TOK MINUS_TOK                                   { $$ = IncDec($1,MinusType);};

Cond          : Expr CondOp Expr                                         { $$ = ConcatenateCond($1,$2,$3); };

CondOp        : NOTEQ_TOK                                                { $$ = NotEqualType; };
CondOp        : EQ_TOK                                                   { $$ = EqualType; };
CondOp        : GT_TOK                                                   { $$ = GreaterThanType; };
CondOp        : LT_TOK                                                   { $$ = LessThanType; };
CondOp        : GTOE_TOK                                                 { $$ = GreaterThanOrEqualType; };
CondOp        : LTOE_TOK                                                 { $$ = LessThanOrEqualType; };

PutF          : PUT_TOK '(' ChrLit  ')'                                  { $$ = PutFunc( $3 , ChrBaseType );};
PutF          : PUT_TOK '(' Id  ')'                                      { $$ = PutFunc( $3, IntBaseType );};
PutF          : PUT_TOK '(' StringLit  ')'                               { $$ = PutFunc( $3, StringBaseType );};

StringLit     : STRINGLIT_TOK                                            { $$ = strdup(yytext); };
ChrLit        : CHRLIT_TOK                                               { $$ = strdup(yytext); };

AssignStmt    : Id '=' Expr                                              { $$ = genStoreWord( $1 , $3); };

Expr          : Expr AddOp Term                                          { $$ = Concatenate($1,$2,$3); };
Expr          : Term                                                     { $$ = $1; };

GetF          : GET_TOK '(' INT_TOK ')'                                  { $$ = GetFunc(); };

Term          : Term MultOp Factor                                         { $$ = Concatenate($1,$2,$3); };
Term          : Factor                                                   { $$ = $1; };

Factor        : '(' Expr ')'                                             { $$ = $2; };
Factor        : MINUS_TOK Expr                                           {  };
Factor        : Id                                                       { $$ = loadExprResult( $1 ); };
Factor        : INTLIT_TOK                                               { $$ = createExprResult( strdup( yytext ),
                                                                          IntBaseType); };
Factor        : GetF                                                     { $$ = $1; };
Factor        : CHRLIT_TOK                                               {  };

AddOp		      :	MINUS_TOK                                                { $$ = MinusType; };
AddOp		      :	PLUS_TOK                                                 { $$ = PlusType; };

MultOp	      :	TIMES_TOK                                                { $$ = TimesType; };
MultOp	      :	DIV_TOK                                                  { $$ = DivideType; };



%%

void
yyerror( char *s)     {
  char msg[MAXLINE];
  sprintf(msg,"ERROR \"%s\" token: \"%s\"",s,yytext);
  PostMessage(GetCurrentColumn(),strlen(yytext),msg);
}
