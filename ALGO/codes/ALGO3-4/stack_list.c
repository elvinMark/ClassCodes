#include "Item.h"
#include "Stack.h"

static link head;

link NEW(Item data,link n){
  link newt;
  newt = malloc(sizeof(*newt));
  newt->data = data;
  newt->next = n;
  return newt;
}
void STACKinit(int maxN){
  head = NULL;
}
int STACKempty(){
  return head == NULL;
}
void STACKpush(Item data){
  head =  NEW(data,head);
}
Item STACKpop(){
  Item elem;
  link nextn;
  elem = head->data;
  nextn = head;
  head = head->next;
  free(nextn);
  return elem;
}
