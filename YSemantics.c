/* Author: Cameron Trim
  Created: 10/20/17
  Resources:
*/

/* Semantics.c
 Support and semantic action routines.
 */


#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "YSemantics.h"

// Shared Data

struct SymTab * IdentifierTable;
struct SymTab * StringLiteralTable;

struct InstrSeq * localvars;

enum AttrKinds { VOID_KIND = -1, INT_KIND, STRING_KIND, STRUCT_KIND,CNST_KIND };

char * BaseTypeNames[2] = { "int", "chr"};
char * TypeNames[2] = { "", "func"};

// corresponds to enum Operators
char * Ops[] = { "add", "sub", "mul", "div"};
char * BoolOps[] = { "and", "or", "not" };

//loop level
int LoopLevel=0;
int SwitchLevel=0;
int CaseLevel=0;

// corresponds to negation of enum Comparisons
// enum Comparisons { LtCmp, LteCmp, GtCmp, GteCmp, EqCmp, NeqCmp };
char * Branches[] = { "bge", "bg", "ble", "bl", "bne", "beq"};
// comparison set instructions, in order with enum Comparisons
char * CmpSetReg[] = { "slt", "sle", "sgt", "sge", "seq", "sne" };


// Supporting Routines
void
PostMessageAndExit(int col, char * message) {
  PostMessage(col,1,message);
  CloseFiles();
  exit(0);
}

void
InitSemantics() {
  IdentifierTable = CreateSymTab(100,"global",NULL);
  StringLiteralTable = CreateSymTab(1,"literals", NULL);
  localvars=GenInstr(NULL,".data",NULL,NULL,NULL);
}

char *
StringForType(struct TypeDesc * desc) {
  switch (desc->declType) {
    case PrimType: {
      return strdup(BaseTypeNames[desc->primDesc]);
    } break;
    case FuncType: {
      return strdup(BaseTypeNames[desc->funcDesc->returnType]);
    } break;
  }
}

struct TypeDesc *
MakePrimDesc(enum BaseTypes type) {
  struct TypeDesc * desc = malloc(sizeof(struct TypeDesc));
  desc->declType = PrimType;
  desc->primDesc = type;
  return desc;
}

struct TypeDesc *
MakeFuncDesc(enum BaseTypes returnType) {
  struct TypeDesc * desc = malloc(sizeof(struct TypeDesc));
  desc->declType = FuncType;
  desc->funcDesc = malloc(sizeof(struct FuncDesc));
  desc->funcDesc->returnType = returnType;
  desc->funcDesc->funcCode = NULL;
  return desc;
}

void displayEntry(struct SymEntry * entry, int cnt, void * ignore) {
  char * scope = GetScope(GetTable(entry));
  printf("%3d %-20s %-15s",cnt,scope,GetName(entry));
  free(scope);
  int attrKind = GetAttrKind(entry);
  struct Attr * attr = GetAttr(entry);
  switch (attrKind) {
    case VOID_KIND: {
    } break;
    case INT_KIND: {
      if (attr) {
        printf("%-10s",attr->reference);
        printf("     ");
        struct TypeDesc * desc = attr->typeDesc;
        char * typeStr = StringForType(desc);
        printf("%-10s ",typeStr);
        free(typeStr);
      }
    } break;
    case CNST_KIND: {
      if (attr) {
        printf("%-10s",attr->reference);
        printf("     ");
        struct TypeDesc * desc = attr->typeDesc;
        char * typeStr = StringForType(desc);
        printf("%-10s ",typeStr);
        free(typeStr);
      }
    } break;
    case STRING_KIND: {
    } break;
    case STRUCT_KIND: {
      if (attr) {
        printf("%-10s",attr->reference);
        printf("     ");
        struct TypeDesc * desc = attr->typeDesc;
        char * typeStr = StringForType(desc);
        printf("%-10s ",typeStr);
        free(typeStr);
      }
      else {
        printf("empty");
      }
    } break;
  }
  printf("\n");
}

void
ListIdentifierTable() {
  printf("\nIdentifier Symbol Table\n");
  printf("Num Scope                Name           Ref       Kind Type\n");
  DoForEntries(IdentifierTable,true,displayEntry,0,NULL);
}

