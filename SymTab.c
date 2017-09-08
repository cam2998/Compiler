#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "SymTab.h"

struct SymTab *
CreateSymTab(int size, char * scopeName, struct SymTab * parentTable) {
}

struct SymTab *
DestroySymTab(struct SymTab *aTable) {
}

int
HashName(int size, const char *name) {
}

struct SymEntry *
FindHashedName(struct SymTab *aTable, int hashValue, const char *name) {
}

struct SymEntry *
LookupName(struct SymTab *aTable, const char * name) {
}

struct SymEntry *
EnterName(struct SymTab *aTable, const char *name) {
}

int
GetAttrKind(struct SymEntry *anEntry) {
}

void
SetAttr(struct SymEntry *anEntry, int kind, void *attributes) {
}

void *
GetAttr(struct SymEntry *anEntry) {
}

const char *
GetName(struct SymEntry *anEntry) {
}

struct SymTab *
GetTable(struct SymEntry *anEntry) {
}

const char *
GetScopeName(struct SymTab *aTable) {
}

char *
GetScope(struct SymTab *aTable) {
}

struct SymTab *
GetParentTable(struct SymTab *aTable) {
}

void
DoForEntries(struct SymTab *aTable, bool includeParentTable,
             void (*entryFunc)(struct SymEntry * entry, int cnt, void * args),
             int startCnt, void * withArgs) {
}

struct Stats *
Statistics(struct SymTab *aTable) {
}
