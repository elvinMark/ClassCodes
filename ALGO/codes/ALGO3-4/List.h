#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct node{
  Item data;
  struct node* next;
}node;

typedef node* link;

link NEW(Item data,link n);
void insertNext(link t,link x);
link deleteNext(link t);
void printList(link h);
