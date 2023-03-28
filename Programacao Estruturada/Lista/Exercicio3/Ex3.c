#include <stdlib.h>
#include <stdio.h>

int main(){
    float x, i; 
    float somatoria=0;
    printf("X = "); scanf("%f", &x);
    for (i=1;i<=50;i++){
        somatoria += x/i;
    }
    printf("Somatoria = %f", somatoria);
}