#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int VetMaior(int A[], int n) {
    // Caso base: quando há apenas um elemento, retorna ele mesmo
    if (n == 1) {
        return A[0];
    }
    // Caso recursivo: compara o elemento atual com o maior elemento do restante do vetor
    int max_resto = VetMaior(A, n-1);
    if (A[n-1] > max_resto) {
        return A[n-1];
    } else {
        return max_resto;
    }
}

void main(){
    int vet[MAX];
    int i;
    for(i=0;i<MAX;i++){
        printf("%i° = ", i+1);
        scanf("%i", &vet[i]);
    }
    printf("Valor: %i", vetMaior(vet,MAX));
}