#include <stdio.h>
#include <stdlib.h>

void transporMatriz(int mat[][10], int m, int n) {
    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < n; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void somarMatrizes(int mat1[][10], int mat2[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat1[i][j] += mat2[i][j];
        }
    }
}

int main() {
    int m, n;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);

    int mat1[m][10], mat2[m][10], mat3[m][10];

    printf("\nDigite os valores da primeira matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nDigite os valores da segunda matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    transporMatriz(mat1, m, n);

    somarMatrizes(mat1, mat2, m, n);

    printf("\nResultado:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    return 0;
}
