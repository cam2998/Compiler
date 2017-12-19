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
%type <IdList> CnstList
%type <IdList> CnstItem
%type <InstrSeq> DeclImpls
%type <BaseType> Type
%type <InstrSeq> FuncBody
%type <InstrSeq> FuncStmts
%type <InstrSeq> Stmt
%type <InstrSeq> AssignStmt
%type <InstrSeq> Assigns
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
%type <CondResult> CondExpr
%type <CondResult> CondTerm
%type <CondResult> CondFactor
%type <BaseType> CondOp
%type <InstrSeq> IncDec
%type <InstrSeq> IncDecs
%type <InstrSeq> Loop
%type <Text> Value
%type <CondResult> Cases
%type <Text> IntLit
%type <Void> Start
%type <ExprResult> FuncArgNames
%type <ExprResult> FuncCall
%type <ExprResult> FunAssign

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
%token FOR_TOK       29
%token LOOP_TOK      30
%token BREAK_TOK     31
%token CNST_TOK      1000
%token SWITCH_TOK    1001
%token CASE_TOK      1002
%token DEF_TOK       1003
%token RET_TOK       1004



// can't go past 31 without conflicting with single char tokens
// could use larger token numbers


%%

Module        : DeclImpls                                                { Finish(); };

DeclImpls     : Decl DeclImpls                                           { };
DeclImpls     : Impl DeclImpls                                           { };
DeclImpls     : Cnst DeclImpls                                           { };
DeclImpls     :                                                          { };


Cnst          : CNST_TOK CnstList ':' Value ';'                          { ProcDecls($2,ConstantBaseType,$4); };
Value         : INTLIT_TOK                                               { $$ = strdup(yytext); };

CnstList      : CnstItem ',' CnstList                                    { $$ = AppendIdList($1,$3); };
CnstList      : CnstItem                                                 { $$ = $1; };

CnstItem      : Id                                                       { $$ = ProcName($1,CnstType,NULL,0); };

Decl          : DECL_TOK DeclList ':' Type ';'                           { ProcDecls($2,$4,0); };

DeclList      : DeclItem ',' DeclList                                    { $$ = AppendIdList($1,$3); };
DeclList      : DeclItem                                                 { $$ = $1; };

DeclItem      : Id                                                       { $$ = ProcName($1,PrimType,NULL,0); };
DeclItem      : Id '[' IntLit ']'                                        { $$ = ProcName($1,PrimType,$3,1); };
DeclItem      : Id FuncArgTypes                                          { $$ = ProcName($1,FuncType,NULL,2); };

Id            : IDENT_TOK                                                { $$ = strdup(yytext); };
FuncArgTypes  : '(' ')'                                            {  };

Type          : INT_TOK                                                  { $$ = IntBaseType; };
Type          : CHR_TOK                                                  { $$ = ChrBaseType; };

Impl          : IMPL_TOK Id FuncArgNames FuncBody ';'                    { ProcFunc($2,$4); };

FuncArgNames  : '('  ')'                                                 { $$ = NULL; };


FuncBody      : Start FuncStmts RB_TOK                                   { $$ = $2;  DeleteTable(); };
FuncBody      : LB_TOK  RB_TOK                                           {  };

Start         : LB_TOK                                                   { NewTable(); };

FuncStmts     : Stmt ';' FuncStmts                                       { $$ = AppendSeq($1,$3);};
FuncStmts     : BREAK_TOK ';' FuncStmts                                  { $$ = AppendBreak($3); };
FuncStmts     :                                                          {  $$ = NULL; };

