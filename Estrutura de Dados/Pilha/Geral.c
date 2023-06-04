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


pilha* cria(){
    pilha *p = (pilha*) malloc(sizeof(pilha)); // Aloca dinamicamente a memória necessária para a criação de uma nova pilha
    p->topo = NULL; // Aponta o topo da pilha para NULL
    return p; // Retorna o ponteiro para a nova pilha
}
/*
    Função cria:
    Descrição: Essa função cria e inicializa uma pilha vazia.
    Retorno: Retorna um ponteiro para a pilha recém-criada.
    Memorização: 
        - Aloca memória para a estrutura da pilha 
        - Inicializ ao topo com NULL
        - Retorna o ponteiro para a pilha
*/

int vazia(pilha *p){
    return (p->topo == NULL);
}
/*
    Função vazia:
    Descrição: Essa função confere se a pilha está vazia, ou seja, se o topo aponta para NULL
    Parâmetro: Recebe um ponteiro para a pilha "p"
    Retorno: Retorna  1 se a pilha estiver vazia e 0 caso contrário
    Memorização:
        - Condicional para verificar se "p->topo" é igual a NULL
*/

void push(pilha *p, float dado){
    no *novo = (no*) malloc(sizeof(no)); // Aloca um novo nó("no") na memória
    novo->info = dado; // Preenche o campo info desse nó com o dado passado como parâmetro
    novo->prox = p->topo; // Atualiza o campo prox desse nó para apontar para o nó que estava no topo da pilha "p" antes da inserção
    p->topo = novo; // Atualiza o ponteiro "topo" da pilha "p" para apontar para o novo nó, fazendo com que ele se torne o novo topo da pilha
}
/*
    Função push:
    Descrição: Adiciona um novo elemento no topo da pilha
    Parâmetros: Recebe um ponteiro para a pilha "p" e o valor do novo elemento "dado"
    Memorização:
        - Aloca memória para um novo nó
        - Define o valor "dado" para esse novo nó
        - Faz o novo nó apontar para o antigo topo da pilha
        - Atualiza o topo para apontar para o novo nó
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
    Função pop:
    Descrição: Remove e retorna o elemento do topo da pilha
    Parâmetro: Recebe um ponteiro para a pilha "p"
    Retorno: Retorn ao valor do elemento removido do topo da pilha
    Memorização:
        - Verifica se a pilha está vazia, se estiver imprime uma mensagem de erro e encerra o programa
        - Caso contrário, armazena o valor do topo em uma variável temporária
        - Atualiza o topo para apontar para o próximo elemento
        - Retorna o valor armazenado na variável temporária
*/

void imprime(pilha *p){
    no *aux;
    for(aux=p->topo;aux!=NULL;aux=aux->prox){
        printf("%f\n", aux->info);
    }
}
/*
    Função imprime:

Descrição: Essa função imprime os elementos da pilha, começando do topo e indo até a base.
Parâmetro: Recebe um ponteiro para a pilha p.
Memorização: 
    - Utiliza um ponteiro auxiliar "aux" para percorrer a pilha a partir do topo
    - Itera enquanto o "aux" não for NULL, imprimindo o valor "aux->info" e movendo o "aux" para o próximo nó
*/

void libera(pilha *p){
    no *aux = p->topo;
    while(aux!=NULL){
        no *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(p);
}
/*
Função libera:
Descrição: Essa função libera a memória alocada para a pilha e seus nós.
Parâmetro: Recebe um ponteiro para a pilha p.
Memorização: 
    - Utiliza um ponteiro auxiliar "aux" para percorrer a pilha a partir do topo
    - Itera enquanto o "aux" não for NULL, liberando a memória do nó atual "aux" e movendo "aux" para o próximo nó
    - Libera a memória da estrutura da pilha "p"
*/