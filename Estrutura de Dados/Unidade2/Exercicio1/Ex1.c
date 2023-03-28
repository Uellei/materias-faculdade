#include <stdlib.h>
#include <stdio.h>

int main(){
    float imc, altura, peso;

    printf("Altura: "); scanf("%f", &altura);
    printf("Peso: "); scanf("%f", &peso);

    imc = peso/(altura*altura);

    if (imc<18){
        printf("Voce esta abaixo do peso");
    } else if(imc>=18 && imc<=25){
        printf("Parabens. Voce esta sarado");
    } else if(imc>25 && imc<=30){
        printf("Atencao. Voce esta acima do peso");
    } else{
        printf("Cuidado. Voce esta obeso");
    }

}