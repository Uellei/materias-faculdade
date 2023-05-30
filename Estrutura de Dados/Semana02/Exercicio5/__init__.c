#include <stdlib.h>
#include <stdio.h>

void main(){
    int n, i, soma=0, valor;
    printf("Digite um valor N: "); scanf("%i", &n);

    int *vet = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("Valor de N%i: ", i+1); scanf("%i", &*(vet+i));
    }
    for (i=0;i<n;i++){
        soma = soma + *(vet+i);
    }
    printf("Soma: %i", soma);

    free(vet);


}