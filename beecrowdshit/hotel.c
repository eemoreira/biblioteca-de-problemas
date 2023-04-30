#include <stdio.h>
int preco(int diax, int diariax, int aumentox);
int main(){
    int diaria, aumento, dia;
    scanf("%d", &diaria); 
    scanf("%d", &aumento); 
    scanf("%d", &dia);
    printf("%d", preco(dia, diaria, aumento));

}

int preco(int diax, int diariax, int aumentox){

    int preco;
    if (diax >= 15){
        preco = (32 - diax)*(diariax + (14)*aumentox);
    }
    else{
    preco = (32 - diax)*(diariax + (diax-1)*aumentox);
    }
    return preco;

    
}