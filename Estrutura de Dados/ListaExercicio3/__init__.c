#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do aluno
typedef struct Aluno {
    int RA;
    char nome[50];
    char curso[50];
    float nota1;
    float nota2;
    float nota3;
    struct Aluno* proximo;
} Aluno;

// Função para inserir um novo aluno em ordem alfabética pelo nome
void inserirAluno(Aluno** lista, int RA, const char* nome, const char* curso, float nota1, float nota2, float nota3) {
    // Criação do novo aluno
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->RA = RA;
    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->curso, curso);
    novoAluno->nota1 = nota1;
    novoAluno->nota2 = nota2;
    novoAluno->nota3 = nota3;
    novoAluno->proximo = NULL;

    // Se a lista está vazia, o novo aluno se torna o primeiro elemento
    if (*lista == NULL) {
        *lista = novoAluno;
    }
    else {
        // Se o nome do novo aluno vem antes do primeiro aluno da lista, ele se torna o novo primeiro aluno
        if (strcmp(novoAluno->nome, (*lista)->nome) < 0) {
            novoAluno->proximo = *lista;
            *lista = novoAluno;
        }
        else {
            // Procura a posição correta para inserir o novo aluno em ordem alfabética
            Aluno* atual = *lista;
            while (atual->proximo != NULL && strcmp(novoAluno->nome, atual->proximo->nome) > 0) {
                atual = atual->proximo;
            }
            // Verifica se já existe um aluno com o mesmo RA
            if (atual->proximo != NULL && novoAluno->RA == atual->proximo->RA) {
                printf("Erro: RA duplicado. O aluno nao foi inserido.\n");
                free(novoAluno);
                return;
            }
            // Insere o novo aluno na posição correta
            novoAluno->proximo = atual->proximo;
            atual->proximo = novoAluno;
        }
    }
}

// Função para alterar um cadastro de aluno
void alterarAluno(Aluno* lista, int RA, const char* novoNome, const char* novoCurso, float novaNota1, float novaNota2, float novaNota3) {
    // Procura o aluno pelo RA na lista
    Aluno* atual = lista;
    while (atual != NULL && atual->RA != RA) {
        atual = atual->proximo;
    }
    // Verifica se o aluno foi encontrado
    if (atual == NULL) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    // Verifica se o novo RA já existe em algum outro aluno
    if (atual->RA != RA) {
        Aluno* alunoExistente = lista;
        while (alunoExistente != NULL && alunoExistente->RA != RA) {
            alunoExistente = alunoExistente->proximo;
        }
        if (alunoExistente != NULL) {
            printf("Erro: RA duplicado. O aluno nao foi alterado.\n");
            return;
        }
    }
    // Atualiza os dados do aluno
    atual->RA = RA;
    strcpy(atual->nome, novoNome);
    strcpy(atual->curso, novoCurso);
    atual->nota1 = novaNota1;
    atual->nota2 = novaNota2;
    atual->nota3 = novaNota3;

    printf("Aluno alterado com sucesso.\n");
}

// Função para excluir um aluno da lista pelo RA
void excluirAluno(Aluno** lista, int RA) {
    // Se a lista está vazia, não há alunos para excluir
    if (*lista == NULL) {
        printf("Lista vazia. Nenhum aluno para excluir.\n");
        return;
    }
    // Se o primeiro aluno tem o RA a ser excluído, remove o primeiro aluno
    if ((*lista)->RA == RA) {
        Aluno* alunoExcluido = *lista;
        *lista = (*lista)->proximo;
        free(alunoExcluido);
        printf("Aluno excluido com sucesso.\n");
        return;
    }
    // Procura o aluno a ser excluído
    Aluno* atual = *lista;
    while (atual->proximo != NULL && atual->proximo->RA != RA) {
        atual = atual->proximo;
    }
    // Verifica se o aluno foi encontrado
    if (atual->proximo == NULL) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    // Remove o aluno da lista
    Aluno* alunoExcluido = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    free(alunoExcluido);
    printf("Aluno excluido com sucesso.\n");
}

