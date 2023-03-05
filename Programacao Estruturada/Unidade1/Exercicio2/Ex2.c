#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int num, result=1, i;
    printf("Digite um número: "); scanf("%i", &num);

    for(i=2;i<=num;i++){
        if(num%i == 0){
            printf("Nao é primo");
            result = 0;
            break;
        }
    }
    if (result){
        printf("Primo");
    }

}
