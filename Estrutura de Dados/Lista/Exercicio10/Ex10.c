#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct c{
    int tipo;
    float largura;
    float comprimento;
}comodo;

float CalculaArea(float largura, float comprimento){
    return largura*comprimento;
}

int Lampada(comodo c){
    if(c.tipo == 0){
        return CalculaArea(c.largura, c.comprimento)*12/60;
    } else if(c.tipo == 1){
        return CalculaArea(c.largura, c.comprimento)*15/60;
    } else if(c.tipo == 2){
        return CalculaArea(c.largura, c.comprimento)*18/60;
    } else if(c.tipo == 3){
        return CalculaArea(c.largura, c.comprimento)*20/60;
    } else{
        return CalculaArea(c.largura, c.comprimento)*22/60;
    }
}

void main(){
    comodo temp;
    int i;
    while(temp.tipo >= 0){
        printf("Digite o tipo do comodo\n"); scanf("%i", &temp.tipo);
        printf("Digite a largura do comodo\n"); scanf("%f", &temp.largura);
        printf("Digite o comprimento do comodo\n"); scanf("%f", &temp.comprimento);
        if(temp.tipo>=0){
            printf("Lampadas 60W: %i\n", Lampada(temp));
        } 

    }
}