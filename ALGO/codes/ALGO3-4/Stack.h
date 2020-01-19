#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  Item data;
  struct node* next;
}node;

typedef node* link;

link NEW(Item data,link n);
void STACKinit(int maxN);
int STACKempty();
void STACKpush(Item data);
Item STACKpop();
