#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 1000
int vogais(char x[]);
int letras(char l[]);
int pontofinal(char p[]);
int espaco(char e[]);


int main(){

    char *arr;
    arr = malloc(sizeof(int)*T);    
    fgets(arr, T, stdin);
    if(arr == NULL){
        printf("memoria insuficiente");
        return -1;
    }
    if((strlen(arr) > 0) && (arr[strlen(arr)] == '\n')){
        arr[strlen(arr)] == '\0';
    }
    printf("vogais %d\n", (int)vogais(arr));
    printf("letras %d\n", (int)letras(arr));
    printf("pontuacao %d\n", (int)pontofinal(arr));
    printf("brancos %d\n", (int)espaco(arr));

    free(arr);
    return 0;
}
int vogais(char x[]){

    int i, vogaisx=0;
    for(i=0;i<strlen(x);i++){
        if ((x[i] == 'a')||(x[i] == 'e')||(x[i] == 'i')||(x[i] == 'o')||(x[i] == 'u')||(x[i] == 'A')||(x[i] == 'E')||(x[i] == 'I')||(x[i] == 'O')||(x[i] == 'U')){
            vogaisx += 1;
        }
            
    }
    return (int)vogaisx;
}

int letras(char l[]){

    int i, letras=0;
    for(i=0;i<strlen(l);i++){
        if (((l[i]>= 'a')&&(l[i]<='z'))||((l[i]>='A')&&(l[i]<='Z'))){
               
            letras += 1;
        }
          
        }
    
    return (int)letras;
}
int pontofinal(char p[]){
    int i, pontos=0;
     for(i=0;i<strlen(p);i++){
        if (ispunct(p[i])){
            pontos += 1;
        }
          
        }
    
    return (int)pontos;

}
int espaco(char e[]){
    
    int i, espacos=0;
    for(i=0;i<strlen(e);i++){
        if(e[i] == ' '){
            espacos += 1;
        } 
        }
    
    return (int)espacos;
}