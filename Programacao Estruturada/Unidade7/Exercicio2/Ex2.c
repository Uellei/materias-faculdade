#include <stdio.h>
#include <stdlib.h>

double* elementosNaoNulos(double **matriz, int n) {
    double *vetor = malloc(n * n * sizeof(double)); // Alocando memória para o vetor de elementos não nulos
    int k = 0; // Índice para controlar o preenchimento do vetor
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != 0) {
                vetor[k] = matriz[i][j]; // Adicionando o elemento não nulo ao vetor
                k++;
            }
        }
    }
    return vetor;
}

int main() {
    int n;
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    double **matriz = malloc(n * sizeof(double*)); // Alocando memória para a matriz
    for (int i = 0; i < n; i++) {
        matriz[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            printf("Digite o elemento (%d,%d): ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    double *vetor = elementosNaoNulos(matriz, n);

    printf("Elementos nao nulos da matriz:\n");
    for (int i = 0; i < n*n; i++) {
        if (vetor[i] != 0) {
            printf("%lf ", vetor[i]);
        }
    }
    printf("\n");

    // Liberando a memória alocada
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);

    return 0;
}
