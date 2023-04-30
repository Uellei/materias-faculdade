/*
- Os ponteiros permitem que vc trabalhe diretamente com a memória do computador, o que é essencial para muitos aplicativos de baixo nível, como drivers de dispositivo e sistemas operacionais.
- É uma variável que contém o endereço de outra variável. Você pode usar o operador "&" para obter o endereço de uma variável e o operador "*" para o bter o valor armazenado em um endereço.
- Podem ser usador para passar informações entre funções. Se precisa modificar uma variável em uma função, pode passar um ponteiro para essa variável como um argumento da função. A função pode, então, usar o ponteiro para modificar a variável original.
- Podem ser usador para alocar memória dinamicamente e criar estruturas de dados complexas, como listas encadeadas, etc.
*/

#include <stdlib.h>
#include <stdio.h>

// Exemplo 1
// Passando argumentos por referência, permitindo que a função modifique o valor original da variável
// Passa os endereços de memória das variáveis "x" e "y", permitindo que a função altere os seus valores direteamente na memória. A troca de valores dentro da função afetará diretamente as variaveis no escopo da função "main".

void teste1(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    teste1(&x, &y);
    printf("x: %d, y: %d", x,y);
    return 0;
}

// Exemplo 2
// Alocando memória dinamicamente, permitindo criar e gerenciar estruturas de dados

int main(){
    int *array = malloc(sizeof(int) * 10);
    for (int i=0;i<10;i++){
        array[i] = i+1;
    }
    for(int i=0;i<10;i++){
        printf("%d ", array[i]);
    }
    free(array);
}


//Exemplo 3
int main(){
    int i, tam = 7;
    char *nome;
    nome = (char*) malloc(sizeof(char)*tam);
    nome = "Weslley";
    printf("\n\t%s", nome);
    nome = (char*) realloc(NULL, 15*sizeof(char));
    nome = "Weslley Marcelo";
    printf("\n\t%s", nome);
    free(nome);
}