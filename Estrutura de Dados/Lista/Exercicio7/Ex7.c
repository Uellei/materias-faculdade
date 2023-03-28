#include <stdlib.h>
#include <stdio.h>

typedef struct dma {
    int dia;
    int mes;//30 dias
    int ano;//365 dias
}Data;

void main(){
    Data inicial, final;
    int dif_dias;
    printf("Digite o dia inicial\n"); scanf("%i", &inicial.dia);
    printf("Digite o mes inicial\n"); scanf("%i", &inicial.mes);
    printf("Digite o ano inicial\n"); scanf("%i", &inicial.ano);
    printf("Digite o dia final\n"); scanf("%i", &final.dia);
    printf("Digite o mes final\n"); scanf("%i", &final.mes);
    printf("Digite o ano final\n"); scanf("%i", &final.ano);
    dif_dias = (final.dia - inicial.dia);
    dif_dias += (final.mes - inicial.mes)*30;
    dif_dias += (final.ano - inicial.ano)*365;
    printf("Diferença de dias: %i", dif_dias);
}