#include "Item.h"
#include "Stack.h"

int main(){
  STACKinit(5);
  STACKpush(1);
  STACKpush(6);
  STACKpush(3);
  STACKpush(7);
  Item a;
  while(!STACKempty()){
    a = STACKpop();
    printf("%d\n",a);
  }
  return 0;
}
