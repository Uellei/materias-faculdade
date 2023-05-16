#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    int info;
    struct n *prox;
}no;

typedef struct p{
    no *topo;
}pilha;

pilha* cria(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

int vazia(pilha *p){
    return(p->topo == NULL);
}

void empilha(pilha* p, int v){
    no* novo = (no*) malloc(sizeof(no));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilha(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");        
        exit(1);
    }
    int temp = p->topo->info;
    no *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    return temp;
}

void libera(pilha *p){
    no *aux = p->topo;
    while(aux!=NULL){
        no *temp = (no*) malloc(sizeof(temp));
        free(aux);
        aux = temp;
    }
    free(p);
}

void SeparaParImpar(pilha *p, pilha *par, pilha *impar){
    while(!vazia(p)){
        int el = desempilha(p);
        if(el%2==0){
            empilha(par, el);
        }else{
            empilha(impar, el);
        }
    }
}

void imprime(pilha *p){
    no *aux;
    for(aux=p->topo;aux!=NULL;aux=aux->prox){
        printf("%i\n", aux->info);
    }
}

int main(){
    pilha *p = cria();
    pilha *par = cria();
    pilha *impar = cria();
    empilha(p, 7);
    empilha(p, 12);
    empilha(p, 9);
    empilha(p, 8);
    empilha(p, 5);
    empilha(p, 3);
    empilha(p, 6);

    SeparaParImpar(p, par, impar);

    imprime(par);
    printf("\n");
    imprime(impar);
}