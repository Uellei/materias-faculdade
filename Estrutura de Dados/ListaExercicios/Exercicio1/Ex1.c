#include <stdlib.h>
#include <stdio.h>

void hm(int mnts, int *h, int *m){
    *h = mnts/60;
    *m = mnts%60;
    // printf("Horas: %i\n", *h);
    // printf("Minutos: %i", *m);
}

void main(){
    int tempomin, horas, minutos;
    printf("Digite o tempo em minutos\n");
    scanf("%i", &tempomin);
    // Como a função hm recebe um ponteiro e as variaveis nao foram definidas como ponteiro, é necessario passar o endereço para a função
    hm(tempomin, &horas, &minutos);
    printf("Hora(s): %i\n", horas);
    printf("Minuto(s): %i\n", minutos);

}
