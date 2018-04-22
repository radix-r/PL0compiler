#include "lexical.h"

#include <stdio.h>

#define MAX_SYMBOL_TABLE_SIZE 1000




typedef struct symbol{
  int atribute;// const = 1, var = 2, proc = 3
  char name[12]; // name up to 11 chars
  int val; // number (ASCII value)
  int level; // L level
  int addr; // M address
} symbol;


// signitures
int block(node * current);
void error(int eCode);
int enter(symbol newSym);
int expression(node *current);
node * getNextLex(node * current);
int parse(node * lexTable);
int statement(node *current);
