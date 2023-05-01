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
        printf("%d ", aux->info);
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

void remove_negativos(fila* f){
    fila* aux = cria();
    while(!vazia(f)){
        int el = remover(f);
        if(el>=0){
            insere(aux, el);
        }
    }
    while(!vazia(aux)){
        int el = remover(aux);
        insere(f, el);
    }
    libera(aux);
}

int main(){
    fila* f = cria();

    insere(f, 10);
    insere(f, -1);
    insere(f, 20);
    insere(f, -31);
    insere(f, -32);
    insere(f, -3);
    insere(f, 12);
    insere(f, 43);

    printf("Fila original: ");
    imprime(f);

    printf("\nFila sem negativos: ");
    remove_negativos(f);
    imprime(f);

    libera(f);

}