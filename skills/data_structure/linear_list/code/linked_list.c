#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;


#define LIST_INIT_SIZE  10
#define LIST_INCREMENT 2

typedef struct LNode
{
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;

Status InitList(LinkList l)
{
  l = (LNode *)malloc(sizeof(LNode));
  if(!l) {
    exit(OVERFLOW);
  }
  l->next = NULL;
  return OK;
}

void DestoryList(LinkList l)
{
  LNode *p;
  while(l!=NULL) {
    p = l;
    l = l->next;
    free(p);
  }

  
}
int main()
{
}
