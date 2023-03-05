#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    float value[25], sum=0, media;
    int i;

    printf("Digite 25 valores:\n");
    for(i=0;i<25;i++){
        printf("%i° ", i+1);
        scanf("%f", &value[i]);
        sum += value[i];
    }
    media = sum/25;
    printf("Soma = %.2f\nMedia aritmetica = %.2f", sum, media); 
}