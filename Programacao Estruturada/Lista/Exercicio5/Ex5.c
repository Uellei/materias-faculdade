#include <stdlib.h>
#include <stdio.h>
#define TAM 5

int main(){
    int i, j, temp;
    int nums[TAM];

    printf("Digite %d números inteiros:\n", TAM);
    for (i=0;i<TAM;i++){
        scanf("%i", &nums[i]);
    }

    // Ordena os números em ordem crescente, salvando em uma váriavel temporária e arrumando a ordem
    for(i=0;i<TAM-1;i++){
        for (j=0;j<TAM-i-1;j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    int num[TAM];
    printf("Digite %d números inteiros:\n", TAM);
    for (i=0;i<TAM;i++){
        scanf("%i", &num[i]);
    }

    for(i=0;i<TAM-1;i++){
        for (j=0;j<TAM-i-1;j++){
            if(num[j] > num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    // Confere os números iguais depois de ordenar os dois
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
                if(nums[i] == num[j]){
                printf("%i: %i -- %i\n", num[i], i, j);
            }
        }
    }
}
