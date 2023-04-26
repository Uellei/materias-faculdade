#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int item;
    struct no *prox;
}lista;

lista* insere (lista *no, int valor){
    lista *novo = (lista*) malloc(sizeof(lista));
    novo->item = valor;
    novo->prox = no;
    return novo;
}

void libera(lista *no){
    lista *aux = no;
    while(aux!=NULL){
        lista *n = aux->prox;
        free(aux);
        aux = n;
    }
}


int tamanho(lista *no){
    int tamanho = 0;
    while(no !=NULL){
        tamanho++;
        no = no->prox;
    }
    return tamanho;
}


int main(){

    // lista *no1 = (lista*) malloc(sizeof(lista));
    // lista *no2 = (lista*) malloc(sizeof(lista));
    // lista *no3 = (lista*) malloc(sizeof(lista));

    // no1->item = 10;
    // no2->item = 20;
    // no3->item = 30;

    // no1->prox = no2;
    // no2->prox = no3;
    // no3->prox = NULL;

    lista *no = NULL;

    no = insere(no, 6);
    no = insere(no, 2);
    no = insere(no, 3);
    no = insere(no, 1);
    no = insere(no, 5);
    no = insere(no, 9);


    printf("Tamano da lista: %i", tamanho(no));

    libera(no);

}