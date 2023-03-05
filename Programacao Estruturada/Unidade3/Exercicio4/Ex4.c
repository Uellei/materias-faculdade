#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    float conjunto1[20], conjunto2[20], interseccao[20];
    int i, j, k=0, l;

    printf("Digite 20 valores para o primeiro arranjo:\n");
    for(i=0;i<20;i++){
        scanf("%f", &conjunto1[i]);
    }
    printf("Digite 20 valores para o segundo arranho:\n");
    for(i=0;i<20;i++){
        scanf("%f", &conjunto2[i]);
    }

    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            if(conjunto1[i] == conjunto2[j]){
                int repetido = 0;
                for(l=0;l<k;l++){
                    if(interseccao[l] == conjunto1[i]){
                        repetido = 1;
                        break;
                    }
                }
                if(!repetido){
                    interseccao[k++] = conjunto1[i];
                }
            }
        }
    }
    printf("Conjunto de interseccao:\n");
    for(i=0;i<k;i++) {
        printf("%f.2\n", interseccao[i]);
    }

}