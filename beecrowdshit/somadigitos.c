#include <stdio.h>
int somadigitos (int x);

int main(){
    printf("%d",somadigitos(1002));

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