void
FreeTypeDesc(struct TypeDesc * desc) {
  switch (desc->declType) {
    case PrimType: {
    } break;
    case FuncType: {
      if (desc->funcDesc->funcCode) FreeSeq(desc->funcDesc->funcCode);
      free(desc->funcDesc);
    } break;
  }
  free(desc);
}

// provided to the SymTab for destroying table contents
void
FreeEntryAttr(struct SymEntry * entry, int cnt, void * ignore) {
  int attrKind = GetAttrKind(entry);
  struct Attr * attr = GetAttr(entry);
  switch (attrKind) {
    case VOID_KIND: {
    } break;
    case INT_KIND: {
    } break;
    case STRING_KIND: {
    } break;
    case STRUCT_KIND: {
      if (attr) {
        if (attr->typeDesc) FreeTypeDesc(attr->typeDesc);
        if (attr->reference) free(attr->reference);
        free(attr);
      }
    } break;
  }
}


void
NewTable(){
  IdentifierTable=CreateSymTab(1,"local",IdentifierTable);
}
// Semantics Actions

void
DeleteTable(){
int i;
for(i=0;i<IdentifierTable->size;i++){
    struct SymEntry * head=IdentifierTable->contents[i];
    while(head){
      struct Attr * headAttr = (struct Attr *) GetAttr(head);
      int kind=GetAttrKind(head);
      if(kind==INT_KIND){
        char * c = strdup(headAttr->reference);
        AppendSeq(localvars,GenInstr(c,".word","0",NULL,NULL));
      }
      head=head->next;
    }
  }
  IdentifierTable=IdentifierTable->parent;
}

void
Finish() {
  printf("Finish\n");
  ListIdentifierTable();

  struct InstrSeq * textCode = GenInstr(NULL,".text",NULL,NULL,NULL);
  struct InstrSeq * dataCode = localvars;
  // form module preamble
  struct SymEntry * mainEntry = LookupName(IdentifierTable,"main");
  if (!mainEntry) {
    PostMessageAndExit(GetCurrentColumn(),"no main function for module");
  }
  // should make sure main takes no arguments
  struct Attr * mainAttr = GetAttr(mainEntry);
  // need to keep spim happy
  AppendSeq(textCode,GenInstr(NULL,".globl","__start",NULL,NULL));
  AppendSeq(textCode,GenInstr("__start",NULL,NULL,NULL,NULL));

  // put functions in code seq
  struct InstrSeq * mainCode=GenInstr(NULL,NULL,NULL,NULL,NULL);
  AppendSeq(mainCode,mainAttr->typeDesc->funcDesc->funcCode);
  //mainAttr->typeDesc->funcDesc->funcCode
  // put globals in data seg
    int i;
    for(i=0;i<IdentifierTable->size;i++){
      struct SymEntry * head=IdentifierTable->contents[i];
      while(head){
        struct Attr * headAttr = (struct Attr *) GetAttr(head);
        int kind=GetAttrKind(head);
        if(kind==STRUCT_KIND){
          AppendSeq(mainCode,headAttr->typeDesc->funcDesc->funcCode);
        }
        if(kind==CNST_KIND){
          AppendSeq(textCode,headAttr->typeDesc->funcDesc->funcCode);
        }
        if(kind==INT_KIND||kind==CNST_KIND){
          char * c = strdup(headAttr->reference);
          int n=headAttr->typeDesc->size;
          char * zeros=calloc(1+2*n,2*sizeof(char));
          strcat(zeros, "0");
          int k;
          for(k=1;k<n;k++)strcat(zeros, ",0");
          AppendSeq(dataCode,GenInstr(c,".word",zeros,NULL,NULL));
        }
        head=head->next;
      }
    }
    for(i=0;i<StringLiteralTable->size;i++){
      struct SymEntry * head=StringLiteralTable->contents[i];
      while(head){
        struct StrAttr * headAttr = (struct StrAttr *) GetAttr(head);
        int kind=GetAttrKind(head);
        char * c = strdup(GetName(head));
        char * l = strdup(headAttr->label);
        AppendSeq(dataCode,GenInstr(l,".asciiz",c,NULL,NULL));
        head=head->next;
      }
    }



    AppendSeq(textCode,GenInstr(NULL,"jal",mainAttr->reference,NULL,NULL));
    AppendSeq(textCode,GenInstr(NULL,"li","$v0","10",NULL));
    AppendSeq(textCode,GenInstr(NULL,"syscall",NULL,NULL,NULL));
    AppendSeq(textCode,mainCode);
  // combine and write
  struct InstrSeq * moduleCode = AppendSeq(textCode,dataCode);
  WriteSeq(moduleCode);

  // free code
  FreeSeq(moduleCode);
  CloseCodeGen();
  fprintf(stderr,"Finish \n");
}

