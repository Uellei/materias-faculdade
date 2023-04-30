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

int separa_fila(fila* f, fila* f_impares, fila* f_pares){
    while(!vazia(f)){
        int valor = remover(f);
        if(valor%2==0){
            insere(f_pares, valor);
        } else{
            insere(f_impares, valor);
        }
    }
}


int main() {
    // Cria cada uma das três filas
    fila* f = cria();
    fila* f_impares = cria();
    fila* f_pares = cria();

    // Adiciona elementos para a fila principal
    insere(f, 1);
    insere(f, 2);
    insere(f, 3);
    insere(f, 4);
    insere(f, 5);

    // Executa a função
    separa_fila(f, f_impares, f_pares);

    // Remove todos os elementos da fila impares, ja a função remover retorna o elemento que foi removido, vai printar todos os elementos impares
    printf("Valores ímpares:\n");
    while (!vazia(f_impares)) {
        printf("%d\n", remover(f_impares));
    }

    // Remove todos os elementos da fila pares, ja a função remover retorna o elemento que foi removido, vai printar todos os elementos pares
    printf("Valores pares:\n");
    while (!vazia(f_pares)) {
        printf("%d\n", remover(f_pares));
    }

    libera(f);
    libera(f_impares);
    libera(f_pares);

    return 0;
}
