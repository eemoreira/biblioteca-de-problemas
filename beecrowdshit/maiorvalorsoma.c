#include <stdio.h>
#define T 10000
int somadigitos(int x);
int main(){

    int primeiro, soma ,ultimo, v[T];
    int i;
    scanf("%d", &primeiro);
    scanf("%d", &ultimo);
    scanf("%d", &soma);

    for(i=primeiro;i<=ultimo;i++){
        v[i-primeiro] = somadigitos(i);
    }
    int w[T], count=0;
    for(i=primeiro;i<=ultimo;i++){
        if(v[i-primeiro] == soma){
            count++;
            w[count] = i;
        }
    }
    int maior = w[0];
    for(i=0;i<T;i++){
        if(w[i] > maior){
            maior = w[i];
        }
    }
    if(count == 0){
        printf("-1");
    }
    else{
    printf("%d", maior);
}
}

int somadigitos (int x){

    int somad=0;
    while(x>=10){
    somad += (x % 10) + somadigitos(x/10);
    return somad;
    }
    if (x<10){
        somad += x;
    }
}