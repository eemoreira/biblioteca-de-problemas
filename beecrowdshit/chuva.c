#include <stdio.h>
#include <stlib.h>
int intervalos(int x[]);

int main(){
    int i, *v, T, soma;
    scanf("%d", &T);
    scanf("%d", &soma);
    v = malloc(sizeof(int)*T);
    for(i=0;i<T;i++){
        scanf("%d", v[i]);
    }
    if (v = NULL){
        return -1;
    }


}   

int intervalos(int x[],int somax , int tamanho){

    int i, j, somaintervalo=0, saida=0;

    for(i=0;i<tamanho;i++){
        while(somaintervalo != somax){
            somaintervalo += x[i];
        }
        saida++;
        somaintervalo = 0;

    }

}