#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

int main() {
    int m, n;
    printf("Digite as dimensoes da matriz (m n): ");
    scanf("%d %d", &m, &n);

    float matriz[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o elemento (%d, %d): ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    float concatenado[m*2];
    for (int j = 0; j < n; j++) {
        concatenado[j] = matriz[0][j];
        concatenado[m + j] = matriz[m-1][j];
    }
    printf("Concatenacao da primeira e ultima linhas:\n");
    for (int i = 0; i < m*2; i++) {
        printf("%g ", concatenado[i]);
    }
    printf("\n");

    int positivos = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > 0) {
                positivos++;
            }
        }
    }
    printf("Numero de elementos positivos: %d\n", positivos);

    int primos[m*n];
    int num_primos = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime((int)matriz[i][j])) {
                primos[num_primos] = (int)matriz[i][j];
                num_primos++;
            }
        }
    }
    printf("Numeros primos na matriz: ");
    for (int i = 0; i < num_primos; i++) {
        printf("%d ", primos[i]);
    }
    printf("\n");

    return 0;
}
