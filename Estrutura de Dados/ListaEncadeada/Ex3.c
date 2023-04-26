#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int item;
    struct no *prox;
} lista;

lista* insere(lista* no, int valor) {
    lista *novo = (lista*) malloc(sizeof(lista));
    novo->item = valor;
    novo->prox = no;
    return novo;
}

void libera(lista* no) {
    lista *aux = no;
    while(aux != NULL) {
        lista *n = aux->prox;
        free(aux);
        aux = n;
    }
}

void imprime (lista* no){
    lista *L;
    for (L = no; L!=NULL; L = L->prox)
        printf("info = %d\n", L->item);
}

int posicaoDoElemento(lista* l1, int info) {
    int posicao = 0;
    while(l1 != NULL) {
        if(l1->item == info) {
            return posicao;
        }
        l1 = l1->prox;
        posicao++;
    }
    return -1;
}

int main() {
    lista *l1 = NULL;
    int pos;

    l1 = insere(l1, 8);
    l1 = insere(l1, 4);
    l1 = insere(l1, 2);
    l1 = insere(l1, 3);
    l1 = insere(l1, 5);
    l1 = insere(l1, 7);

    imprime(l1);


    pos = posicaoDoElemento(l1, 3);
    printf("O numero 3 esta na posicao %i\n", pos);

    pos = posicaoDoElemento(l1, 8);
    printf("O numero 8 esta na posicao %i\n", pos);

    libera(l1);
}
