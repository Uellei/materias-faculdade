#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    int info;
    struct tree *esq;
    struct tree *dir;
}arv;

arv* cria(){
    return NULL;
}

int vazia(arv* a){
    return a == NULL;
}

arv* insere(arv* a, int dado){
    if(vazia(a)){
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

arv* busca(arv* a, int dado){
    if(a==NULL) return NULL;
    else if(a->info > dado){
        return busca(a->esq, dado);
    } else if(a->info < dado){
        return busca(a->dir, dado);
    } else{
        return a;
    }
}

arv* retira(arv* a, int dado) {
    if (a == NULL) {
        return NULL;
    } else if (a->info > dado) {
        a->esq = retira(a->esq, dado);
    } else if (a->info < dado) {
        a->dir = retira(a->dir, dado);
    } else {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            a = NULL;
        } else if (a->esq == NULL) {
            arv* t = cria();
            t = a;
            a = a->dir;
            free(t);
        } else if (a->dir == NULL) {
            arv* t = cria();
            t = a;
            a = a->esq;
            free(t);
        } else {
            arv* f = a->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }
            a->info = f->info;
            f->info = dado;
            a->esq = retira(a->esq, dado);
        }
    }
    return a;
}

void nao_imprime_folhas(arv *a){
    if(a != NULL){
        nao_imprime_folhas(a->dir);

        if(a->esq != NULL || a->dir != NULL){
            printf("%d\n", a->info);
            nao_imprime_folhas(a->esq);
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

    printf("Valores associados que nao sao folhas (em ordem crescente):\n");
    nao_imprime_folhas(arvore);
    
    return 0;
}