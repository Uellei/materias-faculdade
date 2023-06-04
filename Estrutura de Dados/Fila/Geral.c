/*
    Uma fila é uma estrutura de dados do tipo FIFO(First-In-First-Out), o primeiro elemento a ser inserido na fila será o primeiro a ser removido. 
    Semelhando a uma fila de pessoas em um banco, onde o primeiro a chegar é o primeiroa ser atendido.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    float info;
    struct n *prox;
}no;

typedef struct f{
    no *inicio;
    no *fim;
    int tamanho;
}fila;

fila* cria(){
    fila* f = (fila*) malloc(sizeof(fila)); // Aloca dinamicamente a memória necessária para a criação de novo elemento da fila
    f->inicio = NULL; // Aponta o inicio da fila para NULL
    f->fim = NULL; // Aponta o fim da fila para NULL
    return f; // Retorna o ponteiro para a nova fila
}
/*
    Função cria:
    Descrição: Essa função cria e inicializa uma fila vazia.
    Retorno: Retorna um ponteiro para a fila recém-criada.
    Memorização:
        - Aloca memória para a estrutura fila.
        - Inicializa os ponteiro de início e fim como NULL.
        - Retorna o ponteiro para a fila.
*/

int vazia (fila* f){
    return(f->inicio==NULL);
}
/*
    Função vazia:
    Descrição: Essa função verifica se a fila esta vazia.
    Parâmetros: Recebe um ponteiro para a fila "f".
    Retorno: Retorna 1 se a fila estiver vazia e 0 caso contrário.
    Memorização:
        - Verifica se o ponteiro de início da fila é NULL.
        - Se for, fila vazia, então retorna 1. Caso contrário, retorna 0.
*/

void insere(fila* f, float dado){
    no* novo = (no*) malloc(sizeof(no)); // Declara um ponteiro do tipo "no" que recebe o endereço de uma área de memória alocada dinamicamente
    novo->info = dado; // Atribui o valor do parâmetro "dado" passado na função à variável info do nó "novo"
    novo->prox = NULL; // Inicialização do nó "novo" como "NULL", como o novo elemento é o ultimo da fila, já que seu proximo elemento ainda não esta definido
    if(f->fim != NULL) // Confere se a fila não está vazia
        f->fim->prox = novo; // O campo "prox" do último nó da fila("f->fim") é atualizado para apontar para o novo nó("novo"), indicando que o novo nó será o próximo após o último nó
    f->fim = novo; // Atualiza o ponteiro "fim" da fila para apontar para o "novo" nó indicando que ele agora é o último nó da fila
    if(f->inicio == NULL) // Verifia se a lista está vazia
        f->inicio = f->fim; // Atualiza o ponteiro "inicio" da fila para apontar para o "novo" nó, indicando agora que é o primeiro nó da fila
}
/*
    Função insere:
    Descrição: Essa função insere um elemento no fim da fila.
    Parâmetros: Recebe um ponteiro para a fila "f" e o valor do novo elemento "dado".
    Memorização:
        - Cria um novo nó e aloca memória para ele.
        - Define o valor "dado" para esse novo nó.
        - Define o campo "prox" do novo nó como NULL.
        - Verifica se a fila não estava vazia e ajusta o ponteiro "prox" do último nó para apontar para o novo nó.
        - Atualiza o ponteiro de fim para o novo nó.
        - Se a fila estava vazia(se o ponteiro de início é NULL), atualiza o ponteiro de início para o novo nó.
*/

float remove(fila *f){
    float temp; // Declara uma função temporaria
    if(vazia(f)){ // Verifica se a fila esta vazia
        printf("Fila vazia\n");
        exit(1);
    }
    temp = f->inicio->info; // Armazena o valor do primeiro elemento da fila 
    no *aux = f->inicio->prox; // Cria um ponteiro "aux" que aponta para o segundo elemento da fila
    free(f->inicio); // Libera a memoria do primeiro elemento da fila
    f->inicio = aux; // Faz o ponteiro "inicio" apontar para o segundo elemento da fila
    if(f->inicio == NULL) // Verifica se a fila ficou vazia apos a remoção do primeiro elemento
        f->fim = NULL; // Faz o ponteiro "fim" apontar para "NULL"
    return temp; // Retorna o valor do primeiro elemento da fila que foi removido
}
/*
    Função remove:
    Descrição: Essa função remove o elemento do início da fila.
    Parâmetros: Recebe um ponteiro para a fila "f".
    Retorno: Retorna o valor do elemento removido.
    Memorização:
        - Verifica se a fila está vazia, se estiver imprime uma mensagem de erro e encerra o programa.
        - Caso contrário, armazena o valor do elemento no início da fila em uma variável "temp".
        - Atualiza o ponteiro de início para apontar para o próximo nó.
        - Libera a memória do nó removido.
        - Verifica se a fila ficou vazia(ponteiro de início == NULL), atualizando o ponteiro de fim para NULL.
        - Retorna o valor armazenado em "temp".
*/

void imprime(fila *f){
    no* aux;
    for(aux=f->inicio;aux!=NULL;aux=aux->prox)
        printf("%f\n", aux->info);
}

void libera(fila *f){
    no* aux = f->inicio;
    while(aux!=NULL){
        no* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(f);
}