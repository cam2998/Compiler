/* Semantics.h
 The action and supporting routines for performing semantics processing.
 */

#include "SymTab.h"
#include "IOMngr.h"
#include "Scanner.h"
#include "YCodeGen.h"
#include <string.h>

// Declaration of semantic record data types used in grammar.y %union
struct IdList {
  struct SymEntry * entry;
  struct IdList * next;
};
enum IfTypes {IfType, IfElseType };
enum BaseTypes { IntBaseType, ChrBaseType, StringBaseType, PlusType, MinusType, TimesType, DivideType, LessThanType, GreaterThanType, EqualType, NotEqualType, GreaterThanOrEqualType, LessThanOrEqualType};

struct FuncDesc {
  enum BaseTypes returnType;
  struct InstrSeq * funcCode;
};

enum DeclTypes { PrimType, FuncType };
struct TypeDesc {
  enum DeclTypes declType;
  union {
    enum BaseTypes primDesc;
    struct FuncDesc * funcDesc;
  };
};

struct CondResult {
  struct InstrSeq * code;
  char * label;
};

struct ExprResult {
  struct InstrSeq * code;
  int reg;
  enum BaseTypes baseType;
};

// Symbol Table Structures
struct Attr {
  struct TypeDesc * typeDesc;
  char * reference;
};

struct StrAttr {
  char * label;
};

// Supporting Routines

void InitSemantics();
void ListIdentifierTable();

struct TypeDesc * MakePrimDesc(enum BaseTypes type);
struct TypeDesc * MakeFuncDesc(enum BaseTypes returnType);

// Semantics Actions
struct CondResult *     ConcatenateCond(struct ExprResult * first, enum BaseTypes baseType, struct ExprResult * second);
struct ExprResult *     Concatenate(struct ExprResult * first, enum BaseTypes baseType, struct ExprResult * second);
struct ExprResult *     createExprResult(char * k, enum BaseTypes baseType);
struct ExprResult *     loadExprResult(char * k);
struct InstrSeq *       genStoreWord(char * k, struct ExprResult * expr);
struct ExprResult *     GetFunc();
struct InstrSeq *       PutFunc(char * k, enum BaseTypes baseType);
struct InstrSeq *       MakeWhile( struct CondResult * cond, struct InstrSeq * body);
struct InstrSeq *       MakeIf( struct CondResult * cond, struct InstrSeq * body1, enum IfTypes type, struct InstrSeq * body2);
struct InstrSeq *       IncDec(char * k, enum BaseTypes baseType);

void                    Finish();

void                    ProcDecls(struct IdList * idList, enum BaseTypes baseType);
struct IdList *         AppendIdList(struct IdList * item, struct IdList * list);
struct IdList *         ProcName(char * id, enum DeclTypes type);
void                    ProcFunc(char * id, struct InstrSeq * instrs);
