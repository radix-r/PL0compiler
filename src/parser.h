#include "lexical.h"
#include "pm0.h"
#include <stdio.h>

#define MAX_SYMBOL_TABLE_SIZE 1000


typedef struct symbol{
  int atribute;// const = 1, var = 2, proc = 3
  char name[12]; // name up to 11 chars
  int value; // number (ASCII value)
  int level; // L level
  int addr; // M address
}symbol;






// signitures
int block(node * current);
void error(int eCode, int line);
int enter(symbol newSym);
int expression(node *current);
int factor(node * current);
int find(char *ident);
void freeReg(int lexLevel);
void gen(int op, int reg, int l, int m);
node * getNextLex(node * current);
int getNextOpenReg();
int parse(node * lexTable);
void printSymbolTable();
int statement(node *current);
int symbolAddress(int index);
int symbolLevel(int index);
int symbolType(int index);
int term(node * current);
