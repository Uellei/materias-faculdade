#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
    int info;
    struct tree *esq;
    struct tree *dir;
}arv;

arv* cria(){
    return NULL;
}

int vazia (arv* a){
    return a == NULL;
}

arv* insere (arv* a, int dado){ // Define uma função chamada "insere" que recebe um ponteiro para uma árvore e um valor inteiro a ser inserido na árvore
    if(a==NULL){ // Verifica se a árvore é nula (ou seja, se está vazia)
        a = (arv*) malloc(sizeof(arv)); // Aloca espaço na memória para um novo nó da árvore
        a->info = dado; // define o valor do nó recém-criado como sendo o valor passado para a função
        a->esq = a->dir = NULL; // Como o elemento acabou de ser inserido ele não tem elementos na esquerda ou a direita, e define os ponteiros esq, dir do novo nó como nulos.
    } else if(dado < a->info){ // Se a árvore não estiver vazia, verifica se o valor passado é menor do que o valor armazenado no nó atual.
        a->esq = insere(a->esq, dado); // Se o valor for menor, cahama função "insere" recursivamente, passamento como paraâmetro o ponteiro subárvore esquerda e o valor inserido
    } else { // se o valor for maior ou igual ao valor armazenado no nó autal
        a->dir = insere(a->dir, dado); // Chama a função "insere" recursivamente, passando como parâmetro o ponteiro para a subárvore direita e o valor a ser inserido
    }
    return a;
}

arv* libera (arv* a){
    if(!vazia(a)){ ;// Verifica se a árvore não esta vazia
        libera(a->esq); // Chama recursivamente a função "libera" para liberar a memória da subárvore esquerda
        libera(a->dir); // Chama recursivamente a função "libera" para liberar a memória da subárvore direita
        free(a); // Libera a memória alocada para o nó atual
    }
    return NULL; // Retorna um ponteiro NULL para indicar que a árovre foi liberada
}

void imprime(arv* a){
    if(a != NULL){ // Verifica se o nó atual não é nulo
        imprime(a->esq); // Chama a função "imprime" recursivamente passando como parâmetro o nó esquerdo da árvore atual(se existir).
        printf("%d\n", a->info); // Imprime na tela o valor armazenado no nó atual da árvore
        imprime(a->dir); // Chama a função "imprime" recursivamente passando como parâmetro o nó direito da árvore atual(se existir).
    }
}

arv* busca(arv* a, int dado){ // Recebe como parâmetros, um ponteiro para uma árvore e um inteiro
    if(a == NULL) return NULL; // Verifica se o ponteiro da árvore é nulo, se sim retorna null
    else if(a->info > dado){ // Se o elemento da raiz da árvore é maior que o elemento que está sendo buscado, então o elemento pode estar na subárvore esquerda
        return busca(a->esq, dado); // Realiza a chamada recursiva para buscar o elemento na subárvore esquerda
    } else if(a->info < dado){ // se o elemento da raiz da árvore é menor que o elemento que está sendo buscado, então o elemento pode estar na subárvore direita
        return busca(a->dir, dado); // Realiza uma chamada recursiva para buscar o elemento na subárvore direita
    } else { // Sobra apenas a possibilidade de o elemento ser igual ao elemento da raiz
        return a; // Retorna então o ponteiro para a árvore atual, pois foi encontrado
    }
}

arv* retira(arv* a, int dado){ // Recebece como parâmetros, uma árvore "a" e um valor "dado" para ser removido da árvore
    if(a == NULL) return NULL; // Caso a árvore seja vazia, não há nada a ser removido então retorna NULL
    else if(a->info > dado){ 
        a->esq = retira(a->esq, dado);// Se o valor a ser removido é menor que o valor do nó atual, a função é chamada recursivamente para a subárvore esquerda
    } else if(a->info < dado){
        a->dir = retira(a->dir, dado); // Se o valor a ser removido é maior que o valor do nó atual, a função é chamada recursivamente para a subárvore direita
    } else{
        if (a->esq == NULL && a->dir == NULL){ // Esse é o caso em que o nó a ser removido não tem filhos. Nesse caso, o nó é simplesmente removido com "free" e "a" é definido como NULL
            free(a);
            a = NULL;
        }
        else if(a->esq == NULL){ // Esse é o caso em que o nó a ser removido tem apenas um filho, que é o filho da direita. Nesse caso, o nó é removido e substituído pelo seu filho à direta
            arv* t = a;
            a = a->dir;
            free(t);
        }
        else if(a->dir == NULL){ // Esse é o caso em que o nó a ser removido tem apenas um filho, que é o filho da esquerda. Nesse caso, o nó é removido e substituído pelo seu filho à esquerda.
            arv* t = a;
            a = a->esq;
            free(t);
        } else { // Esse é o caso em que o nó a ser removido tem dois filhos. Nesse caso, é necessário encontrar o nó com o maior valor na subárvore esquerda e trocar seus valores com o nó a ser removido. Isso garante que a propriedade da árvore binária de busca seja mantida após a remoção
            arv* f = a->esq; // Aqui percorre a subárvore esquerda do nó a ser removido para encontrar o nó com o maior valor
            while(f->dir != NULL){ // Continua indo para a direita até que encontre o maior valor
                f = f->dir;
            }
            a->info = f->info;
            f->info = dado; // Agora que encontrou o nó com o maior valor, troca o seu valor com o nó a ser removido
            a->esq = retira(a->esq, dado); // Por fim, a função é chamada recursivamente para remover o valor da subárvore a esquerda
        }
    }
    return a; // Retorna a árvore atualizada após a remoção do nó
}