#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    float info;
    struct n *prox;
}no;

typedef struct f{
    no *inicio;
    no *fim;
    int tamanho;
}fila;

fila* cria(){
    fila* f = (fila*) malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int vazia(fila* f){
    return(f->inicio == NULL);
}

void insere(fila* f, float v){
    no *novo = (no*) malloc(sizeof(no));
    novo->info = v;
    novo->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    if(f->inicio == NULL)
        f->inicio = f->fim;
}

float retira(fila *f){
    float temp;
    if(vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    temp = f->inicio->info;
    no *aux = f->inicio->prox;
    free(f->inicio);
    f->inicio = aux;
    if(f->inicio == NULL)
        f->fim = NULL;
    return temp;
}

void libera(fila *f){
    no* aux = f->inicio;
    while(aux!=NULL){
        no *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(f);
}

void preenche(fila *f1, fila *f2, fila *retorno){
    while(!vazia(f1) && !vazia(f2)){
        if(retira(f1) < retira(f2))
            insere(retorno, retira(f1));
        else
            insere(retorno, retira(f2));
    }
    while(!vazia(f1)){
        insere(retorno, retira(f1));
    }
    while(!vazia(f2)){
        insere(retorno, retira(f2));
    }
}

int main(){
    fila *f1 = cria();
    fila *f2 = cria();
    fila *retorno = cria();

    insere(f1, 1.0);
    insere(f1, 3.0);
    insere(f1, 5.0);
    insere(f1, 7.0);
    insere(f1, 9.0);

    insere(f2, 2.0);
    insere(f2, 4.0);
    insere(f2, 6.0);
    insere(f2, 8.0);
    insere(f2, 10.0);

    preenche(f1, f2, retorno);

    printf("Fila retorno:\n");
    while (!vazia(retorno)) {
        printf("%f\n", retira(retorno));
    }

    libera(f1);
    libera(f2);
    libera(retorno);
    
}