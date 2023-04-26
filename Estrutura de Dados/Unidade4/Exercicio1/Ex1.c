#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int item;
    struct no *prox;
    
}lista;

// inicializa a lista
lista *inicializa(){
    return NULL;
}

// Funcao vazia: retorna 1 se vazia ou 0 se n„o vazia
int vazia(lista *no){
    if (no==NULL) return 1;
    else return 0;
}

// inserir na lista
lista *insere(lista *no, int info){
    lista *novo = (lista*)malloc(sizeof(lista));
    novo -> item = info;
    novo -> prox = no;
    return novo;
}

// Função imprime: imprime valores dos elementos
void imprime(lista* no){
    lista *L;
    for(L=no;L!=NULL;L=L->prox)
        printf("info = %i\n", L->item);
}

// Funcao libera: libera a memÛria de todos os nÛs
void libera(lista* no){
    lista *L = no;
    while(L != NULL){
        lista *n = L->prox;
        free(L);
        L = n;
    }
}

// Funcao busca: busca um elemento na lista
lista* busca(lista *no, int info){
    lista *p;
    for(p=no;p!=NULL;p=p->prox)
        if(p->item == info) return p;
    return NULL;
}

int pares(lista*no){
    int x = 0;
    lista *p;
    for(p=no;p!=NULL;p-p->prox){
        if(p->item%2 == 0) x++;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    lista *l1=inicializa();
    l1=insere(l1,4);
    l1=insere(l1,7);
    l1=insere(l1,6);
    printf("L1\n");
    imprime(l1);
    lista *l2=pares(l1);
    printf("L2\n");
    imprime(l2);
    libera(l2);
    libera(l1);
    return 0;
}