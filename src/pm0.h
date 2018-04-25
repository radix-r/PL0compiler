
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct instruction{
  int op; // opcode
  int r; // reg
  int l; // arguement L
  int m; // arguement M
}instruction;

// constants for getLine
#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2
#define MAX_LINE_LEN 30

// constants for the vm
#define CMD_LEN 4 // lenght of comands
#define NUM_OP 23 // the number of different instructions
#define NUM_PARAM 4 // number of peramiters in each instruction
#define NUMREG 8
#define MAX_CODE_LENGTH 500
#define MAX_LEXI_LEVLES 3
#define MAX_NUM_LEN  11// number can have a most 11 digits, includs potental "-"
#define MAX_STACK_HEIGHT 2000

// function declarations
int base(int, int, int*);
void execute(instruction ir, int *spPtr, int *bpPtr, int *pcPtr, int *lexPtr,
  int *haultPtr, int *stack, int *reg);
int getLine( char*, size_t, FILE*);
int fetch(int*, instruction*, int*,int, int*, instruction*);
FILE *fileStuff(char**);
void init(FILE *fid, instruction *code,int *codeLenPtr, int* bpPtr, instruction *irPtr, int *pcPtr, int *spPtr, int *lexPtr, int *reg, int *stack, char ops[NUM_OP][CMD_LEN]);
void printReg(int*);
void printStack(int , int , int* , int );
void printStackTrace(char [NUM_OP][CMD_LEN], int *, instruction , int , int , int , int );
//void printStrArray(char **, int);
void runVM(FILE *fid);
char ** tokenize(const char *);
