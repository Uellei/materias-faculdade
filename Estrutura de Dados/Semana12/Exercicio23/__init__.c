#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MAX 7

typedef struct n {
    float info;
    struct n *prox;
}no;


int f_hash(float valor) {
    return abs(valor) % TAM_MAX;
}
/**
Inicializa a tabela hash
 */
void inicializa(no **hash) {
    int i;
    for(i=0; i<TAM_MAX; i++)
        hash[i]=NULL;
}

void insere(no **hash, float valor){
    int pos = f_hash(valor); // Retorna uma posição do hash para inserir o valor
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL){
        printf("Erro!\n");
        exit(1);
    }
    novo->info = valor;
    novo->prox = NULL;
    no **lista = &hash[pos]; // O ponteiro "lista" é inicializado com o endereço do elemento do hash na posição "pos".
    if(*lista == NULL){ // Se o elemento do hash na posição "pos" está vazio 
        *lista = novo; // O novo nó é inserido nessa posição, atualizando o ponteiro "lista" para apontar para o novo nó.
        printf("Inserido HASH[%i]\n", pos);
    } else { // Se o elemento na posição "pos" já tiver um nó, ocorre uma colisão.
        printf("Inserido com Colisao HASH[%i]\n", pos);
        no *temp = hash[pos]; // Retorna o ponteiro da posição inicial da fila de colisões
        if(temp->info == valor){ // Verifica se o valor já esta presente
            printf("Valor %.2f ja inserido\n", valor);
        }
        while(temp->prox != NULL){ // Percorre até chegar no final da lista encadeada (NULL)
            if(temp->info == valor){ // Verifica se o valor já existe no meio da lista
                printf("Valor %2.f ja inserido\n", valor);
            }
            temp = temp->prox; // Atualiza o campo para o próximo
        }
        temp->prox = novo; // Atualiza o campo "prox" do último nó para apontar para o novo nó.
    }
}

void apaga(no **hash, float valor) {
    int pos = f_hash(valor);
    no **lista = &hash[pos];
    no* ant = NULL;
    no* aux = *lista;
    while (aux != NULL && aux->info != valor) {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("Valor nao encontrado!\n");
        return;
    }
    if (ant == NULL) hash[pos] = aux->prox;
    else ant->prox = aux->prox;
    free(aux);
}

no* busca(no **hash, float valor) {
    int pos = f_hash(valor);
    no *lista = hash[pos];
    while (lista != NULL) {
        if (valor == lista->info) return lista;
        lista = lista->prox;
    }
    return NULL;
}

void imprime(no **hash) {
    printf("\nTabela Hash\n");
    int i;
    for (i=0; i<TAM_MAX; i++) {
        printf("HASH[%d]\t",i);
        no *lista = hash[i];
        while (lista != NULL) {
            printf(" -> %.2f\t",lista->info);
            lista = lista->prox;
        }
        printf("\n");
    }
}

void libera(no **hash) {
    int i;
    no *aux;
    for(i=0; i<TAM_MAX; i++) {
        no **lista=&hash[i];
        while(*lista!= NULL) {
            aux = (*lista)->prox;
            free(*lista);
            *lista = aux;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int numero = 11;
    
    no *tabela_hash[TAM_MAX];
    inicializa(tabela_hash);
    float valor;
    int i;
    for(i=0;i<10;i++){
        printf("Digite o %io valor\n",i+1);
        scanf("%f",&valor);
        insere(tabela_hash,valor);
        imprime(tabela_hash);
    }
    no *temp=busca(tabela_hash,5);
    if(temp!=NULL) printf("Encontrou: %.2f\n",temp->info);
    while(1){
        printf("Digite o valor para ser apagado\n");
        scanf("%f",&valor);
        if(valor<0) break;
        apaga(tabela_hash,valor);
        imprime(tabela_hash);
    }
    libera(tabela_hash);
    
    return 0;
}
