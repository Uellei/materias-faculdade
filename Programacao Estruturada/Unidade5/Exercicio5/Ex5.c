#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int vetSoma(int a[], int n){
    if(n==0) return 0;
    else return a[n-1]+vetSoma(a,n-1);
}

void main(){
    int vet[MAX];
    int i,a;
    for(i=0;i<MAX;i++){
        printf("%i° = ", i+1);
        scanf("%i", &vet[i]);
    }
    printf("Valor: %i", vetSoma(vet,MAX));
}
