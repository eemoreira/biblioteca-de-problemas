#include <stdio.h>
#include <stdlib.h>


int main(){

    int *v, t, n, n2, i=0, menor,posicaomenor;

    printf("\ndigite o tamanho: \n");
    scanf("%d", &t);
    v = malloc(sizeof(int)*t);

   if (v != NULL){

    printf("\ndigite os valores do vetor: \n");
    for(i=0;i<t;i++){
        scanf("%d", &v[i]);
    }

    printf("\ndigite o valor a ser adicionado \n");
    scanf("%d", &n);
    for(i=0;i<t;i++){
        v[i] += n;
    }
    printf("\nnovo vetor: \n");
     for(i=0;i<t;i++){
        printf("%d, ", v[i]);
        }

    printf("\ndigite um numero para ser somado a todos os indices pares de v \n");
    scanf("%d", &n2);
    for(i=0;i<t;i++){
        if (i % 2 == 0){
            v[i] += n2;
        }
    }
    printf("\nnovo vetor: \n");
     for(i=0;i<t;i++){
        printf("%d, ", v[i]);
        }

    printf("\nmenor numero: \n");
    menor = v[0];
    for(i=0;i<t;i++){
        if (v[i] < menor){
            menor = v[i];
            posicaomenor = i;
        }
    }
    printf("%d\n", menor);
    printf("\nna posicao: %d\n", posicaomenor);

    printf("\nbotando o menor valor do vetor em v[0]\n");
    printf("\nvetor antes da troca: \n");
    for(i=0;i<t;i++){
        printf("%d, ", v[i]);

    }
    for(i=0;i<t;i++){
        if (i == posicaomenor){
          v[posicaomenor] = v[0];
          v[0] = menor;  
        }
    }
    printf("\nvetor atualizado: \n");
    for(i=0;i<t;i++){
        printf("%d, ", v[i]);
    }
    printf("\nvalores impares do vetor: \n");
    for(i=0;i<t;i++){
        if (v[i] % 2 != 0){
            printf("%d ", v[i]);
        }
    }
    printf("\nvalores pares do vetor: \n");
    for(i=0;i<t;i++){
        if (v[i] % 2 == 0){
            printf("%d ", v[i]);
        }
    }
    printf("\nvalores positivos: \n");
    for(i=0;i<t;i++){
        if (v[i] > 0){
            printf("%d ", v[i]);
        }
    }
    printf("\nvalores negativos: \n");
    for(i=0;i<t;i++){
        if (v[i] < 0){
            printf("%d ", v[i]);
        }
    }
    printf("\nzeros do vetor: \n");
    for(i=0;i<t;i++){
        if (v[i] == 0){
            printf("%d ", v[i]);
        }
    }
    printf("\nvalores em indices impares do vetor: \n");
    for(i=0;i<t;i++){
        if (i % 2 != 0){
            printf("%d ", v[i]);
        }
    }
   }
    else{
        printf("tamanho muito grande.");
        return -1;
    }
}
