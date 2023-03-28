#include <stdlib.h>
#include <stdio.h>

float reajuste_preco(float preco){
    if (preco >=0 && preco<50){
        preco = preco * 0.7;
    } else if(preco >= 50 && preco < 200){
        preco = preco * 0.8;
    } else if(preco >=200 && preco < 500){
        preco = preco * 0.9;
    } else{
        preco = preco * 0.95;
    }
}

int main(){
    float preco;
    printf("Preco Atual: "); scanf("%f", &preco);
    printf("Preço com desconto Black Friday = %.2f", reajuste_preco(preco));
}