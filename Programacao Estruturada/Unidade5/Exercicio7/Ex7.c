#include <stdio.h>

void VetInv(int A[], int inic, int fim);

int main() {
    int A[] = {1, 2, 3, 4, 5, 6};
    int inic = 1;
    int fim = 4;
    
    printf("Vetor original: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", A[i]);
    }
    
    VetInv(A, inic, fim);
    
    printf("\nVetor invertido: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", A[i]);
    }
    
    return 0;
}

void VetInv(int A[], int inic, int fim) {
    if (inic < fim) {
        int temp = A[inic];
        A[inic] = A[fim];
        A[fim] = temp;
        VetInv(A, inic+1, fim-1);
    }
}
