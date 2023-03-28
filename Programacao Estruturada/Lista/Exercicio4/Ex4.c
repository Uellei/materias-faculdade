#include <stdlib.h>
#include <stdio.h>

float somatoria(float x, float n){
    if (n<=50){
        return x/n + somatoria(x, n+1);
    } else {
        return 0;
    }
}

int main(){
    float x, n=1;
    printf("X = "); scanf("%f", &x);
    printf("Somatoria = %f", somatoria(x, n));
}