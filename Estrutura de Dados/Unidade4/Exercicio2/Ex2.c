#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int item;
    struct no *prox;
}lista;

lista* duplica_lista(lista *no){
    lista *l1=no, *l2, *ant, *novo;
    if(l1==NULL) return NULL;
    else{
        novo=(lista*)malloc(sizeof(lista));
        novo->item=l1->item;
        l2=novo;
        ant=novo;
        l1=l1->prox;
    }
    while(l1!=NULL){
        novo=(lista*)malloc(sizeof(lista));
        novo->item=l1->item;
        ant->prox=novo;
        ant=novo;
        l1=l1->prox;
    }
    ant->prox=NULL;
    return l2;
}