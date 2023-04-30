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

int vazia (fila* f){
    return(f->inicio==NULL);
}

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