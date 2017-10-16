/* Author: Cameron Trim
  Created: 9/26/17
  Resources: https://stackoverflow.com/questions/308695/how-do-i-concatenate-const-literal-strings-in-c
  https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
  https://www.cprogramming.com/tutorial/cfileio.html
  https://stackoverflow.com/questions/10279718/append-char-to-string-in-c
*/
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
char symbol = 'A';
int lastPos;

struct postMessageInfo
{
    int columnPosition;
    char messageChar;
    char *message;
};

struct postMessageInfo messageArray[ MAX_MESSAGES ];

//done
bool
OpenFiles(const char * aSourceName,const char * aListingName){
  sourceFile = fopen(aSourceName,"r");
  listingFile = fopen(aListingName,"w");
  if(sourceFile==NULL) return false;
  nextPos=0;
  curLine=1;
  lastPos=0;
  fgets(buffer,MAXLINE,sourceFile);
  bufLen=strlen(buffer);
  indicatorLine=malloc(strlen(buffer));
  messageCnt=0;
  if(listingFile==NULL)needDisplay=true;  else needDisplay=false;
  return true;
}

//done
void
CloseFiles() {
  int i=0;
  if(needDisplay){
    printf("       %s\n",indicatorLine);
    while(messages[i]!=NULL && i<messageCnt){
      printf("    -%c %s\n", symbol+i, messages[i]);
      i++;
    }
  }else{
    fprintf(listingFile,"       %s\n",indicatorLine);
    while(messages[i]!=NULL && i<messageCnt){
      fprintf(listingFile,"    -%c %s\n", symbol+i, messages[i]);
      i++;
    }
  }
  if(sourceFile!=NULL) fclose(sourceFile);
  if(listingFile!=NULL) fclose(listingFile);
}

char
GetSourceChar() {
  char c;
 if(nextPos>bufLen){
   if(fgets(buffer, MAXLINE, sourceFile)==NULL){
     return EOF;
   }
   bufLen=strlen(buffer);
   nextPos=0;
   lastPos=0;
   curLine+=1;
   messageCnt=0;
 }

   c=buffer[nextPos];
   nextPos+=1;
   return c;
}

void
PostMessage(int aColumn, int aLength, const char * aMessage) {

  char * line = malloc(aLength);
  int cmp=strcmp(aMessage, "EOF found");
  if(aColumn<strlen(buffer)||cmp==0){
    char sym= 'A'+messageCnt;
    char cToStr[2];
    cToStr[1]='\0';
    cToStr[0]=sym;
    if(cmp!=0){
    while(lastPos!=aColumn&&lastPos<aColumn){
      strcat(indicatorLine, " ");
      lastPos++;
    }
      strcat(indicatorLine, cToStr);
      for(int i=1; i<aLength;i++){
        strcat(indicatorLine, "-");
      }
    }
    if(cmp==0){
      strcat(indicatorLine,cToStr);
    }
    messages[messageCnt]=strdup(aMessage);
    messageCnt++;
    lastPos=aColumn+aLength;

  }else{
    if(needDisplay){
      printf("    %i: %s",GetCurrentLine(), buffer );
      printf("      %s\n", indicatorLine );
      int i=0;
      while(messages[i]!=NULL && i<messageCnt){
        printf("    -%c %s\n", symbol+i, messages[i]);
        i++;
      }
    }else{
      fprintf(listingFile,"    %i: %s",GetCurrentLine(), buffer );
      fprintf(listingFile,"      %s\n", indicatorLine );
      int i=0;
      while(messages[i]!=NULL && i<messageCnt){
        fprintf(listingFile,"    -%c %s\n", symbol+i, messages[i]);
        i++;
      }
    }
    if(*indicatorLine) free(indicatorLine);
    indicatorLine=malloc(strlen(buffer)*sizeof(char));
    messageCnt=0;
    //printf("%i: %s      %i \n",aColumn ,buffer, aLength );
    //printf("Message: %s\n",aMessage );
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
  return nextPos;
}
