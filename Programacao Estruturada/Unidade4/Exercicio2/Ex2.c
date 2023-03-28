#include <stdio.h>
#include <stdlib.h>

int area_retangulo(int base, int altura){
    return base*altura;
}

int area_triangulo(int base, int altura){
    return base*altura/2;
}

int main(){
    int base, altura;
    char escolha[10];

    printf("Quer calcular a area do triangulo ou do retangulo? "); scanf("%s", &escolha);
    if (strcmp(escolha, "retangulo") == 0){
        printf("Digite a base do retangulo: "); scanf("%i", &base);
        printf("Digite a altura do retangulo: "); scanf("%i", &altura);

        printf("Area = %i", area_retangulo(base, altura));
    } else if (strcmp(escolha, "triangulo") == 0){
        printf("Digite a base do triangulo: "); scanf("%i", &base);
        printf("Digite a altura do triangulo: "); scanf("%i", &altura);

        printf("Area = %i", area_triangulo(base, altura));
    } else {
        printf("Digite uma figura valida");
    }

    return 0;    
}