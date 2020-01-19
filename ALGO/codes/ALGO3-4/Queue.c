#include "Queue.h"

int QUEUEempty(){
  return head==NULL;
}

void QUEUEenqueue(Item item){
  if(head == NULL){
    head = NEW(item,NULL);
    tail = head;
  }
  else{
    link t = NEW(item,NULL);
    tail->next = t;
    tail = t;
  }
}

Item QUEUEdequeue(){
  Item elem;
  link t;
  t = head;
  elem = head->data;
  head = head->next;
  free(t);
  return elem;
}

