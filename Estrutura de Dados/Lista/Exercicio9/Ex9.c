#include <stdlib.h>
#include <stdio.h>

typedef struct prod {
char nome[30]; /* Nome do produto */
int codigo; /* Codigo do produto */
float preco; /* Preco do produto */
}produtos;

void main(){
    int i;
    produtos *p = (produtos*)malloc(sizeof(produtos)*2);
    for(i=0;i<2;i++){
        printf("Digite o nome %i° do produto: ", i+1); scanf("%s", &p[i].nome);
        printf("Digite o codigo %i° do produto: ", i+1); scanf("%i", &p[i].codigo);
        printf("Digite o preco %i° do produto: ", i+1); scanf("%f", &p[i].preco);
    }
    printf("Nome\tCodigo\tPreco\n");
    for(i=0;i<2;i++){
        printf("%s\t", p[i].nome);
        printf("%i\t", p[i].codigo);
        printf("%f\n", p[i].preco);
    }
    free(p);
}