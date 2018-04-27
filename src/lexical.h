#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TOKEN_LEN 20
#define MAX_NUM_LEN  11// number can have a most 11 digits, includs potental "-"
#define MAX_IDENTIFIER_LEN 11



typedef struct token{
  char text[MAX_TOKEN_LEN];
  int atribute;
  int line;
}token;

typedef struct node{
  struct node *prev;
  struct node *next;
  token token;
}node;

// signitures
void chopFront(char *src,int len, int n);
void destroyLL(node *head);
node * dequeue(node *head, node* tail);
void enqueue(node *ll, node *tail, token t);
char * fileNameToStr(char *fName);
int getToken(char ** codePtr, token *ret);
void initLL(node ** inHead, node ** inTail);
int isEmpty(node * llHead);
node * makeLexTable(char ** codePtr);
void printLexTable(node * head);
void printLexList(node * head);
int runLex(char *progName);
