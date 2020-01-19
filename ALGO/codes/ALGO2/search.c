#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *data;
int N;
int count;

void init_array(int length);
void print_array();
int linear_search(int x);
int binary_search(int x);
void quick_sort(int l,int r);

int main(int argc,char** args){
  int index;
  int look;
  init_array(atoi(args[1]));
  print_array();
  quick_sort(0,N-1);
  print_array();
  look = N/2;
  printf("Looking for: %d\n",look);
  count = 0;
  index = linear_search(look);
  printf("Count Linear Search: %d\n",count);
  count = 0;
  index = binary_search(look);
  printf("Count Binary Search: %d\n",count);
  if (index>=0)
    printf("%d\n",index);
  else
    printf("Not found\n");
  return 0;
}

void init_array(int length){
  N = length;
  data = (int*)malloc(N * (sizeof *data));
  srand(time(NULL));
  for(int i = 0;i<N;i++)
    data[i] = rand()%N;
}

void print_array(){
  int i;
  for(i=0;i<N;i++)
    printf("%d ",data[i]);
  printf("\n");
}

int linear_search(int x){
  int i;
  for(int i = 0;i<N;i++){
    count++;
    if(data[i] == x)
      return i;
  }
  return -1;
}

int binary_search(int x){
  int a,b,m;
  a = 0;
  b = N-1;
  while(a<=b){
    count++;
    m = (a+b)/2;
    if(x < data[m])
      b = m-1;
    else if(x>data[m])
      a = m+1;
    else
      break;
  }
  return x==data[m]?m:-1;
}

void quick_sort(int l,int r){
  if(r<=l)
    return;
  int pivot,left,right,tmp;
  left = l+1;
  right = r;
  pivot = l;
  while(right>left){
    while(data[left]<=data[pivot]){
      if(left==right)
	break;
      left++;
    }
    while(data[right]>data[pivot]){
      if(left==right)
	break;
      right--;
    }
    tmp = data[left];
    data[left] = data[right];
    data[right] = tmp;
  }
  if(data[left]<=data[pivot]){
    tmp = data[pivot];
    data[pivot] = data[left];
    data[left] = tmp;
    pivot = left;
  }
  else{
    tmp = data[pivot];
    data[pivot] = data[left-1];
    data[left-1] = tmp;
    pivot = left-1;
  }
  quick_sort(l,pivot-1);
  quick_sort(pivot+1,r);
}