Stmt          : Id FunAssign                                             { $$ = genStoreWord( $1 , $2); };
Stmt          : Id ':' ChrLit                                            { $$ = LocDecl($1,$3,ChrBaseType); };
Stmt          : Id ':' IntLit                                            { $$ = LocDecl($1,$3,IntBaseType); };
Stmt          : LOOP_TOK Loop                                            { IncLoop(); $$=$2;};
Stmt          : AssignStmt                                               { $$ = $1; };
Stmt          : PutF                                                     { $$ = $1; };
Stmt          : WHILE_TOK '(' CondExpr ')' FuncBody                      { $$ = MakeWhile($3,$5); };
Stmt          : IF_TOK '(' CondExpr ')' FuncBody ELSE_TOK FuncBody       { $$ = MakeIf($3,$5, IfElseType, $7); };
Stmt          : IF_TOK '(' CondExpr ')' FuncBody                         { $$ = MakeIf($3,$5, IfType, NULL); };
Stmt          : IncDec                                                   { $$ = $1; };
Stmt          : FOR_TOK'('Assigns ';' CondExpr ';'IncDecs')'FuncBody     { $$ = MakeFor($3,$5,$7,$9); };
Stmt          : SWITCH_TOK '(' Expr ')' LB_TOK Cases RB_TOK              { $$ = MakeSwitch($3,$6); };
Stmt          : FuncCall                                                 { $$ = MakeSeq($1); };
Stmt          : RET_TOK Expr                                             { $$ = ReturnVal($2); };

FunAssign     : '=' FuncCall                                             { $$ = $2; };

FuncCall      : Id FuncArgNames                                          { $$ = MakeFuncCall($1, $2); };

Cases         : Cases CASE_TOK Expr ':' FuncBody ';'                     { $$ = MakeCase($3,$5,$1); };
Cases         : Cases DEF_TOK ':' FuncBody ';'                           { $$ = MakeCase(NULL,$4,$1); };
Cases         :                                                          { $$ = NULL; };

Loop          : FuncBody                                                 { DecLoop();  $$ = MakeLoop($1);};

Assigns       : Assigns','AssignStmt                                     { $$ = AppendSeq($1,$3);};
Assigns       : AssignStmt                                               { $$ = $1;};

IncDecs       : IncDec','IncDecs                                         { $$ = AppendSeq($1,$3);};
IncDecs       : IncDec                                                   { $$ = $1;};

CondExpr      : CondExpr BOR_TOK BOR_TOK CondTerm                        { $$ = ConcatenateCond($1, OrType, $4); };
CondExpr      : CondTerm                                                 { $$ = $1; };

CondTerm      : CondTerm BAND_TOK BAND_TOK CondFactor                    { $$ = ConcatenateCond($1, AndType, $4); };
CondTerm      : CondFactor                                               { $$ = $1; };

CondFactor    : '(' CondExpr ')'                                         { $$ = $2; };
CondFactor    : '!' '(' CondExpr ')'                                     { $$ = NegateCond($3); };
CondFactor    : Cond                                                     { $$ = $1; };
Cond          : Expr CondOp Expr                                         { $$ = MakeCond($1,$2,$3); };


IncDec        : Id PLUS_TOK PLUS_TOK                                     { $$ = IncDec($1,PlusType);};
IncDec        : Id MINUS_TOK MINUS_TOK                                   { $$ = IncDec($1,MinusType);};


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
IntLit         :INTLIT_TOK                                               { $$ = strdup(yytext); };

AssignStmt    : Id '=' Expr                                              { $$ = genStoreWord( $1 , $3); };
AssignStmt    : Id'[' Expr ']' '=' Expr                                  { $$ = GenStoreArr( $1 , $6, $3); };


Expr          : Expr AddOp Term                                          { $$ = Concatenate($1,$2,$3); };
Expr          : Term                                                     { $$ = $1; };

GetF          : GET_TOK '(' INT_TOK ')'                                  { $$ = GetFunc(); };

Term          : Term MultOp Factor                                       { $$ = Concatenate($1,$2,$3); };
Term          : Factor                                                   { $$ = $1; };

Factor        : '(' Expr ')'                                             { $$ = $2; };
Factor        : MINUS_TOK Expr                                           {  };
Factor        : Id                                                       { $$ = loadExprResult( $1 ); };
Factor        : Id '[' Expr ']'                                          { $$ = LoadExprArr( $1, $3); };

Factor        : INTLIT_TOK                                               { $$ = createExprResult( strdup( yytext ),
                                                                          IntBaseType); };
Factor        : GetF                                                     { $$ = $1; };
Factor        : ChrLit                                                   {  };

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
