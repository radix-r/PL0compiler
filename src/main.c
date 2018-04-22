/***/

#include "codes.h"
//#include "lexical.h"
#include "parser.h"
#include <stdio.h>

// global error node
token errorToke;
node errorNode;

// where errors are stored. global so I dont have to pass it where it is not needed
FILE* errorFile;

// for testing
int main(int argc, char** argv){

  if(argc != 2){
    printf("Usage: ./parse <PM0 source file>\n" );
    return ERROR;
  }

  errorFile = fopen("errors.txt", "w");
  if(!errorFile){
    printf("Failed to open errors.txt");
    return ERROR;
  }
  // get lexem list
  char * code = fileNameToStr(argv[1]);

  if(code == NULL){
    printf("Failed to read file\n");
    return ERROR;
  }

  // init the error node
  strcpy(errorToke.text,"");
  errorToke.atribute = -1;
  errorNode.token = errorToke;
  errorNode.next = NULL;
  errorNode.prev = NULL;

  //printf("%s", code);

  node * lexTable = NULL;
  lexTable = makeLexTable(&code);

  parse(lexTable);

}
