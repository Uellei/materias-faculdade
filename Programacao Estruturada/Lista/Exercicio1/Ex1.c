#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float converte(float valor){
    return valor * 4.22;
}


int main(){
    float valor;
    printf("Digite um valor(R$): "); scanf("%f", &valor);
    printf("R$%.3f em Dolar = $%.3f ", converte(valor));
}