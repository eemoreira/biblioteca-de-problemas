#include <stdio.h>
#define T 1000

int main(){
  int i;
  float arr[T];
  for(i=0;i<T;i++){
    scanf("%f", &arr[i]);
   if(arr[i] == -1){
     break;
   } 
    scanf("%f", &arr[i+1]);
    if(arr[i] == arr[i+1]){
      printf("Quadrado\n");
      printf("Area:%.1f\n", arr[i] * arr[i+1]);
    }
    else{
      printf("Retangulo\n");
      printf("Area:%.1f\n", arr[i] * arr[i+1]);
    }
    i++
  }
  }