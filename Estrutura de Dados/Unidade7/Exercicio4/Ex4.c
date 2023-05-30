#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    int info;
    struct tree *dir;
    struct tree *esq;
}arv;

arv* cria(){
    return NULL;
}

void imprime(arv* a){
    if(a != NULL){
        imprime(a->esq); 
        printf("%d\n", a->info);
        imprime(a->dir);
    }
}

arv* insere(arv* a, int dado){
    if(a == NULL){
        a = (arv*) malloc(sizeof(arv));
        a->info = dado;
        a->dir = a->esq = NULL;
    } else if(dado < a->info){
        a->esq = insere(a->esq, dado);
    } else{
        a->dir = insere(a->dir, dado);
    }
    return a;
}

arv* exclui_folhas(arv *a){
    if(a==NULL) return a;
    if(a->esq==NULL && a->dir==NULL){
        free(a);
        return NULL;
    }
    a->esq=exclui_folhas(a->esq);
    a->dir=exclui_folhas(a->dir);
    return a;

}

int main(){
    arv* arvore = cria();
    arvore = insere(arvore, 20);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 10);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 3);

    printf("Arvore inicial\n");
    imprime(arvore);

    exclui_folhas(arvore);

    printf("Arvore apos excluir folhas\n");
    imprime(arvore);

}