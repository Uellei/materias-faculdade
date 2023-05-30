#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    int info;
    struct tree *esq;
    struct tree *dir;
}arv;

int conta_no(arv* a){
    if(a != NULL){
        conta_no(a->dir);
        if(a->esq != NULL || a->dir != NULL){
            return 1 + conta_no(a->esq) + conta_no(a->dir);
        }
    }
}

arv* cria(){
    return NULL;
}

arv* insere(arv* a, int dado){
    if(a == NULL){
        a = (arv*) malloc(sizeof(arv));
        a->info = dado;
        a->esq = a->dir = NULL;
    } else if(dado < a->info){
        a->esq = insere(a->esq, dado);
    } else{
        a->dir = insere(a->dir, dado);
    }
    return a;
}

int main(){    
    /* Constrói a árvore abaixo:
           10
          /  \
         5   15
        / \    \
       3   7   20
    */
    // Um exemplo de montar árvore sem a função insere
    // arv *no20 = (arv*) malloc(sizeof(arv));
    // no20->info = 20;
    // no20->esq = no20->dir = NULL;

    // arv *no15 = (arv*) malloc(sizeof(arv));
    // no15->info = 15;
    // no15->esq = NULL;
    // no15->dir = no20;

    // arv *no3 = (arv*) malloc(sizeof(arv));
    // no3->info = 3;
    // no20->esq = no20->dir = NULL;

    // arv *no7 = (arv*) malloc(sizeof(arv));
    // no7->info = 7;
    // no7->esq = no7->dir = NULL;

    // arv *no5 = (arv*) malloc(sizeof(arv));
    // no5->info = 5;
    // no5->esq = no3;
    // no5->dir = no7;

    // arv *no10 = (arv*) malloc(sizeof(arv));
    // no10->info = 10;
    // no10->esq = no5;
    // no10->dir = no15;

    arv* arvore = cria();

    arvore = insere(arvore, 20);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 10);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 3);


    int num_nos = conta_no(arvore);
    printf("A arvore tem %d nos.\n", num_nos);


    return 0;
}