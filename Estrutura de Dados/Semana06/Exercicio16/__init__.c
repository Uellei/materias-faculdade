#include <stdlib.h>
#include <stdio.h>
#define MAX 7

typedef struct p{
    int n; // Quantidade de elementos
    float vet[MAX];
}pilhavet;

int cheia(pilhavet p){
    return p.n == MAX;
}

int main() {
    pilhavet p1 = {5, {1.0, 2.0, 3.0, 4.0, 5.0}};
    pilhavet p2 = {MAX, {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0}};

    if (cheia(p1)) {
        printf("Pilha 1 esta cheia\n");
    } else {
        printf("Pilha 1 nao esta cheia\n");
    }

    if (cheia(p2)) {
        printf("Pilha 2 esta cheia\n");
    } else {
        printf("Pilha 2 nao esta cheia\n");
    }

    return 0;
}