#include <stdio.h>

int main (){

    int i=1, n=6, somadiv=0, tamanho, iteracoes=0;
    scanf("%d", &tamanho);

    while (iteracoes < tamanho){
      while (i<n){
        if (n%i == 0){
            somadiv += i;
        }
        i++;
        }
      if (somadiv == n){
        printf("%d\n",n);
        iteracoes++;
        i = 1;
        n++;
        somadiv = 0;
      }
      else{
        n++;
        i = 1;
        somadiv = 0;
      }
     
      }
      }
    

    