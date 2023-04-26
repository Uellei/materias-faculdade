#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int item;
    struct no *prox;
}lista;

lista* insere(lista* no, int valor){
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

int sao_iguais(lista *l1, lista *l2){
    while (l1!=NULL && l2!=NULL){
        if(l1->item != l2->item){
            return 0;
        }
        l1 = l1->prox;
        l2 = l2->prox;
    }
    if (l1 != NULL || l2 != NULL){
        return 0;
    }
    return 1;
}

int main(){
    lista *l1 = NULL;

    l1 = insere(l1,5);
    l1 = insere(l1,1);

    lista *l2 = NULL;

    l2 = insere(l2,5);
    l2 = insere(l2,2);

    if(sao_iguais(l1,l2)){
        printf("iguais");
    }else printf("Não igauis");

    libera(l1);
    libera(l2);

}