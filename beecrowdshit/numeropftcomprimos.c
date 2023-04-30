#include <stdio.h>
#include <math.h>
int primo (int x);


int main (){

    int tamanho, iteracoes=0, termo, p=2;
    long long int pft;
    scanf("%d", &tamanho);
    
    while (iteracoes < tamanho){
        termo = pow(2, p) - 1;
        pft = termo*(pow(2, p-1));
            if (primo(termo) == 1) {
                printf("%lld\n", pft);
                iteracoes++;
            }
            p++;
      }
    return 0;
    }
int primo(int x){
    int i=2, verificarprimo=0;
    if (x < 2){
      verificarprimo += 1;
    }
        while (i<x){
          if (x % i == 0){
              verificarprimo += 1;
          }
          i++;
          }

          if (verificarprimo == 0) {
              return 1;
          }
          else{
              return 0;
          }
    return 0;
  }
