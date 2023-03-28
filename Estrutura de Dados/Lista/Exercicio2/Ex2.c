#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void calcula_hexa(float l, float *area, float *perimetro){
    *area = (3*l*l*sqrt(3))/2;
    *perimetro = 6*l;
}

int main(){
    float lado;
    printf("Lado do Hexagono: "); scanf("%f", &lado);
    float area, perimetro;
    calcula_hexa(lado, &area, &perimetro);
    printf("Hexagono tem\nLado: %f\n", lado);
    printf("Area: %.2f\n", area);
    printf("Perimetro: %f\n",perimetro);

}