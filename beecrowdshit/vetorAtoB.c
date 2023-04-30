#include <stdio.h>
#include <stdlib.h>
#define T 10

int main(){

    int a[T], b[T], i;

    for(i=1;i<T;i++){
        scanf("%d", &a[i]);
    }
    
    for(i=1;i<T;i++){
        if (i <= 5){
            b[i] = a[i];
        }
        else{
            b[i] = 0;
        }
    }

    for(i=1;i<T;i++){
    printf("%d, ", a[i]);
    }
    printf("\n");
    for(i=1;i<T;i++){
    printf("%d, ", b[i]);
    }
    
}