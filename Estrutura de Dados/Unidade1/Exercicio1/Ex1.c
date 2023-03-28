#include <stdlib.h>
#include <stdio.h>

int main(){
    int tam;
    printf("Quantidade de elementos: ");
    scanf("%i", &tam);
    int array[tam], i, j;

    for (i=0;i<tam;i++){
        printf("%i°", i+1);
        scanf("%i", &array[i]);
    }

    for(i=0;i<tam;i++){
        for(j=i+1;j<tam;j++){
            if(array[i] == array[j]){
                printf("Elemento repetido: %i - nos indices %i e %i", array[i], i, j);
                printf("\n");
            }
        }
    }

    return 0;
}