struct InstrSeq *
LocDecl(char * k, char * num, enum BaseTypes baseType){
  struct SymEntry * name = EnterName(IdentifierTable,k);
  struct TypeDesc *desc = MakePrimDesc(baseType);
  struct Attr * att=malloc(sizeof(struct Attr *));
  char * ref = malloc(strlen(name->name) + 3);
  strcat(ref, "_");
  strcat(ref, name->name);
  att->reference=strdup(ref);
  att->typeDesc=desc;
  SetAttr(name, INT_KIND , att);
  int reg = AvailTmpReg();
  ReleaseTmpReg(reg);
  struct InstrSeq * code;
  if(num[0]=='\''){
    char this[10];
    this[0]=num[1];
    code = GenInstr(NULL,"la",TmpRegName(reg),this,NULL);
  }else{
    char this[10];
    sprintf(this, "%d", atoi(num));
    code = GenInstr(NULL,"li",TmpRegName(reg),this,NULL);
  }
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(reg),att->reference,NULL));
  return code;
}


struct InstrSeq *
GenStoreArr(char * k, struct ExprResult * expr, struct ExprResult * ind){
  struct SymEntry * idEntry = LookupName(IdentifierTable, k);
  if(!idEntry)return NULL; //TODO: post message
  struct Attr * attribute = GetAttr(idEntry);
  if(attribute->typeDesc->declType==FuncType)return NULL; //TODO: Post message
  if(attribute->typeDesc->primDesc!=expr->baseType)return NULL;//TODO: Post message
  int reg=AvailTmpReg();
  char * name=malloc((strlen(k)+3)*sizeof(char));
  strcat(name,"_");
  strcat(name,k);
  char * reggg = calloc(7,sizeof(char));
  strcat(reggg,"(");
  strcat(reggg,TmpRegName(reg));
  strcat(reggg,")");
  struct InstrSeq * code=expr->code;
  int temp=AvailTmpReg();
  AppendSeq(code,GenInstr(NULL,"addi",TmpRegName(temp),"$zero","4"));
  AppendSeq(code,GenInstr(NULL,"mul",TmpRegName(ind->reg),TmpRegName(ind->reg),TmpRegName(temp)));
  ReleaseTmpReg(temp);
  AppendSeq(code,GenInstr(NULL,"la",TmpRegName(reg),name,NULL));
  if(ind>0)AppendSeq(code,GenInstr(NULL,"add",TmpRegName(reg),TmpRegName(reg),TmpRegName(ind->reg)));
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(expr->reg),reggg,NULL));
  ReleaseTmpReg(expr->reg);
  ReleaseTmpReg(reg);
  free(expr);
  //free regs and expr?
  return code;
}
struct ExprResult *
LoadExprArr(char * k, struct ExprResult * ind){
  struct SymEntry * idEntry = LookupName(IdentifierTable, k);
  if(!idEntry)return NULL; //TODO: post message
  struct Attr * attribute = GetAttr(idEntry);
  struct ExprResult * ret = malloc(sizeof(struct ExprResult *));
  int newReg = AvailTmpReg();
  int reg=AvailTmpReg();
  char * reggg = calloc(7,sizeof(char));
  strcat(reggg,"(");
  strcat(reggg,TmpRegName(reg));
  strcat(reggg,")");
  char * name=malloc((strlen(k)+3)*sizeof(char));
  strcat(name,"_");
  strcat(name,k);
  struct InstrSeq * code=ind->code;
  int temp=AvailTmpReg();
  AppendSeq(code,GenInstr(NULL,"addi",TmpRegName(temp),"$zero","4"));
  AppendSeq(code,GenInstr(NULL,"mul",TmpRegName(ind->reg),TmpRegName(ind->reg),TmpRegName(temp)));
  ReleaseTmpReg(temp);
  AppendSeq(code,GenInstr(NULL,"la",TmpRegName(reg),name,NULL));
  if(ind>0)AppendSeq(code,GenInstr(NULL,"add",TmpRegName(reg),TmpRegName(reg),TmpRegName(ind->reg)));
  AppendSeq(code,GenInstr(NULL,"lw",TmpRegName(newReg),reggg,NULL));
  ret->code=code;
  ret->reg=newReg;
  if(attribute->typeDesc->declType==FuncType)return NULL; //TODO: Post message
  ret->baseType=attribute->typeDesc->primDesc;
  ReleaseTmpReg(reg);
  return ret;
}

