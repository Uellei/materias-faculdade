#include <stdlib.h>
#include <stdio.h>

int sum(int n){ 
    if (n == 0){
        return 0;
    } else {
        return n + sum(n-1);
    }
}

int main() {
    int n;
    printf("Digite o numero: "); scanf("%i", &n);
    int result = sum(n);
    printf("A somatoria dos numeros de 0 ate %i é: %i\n", n,result);
}