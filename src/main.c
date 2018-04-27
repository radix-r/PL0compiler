/***/

#include "codes.h"
//#include "lexical.h"
#include "parser.h"
#include <stdio.h>

// global vars
symbol symbolTable[MAX_SYMBOL_TABLE_SIZE];
int symbolTableIndex = 0;

// global error node
token errorToke;
node errorNode;

// error flag
int errorFlag = 0;
// where intermidiate code from generated in parser will go
FILE* codeFile;

// where errors are stored. global so I dont have to
FILE* errorFile;

instruction aCode[MAX_CODE_LENGTH];
int aCodeIndex = 0;

// keeps track of open registers. 0 for open 1 for occupied
int regStatus [NUMREG];

// booleans for l, a, and v flags
int l =0;
int a=0;
int v = 0;

// for testing
int main(int argc, char** argv) {

  // init regStatus
  int i;
  for(i = 0; i < NUMREG; i++){
    regStatus[i] = 0;
  }

  char *fileName;
  if(argc < 2 || argc > 5){
    printf("Usage: ./compile <flags> <PM0 source file>\n" );
    return ERROR;
  }
  else{
    int i;
    for(i=1;i<argc;i++){
      if(strcmp(argv[i], "-l") == 0){
        l=1;
      }
      else if(strcmp(argv[i], "-a") == 0){
        a=1;
      }
      else if(strcmp(argv[i], "-v") == 0){
        v=1;
      }
      else {
        fileName = argv[i];
      }
    }
  }

  errorFile = fopen("errors.txt", "w");
  if(!errorFile){
    printf("Failed to open errors.txt");
    return ERROR;
  }

  codeFile = fopen("codeFile.txt", "w");
  if(!codeFile){
    printf("Failed to open codeFile.txt");
    return ERROR;
  }
  // get lexem list
  char * code = fileNameToStr(fileName);

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



  if (lexTable){
    if(l){
      printLexTable(lexTable);
      printf("\n");
    }
    parse(lexTable);
    destroyLL(lexTable);
  }

  fclose(errorFile);
  //debug
  //printSymbolTable();
  if (errorFlag){
    //print errorsfile
    return ERROR;
  }

  if (a){
    // print aCode
    printf("Printing assembly code\n" );
    printf("---------------------------\n" );
    int i;
    for(i = 0; i < aCodeIndex; i++){
      printf("%d %d %d %d\n", aCode[i].op, aCode[i].r, aCode[i].l, aCode[i].m);
    }
    printf("\n");
  }



  free(code);


  runVM(aCode, aCodeIndex, v);
  fclose(codeFile);
}
