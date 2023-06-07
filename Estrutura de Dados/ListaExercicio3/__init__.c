#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do aluno
typedef struct Aluno {
    int RA;
    char nome[50];
    char curso[50];
    float n1;
    float n2;
    float n3;
    struct Aluno* proximo;
} Aluno;

// Função para inserir um novo aluno em ordem alfabética pelo nome
void inserirAluno(Aluno** lista, int RA, const char* nome, const char* curso, float n1, float n2, float n3) {
    // Criação do novo aluno
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    novo_aluno->RA = RA;
    strcpy(novo_aluno->nome, nome);
    strcpy(novo_aluno->curso, curso);
    novo_aluno->n1 = n1;
    novo_aluno->n2 = n2;
    novo_aluno->n3 = n3;
    novo_aluno->proximo = NULL;

    // Se a lista está vazia, o novo aluno se torna o primeiro elemento
    if (*lista == NULL) {
        *lista = novo_aluno;
    }
    else {
        // Se o nome do novo aluno vem antes do primeiro aluno da lista, ele se torna o novo primeiro aluno
        if (strcmp(novo_aluno->nome, (*lista)->nome) < 0) {
            novo_aluno->proximo = *lista;
            *lista = novo_aluno;
        }
        else {
            // Procura a posição correta para inserir o novo aluno em ordem alfabética
            Aluno* atual = *lista;
            while (atual->proximo != NULL && strcmp(novo_aluno->nome, atual->proximo->nome) > 0) {
                atual = atual->proximo;
            }
            // Verifica se já existe um aluno com o mesmo RA
            if (atual->proximo != NULL && novo_aluno->RA == atual->proximo->RA) {
                printf("Erro: RA duplicado. O aluno nao foi inserido.\n");
                free(novo_aluno);
                return;
            }
            // Insere o novo aluno na posição correta
            novo_aluno->proximo = atual->proximo;
            atual->proximo = novo_aluno;
        }
    }
}

// Função para alterar um cadastro de aluno
void alterarAluno(Aluno* lista, int RA, const char* novoNome, const char* novoCurso, float novan1, float novan2, float novan3) {
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
    atual->n1 = novan1;
    atual->n2 = novan2;
    atual->n3 = novan3;

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
        Aluno* aluno_excluido = *lista;
        *lista = (*lista)->proximo;
        free(aluno_excluido);
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
    Aluno* aluno_excluido = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    free(aluno_excluido);
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
    printf("n1: %.2f\n", atual->n1);
    printf("n2: %.2f\n", atual->n2);
    printf("n3: %.2f\n", atual->n3);
}

// Função para calcular a maior média entre as notas
float calcular_maior_media(float n1, float n2, float n3) {
    float media1 = (n1 + n2) / 2.0;
    float media2 = (n1 + n3) / 2.0;
    float media3 = (n2 + n3) / 2.0;
    float maior_media = media1;

    if (media2 > maior_media) {
        maior_media = media2;
    }

    if (media3 > maior_media) {
        maior_media = media3;
    }

    return maior_media;
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
        printf("n1: %.2f\n", atual->n1);
        printf("n2: %.2f\n", atual->n2);
        printf("n3: %.2f\n", atual->n3);

        float maior_media = calcular_maior_media(atual->n1, atual->n2, atual->n3);
        printf("Maior Media: %.2f\n\n", maior_media);

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
                float n1, n2, n3;

                printf("Digite o RA do aluno: ");
                scanf("%d", &RA);
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nome);
                printf("Digite o curso do aluno: ");
                scanf(" %[^\n]", curso);
                printf("Digite a nota 1 do aluno: ");
                scanf("%f", &n1);
                printf("Digite a nota 2 do aluno: ");
                scanf("%f", &n2);
                printf("Digite a nota 3 do aluno: ");
                scanf("%f", &n3);

                inserirAluno(&lista, RA, nome, curso, n1, n2, n3);
                break;
            }
            case 2: {
                int RA;
                char novoNome[50];
                char novoCurso[50];
                float novan1, novan2, novan3;

                printf("Digite o RA do aluno a ser alterado: ");
                scanf("%d", &RA);
                printf("Digite o novo nome do aluno: ");
                scanf(" %[^\n]", novoNome);
                printf("Digite o novo curso do aluno: ");
                scanf(" %[^\n]", novoCurso);
                printf("Digite a nova nota 1 do aluno: ");
                scanf("%f", &novan1);
                printf("Digite a nova nota 2 do aluno: ");
                scanf("%f", &novan2);
                printf("Digite a nova nota 3 do aluno: ");
                scanf("%f", &novan3);

                alterarAluno(lista, RA, novoNome, novoCurso, novan1, novan2, novan3);
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
