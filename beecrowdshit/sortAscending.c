#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, *v, tamanho, store;

    scanf("%d", &tamanho);
    v = malloc(sizeof(int)*tamanho);
    if (v != NULL){
        for(i=0;i<tamanho;i++){
            scanf("%d", &v[i]);
        }
        for(i=0;i<tamanho;i++){
            for(j=i+1;j<tamanho;j++){
                if(v[i] > v[j]){
                    store = v[i];
                    v[i] = v[j];
                    v[j] = store; 

                }
            }
        }
        for(i=0;i<tamanho;i++){
            printf("%d, ", v[i]);
        }
    }
    else{
        printf("muito grande");
        return -1;
        
    }
    free(v);
    
}