#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    float info;
    struct n *prox;
}no;

typedef struct p{
    no *topo;
}pilha;

// Cria a pilha para conseguir armazenar e manipular os elementos
pilha* cria(){
    pilha *p = (pilha*) malloc(sizeof(pilha)); // Aloca dinamicamente a memória necessária para a criação de uma nova pilha
    p->topo = NULL; // Aponta o topo da pilha para NULL
    return p; // Retorna o ponteiro para a nova pilha
}

int vazia(pilha *p){
    return (p->topo == NULL);
}

void push(pilha *p, float dado){
    no *novo = (no*) malloc(sizeof(no)); // Aloca um novo nó("no") na memória
    novo->info = dado; // Preenche o campo info desse nó com o dado passado como parâmetro
    novo->prox = p->topo; // Atualiza o campo prox desse nó para apontar para o nó que estava no topo da pilha "p" antes da inserção
    p->topo = novo; // Atualiza o ponteiro "topo" da pilha "p" para apontar para o novo nó, fazendo com que ele se torne o novo topo da pilha
}

float pop(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    float temp = p->topo->info; // Armazena o valor do topo da pilha em uma variável temporária
    no *aux = p->topo; // Cria um ponteiro auxiliar "aux" e aponta para o mesmo nó que está no topo da pilha 
    p->topo = aux->prox; // A nova referência do topo da pilha será o próximo nó("prox") do nó que acabou de ser removido(topo agora é o elemento que estava embaixo)
    free(aux); // Libera a memória alocada para o nó que foi removido
    return temp; // Retorna o valor do elemento que foi removido
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
        no *temp = (no*) malloc(sizeof(temp));
        free(aux);
        aux = temp;
    }
    free(p);
}