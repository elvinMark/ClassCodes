#include "Queue.h"

int main(){
  QUEUEenqueue(2);
  QUEUEenqueue(8);
  QUEUEenqueue(1);
  QUEUEenqueue(5);
  while(!QUEUEempty())
    printf("%d\n",QUEUEdequeue());
}
