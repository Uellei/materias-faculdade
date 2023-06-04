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
        no *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(p);
}

int conta_negativos(pilha *p){
    pilha *aux = cria(); // Cria uma pilha auxiliar 
    int count = 0; // Inicia o contador de negativos em 0
    while(!vazia(p)){ // Enquanto a pilha p não estiver vazia:
        int el = pop(p); // Salva o valor do elemento antes de apaga-lo
        push(aux, el); // Adiciona o elemento na pilha auxiliar
        if(el < 0) // Confere se o elemento é negativo
            count+=1; // Se for negativo aumenta em um o contador
    }
    while(!vazia(aux)){ // Equanto a pilha aux não estiver vazia
        int el = pop(aux); // Salva o valor do elemento antes de apaga-lo
        push(p, el); // Adiciona o elemento que foi apagado da lista aux na lista p para voltar a pilha que entrou na função, no mesmo formato
    }
    libera(aux);
    return count; // Retorna o tanto de números negativos contidos na pilha
}

int main(){
    pilha *p = cria();

    push(p, 10);
    push(p, -1);
    push(p, 20);
    push(p, -31);
    push(p, -32);
    push(p, -3);
    push(p, 12);
    push(p, 43);

    int negativos = conta_negativos(p);
    printf("Quantidade de negativos: %i\n", negativos);

    libera(p);
}