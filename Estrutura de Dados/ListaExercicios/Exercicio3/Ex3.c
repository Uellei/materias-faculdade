#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mm(int v[], int tam, int *min, int *max){
    int i;
    *min = v[0];
    *max = v[0];
    // Fazer um for que percorre cada item i de 0 até o tamanho descrito, e compara valor por valor e sempre salva o maior/menor ate entao
    for (i=0;i<tam;i++){
        if(*min>v[i]) *min=v[i];
        if(*max<v[i]) *max=v[i];
    }
}

int main(){
    int TAM;
    printf("Digite o tamanho: "); scanf("%i", &TAM);
    int v[TAM];
    int i, menor, maior;
    srand(time(NULL));
    for(i=0;i<TAM;i++){
        v[i] = rand()%100;
        printf("v[%i]=%i\n", i, v[i]);
    }

    mm(v, TAM, &menor, &maior);
    printf("Menor: %i\n", menor);
    printf("Maior: %i\n", maior);
}