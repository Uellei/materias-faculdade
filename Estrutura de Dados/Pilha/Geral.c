/* 
    É uma coleção linear que segue a abordagem Last-In-First-Out (LIFO), ou seja, o último elemento inserido é o primeiro a ser removido. 
    Amplamente utilizada em algoritmos e programas que requerem um comportamento de dados no estilo LIFO.
*/
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
/*
    1° Criar um malloc para alocar a memória de um ponteiro do tipo "pilha"
    2° Atribuir NULL para o topo da pilha(p->topo)
    3° Retornar o ponteiro
*/

int vazia(pilha *p){
    return (p->topo == NULL);
}
/*
    1° Confere se o topo da pilha é NULL, e se for ele retorna, se não ele continua conferindo
*/

void push(pilha *p, float dado){
    no *novo = (no*) malloc(sizeof(no)); // Aloca um novo nó("no") na memória
    novo->info = dado; // Preenche o campo info desse nó com o dado passado como parâmetro
    novo->prox = p->topo; // Atualiza o campo prox desse nó para apontar para o nó que estava no topo da pilha "p" antes da inserção
    p->topo = novo; // Atualiza o ponteiro "topo" da pilha "p" para apontar para o novo nó, fazendo com que ele se torne o novo topo da pilha
}
/*
    1° Cria um malloc para alocar a memória de um ponteiro novo do tipo "no"
    2° Sabendo que a struct "no" tem um info, atribui-se para novo->info o valor "dado" passado como parâmetro na função
    3° Sabendo que a struct "no" tem um struct *n prox, faz com que o novo->prox aponte para o antigo valor que estava no topo
    4° p->topo agora vai apontar para o novo elemento "novo", virando o topo da pilha
*/

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
/*
    1° Condicional para conferir se a pilha esta vazia ou não
    2° Se não for vazia, armazenar o valor do topo da pilha(p->topo->info) em uma variavel temporaria
    3° Criar um ponteiro do auxiliar do tipo no, para apontar para o topo atual da pilha
    4° p->topo agora recebe aux->prox, sendo assim, o topo agora é o proximo elemento que estava embaixo
    5° Liberar a memória alocada para o nó auxiliar que foi removido
    6° Retornar o valor do elemento que foi removido(p->topo->info)
*/

void imprime(pilha *p){
    no *aux;
    for(aux=p->topo;aux!=NULL;aux=aux->prox){
        printf("%f\n", aux->info);
    }
}
/*
    1° Criar um ponteiro auxiliar do tipo "no"
    2° Fazer um for com aux=p->topo, enquando aux!=NULL, indo sempro para o proximo, aux=aux->prox, ele começa no topo e vai descendo ate aux ser NULL
*/

void libera(pilha *p){
    no *aux = p->topo;
    while(aux!=NULL){
        no *temp = (no*) malloc(sizeof(temp));
        free(aux);
        aux = temp;
    }
    free(p);
}
/*
    1° Criar um ponteiro auxiliar do tipo "no" que receba o p->topo
    2° Equanto o topo(auxiliar) for != NULL
    3° Criar malloc temp do tipo "no"
    4° Liberar o auxiliar
    5° Igualar o auxiliar ao temporario
*/