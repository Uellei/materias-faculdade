#include <stdlib.h>
#include <stdio.h>

typedef struct Aluno{
    char RA[13];
    char nome[50];
    float n1,n2;
}aluno;

void main(){
    int i, n;
    printf("Digite N\n"); scanf("%i", &n);
    aluno *p=(aluno*)malloc(sizeof(aluno)*n);
    for(i=0;i<n;i++){
        printf("Digite o RA do %i° aluno: ", i+1); scanf("%s", &p[i].RA);
        printf("Digite o nome do %i° aluno: ", i+1); scanf("%s", &p[i].nome);
        printf("Digite a N1 do %i° aluno: ",i+1); scanf("%f", &p[i].n1);
        printf("Digite a N2 do %i° aluno: ",i+1); scanf("%f", &p[i].n2);
    }
    printf("RA\tNome\tN1\tN2\tMedia\n",i+1);
    for (i=0;i<n;i++){
        printf("%s\t", p[i].RA);
        printf("%s\t", p[i].nome);
        printf("%.1f\t", p[i].n1);
        printf("%.1f\t", p[i].n2);
        printf("%.1f\n", (p[i].n2 + p[i].n1)/2);
    }
    free(p);
}