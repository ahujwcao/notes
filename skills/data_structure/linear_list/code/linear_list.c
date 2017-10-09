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

typedef struct
{
    ElemType *elem;
    int length;
    int list_size;
}SqList;

Status InitList(SqList *l)
{
    l->elem = (ElemType *)malloc(sizeof(int)*LIST_INIT_SIZE);
    if (!l->elem) {
      exit(OVERFLOW);
    }
    l->length = 0;
    l->list_size = LIST_INIT_SIZE;
    return OK;
}

Status DestoryList(SqList *l)
{
  free(l->elem);
  l->elem = NULL;
  return OK;
}

Status ListInsert(SqList *l, int i, ElemType e)
{
  if (i<1||i>l->length+1) {
    return ERROR;
  }
  if (l->length>=l->list_size) {
    ElemType *newbase = (ElemType *) realloc(l->elem, l->list_size+LIST_INCREMENT*sizeof(ElemType));
    if (!newbase) {
      exist(OVERFLOW);
    }
    l->elem = newbase;
    l->list_size += LIST_INCREMENT;
  }
  ElemType *end = l->elem + l->length;
  ElemType *start = l->elem + i - 1;
  for(ElemType *p = end; p>start;p--) {
    *p = *(p-1);
  }
  *start = e;
  l->length++;
  return OK;
}

Status ListDelete(SqList *l, int i, ElemType *e)
{
  if (i<1||i>l->length) {
    return ERROR;
  }
  ElemType *start = l->elem + i - 1;
  ElemType *end = l->elem + l->length - 1;
  *e = *start;
  for(ElemType *p = start;p<end;p++) {
    *p = *(p+1);
  }
  --l->length;
}


Status ListTraverse(SqList *l, void (*vist)(ElemType *e))
{

}

Status ListEmpty(SqList *l)
{
  if (l->length==0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

Status ClearList(SqList *l)
{
  l->length = 0;
}

int ListLength(SqList *l)
{
  return l->length;
}


int main()
{

}