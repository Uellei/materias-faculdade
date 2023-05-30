#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 25;
    int *pa = &a;
    int b = *pa + a;
    printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b);
    getchar();
    return 0;
}
/*
a) Qual o resultado da execução do programa?
a = 25
pa = -9672
&a = -9672
*pa = 25
b = 50
&b = -9668
*/

/*
b) Qual o significado de cada um dos valores escritos na tela?
a = Imprime o valor da variavel definida: 25
pa = Imprime o valor armazenado na variavel pa que que é o endereço de memória do a
&a = Imprime o endereço de memória do a
*pa = Imprime o valor na posição de memória apontada por pa, sendo o valor de a: 25
b = A soma entre o valor armazenado na posição de memória apontada por pa: 25 e o valor de a, sendo: 50
&b = Endereço de memória da variável b
*/