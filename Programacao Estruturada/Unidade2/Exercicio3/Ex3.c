#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Digite um valor inteiro N (entre 0 e 1000): ");
    scanf("%d", &n);

    int nums[n];
    printf("Digite %d números inteiros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Imprime valores lidos
    printf("Valores lidos: ");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Ordena os valores em ordem crescente
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // Imprime valores em ordem crescente
    printf("Valores em ordem crescente: ");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Imprime valores em ordem contrária
    printf("Valores em ordem contrária: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}