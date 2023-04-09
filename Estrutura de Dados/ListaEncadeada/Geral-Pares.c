// Uma lista encadeada é uma estrutura de dados em que cada elemento (nó) armazena um valor e um ponteiro (endereço de memória) para o 
// próximo elemento na lista. Essa estrutura de dados é bastante útil quando não se sabe o tamanho total da lista ou quando os elementos da 
// lista precisam ser inseridos ou removidos com frequência, já que a lista encadeada permite inserções e remoções em tempo constante (O(1)).

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int item;
    struct no* prox;
}lista;

int pares(lista *no){
    if(no != NULL){
        if(no->item %2 == 0){
            return 1+pares(no->prox);
        } else{
            return pares(no->prox);
        }
    } else return 0;
}

int main(){
    // Alocar memória dinamicamente para armazenar a estrutura de dados da lista encadeada, alocando assim cada nó.
    lista *no1 = malloc(sizeof(lista));
    lista *no2 = malloc(sizeof(lista));
    lista *no3 = malloc(sizeof(lista));
    lista *no4 = malloc(sizeof(lista));

    // Atribui o valor(item) de cada nó
    no1->item = 1;
    no2->item = 2;
    no3->item = 3;
    no4->item = 4;

    // Aponta o próximo valor de cada nó, e o ultimo aponta para NULL.
    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = NULL;

    int count = pares(no1);
    printf("Numero de elementos pares: %i", count);

    free(no1);
    free(no2);
    free(no3);
    free(no4);

    return 0;

    // Ao criar a lista encadeada, o campo prox de cada nó é atribuito manualmente na criação, usando o endereço de memória do próximo nó a ser inserido na lista.
    // Na linha 'no1->prox = n2; estamos atribuindo ao campo 'prox' do nó 'no1' o endereço de memória do nó 'no2'.
    // Dessa forma, quando passa um ponteiro para a função, a função tem acesso a todos os elementos da lista porque cada nó contém o endereço do próximo nó. Assim, a função pode percorrer a lista recursivamente usando o campo 'prox' de cada nó até chegar no final da lista.
}



lista* insere(lista *no, int valor){
    lista *novo = (lista*) malloc(sizeof(lista)); // Aloca dinamicamente a memória para um novo nó da lista
    novo->item = valor; // Atribui o valor passado como parâmetro(valor) á variavel item do novo nó.
    novo->prox = no; // Faz com que o novo nó aponte para o antifo início da lista 'no' através do campo 'prox'. Dessa forma, o novo nó se torna o novo início da lista;
    return novo;
}

void libera(lista* no){
    lista *aux = no; // Ponteiro auxiliar inicializando com o valor de 'no'. A ideia é percorrer a lista, começando pelo primeiro nó, e liberar a memória de cada nó um por um.
    while(aux != NULL){
        lista *n = aux->prox; // Ponteiro 'n' que recebe o valor do ponteiro 'prox' do nó atual, apontado por 'aux'. É feito para guardar o endereço do próximo nó antes de liberar a memória do nó atual. 
        free(aux); // Libera a memória do nó atual, apontado por 'aux'.
        aux = n; // aux é atualizado com o valor 'n' que representa o próximo nó da lista.
    }
}

int main(){
    lista *no = NULL;

    no = insere(no, 6);
    no = insere(no, 4);
    no = insere(no, 2);
    no = insere(no, 3);
    no = insere(no, 56);
    no = insere(no, 5);
    no = insere(no, 9);

    int count = pares(no);
    printf("A lista tem %d elementos pares.", count);


    libera(no);


    // Versão simplificada da função libera
    // while(no != NULL){
    // lista *aux = no;
    // no = no->prox;
    // free(aux);
// }

    return 0;
}