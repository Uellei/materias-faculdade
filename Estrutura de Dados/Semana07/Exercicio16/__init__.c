#include <stdlib.h>
#include <stdio.h>

#define MAX 7

typedef struct p{
    int n;// Quantidade elementos
    float vet[MAX];
}pilhavet;

int cheia(pilhavet p){
    return (p.n == MAX);
}

void push(pilhavet *p, float dado){
    if(cheia(*p)){
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
    p->vet[p->n] = dado;
    p->n++;
}

int main(){
    pilhavet pilha;
    pilha.n = 0;
    
    push(&pilha, 1.5);
    push(&pilha, 2.5);
    push(&pilha, 3.5);
    push(&pilha, 4.5);
    push(&pilha, 5.5);
    push(&pilha, 6.5);
    
    if(cheia(pilha)){
        printf("A pilha esta cheia\n");
    } else
        printf("A pilha não esta cheia\n");
}