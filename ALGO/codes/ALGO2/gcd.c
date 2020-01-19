#include <stdio.h>

int gcd_iterative(int a,int b){
    int a0,b0,r;
    a0 = a;
    b0 = b;
    r = a%b;
    while(r != 0){
        a0 = b0;
	b0 = r;
        r = a0%b0;
    }
    return b0;
}

int gcd_recursive(int a,int b){
    if(b==0)
        return a;
    return gcd_recursive(b,a%b);
}

int main(){
  printf("%d\n",gcd_iterative(100,30));
  printf("%d\n",gcd_recursive(100,30));
  return 0;
}

