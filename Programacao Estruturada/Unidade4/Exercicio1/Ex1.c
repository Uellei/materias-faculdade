#include <stdio.h>
#include <stdlib.h>

int area_retangulo(int base, int altura){
    return base*altura;
}

int main(){
    int base, altura;
    printf("Digite a base do retangulo: "); scanf("%i", &base);
    printf("Digite a altura do retangulo: "); scanf("%i", &altura);

    printf("Area = %i", area_retangulo(base, altura));
}