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
enum AttrKinds { VOID_KIND = -1, INT_KIND, STRING_KIND, STRUCT_KIND };

char * BaseTypeNames[2] = { "int", "chr"};
char * TypeNames[2] = { "", "func"};

// corresponds to enum Operators
char * Ops[] = { "add", "sub", "mul", "div"};
char * BoolOps[] = { "and", "or", "not" };

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

// Semantics Actions


void
Finish() {
  printf("Finish\n");
  ListIdentifierTable();

  struct InstrSeq * textCode = GenInstr(NULL,".text",NULL,NULL,NULL);
  struct InstrSeq * dataCode = GenInstr(NULL,".data",NULL,NULL,NULL);
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

  AppendSeq(textCode,GenInstr(NULL,"jal",mainAttr->reference,NULL,NULL));
  AppendSeq(textCode,GenInstr(NULL,"li","$v0","10",NULL));
  AppendSeq(textCode,GenInstr(NULL,"syscall",NULL,NULL,NULL));

  // put functions in code seq
  AppendSeq(textCode,mainAttr->typeDesc->funcDesc->funcCode);
  //mainAttr->typeDesc->funcDesc->funcCode
  // put globals in data seg
    int i;
    for(i=0;i<IdentifierTable->size;i++){
      struct SymEntry * head=IdentifierTable->contents[i];
      while(head){
        struct Attr * headAttr = (struct Attr *) GetAttr(head);
        int kind=GetAttrKind(head);
        if(kind==STRUCT_KIND){
          AppendSeq(textCode,headAttr->typeDesc->funcDesc->funcCode);
        }
        if(kind==INT_KIND){
          char * c = strdup(headAttr->reference);
          AppendSeq(dataCode,GenInstr(c,".word","0",NULL,NULL));
        }
        head=head->next;
      }
    }

  // combine and write
  struct InstrSeq * moduleCode = AppendSeq(textCode,dataCode);
  WriteSeq(moduleCode);

  // free code
  FreeSeq(moduleCode);
  CloseCodeGen();
  fprintf(stderr,"Finish \n");
}

void
ProcDecls(struct IdList * idList, enum BaseTypes baseType) {
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
        char *ref = malloc(strlen(idList->entry->name) + 3);
        strcat(ref, "_");
        strcat(ref, idList->entry->name);
        att->reference=strdup(ref);
        att->typeDesc=desc;
        SetAttr(idList->entry, INT_KIND , att);
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
  struct IdList * original = list;
  while (list->next) {
    list = list->next;
  }
  list->next=item;
  return original;
}

struct IdList *
ProcName(char * id, enum DeclTypes type) {
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
  // create, init and set attr struct
  struct Attr * attribute=malloc(sizeof(struct Attr));
  attribute->typeDesc=typeD;
  SetAttr(node->entry, type , attribute);
  return node;
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
  return ret;
}

struct CondResult *
ConcatenateCond(struct ExprResult * first, enum BaseTypes baseType, struct ExprResult * second){
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
  ret->label=strdup(newLab);
  return ret;
}

struct InstrSeq *
MakeWhile( struct CondResult * cond, struct InstrSeq * body){
  char * newLab = GenLabel();
  struct InstrSeq * code = GenInstr(newLab, NULL,NULL,NULL,NULL);
  AppendSeq(code,cond->code);
  AppendSeq(code,body);
  AppendSeq(code,GenInstr(NULL,"b",newLab,NULL,NULL));
  AppendSeq(code,GenInstr(cond->label,NULL,NULL,NULL,NULL));
  //free(cond);
  return code;
}

struct InstrSeq *
MakeIf( struct CondResult * cond, struct InstrSeq * body1, enum IfTypes type, struct InstrSeq * body2){
    struct InstrSeq * code = cond->code;
    AppendSeq(code,body1);
    if(type==IfType) return AppendSeq(code,GenInstr(cond->label,NULL,NULL,NULL,NULL));
    char * newLab = GenLabel();
    AppendSeq(code,GenInstr(NULL,"b",newLab,NULL,NULL));
    AppendSeq(code,GenInstr(cond->label,NULL,NULL,NULL,NULL));
    AppendSeq(code,body2);
    AppendSeq(code,GenInstr(newLab,NULL,NULL,NULL,NULL));
    //free(cond);
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
  struct InstrSeq * code=GenInstr(NULL,"li",TmpRegName(newReg),k,NULL);
  ret->code=code;
  ret->reg=newReg;
  ret->baseType=baseType;
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
  }
  ReleaseTmpReg(newReg);
  return code;
}
