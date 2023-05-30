#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    int info;
    struct n *prox;
}no;

typedef struct f{
    no *inicio;
    no *fim;
    int tamanho;
}fila;

int vazia(fila* f){
    return(f->inicio == NULL);
}

fila* cria(void){
    fila* f = (fila*) malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(fila* f, int dado){
    no* novo = (no*) malloc(sizeof(no));
    novo->info = dado;
    novo->prox = NULL;
    if(f->fim != NULL){
        f->fim->prox = novo;
    }
    f->fim = novo;
    if(f->inicio == NULL){
        f->inicio = f->fim;
    }
}

void imprime(fila *f){
    no* aux;
    for(aux=f->inicio;aux!=NULL;aux=aux->prox)
        printf("%d\n", aux->info);
}

int remover(fila* f){
    int temp;
    if(vazia(f)){
        printf("Fila vazia\n");
        exit(1);

    }
    temp = f->inicio->info;
    no *aux = f->inicio->prox;
    free(f->inicio);
    f->inicio = aux;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    return temp;
}


void libera(fila *f){
    no* aux = f->inicio;
    while(aux != NULL){
        no* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(f);
}

// Chamando de forma recursiva ela vai remover elemento por elemento ate ela ficar vazia, e depois ir inserindo os elementos começando da ultima chamada da função recursiva ate a primeira
void inverte(fila *f){
    if(vazia(f)){
        return;
    }
    int valor = remover(f);
    inverte(f);
    insere(f, valor);
}

int main(){
    fila* f = cria();

    insere(f, 4);
    insere(f, 3);
    insere(f, 9);
    insere(f, 2);

    inverte(f);

    imprime(f);

    libera(f);



}