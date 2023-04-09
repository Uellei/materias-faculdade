#include <stdlib.h>
#include <stdio.h>

int Eleva(int a, int b){
    if(b == 0) return 1; 
    else return a*Eleva(a,b-1);
}

void main(){
    int a, b;
    printf("Base: "); scanf("%i", &a);
    printf("Expoente: "); scanf("%i", &b);
    printf("Valor: %i", Eleva(a,b));
}