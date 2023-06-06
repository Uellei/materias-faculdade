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

void insere(no **hash, float valor) {
    int pos = f_hash(valor);//Retorna o valor que será utilizado como posição segundo DH.
    no* novo = (no *) malloc(sizeof(no)); //Aloca um ponteiro de ponteiro para a estrutura HASH
    if (novo==NULL) { //No caso em que o novo elemento aponte para NULL, um erro na alocação aconteceu.
        printf("Erro!\n");
        exit(1);
    }
    novo->info=valor; // Preenche o novo elemento com um valor
    novo->prox=NULL;  //NULL para o próximo elemento na estrutura de alocação HASH
    no **lista = &hash[pos]; //Aqui, segundo a posição do elemento na tabela HASH, pega o endereço da lista de elementos da posição /e assina para o hash.
    if (*lista == NULL) { //Se a Lista ainda não estiver sendo utilizada, significa que é o primeiro elemento dessa posição
        *lista = novo; //Então o novo elemento é atribuído para este elemento na lista
        printf("Inserido HASH[%d]\n",pos); // Imprimimos então o elemento HASH inserido na posição
    }
    else { //Caso contrário, caso o primeiro elemento na tabela HASH tenha sido preenchido, o próximo elemento que compartilha a posiçãoo é então inserido na fila, ou seja, quando há colisão, o elemento é inserido em uma fila.
        printf("Inserido com Colisao HASH[%d]\n",pos);//imprime a posição que gerou a colisão.
        no *temp= hash[pos]; //retorna o ponteiro da posição inicial da fila de colisões
        if(temp->info==valor)//checa se o valor a ser inserido, é o mesmo valor da posição inicial da fila de colisões
            printf("Valor %.2f ja inserido\n",valor); //imprime o valor
        
        /**
         Checa todos os elemento da lista de colisões e informa se há valores repetidos
         */
        while (temp->prox != NULL){
            if(temp->info==valor)
                printf("Valor %.2f ja inserido\n",valor);
            temp=temp->prox;
        }
        temp->prox=novo;//Insere o novo elemento no final da lista.
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
    
    numero%2==0 ? printf("true"): printf("false");
    
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
