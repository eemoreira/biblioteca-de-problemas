#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define T 10
int main(){

    int i, v[T],n, menordif,pertence=0;
    
    scanf("%d", &n);

    for(i=0;i<T;i++){
        scanf("%d", &v[i]);
    }
    for(i=0;i<T;i++){
        if (n == v[i]){
          printf("%d\n", n);
          printf("Posicao %d",i);
          pertence = 1; // se eh igual ele so printa e bota pertence = 1
        }
    }
    if(pertence != 1){
        for(i=0;i<T;i++){
            v[i] = v[i] - n; // pra ver a distancia do numero na posicao i
        }
        menordif = abs(v[0]);
        for(i=0;i<T;i++){
            if (abs(v[i]) < menordif){
                menordif = abs(v[i]); // testando pra ver qual eh o menor modulo no vetor
              }
          }
          for(i=0;i<T;i++){
            if (abs(v[i]) == menordif){
            v[i] += n; // se o modulo do numero do vetor na posicao i for igual a menor diferença, soma o n pra pegar o numero original e printa 
            printf("Mais proximo %d posicao %d\n", v[i], i);
          }
            }
      }
  }