void
ProcDecls(struct IdList * idList, enum BaseTypes baseType, char * num) {
  // walk IdList items
      // names on IdList are only specified as PrimType or FuncType
      // set type desc
    // global scope so will be allocated in data segment
    // reference string is id name with prepended "_"
      while (idList != NULL) {
        if (idList->entry->attrKind == PrimType) {
          struct TypeDesc *desc = MakePrimDesc(baseType);
          struct Attr * att=malloc(sizeof(struct Attr *));
          att = (struct Attr *) GetAttr(idList->entry);
          desc->size=att->typeDesc->size;
          char *ref = malloc(strlen(idList->entry->name) + 3);
          strcat(ref, "_");
          strcat(ref, idList->entry->name);
          att->reference=strdup(ref);
          att->typeDesc=desc;
          SetAttr(idList->entry, INT_KIND , att);
        } else if (idList->entry->attrKind == CnstType) {
          struct TypeDesc *desc = MakeFuncDesc(IntBaseType);
          struct Attr * att=malloc(sizeof(struct Attr *));
          att = (struct Attr *) GetAttr(idList->entry);
          char *ref = malloc(strlen(idList->entry->name) + 3);
          strcat(ref, "_");
          strcat(ref, idList->entry->name);
          att->reference=strdup(ref);
          int reg=AvailTmpReg();
          char this[10];
          desc->funcDesc->funcCode=AppendSeq(GenInstr(NULL,"li",TmpRegName(reg),this,NULL),GenInstr(NULL,"sw",TmpRegName(reg),ref,NULL));
          att->typeDesc=desc;
          SetAttr(idList->entry, CNST_KIND , att);
        } else {
          struct TypeDesc *desc = MakeFuncDesc(baseType);
          struct Attr * att=malloc(sizeof(struct Attr));
          att = (struct Attr *) GetAttr(idList->entry);
          char *ref = malloc(strlen(idList->entry->name) + 2);
          strcat(ref, "_");
          strcat(ref, idList->entry->name);
          att->reference=strdup(ref);
          att->typeDesc=desc;
          SetAttr(idList->entry, STRUCT_KIND, att);
        }
        idList = idList->next;
      }
}

struct IdList *
AppendIdList(struct IdList * item, struct IdList * list) {
char *
GenSwitchLabel(){
  char * label = (char *) malloc(16);
  sprintf(label,"SW_EXIT%d",SwitchLevel++);
  return label;
}
  struct IdList * original = list;
  while (list->next) {
    list = list->next;
  }
  list->next=item;
  return original;
}

struct IdList *
ProcName(char * id, enum DeclTypes type, char * n, int m) {
  // get entry for id, error if it exists
  if(LookupName(IdentifierTable,id))return NULL;//do post message
  // enter id
  struct SymEntry * name = EnterName(IdentifierTable,id);
  // create IdList node for entry
  struct IdList * node=malloc(sizeof(struct IdList));
  node->entry=name;
  // create and init type descriptor
  struct TypeDesc * typeD=NULL;
  if(type==PrimType)typeD=MakePrimDesc(-1);
  if(type==FuncType)typeD=MakeFuncDesc(-1);
  if(type==CnstType)typeD=MakePrimDesc(-1);
  if(type==ArrType)typeD=MakePrimDesc(-1);

  // create, init and set attr struct
  struct Attr * attribute=malloc(sizeof(struct Attr));
  attribute->typeDesc=typeD;

  char * label = (char *) malloc(8);
  if(m==1)attribute->typeDesc->size=atoi(n);
  SetAttr(node->entry, type , attribute);
  return node;
}

