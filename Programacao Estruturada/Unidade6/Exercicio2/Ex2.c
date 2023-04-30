#include <stdio.h>

int main() {
    int m, n;
    printf("Digite o numero de linhas (M): ");
    scanf("%d", &m);
    printf("Digite o numero de colunas (N): ");
    scanf("%d", &n);

    int matriz[m][n];
    int somas[m];

    // Parte que vai ler os valores da matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Aqui vai calcular as linhas das matrizes
    for (int i = 0; i < m; i++) {
        somas[i] = 0;
        for (int j = 0; j < n; j++) {
            somas[i] += matriz[i][j];
        }
    }

    // Dar um print da soma das linhas
    printf("Somas das linhas:\n");
    for (int i = 0; i < m; i++) {
        printf("Linha %d: %d\n", i, somas[i]);
    }

    return 0;
}
