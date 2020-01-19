#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *data;
int *aux;
int N;

void init_array(int n);
void print_array();
void selection_sort();
void insertion_sort();
void bubble_sort();
void shell_sort();
void quick_sort(int l,int r);
void merge_sort(int l,int r);

int main(int argc,char** args){
  if(argc < 3)
    return -1;
  init_array(atoi(args[1]));
  print_array();
  switch(atoi(args[2])){
  case 1:
    printf("Using selection sort\n");
    selection_sort();
    break;
  case 2:
    printf("Using insertion sort\n");
    insertion_sort();
    break;
  case 3:
    printf("Using bubble sort\n");
    bubble_sort();
    break;
  case 4:
    printf("Using quick sort\n");
    quick_sort(0,N-1);
    break;
  case 5:
    printf("Using merge sort\n");
    merge_sort(0,N-1);
    break;
  case 6:
    printf("Using shell sort\n");
    shell_sort();
    break;
  }  
  print_array();
  return 0;
}

void init_array(int n){
  int i;
  N = n;
  data = malloc(sizeof(*data)*n);
  aux = malloc(sizeof(*data)*n);
  srand(time(NULL));
  for(i = 0;i<N;i++)
    data[i] = rand()%N;
}
void print_array(){
  int i;
  for(i = 0;i<N;i++)
    printf("%d ",data[i]);
  printf("\n");
}
void selection_sort(){
  int i,j,min,tmp;
  for(i=0;i<N;i++){
    min = i;
    for(j=i+1;j<N;j++){
      if(data[j]<data[min])
	min = j;
    }
    tmp = data[i];
    data[i] = data[min];
    data[min] = tmp;
  }
}
void insertion_sort(){
  int i,j,tmp;
  for(i = 1;i<N;i++){
    for(j=i-1;j>=0;j--){
      if(data[j+1]>data[j])
	break;
      tmp = data[j];
      data[j] = data[j+1];
      data[j+1] = tmp;
    }
  }
}
void bubble_sort(){
  int i,j,tmp;
  for(i=N-1;i>=0;i--){
    for(j=0;j<i;j++){
      if(data[j]>data[j+1]){
	tmp =data[j];
	data[j] = data[j+1];
	data[j+1] = tmp;
      }
    }
  }
}
void shell_sort();
void quick_sort(int l,int r){
  if(l>=r)
    return;
  int tmp,left,right,pivot;
  pivot = l;
  left = l+1;
  right = r;
  while(right>left){
    while(data[left]<=data[pivot]){
      if(left == right)
	break;
      left++;
    }
    while(data[right]>data[pivot]){
      if(left == right)
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
void merge_sort(int l,int r){
  if(l==r)
    return;
  int m;
  int i;
  int left,right;
  m = (l+r)/2;
  merge_sort(l,m);
  merge_sort(m+1,r);
  left = l;
  right = m+1;
  for(i = l;i<=r;i++){
    if(right>r)
      aux[i] = data[left++];
    else if(left>m)
      aux[i] = data[right++];
    else if(data[left]<=data[right])
      aux[i] = data[left++];
    else if(data[right]<data[left])
      aux[i] = data[right++];
  }
  
  for(i = l;i<=r;i++)
    data[i] = aux[i];
}

void shell_sort(){
  int h;
  int i,j,k,tmp,min;
  for(h = N/2;h>=1;h/=2){
    //This 2 fors is for the insertion method along the gapped lists.
    for(i=h;i<N;i++){
      tmp = data[i];
      for(j=i;j>=h && data[j-h]>tmp;j-=h)
	data[j] = data[j-h];
      data[j] = tmp;
    }
  }
}
