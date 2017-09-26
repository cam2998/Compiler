#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "SymTab.h"

//done
struct SymTab *
CreateSymTab(int size, char * scopeName, struct SymTab * parentTable) {
  struct SymTab * table=malloc(sizeof(struct SymTab));
  table->size=size;
  if(scopeName!=NULL)
  table->scopeName=strdup(scopeName);
  table->parent=parentTable;
  table->contents=malloc(sizeof(struct SymEntry *)*size);
  return table;
}

//done
int
HashName(int size, const char *name) {
  if(size==0) return -1;
  int i;
  int value=0;
  for(i=0;i<strlen(name);i++){
    value=value+name[i];
  }
  return value%size;
}

//done
struct SymEntry *
FindHashedName(struct SymTab *aTable, int hashValue, const char *name) {
  struct SymEntry * entry=malloc(sizeof(struct SymEntry ));
  if(aTable->contents[hashValue]==NULL){
    return NULL;
  }
  entry=aTable->contents[hashValue];
  int match = 0;
  if(entry==NULL)return NULL;
  if(strcmp(entry->name,name)==0) {
    match=1;
  }
  while(match==0&&entry->next!=NULL){
    entry=entry->next;
    if(strcmp(entry->name,name)==0){
      match=1;
    }
  }
  if(match==0){
    return entry->next;
  }
  return entry;
}

//done
struct SymEntry *
LookupName(struct SymTab *aTable, const char * name) {
  if(aTable==NULL||name==NULL)return NULL;
  struct SymEntry * entry=FindHashedName(aTable,HashName(aTable->size,name),name);
  if(entry==NULL){
    return NULL;
  }
  return entry;
}

//done
struct SymEntry *
EnterName(struct SymTab *aTable, const char *name) {
  struct SymEntry * newEntry=malloc(sizeof(struct SymEntry ));
  struct SymEntry * result=malloc(sizeof(struct SymEntry ));
  result = LookupName(aTable,name);
  if(result==NULL){
    if(name==NULL){
      newEntry->name=NULL;
    }else{
      newEntry->name=strdup(name);
    }
    newEntry->next=aTable->contents[HashName(aTable->size,name)];
    newEntry->table=aTable;
    result=newEntry;
    aTable->contents[HashName(aTable->size,name)]=result;
  }
  return result;
}

//done
int
GetAttrKind(struct SymEntry *anEntry) {
  return anEntry->attrKind;
}

//done
void
SetAttr(struct SymEntry *anEntry, int kind, void *attributes) {
  if(kind!=NULL){
    anEntry->attrKind = kind;
  }else{
    anEntry->attrKind=-1;
  }
  if(attributes!=NULL){
    anEntry->attributes = attributes;
  }else{
    anEntry->attributes = NULL;
  }
}

//done
void *
GetAttr(struct SymEntry *anEntry) {
  if(anEntry==NULL) return NULL;
  if(anEntry->attributes==NULL) return NULL;
  return anEntry->attributes;
  //return NULL;
}

//done
const char *
GetName(struct SymEntry *anEntry) {
  if(anEntry==NULL||anEntry->name==NULL)return NULL;
  return anEntry->name;
}

//done
struct SymTab *
GetTable(struct SymEntry *anEntry) {
  if(anEntry==NULL) return NULL;
  if(anEntry->table==NULL)return NULL;
  return anEntry->table;
}

//done
const char *
GetScopeName(struct SymTab *aTable) {
  if(aTable==NULL)return NULL;
  if(aTable->scopeName==NULL)return NULL;
  return aTable->scopeName;
}

//done
char *
GetScope(struct SymTab *aTable) {
  char * scope=strdup(GetScopeName(aTable));
  if(scope==NULL)return NULL;
  aTable=aTable->parent;
  while(aTable!=NULL){
    //printf("%s\n",aTable->scopeName );
    char * result=malloc(strlen(scope)+strlen(GetScopeName(aTable))+5);

    strcpy(result,GetScopeName(aTable));
    strcat(result,">");
    strcat(result,scope);

    scope=strdup(result);
    aTable=aTable->parent;
    free(result);
  }
  return scope;
}

//done
struct SymTab *
GetParentTable(struct SymTab *aTable) {
  return aTable->parent;
}

//done
struct SymTab *
DestroySymTab(struct SymTab *aTable) {
  struct SymTab * table=malloc(sizeof(struct SymTab));
  if(aTable==NULL)return NULL;
  if(aTable->parent!=NULL){
    table=aTable->parent;
  }else{
    table=NULL;
  }
  aTable->size=0;
  if(aTable->scopeName!=NULL) free(aTable->scopeName);
  free(aTable->contents);
  free(aTable);
  return table;
}

//done
void
DoForEntries(struct SymTab *aTable, bool includeParentTable,void (*entryFunc)(struct SymEntry * entry, int cnt, void * args), int startCnt, void * withArgs) {
  //printf("Going through entries \n");
  struct SymEntry * next=malloc(sizeof(struct SymEntry *));
  int i;
  struct SymEntry * head;
  while(aTable!=NULL){
    for(i=0;i<aTable->size;i++){
      head=aTable->contents[i];
      while(head!=NULL){
        next=head->next;
        entryFunc(head,startCnt,withArgs);
        startCnt+=1;
        head=next;
      }

    //printf("%i\n",i );
    }
    if(includeParentTable) aTable=aTable->parent; else return;
  }
}

//done
struct Stats *
Statistics(struct SymTab *aTable) {
  int avgL=0;
  int maxL=0;
  int minL=INT_MAX;
  int eCnt=0;
  struct Stats *sta=malloc(sizeof(struct Stats*));
  int i;
  struct SymEntry * head;
  for(i=0;i<aTable->size;i++){
    int chainLen=0;
    head=aTable->contents[i];
    while(head!=NULL){
      chainLen++;
      head=head->next;
    }
    if(chainLen<minL) minL=chainLen;
    if(chainLen>maxL) maxL=chainLen;
    eCnt=eCnt+chainLen;
  }
  avgL=eCnt/aTable->size;
  sta->minLen=minL;
  sta->maxLen=maxL;
  sta->avgLen=avgL;
  sta->entryCnt=eCnt;
  return sta;
}
