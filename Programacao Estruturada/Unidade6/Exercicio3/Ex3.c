#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, i, j;
    int *matriz, *diagonal;
    printf("Digite o valor de M (limite 10): ");
    scanf("%d", &m);

    // Alocando memória para a matriz e o vetor
    matriz = (int*) malloc(m * m * sizeof(int));
    diagonal = (int*) malloc(m * sizeof(int));

    // Preenchendo a matriz com valores do usuário
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i*m+j]);
        }
    }

    // Armazenando os elementos da diagonal principal no vetor
    int pos = 0;
    for (i = 0; i < m; i++) {
        diagonal[pos] = matriz[i*m+i];
        if (diagonal[pos] != 0) {
            pos++;
        }
    }

    // Imprimindo o vetor com os elementos da diagonal principal
    printf("Elementos da diagonal principal: ");
    for (i = 0; i < pos; i++) {
        printf("%d ", diagonal[i]);
    }

    // Liberando a memória alocada
    free(matriz);
    free(diagonal);
    return 0;
}
