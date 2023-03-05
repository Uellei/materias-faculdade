#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    float nota, soma_nota, media;
    int qtd_alunos, i;

    printf("Quantidade de alunos: "); scanf("%i", &qtd_alunos);
    for(i=1;i <= qtd_alunos;i++){
        printf("Nota do aluno %i: ", i); scanf("%f", &nota);
        soma_nota += nota;
    }

    media = soma_nota/qtd_alunos;

    printf("A media da sala foi de: %.2f\n", media);

}