char *
GenSwitchLabel(){
  char * label = (char *) malloc(8);
  sprintf(label,"S%d",SwitchLevel++);
  return label;
}

char *
GenCaseLabel(){
  char * label = (char *) malloc(8);
  sprintf(label,"C%d",CaseLevel++);
  return label;
}

char *
GenBodyLabel(){
  char * label = (char *) malloc(8);
  sprintf(label,"B%d",CaseLevel);
  return label;
}

void
IncSwitch(){
  SwitchLevel++;
}

struct CondResult *
MakeCase(struct ExprResult * expr, struct InstrSeq * body, struct CondResult * expression){
  struct InstrSeq * code;
  struct InstrSeq * casestmt;
  struct CondResult * ret = malloc(sizeof(struct CondResult));
  if(!expression){
    int reg=AvailTmpReg();
    char * label = GenSwitchLabel();
    char * caselabel = GenCaseLabel();
    char * casebody = GenBodyLabel();
    ret->exitlabel=label;
    ret->swlabel=GenInstr(label,NULL,NULL,NULL,NULL);
    code=GenInstr(caselabel,NULL,NULL,NULL,NULL);
    if(expr){
      AppendSeq(code,expr->code);
      AppendSeq(code,GenInstr(NULL,"bne",TmpRegName(reg),TmpRegName(expr->reg),label));
      AppendSeq(code,GenInstr(NULL,"b", casebody,NULL,NULL));
    }

    ret->label=code;
    ret->nextlabel=caselabel;
    casestmt=GenInstr(casebody,NULL,NULL,NULL,NULL);
    AppendSeq(casestmt,body);
    ret->code=AppendSeq(casestmt,GenInstr(NULL,"b",label,NULL,NULL));

    ret->reg=reg;
  }else{
    char * caselabel = GenCaseLabel();
    char * casebody = GenBodyLabel();
    code=GenInstr(caselabel,NULL,NULL,NULL,NULL);
      AppendSeq(code,expr->code);
      AppendSeq(code,GenInstr(NULL,"bne",TmpRegName(expression->reg),TmpRegName(expr->reg),expression->nextlabel));

      AppendSeq(code,GenInstr(NULL,"b", casebody,NULL,NULL));
    ret->label=AppendSeq(code,expression->label);
    casestmt=expression->code;
    AppendSeq(casestmt,GenInstr(casebody,NULL,NULL,NULL,NULL));
    AppendSeq(casestmt,body);
    ret->nextlabel=caselabel;
    ret->swlabel=expression->swlabel;
    ret->code=AppendSeq(casestmt,GenInstr(NULL,"b",expression->exitlabel,NULL,NULL));
    ret->reg=expression->reg;
    ret->exitlabel=expression->exitlabel;
  }
  if(expr)ReleaseTmpReg(expr->reg);
  return ret;
}

struct InstrSeq *
MakeSwitch( struct ExprResult * expr, struct CondResult * cond){
  struct InstrSeq * code = expr->code;
  AppendSeq(code,GenInstr(NULL, "move", TmpRegName(cond->reg),TmpRegName(expr->reg),NULL));
  AppendSeq(code,cond->label);
  AppendSeq(code,cond->code);
  AppendSeq(code,cond->swlabel);
  ReleaseTmpReg(cond->reg);
  ReleaseTmpReg(expr->reg);
  return code;
}

void
ProcFunc(char * id, struct InstrSeq * instrs) {
  // lookup name
  struct SymEntry * idEntry = LookupName(IdentifierTable, id);
  if(!idEntry)return; //TODO: post message
  // get attr
  if(instrs==NULL)return;
  struct Attr * attribute = GetAttr(idEntry);
  // function entry
  struct InstrSeq * code = GenInstr(attribute->reference,NULL,NULL,NULL,NULL);
  // include function body code
  AppendSeq(code, instrs);
  // function exit code
  AppendSeq(code,GenInstr(NULL,"jr","$ra",NULL,NULL));

  if(attribute){
    if(!attribute->typeDesc)return;
    if(attribute->typeDesc->declType==FuncType){
      attribute->typeDesc->funcDesc->funcCode = code;
      SetAttr(idEntry,GetAttrKind(idEntry),attribute);
    }
  }
}

