#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IOMngr.h"

#define LISTINGMARGIN 6

FILE *sourceFile, *listingFile;
char buffer[MAXLINE];
int bufLen, nextPos;
int curLine;
bool needDisplay;

#define MAX_MESSAGES 26
char * indicatorLine;
char * messages[MAX_MESSAGES];
int messageCnt;

//done
bool
OpenFiles(const char * aSourceName,const char * aListingName){
  sourceFile = fopen(aSourceName,"r");
  listingFile = fopen(aListingName,"w");
  nextPos=0;
  curLine=1;
  if(sourceFile==NULL) return false;
  fgets(buffer,MAXLINE,sourceFile);
  bufLen=strlen(buffer);
  if(listingFile==NULL)needDisplay=true;  else needDisplay=false;
  return true;
}

//done
void
CloseFiles() {
  if(sourceFile!=NULL) fclose(sourceFile);
  if(listingFile!=NULL) fclose(listingFile);
}

char
GetSourceChar() {
  char c;
  if(nextPos==bufLen){
    if(fgets(buffer, MAXLINE, sourceFile)==NULL)return EOF;
    bufLen=strlen(buffer);
    nextPos=1;
    curLine+=1;
  }else{
    c=buffer[nextPos];
    nextPos+=1;
    return c;
  }
}

void
PostMessage(int aColumn, int aLength, const char * aMessage) {
  if(true){ //needDisplay
    printf("%i: %s      %i \n",aColumn ,buffer, aLength );
    printf("%s\n",aMessage );
  }else{
    fprintf(listingFile,"%i: %s \n",aColumn ,buffer );
    fprintf(listingFile, "%s\n",aMessage );
    /*fprintf(listingFile, "\n%s",buffer );
    fprintf(listingFile, "%i-",bufLen );
    fprintf(listingFile, "%i-",nextPos);
    fprintf(listingFile, "%c\n",buffer[nextPos]);*/
  }
}

//done
int
GetCurrentLine() {
  return curLine;
}

//check later
int
GetCurrentColumn() {
  return nextPos-1;
}
