#include <stdio.h>
#include <stdlib.h>

int main(){

    int *arr, soma=0, roubados=0,atacados=0,zeros=0, numerofazendas;
    scanf("%d", &numerofazendas);
    arr = malloc(sizeof(int)*numerofazendas);
    if (arr == NULL){
        return -1;
    }
    for(int i=0; i<numerofazendas;i++){
        scanf("%d", &arr[i]);
        soma += arr[i];
    }
    for(int i=0;i<numerofazendas;i++){
        if ((arr[i] % 2 != 0) || (arr[i] == 0)){
            atacados++;
            roubados++;
            arr[i]--;
        }
        else{
            atacados++;
            roubados += i + 1;
            for(int k=0; k<=i;k++){
                arr[k]--;
            }
            for (int i=0;i<numerofazendas;i++){
                if (arr[i] <= 0){
                    zeros++;
                }
            }
            break;
        }

    }
    printf("%d %d\n", atacados, soma - roubados + zeros);

    return 0;
}