// Função para buscar um aluno na lista pelo RA
void buscarAluno(Aluno* lista, int RA) {
    // Procura o aluno pelo RA na lista
    Aluno* atual = lista;
    while (atual != NULL && atual->RA != RA) {
        atual = atual->proximo;
    }
    // Verifica se o aluno foi encontrado
    if (atual == NULL) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    // Exibe os dados do aluno
    printf("RA: %d\n", atual->RA);
    printf("Nome: %s\n", atual->nome);
    printf("Curso: %s\n", atual->curso);
    printf("Nota1: %.2f\n", atual->nota1);
    printf("Nota2: %.2f\n", atual->nota2);
    printf("Nota3: %.2f\n", atual->nota3);
}

// Função para calcular a maior média entre as notas
float calcularMaiorMedia(float nota1, float nota2, float nota3) {
    float media1 = (nota1 + nota2) / 2.0;
    float media2 = (nota1 + nota3) / 2.0;
    float media3 = (nota2 + nota3) / 2.0;
    float maiorMedia = media1;

    if (media2 > maiorMedia) {
        maiorMedia = media2;
    }

    if (media3 > maiorMedia) {
        maiorMedia = media3;
    }

    return maiorMedia;
}

// Função para exibir o relatório dos alunos
void relatorioNotas(Aluno* lista) {
    // Verifica se a lista está vazia
    if (lista == NULL) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    // Percorre a lista e exibe o relatório de cada aluno
    Aluno* atual = lista;
    while (atual != NULL) {
        printf("RA: %d\n", atual->RA);
        printf("Nome: %s\n", atual->nome);
        printf("Curso: %s\n", atual->curso);
        printf("Nota1: %.2f\n", atual->nota1);
        printf("Nota2: %.2f\n", atual->nota2);
        printf("Nota3: %.2f\n", atual->nota3);

        float maiorMedia = calcularMaiorMedia(atual->nota1, atual->nota2, atual->nota3);
        printf("Maior Media: %.2f\n\n", maiorMedia);

        atual = atual->proximo;
    }
}

// Função para liberar a memória ocupada pela lista de alunos
void liberarLista(Aluno** lista) {
    Aluno* atual = *lista;
    while (atual != NULL) {
        Aluno* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

// Função principal
int main() {
    Aluno* lista = NULL;
    int opcao;

    do {
        printf("MENU:\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Alterar Aluno\n");
        printf("3 - Excluir Aluno\n");
        printf("4 - Buscar Aluno\n");
        printf("5 - Relatorio das Notas\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int RA;
                char nome[50];
                char curso[50];
                float nota1, nota2, nota3;

                printf("Digite o RA do aluno: ");
                scanf("%d", &RA);
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nome);
                printf("Digite o curso do aluno: ");
                scanf(" %[^\n]", curso);
                printf("Digite a nota 1 do aluno: ");
                scanf("%f", &nota1);
                printf("Digite a nota 2 do aluno: ");
                scanf("%f", &nota2);
                printf("Digite a nota 3 do aluno: ");
                scanf("%f", &nota3);

                inserirAluno(&lista, RA, nome, curso, nota1, nota2, nota3);
                break;
            }
            case 2: {
                int RA;
                char novoNome[50];
                char novoCurso[50];
                float novaNota1, novaNota2, novaNota3;

                printf("Digite o RA do aluno a ser alterado: ");
                scanf("%d", &RA);
                printf("Digite o novo nome do aluno: ");
                scanf(" %[^\n]", novoNome);
                printf("Digite o novo curso do aluno: ");
                scanf(" %[^\n]", novoCurso);
                printf("Digite a nova nota 1 do aluno: ");
                scanf("%f", &novaNota1);
                printf("Digite a nova nota 2 do aluno: ");
                scanf("%f", &novaNota2);
                printf("Digite a nova nota 3 do aluno: ");
                scanf("%f", &novaNota3);

                alterarAluno(lista, RA, novoNome, novoCurso, novaNota1, novaNota2, novaNota3);
                break;
            }
            case 3: {
                int RA;
                printf("Digite o RA do aluno a ser excluido: ");
                scanf("%d", &RA);
                excluirAluno(&lista, RA);
                break;
            }
            case 4: {
                int RA;
                printf("Digite o RA do aluno a ser buscado: ");
                scanf("%d", &RA);
                buscarAluno(lista, RA);
                break;
            }
            case 5: {
                relatorioNotas(lista);
                break;
            }
            case 6:
                liberarLista(&lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        printf("\n");
    } while (opcao != 6);

    return 0;
}
