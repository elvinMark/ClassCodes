#include "Item.h"
#include "Stack.h"

static Item* stack;
static int N;
static int pos;

void STACKinit(int maxN){
  N = maxN;
  pos = 0;
  stack = malloc(N*sizeof(*stack));
}
int STACKempty(){
  return pos==0;
}
void STACKpush(Item data){
  if(pos>=N-1)
    return;
  stack[pos++] = data;
}
Item STACKpop(){
  Item elem;
  elem = stack[--pos];
  return elem;
}
