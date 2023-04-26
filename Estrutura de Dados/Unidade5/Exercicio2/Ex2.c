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
    return (p->topo == NULL);
}

void push(pilha *p, int dado){
    no *novo = (no*) malloc(sizeof(no)); 
    novo->info = dado; 
    novo->prox = p->topo;
    p->topo = novo; 
}

int pop(pilha *p){
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

void imprime(pilha *p){
    no *aux;
    for(aux=p->topo;aux!=NULL;aux=aux->prox){
        printf("%i\n", aux->info);
    }
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

void retira_impares(pilha *p){
    pilha *aux = cria(); // Cria uma pilha pra auxiliar e ir colocando os elementos que são par
    while(!vazia(p)){
        int elemento = pop(p); // Tira elemento da pilha e salva o valor na variavel
        if(elemento%2==0){ // Confere se o valor da pilha removida é par
            push(aux, elemento); // Se for par ele coloca o elemento dentro da pilha auxiliar
        }
    }
    while(!vazia(aux)){ // Equanto a lista auxiliar(com os numeros pares) não vou vazia
        int elemento = pop(aux); // Remove o elemento e salva o valor na variavel
        push(p, elemento); // Adiciona o elemento par na pilha original
    }
    libera(aux);
}

int main(){
    pilha *p1 = cria();
    pilha *p2 = cria();

    push(p1, 19);
    push(p1, 1);
    push(p1, 3);
    push(p1, 29);
    push(p1, 32);
    push(p1, 14);
    push(p1, 12);

    retira_impares(p1);

    imprime(p1);

    libera(p1);
    return 0;
}

