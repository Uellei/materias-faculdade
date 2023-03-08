#include <stdlib.h>
#include <stdio.h>

// void main(){
// int n, fatorial, i;
// printf("Digite o numero: "); scanf("%d",&n);
// fatorial = 1;
// for(i = n; i > 0; i--) {
//     fatorial *= i;
// }
// printf("Fatorial de %d: %d\n", n, fatorial);
// }

// TRANSFORMANDO A FUNÇÃO ACIMA EM UMA FUNÇÃO RECURSIVA

int fatorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}

int main(){
    int n;
    printf("Digite um numero: "); scanf("%i", &n);
    printf("Fatorial de %i: %i\n", n, fatorial(n));
    return 0;
}