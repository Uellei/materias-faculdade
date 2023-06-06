/*
    A estrutura de dados hash é uma técnica usada para armazenar e recuperar dados de forma eficiente.
    Ela é baseada em uma função de hash, que mapeia uma chave(conjunto de dados) para um valor inteiro, conhecido como hash code.
    Esse hash code é usado como um índice para acessar e armazenar os dados em uma estrutura de dados chamada tabela hash.
    É essencialmente um vetor de tamnho fixo, onde cada elemento é chamado de "slot". Cada slot da tabela hash armazena um item de dados, que pode ser uma chave-valor, um objeto, uma lista, entre outros.
    A função de hash determina em qual slot da tabela um item deve ser armazenado com base em seu hash code.
    A principal vantagem da estrutura de dados hash é a sua capacidade de realizar operações de inserção, busca e remoção em tempo médio constante (O(1)), desde que a função de hash seja bem projetada e as colisões sejam minimizadas.
    No entanto, em casos de colisões frequentes ou tabe hash mal dimensionadas, o desempenho pode degradas para tempo médio linear (O(n)).
*/

#include <stdlib.h>
#include <stdio.h>

#define TAM_MAX 7

typedef struct n{
    int info;
    struct n *prox;
}no;

int f_hash(float valor){
    return abs(valor) % TAM_MAX;
}
/*
    Função f_hash:
    Descrição: A função f_hash é uma função de hash que recebe um valor float e retorna um índice para ser usado na tabela de hash.
    Parâmetro: Valor do tipo float que representa o valor que será inserido na tabela.
    Retorno: Retorna um valor inteiro que representa o índice onde o valor deve ser armazenado na tabela de hash.
    Memorização:
        - Utiliza um operador abs para obter o valor absoluto do valor, garantindo que o resultado seja sempre não negativo.
        - O opera o % é aplicado ao valor absoluto de valor dividido pelo valor máximo definido na constante TAM_MAX.
        - O resultado final é retornado como o índice onde o valor será armazenado na tabela de hash.

*/

void inicializa(no **hash){
    int i;
    for(i=0;i<TAM_MAX;i++){
        hash[i] = NULL;
    }
}
/*
    Função inicializa:
    Descrição: A função inicializa é responsável por inicializar todos os elementos de um vetor de ponteiros para nós(hash) como valor NULL.
    Parâmetro: O parâmetro hash é um ponteiro para um ponteiro para o nó(no**), que representa o vetor de ponteiros para nós(hash) a ser inicializado.
    Memorização:
        - Percorre todos os índices do vetor de ponteiros para nós e atribui NULL para cada posição.
        - Utilizando um laço de repetição que varre o vetor de 0 até TAM_MAX.
*/

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
        no *temp = hash[pos]; // Retorna o ponteiro para o nó na posição "pos"
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
/*
    Função insere:
    Descrição: A função insere é responsável por inserir um valor em uma tabela hash representada por um vetor de ponteiros para nós(hash).
    Parâmetros: Um ponteiro para um ponteiro nó(no**) que representa o vetor de ponteiros para nós(hash), e o valor floar que será inserido.
    Memorização:
        - Calcula a posição de inserção na tabela utilizando a função f_hash.
        - Aloca a memória para um novo nó(novo) e armazena o valor inserido e aponta o prox para NULL.
        - É criado um ponteiro para ponteiro para nó(lista) que aponta para o endereço do vetor hash na posição calculada.
        - Se estiver vazia, o ponteiro do vetor hash na posição calculada é atualizada para apontar para o novo nó.
        - Caso contrário, verifica se o valor ja foi inserido na tabela.
        - Se ainda nao foi inserido, percorre o ponteiro do vetor hash na posição calculada enquanto nao for null.
        - Atualiza o campo prox do ultimo nó para apontar para o novo nó.
*/

void apaga(no **hash, float valor){
    int pos = f_hash(valor); // Calcula a posição no hash para o valor fornecido. Armazena a posição na variável
    no **lista = &hash[pos]; // Inicializa o ponteiro "lista" com o endereço da posição "pos" do hash. Será usado para percorr a lista encadeada na posição "pos".
    no* ant = NULL; // Inicializado como null, mas será usado para guardar o nó anterior ao nó que esta sendo examinado durante a iteração na lista. 
    no* aux = *lista; // Inicializado com o nó inicial da lista encadeada na posição "pos" do hash.
    while(aux != NULL && aux->info != valor){ // Veririfa se o valor não é null e se o valor no nó atual é diferente do valor que se deseja remover.
        ant = aux; // Atualiza o ponteiro para apontar para o nó atual
        aux = aux->prox; // Atualiza o ponteiro para apontar para o próximo nó na lista.
    }
    if(aux == NULL){ // Após sair do loop, se aux for NULL significa que o valor não foi encontrado
        printf("Valor não encontrado");
        return;
    }
    if(ant == NULL){ // Se "ant" for NULL, significa que o nó a ser removido é o nó inicial da lista.
        hash[pos] = aux->prox; // Atualiza o ponteiro "hash[pos]" para apontar para o próximo nó.
    } else{ // Se "ant" não for null, significa que o nó a ser removido nao é o inicial
        ant->prox = aux->prox; // Atualiza o ponteiro "ant->prox" para apontar para o próximo nó.
    }
    free(aux); // libera o nó aux da memória.
}