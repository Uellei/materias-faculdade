#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    int info;
    struct tree *esq;
    struct tree *dir;
}arv;

arv* cria(){
    return NULL;
}

int vazia(arv* a){
    return a == NULL;
}

arv* insere(arv* a, int dado){
    if(vazia(a)){
        a = (arv*) malloc(sizeof(arv));
        a->info = dado;
        a->esq = a->dir = NULL;
    } else if(dado < a->info){
        a->esq = insere(a->esq, dado);
    } else{
        a->dir = insere(a->dir, dado);
    }
    return a;
}

arv* busca(arv* a, int dado){
    if(a==NULL) return NULL;
    else if(a->info > dado){
        return busca(a->esq, dado);
    } else if(a->info < dado){
        return busca(a->dir, dado);
    } else{
        return a;
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


void imprime(arv* a){
    if(a != NULL){
        imprime(a->esq); 
        printf("%d\n", a->info); 
    }
}

int altura(arv* a){
    if(a==NULL){
        return 0;
    } else{
        int altura_esq = altura(a->esq);
        int altura_dir = altura(a->dir);
        if(altura_esq > altura_dir) return altura_esq + 1;
        else return altura_dir + 1;
    }
}

int main(){
     arv* arvore = cria();

    arvore = insere(arvore, 10);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 20);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 3);

    int tamanho = altura(arvore);
    printf("Altura da arvore: %i", tamanho);
    return 0;
}