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

#define MAX_MESSAGES 26

FILE *sourceFile, *listingFile;
char buffer[ MAXLINE ], otherBuffer[ MAXLINE ];
int bufLen, nextPos;
int curLine;
char * messages[ MAX_MESSAGES ];
char * indicatorLine;
int messageCnt;
char symbol='A';


struct message{
    int aColumn;
    int aLength;
    char symbol;
    char *aMessage;
};
struct message messA[ MAX_MESSAGES ];
void printOutput();

bool
OpenFiles(const char * aSourceName,const char * aListingName){
  sourceFile=fopen(aSourceName,"r");
  if(sourceFile==NULL) return false;

  if(aListingName==NULL){
    listingFile=stdout;
    return true;
  }
  listingFile=fopen(aListingName,"w");
  if(listingFile==NULL) return false;
  return true;
}

// Closes the files and makes sure all posted messages have been displayed
void CloseFiles(){
    fclose( sourceFile );
    printOutput();
    if( listingFile !=stdout ) fclose( listingFile );
}

char GetSourceChar(){
    if( !indicatorLine || *indicatorLine=='\0' ){
        if( curLine ) printOutput();else curLine=0;
        curLine++;
        nextPos=-1;
        indicatorLine=fgets( buffer, MAXLINE, sourceFile );
        if( !indicatorLine ){
            curLine=0;
            nextPos=0;
            buffer[0]='\0';
            return EOF;
        }
    }
    if( '\t'==*indicatorLine ) *indicatorLine=' ';
    nextPos++;
    return *indicatorLine++;
}

void printOutput()
{
    if( !listingFile || curLine>=0 ){
        fprintf( listingFile, "%i:  %s", curLine, buffer );
        int column=0;
        int endingPos=0;
        int pos=0;
        int symPos=symbol-'A';
        struct message *ptr=messA;
        int currentPos=indicatorLine - buffer;
        while( pos<symPos&&endingPos<currentPos){
          while(endingPos<ptr->aColumn){
            otherBuffer[endingPos]=' ';
            endingPos++;
          }
          otherBuffer[ptr->aColumn]=ptr->symbol;
          endingPos++;
          for(int i=0;i<ptr->aLength-1; i++){
            otherBuffer[endingPos]='-';
            endingPos++;
          }
            ptr++;
            pos++;
        }

        otherBuffer[ endingPos]='\0';
        if( symbol!='A' ){
            fprintf( listingFile, "    %s\n", otherBuffer );
        }

        ptr=messA;
        for( int i=0 ; i<symbol-'A'; i++){
                fprintf( listingFile, "    -%c %s\n", 'A'+i, ptr->aMessage );
                free( ptr -> aMessage );
                ptr++;
            }
    }
    symbol='A';
}

void PostMessage( int aColumn, int aLength, const char * aMessage ){
    if( symbol<='A'+25 && aColumn<=MAXLINE ){
        int i=symbol- 'A';
        messA[i].aColumn=aColumn;
        messA[i].aLength=aLength;
        messA[i].symbol=symbol;
        messA[i].aMessage=strdup( aMessage );
        symbol++;
    }
}

int GetCurrentLine(){
    return curLine;
}

int GetCurrentColumn(){
    return nextPos;
}
