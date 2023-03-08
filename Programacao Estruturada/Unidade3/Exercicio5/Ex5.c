#include <stdio.h>

int main()
{
    float conjunto1[20], conjunto2[20], conjunto3[40];
    int i, j, k, tamanho_conjunto3 = 0;

    // Lendo os dois conjuntos do usuário
    printf("Digite os elementos do primeiro conjunto:\n");
    for (i = 0; i < 20; i++) {
        scanf("%f", &conjunto1[i]);
    }

    printf("Digite os elementos do segundo conjunto:\n");
    for (i = 0; i < 20; i++) {
        scanf("%f", &conjunto2[i]);
    }

    // Ordenando os dois conjuntos
    for (i = 0; i < 19; i++) {
        for (j = i + 1; j < 20; j++) {
            if (conjunto1[i] > conjunto1[j]) {
                float temp = conjunto1[i];
                conjunto1[i] = conjunto1[j];
                conjunto1[j] = temp;
            }

            if (conjunto2[i] > conjunto2[j]) {
                float temp = conjunto2[i];
                conjunto2[i] = conjunto2[j];
                conjunto2[j] = temp;
            }
        }
    }

    // Criando o terceiro conjunto (união dos dois conjuntos)
    i = 0;
    j = 0;
    while (i < 20 && j < 20) {
        if (conjunto1[i] < conjunto2[j]) {
            conjunto3[tamanho_conjunto3] = conjunto1[i];
            i++;
            tamanho_conjunto3++;
        } else if (conjunto1[i] > conjunto2[j]) {
            conjunto3[tamanho_conjunto3] = conjunto2[j];
            j++;
            tamanho_conjunto3++;
        } else {
            conjunto3[tamanho_conjunto3] = conjunto1[i];
            i++;
            j++;
            tamanho_conjunto3++;
        }
    }

    // Adicionando os elementos restantes do conjunto 1 (se houver)
    while (i < 20) {
        conjunto3[tamanho_conjunto3] = conjunto1[i];
        i++;
        tamanho_conjunto3++;
    }

    // Adicionando os elementos restantes do conjunto 2 (se houver)
    while (j < 20) {
        conjunto3[tamanho_conjunto3] = conjunto2[j];
        j++;
        tamanho_conjunto3++;
    }

    // Imprimindo o terceiro conjunto (união dos dois conjuntos)
    printf("O terceiro conjunto, contendo os elementos da união dos dois conjuntos, é:\n");
    for (k = 0; k < tamanho_conjunto3; k++) {
        printf("%.2f ", conjunto3[k]);
    }

    return 0;
}