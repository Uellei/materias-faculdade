#include <stdio.h>
#include <stdlib.h>

#define num_questoes 10
#define num_alternativas 4

typedef struct {
    int RA;
    float nota;
    char respostas[num_questoes];
} Aluno;

int main() {
    char gabarito[num_questoes];
    printf("Digite o gabarito:\n");
    for (int i = 0; i < num_questoes; i++) {
        scanf(" %c", &gabarito[i]);
    }

    int num_alunos = 0;
    Aluno* alunos = malloc(sizeof(Aluno));
    while (1) {
        int RA;
        printf("Digite o RA do aluno (digite 0 ou um número negativo para encerrar): ");
        scanf("%d", &RA);
        if (RA <= 0) {
            break;
        }

        Aluno aluno;
        aluno.RA = RA;
        printf("Digite as respostas do aluno:\n");
        for (int i = 0; i < num_questoes; i++) {
            scanf(" %c", &aluno.respostas[i]);
        }

        float nota = 0;
        for (int i = 0; i < num_questoes; i++) {
            if (aluno.respostas[i] == gabarito[i]) {
                nota += 1;
            }
        }
        aluno.nota = nota;

        num_alunos++;
        alunos = realloc(alunos, num_alunos * sizeof(Aluno));
        alunos[num_alunos-1] = aluno;
    }

    float media_classe = 0;
    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("RA: %d\tNota: %.1f\n", alunos[i].RA, alunos[i].nota);
        media_classe += alunos[i].nota;
    }
    media_classe /= num_alunos;

    int num_aprovados = 0;
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].nota >= 5.0) {
            num_aprovados++;
        }
    }
    float porc_aprovacao = 100.0 * num_aprovados / num_alunos;

    printf("\nPorcentagem de aprovação: %.1f%%\n", porc_aprovacao);
    printf("Média da classe: %.1f\n", media_classe);

    float maior_nota = 0;
    float menor_nota = 10;
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].nota > maior_nota) {
            maior_nota = alunos[i].nota;
        }
        if (alunos[i].nota < menor_nota) {
            menor_nota = alunos[i].nota;
        }
    }
    printf("\nMaior nota: %.1f\n", maior_nota);
    printf("RA do aluno:");
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].nota == maior_nota) {
            printf(" %d", alunos[i].RA);
        }
    }
    printf("\n");

    printf("\nMenor nota: %.1f\n", menor_nota);
    printf("RA do aluno:");
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].nota == menor_nota) {
            printf(" %d", alunos[i].RA);
        }
    }
    printf("\n");

    free(alunos);

    return 0;
}

