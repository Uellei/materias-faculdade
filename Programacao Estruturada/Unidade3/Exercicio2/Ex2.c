#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int value1[20], value2[20], i, j;

    printf("Digite 20 valores para o primeiro arranjo:\n");
    for(i=0;i<20;i++){
        scanf("%i", &value1[i]);
    }
    printf("Digite 20 valores para o segundo arranho:\n");
    for(i=0;i<20;i++){
        scanf("%i", &value2[i]);
    }

    printf("\nElementos repetidos em cada arranjo\n");
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
                if(value1[i] == value2[j]){
                printf("%i: %i -- %i\n", value1[i], i, j);
            }
        }
    }
}