#include <stdlib.h>
#include <stdio.h>

int pares(int arranjo[]){
    int qtd_pares = 0;
    int i;
    // Conta quantos pares tem 
    for (i=0;i<10;i++){
        if(arranjo[i]%2==0){
            qtd_pares++;
        }
    }
    // Aloca o novo arranjo de pares com o tamanho exato necessário + 1
    int* arranjo_pares = (int*) malloc((qtd_pares+1)*sizeof(int));
    // Armazena a quantidade de pares na posição 0 do novo arranjo
    arranjo_pares[0] = qtd_pares;
    // Armazena os elementos pares no novo arranjo
    int j = 1;
    for(i=0;i<10;i++){
        if(arranjo[i]%2==0){
            arranjo_pares[j] = arranjo[i];
            j++;
        }
    }
    return arranjo_pares;
}


int main(){
    int arranjo[] = {1,2,3,4,5,6,7,8,9,10};
    // Como a função pares retorna um ponteiro criado com alocação dinâmica, é necessario criar essa variavel como ponteiro tbm
    int* arranjo_pares = pares(arranjo);

    int i;
    printf("Quantidade de pares: %d\n", arranjo_pares[0]);
    printf("Elementos paers: ");
    for(i=1;i<arranjo_pares[0];i++){
        printf("%d ", arranjo_pares[i]);
    }
    printf("\n");
    free(arranjo_pares);
    return 0;
}