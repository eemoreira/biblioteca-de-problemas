#include <stdio.h>
#include <stdlib.h>
int primo( int x);

int main(){

    int *v, i;

    v = malloc(sizeof(int)*10);

        for(i=0;i<10;i++){
            scanf("%d", &v[i]);
        }
        for(i=0;i<10;i++){
            if (primo(v[i]) == 1){
                printf("Posicao %d: %d\n", i, v[i]);
            }
        }
    free(v);
    
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