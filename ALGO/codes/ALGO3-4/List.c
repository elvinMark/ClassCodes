#include "List.h"

link NEW(Item data,link n){
  link newl;
  newl = malloc(sizeof(*newl));
  newl->data = data;
  newl->next = n;
}
void insertNext(link t,link x){
  if(t->next != NULL){
    x->next = t->next;
    t->next = x;
  }
  else{
    t->next = x;
  }
}
link deleteNext(link t){
  link tmp;
  tmp = t->next;
  if(tmp != NULL)
    t->next = tmp->next;
  return tmp;
}
void printList(link h){
  link tmp;
  for(tmp = h;tmp!=NULL;tmp=tmp->next)
    printf("%d ",tmp->data);
  printf("\n");
}
