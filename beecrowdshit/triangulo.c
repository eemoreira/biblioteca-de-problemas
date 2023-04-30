#include <stdio.h>

int main(){
    float a,b,c,perimetrotriangulo, areatrapezio;
    scanf("%f%f%f",&a,&b,&c);
    if ((a >= (b + c)) && (b >= (a + c)) && (c >= (b + a))){
        perimetrotriangulo = a+b+c;
        printf("Perimetro = %.1f", perimetrotriangulo);
    }
    else{
        areatrapezio = ((a + b)*c)/2;
        printf("Area = %.1f", areatrapezio);
    }
    return 0;
}