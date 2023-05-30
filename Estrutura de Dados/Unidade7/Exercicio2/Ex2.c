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

int altura(arv* a){
    if(a != NULL){
        int altura_esq = altura(a->esq);
        int altura_dir = altura(a->dir);
        if(altura_esq > altura_dir){
            return altura_esq + 1;
        } else {
            return altura_dir + 1;
        }
    }
}

int main(){
     arv* arvore = cria();

    arvore = insere(arvore, 10);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 20);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 3);

    int tamanho = altura(arvore);
    printf("Altura da arvore: %i", tamanho);
    return 0;
}