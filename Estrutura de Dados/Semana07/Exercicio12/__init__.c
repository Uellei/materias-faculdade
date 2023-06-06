#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    float info;
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
    return (p->topo == NULL);
}

void push(pilha *p, float dado){
    no *novo = (no*) malloc(sizeof(no)); 
    novo->info = dado; 
    novo->prox = p->topo;
    p->topo = novo; 
}

float pop(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    float temp = p->topo->info; 
    no *aux = p->topo; 
    p->topo = aux->prox; 
    free(aux); 
    return temp; 
}

void imprime(pilha *p){
    no *aux;
    for(aux=p->topo;aux!=NULL;aux=aux->prox){
        printf("%f\n", aux->info);
    }
}

void libera(pilha *p){
    no *aux = p->topo;
    while(aux!=NULL){
        no *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(p);
}

void concatena_pilhas(pilha *p1, pilha *p2){
    while(!vazia(p2)){ // Enquanto a pilha 2 não for vazia, ele faz:
        float elemento = pop(p2); // Como a função pop remove um elemento da pilha e retorna o seu valor, salvei o valor em uma variavel
        push(p1, elemento); // Adiciono então o valor que foi salvo do elemento na nova pilha
    }
}
int main(){
    pilha *p1 = cria();
    pilha *p2 = cria();

    push(p1, 19.2);
    push(p1, 1.2);
    push(p1, 31.2);
    push(p2, 11.23);
    push(p2, 165.22);
    push(p2, 311.22);

    concatena_pilhas(p1, p2);

    imprime(p1);

    libera(p1);
    return 0;
}