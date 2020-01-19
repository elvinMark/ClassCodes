#include "List.h"

int main(){
  link h = NEW(-999,NULL);
  for(int i =0;i<10;i++){
    insertNext(h,NEW(i,NULL));
  }
  printList(h);
  return 0;
}
