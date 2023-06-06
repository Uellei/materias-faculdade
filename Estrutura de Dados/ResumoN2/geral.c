// PILHA
// É uma estrutura de dados linear que segue o princípio LIFO(Last In, First Out), o que significa que o último elemento inserido é o primeiro a ser removido.
// Insere
void push(pilha *p, float dado){
    no *novo = (no*) malloc(sizeof(no));
    novo->info = dado;
    novo->prox = p->topo;
    p->topo = novo;
}
// Remove
float pop(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    float temp = p->topo->info;
    no *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    return temp; 
}
// Exercício 1 - Concatenar pilha
void concatena_pilhas(pilha *p1, pilha *p2){
    while(!vazia(p2)){ // Enquanto a pilha 2 não for vazia, ele faz:
        float elemento = pop(p2); // Como a função pop remove um elemento da pilha e retorna o seu valor, salvei o valor em uma variavel
        push(p1, elemento); // Adiciono então o valor que foi salvo do elemento na nova pilha
    }
}

// Exercício 2
#define MAX 7

typedef struct p{
    int n;// Quantidade elementos
    float vet[MAX];
}pilhavet;

int cheia(pilhavet p){
    return (p.n == MAX);
}

void push(pilhavet *p, float dado){
    if(cheia(*p)){
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
    p->vet[p->n] = dado;
    p->n++;
}

int main(){
    pilhavet pilha;
    pilha.n = 0;
    
    push(&pilha, 1.5);
    push(&pilha, 2.5);
    push(&pilha, 3.5);
    push(&pilha, 4.5);
    push(&pilha, 5.5);
    push(&pilha, 6.5);
    
    if(cheia(pilha)){
        printf("A pilha esta cheia\n");
    } else
        printf("A pilha não esta cheia\n");
}

// FILA
// É uma estrutura de dados linear que segue o princípio FIFO(First In, First Out), o que significa que o primeiro elemento inserido é o primeiro elemento a ser removido.
// Insere
void insere(fila* f, int dado){
    no* novo = (no*) malloc(sizeof(no));
    novo->info = dado;
    novo->prox = NULL;
    if(f->fim != NULL){
        f->fim->prox = novo;
    }
    f->fim = novo;
    if(f->inicio == NULL){
        f->inicio = f->fim;
    }
}
// Remove
int remover(fila* f){
    int temp;
    if(vazia(f)){
        printf("Fila vazia\n");
        exit(1);

    }
    temp = f->inicio->info;
    no *aux = f->inicio->prox;
    free(f->inicio);
    f->inicio = aux;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    return temp;
}
// Exercício 1 - Separa Filas
void separa_filas (fila* f, fila* f_pares, fila* f_impares){
    int temp;
    while(!vazia(f)){
        temp=remover(f);
        if(temp%2==0){
            insere(f_pares,temp);
        }else{
            insere(f_impares,temp);
        }
    }
}
// Exercício 2 - Inverter Fila
void inverte(fila *f){
    if(vazia(f)){
        return;
    }
    int valor = remover(f);
    inverte(f);
    insere(f, valor);
}

// Árvore
// É uma estrutura de dados hierárquica em que os elemento são organizados em nós(nodes). Cada nó pode ter zero ou mais nós filhos, exceto o nó do topo, chamado de nó raiz.
/*
    Nó: Uma entidade que armazena o valor e pode ter referência para outros nós. É a bolinha com os valores
    Folha: É um nó que não tem filhos.
    Galho: É um nó que tem pelo menos um filho. A linha que liga.
    Ramificações: Se refere as conexões entre os nós de uma árvore.
*/
// Exercício 1 - Quantidade de folhas
int quant_folhas(arv* a) {
    if (a == NULL) return NULL;
    if (a->esq == NULL && a->dir == NULL) return 1;
    int folhas_esq = quant_folhas(a->esq);
    int folhas_dir = quant_folhas(a->dir);
    return folhas_esq + folhas_dir;
}

// Exercício 2 - Altura da árvore
int altura(arv* a){
    if(a != NULL){
        int altura_esq = altura(a->esq);
        int altura_dir = altura(a->dir);
        if(altura_esq > altura_dir){
            return altura_esq + 1;
        } else {
            return altura_dir + 1;
        }
    }
}

// Exercício 3 - Exluir Folhas
arv* exclui_folhas(arv *a){
    if(a==NULL) return a;
    if(a->esq==NULL && a->dir==NULL){
        free(a);
        return NULL;
    }
    a->esq=exclui_folhas(a->esq);
    a->dir=exclui_folhas(a->dir);
    return a;

}

// Exercício 4 - Contar elementos
int quant_elementos(arv *a){
    if(a==NULL) return 0;
    return 1+quant_elementos(a->esq) +quant_elementos(a->dir);
}

// HASH
// É uma estrutura de dados que permite armazenar e recuperar informações de forma eficiente.