/*Create a struct ExprResult which holds both the code sequence that computes the
  expression and the register number where the result is located when the code
  executes. This will get added as an option for the "union" and associated with
  certain nonterminals. You may also want an enumerated type for the various
  operators or simply use the operator character.*/

struct ExprResult *
 Concatenate(struct ExprResult * first, enum BaseTypes baseType, struct ExprResult * second){
  if(first->baseType!=second->baseType)return NULL; //TODO: Post message;
  struct ExprResult * ret = malloc(sizeof(struct ExprResult *));
  struct InstrSeq * code=first->code;
  AppendSeq(code, second->code);
  int newReg = AvailTmpReg();
  switch(baseType){
    case PlusType: {
      AppendSeq(code,GenInstr(NULL,"add",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
    } break;
    case MinusType: {
      AppendSeq(code,GenInstr(NULL,"sub",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
    } break;
    case TimesType: {
      AppendSeq(code,GenInstr(NULL,"mul",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
    } break;
    case DivideType: {
      AppendSeq(code,GenInstr(NULL,"div",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
    } break;
  }
  //free first and second regs?
  ReleaseTmpReg(second->reg);
  free(second);
  //free first and second?
  ReleaseTmpReg(first->reg);
  free(first);
  ret->code=code;
  ret->reg=newReg;
  ret->baseType=second->baseType;
  return ret;
}

struct CondResult *
NegateCond(struct CondResult * expression){
  char * x = GenLabel();
  AppendSeq(expression->code,GenInstr(NULL,"b",x,NULL,NULL));
  AppendSeq(expression->code,expression->label);
  expression->label=GenInstr(x,NULL,NULL,NULL,NULL);
  return expression;
}

struct InstrSeq *
MakeFor(struct InstrSeq * assign, struct CondResult * condition ,struct InstrSeq * incdecs, struct InstrSeq * funbody ){
  char * lab=GenLabel();
  AppendSeq(assign,GenInstr(lab,NULL,NULL,NULL,NULL));
  AppendSeq(assign,condition->code);
  AppendSeq(assign,funbody);
  AppendSeq(assign,incdecs);
  AppendSeq(assign,GenInstr(NULL,"b",lab,NULL,NULL));
  AppendSeq(assign,condition->label);
  free(condition);
  return assign;
}

struct InstrSeq *
AppendBreak(struct InstrSeq * code){
  char * exitloop = (char *) malloc(16);
  sprintf(exitloop,"EXIT%d",(LoopLevel/2)+1);
  code=AppendSeq(GenInstr(NULL,"b",exitloop,NULL,NULL),code);
  return code;
}

void
IncLoop(){
  LoopLevel++;
}

void
DecLoop(){
  LoopLevel++;
}

char *
GenLoopLabel(){
  char *label = (char *) malloc(16);
  sprintf(label,"LOOP%d",(LoopLevel/2)+1);
  return label;
}

struct InstrSeq *
MakeLoop( struct InstrSeq * breakR){
  char * loop = GenLoopLabel();
  char * exitloop = (char *) malloc(16);
  breakR=AppendSeq(GenInstr(loop,NULL,NULL,NULL,NULL),breakR);
  AppendSeq(breakR,GenInstr(NULL,"b",loop,NULL,NULL));
  sprintf(exitloop,"EXIT%d",((LoopLevel-1)/2)+1);
  AppendSeq(breakR,GenInstr(exitloop,NULL,NULL,NULL,NULL));
  return breakR;
}

struct CondResult *
ConcatenateCond(struct CondResult * first, enum IfTypes type, struct CondResult * second){
  struct CondResult * ret = malloc(sizeof(struct CondResult *));
  struct InstrSeq * code=first->code;
  switch(type){
    case OrType: {
      ret->type=OrType;
      if(first->type == AndType){
        first=NegateCond(first);
        code=first->code;
        AppendSeq(code,second->code);
        AppendSeq(code,first->label);
        ret->label=second->label;
      }else{
        first=NegateCond(second);
        code=second->code;
        AppendSeq(code,first->code);
        AppendSeq(code,second->label);
        ret->label=first->label;
      }
    }break;

    case AndType:{
      if(first->type == OrType || second->type == OrType){
        ret->type=OrType;
      }else{
        ret->type=AndType;
      }
      if(first->type == OrType){
        code=second->code;
        AppendSeq(code,first->code);
      }else{
        code=first->code;
        AppendSeq(code,second->code);
      }
      ret->label=AppendSeq(first->label,second->label);
    }
  }
  //free first and second regs?
  free(second);
  //free first and second?
  free(first);
  ret->code=code;
  return ret;
}


struct CondResult *
MakeCond(struct ExprResult * first, enum BaseTypes baseType, struct ExprResult * second){
  if(first->baseType!=second->baseType)return NULL; //TODO: Post message;
  struct CondResult * ret = malloc(sizeof(struct CondResult *));
  struct InstrSeq * code=first->code;
  AppendSeq(code, second->code);
  int newReg=AvailTmpReg();
  char * newLab = GenLabel();
  switch(baseType){
    case NotEqualType: {
      AppendSeq(code,GenInstr(NULL,"beq",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","sne",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
    case EqualType: {
      AppendSeq(code,GenInstr(NULL,"bne",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","se",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
    case GreaterThanType: {
      AppendSeq(code,GenInstr(NULL,"ble",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","sgt",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
    case LessThanType: {
      AppendSeq(code,GenInstr(NULL,"bge",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","slt",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
    case GreaterThanOrEqualType: {
      AppendSeq(code,GenInstr(NULL,"blt",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","sge",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
    case LessThanOrEqualType: {
      AppendSeq(code,GenInstr(NULL,"bgt",TmpRegName(first->reg),TmpRegName(second->reg), newLab));
      AppendSeq(code,GenInstr("#","sle",TmpRegName(newReg),TmpRegName(first->reg),TmpRegName(second->reg)));
      AppendSeq(code,GenInstr("#","beqz",TmpRegName(newReg) ,newLab, NULL));
    } break;
  }
  //free first and second regs?
  ReleaseTmpReg(second->reg);
  free(second);
  //free first and second?
  ReleaseTmpReg(first->reg);
  free(first);
  ret->code=code;
  ret->label=GenInstr(newLab,NULL,NULL,NULL,NULL);
  ret->type=AndType;
  return ret;
}

struct InstrSeq *
MakeWhile( struct CondResult * cond, struct InstrSeq * body){
  char * newLab = GenLabel();
  struct InstrSeq * code = GenInstr(newLab, NULL,NULL,NULL,NULL);
  AppendSeq(code,cond->code);
  AppendSeq(code,body);
  AppendSeq(code,GenInstr(NULL,"b",newLab,NULL,NULL));
  AppendSeq(code,cond->label);
  free(cond);
  return code;
}

struct InstrSeq *
MakeIf( struct CondResult * cond, struct InstrSeq * body1, enum IfTypes type, struct InstrSeq * body2){
    struct InstrSeq * code = cond->code;
    AppendSeq(code,body1);
    if(type==IfType) return AppendSeq(code,cond->label);
    char * newLab = GenLabel();
    AppendSeq(code,GenInstr(NULL,"b",newLab,NULL,NULL));
    AppendSeq(code,cond->label);
    AppendSeq(code,body2);
    AppendSeq(code,GenInstr(newLab,NULL,NULL,NULL,NULL));
    free(cond);
    return code;
}

struct ExprResult *
loadExprResult(char * k){
  struct SymEntry * idEntry = LookupName(IdentifierTable, k);
  if(!idEntry)return NULL; //TODO: post message
  struct Attr * attribute = GetAttr(idEntry);
  struct ExprResult * ret = malloc(sizeof(struct ExprResult *));
  int newReg = AvailTmpReg();
  struct InstrSeq * code=GenInstr(NULL,"lw",TmpRegName(newReg),attribute->reference,NULL);
  ret->code=code;
  ret->reg=newReg;
  if(attribute->typeDesc->declType==FuncType)return NULL; //TODO: Post message
  ret->baseType=attribute->typeDesc->primDesc;
  return ret;
}

struct ExprResult *
createExprResult(char * k, enum BaseTypes baseType){
  struct ExprResult * ret = malloc(sizeof(struct ExprResult *));
  int newReg = AvailTmpReg();
  ret->reg=newReg;
  ret->baseType=baseType;
  struct InstrSeq * code=GenInstr(NULL,"li",TmpRegName(newReg),k,NULL);
  ret->code=code;
  return ret;
}

struct InstrSeq *
genStoreWord(char * k, struct ExprResult * expr){
  struct SymEntry * idEntry = LookupName(IdentifierTable, k);
  if(!idEntry)return NULL; //TODO: post message
  struct Attr * attribute = GetAttr(idEntry);
  if(attribute->typeDesc->declType==FuncType)return NULL; //TODO: Post message
  if(attribute->typeDesc->primDesc!=expr->baseType)return NULL;//TODO: Post message
  struct InstrSeq * code=expr->code;
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(expr->reg),attribute->reference,NULL));
  ReleaseTmpReg(expr->reg);
  free(expr);
  //free regs and expr?
  return code;
}

struct ExprResult *
GetFunc(){
  struct ExprResult * ret = malloc(sizeof(struct ExprResult *));
  int newReg = AvailTmpReg();
  struct InstrSeq * code=GenInstr(NULL,"li","$v0","5",NULL);
  AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,"move",TmpRegName(newReg),"$v0",NULL));
  ReleaseTmpReg(newReg);
  ret->code=code;
  ret->reg=newReg;
  ret->baseType=IntBaseType;
  return ret;
}

struct InstrSeq *
PutFunc(char * k, enum BaseTypes type){
  int newReg = AvailTmpReg();
  struct InstrSeq * code;
  if(type==ChrBaseType){
    char c = k[1];
    int i= (int) c;
    if(c == '\\' && k[2]=='n')i=10;
    if(c == '\\' && k[2]=='t')i=11;
    char this[10];
    sprintf(this, "%d", i);
    code=GenInstr(NULL,"li",TmpRegName(newReg),this,NULL);
    AppendSeq(code,GenInstr(NULL,"li","$v0","11",NULL));
    AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(newReg),NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  }else if(type==IntBaseType){
    struct SymEntry * idEntry = LookupName(IdentifierTable, k);
    if(!idEntry)return NULL; //TODO: post message
    struct Attr * attribute = GetAttr(idEntry);
    code=GenInstr(NULL,"lw",TmpRegName(newReg),attribute->reference,NULL);
    AppendSeq(code,GenInstr(NULL,"li","$v0","1",NULL));
    AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(newReg),NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  }else if(type==StringBaseType){
    struct SymEntry * idEntry = LookupName(StringLiteralTable, k);
    struct StrAttr * attribute;
    if(!idEntry){
      idEntry=EnterName(StringLiteralTable, k);
      attribute = malloc(sizeof(struct StrAttr *));
      attribute->label=GenLabel();
      SetAttr(idEntry, STRING_KIND, attribute);
    }else{
      attribute = GetAttr(idEntry);
    }
    code = GenInstr(NULL,"li","$v0","4",NULL);
    AppendSeq(code,GenInstr(NULL,"la","$a0",attribute->label,NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
  }
  ReleaseTmpReg(newReg);
  return code;
}

struct InstrSeq *
IncDec(char * k, enum BaseTypes baseType){
  struct SymEntry * idEntry = LookupName(IdentifierTable, k);
  if(!idEntry)return NULL; //TODO: post message
  struct Attr * attribute = GetAttr(idEntry);
  int newReg = AvailTmpReg();
  struct InstrSeq * code=GenInstr(NULL,"lw",TmpRegName(newReg),attribute->reference,NULL);
  char * immed;
  if(baseType==PlusType) immed="1";
  if(baseType==MinusType) immed="-1";
  AppendSeq(code,GenInstr(NULL,"addi",TmpRegName(newReg),TmpRegName(newReg),immed));
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(newReg),attribute->reference,NULL));
  ReleaseTmpReg(newReg);
  return code;
}
