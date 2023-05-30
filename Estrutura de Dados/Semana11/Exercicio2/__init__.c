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

int quant_folhas(arv* a) {
    if (a == NULL) return NULL;
    if (a->esq == NULL && a->dir == NULL) return 1;
    int folhas_esq = quant_folhas(a->esq);
    int folhas_dir = quant_folhas(a->dir);
    return folhas_esq + folhas_dir;
}


int main(){
    arv* arvore = cria();
    arvore = insere(arvore, 20);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 10);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 3);

    int num_folhas = quant_folhas(arvore);
    printf("A arvore tem %d folhas.\n", num_folhas);
    
    return 0;
}