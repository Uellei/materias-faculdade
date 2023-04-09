#include <stdlib.h>
#include <stdio.h>

int Soma(int n){
    if(n==0) return 0;
    else return n+Soma(n-1);

}

void main(){
    int n;
    printf("N: "); scanf("%i", &n);
    printf("Soma de N: %i", Soma(n));
}