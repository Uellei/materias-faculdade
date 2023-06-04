#include <stdlib.h>
#include <stdio.h>

int is_palindrome(char* str) {
    int length = strlen(str); // Cria uma variável com o tamanho da string passada como parâmetro
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);
    if (is_palindrome(str)) {
        printf("%s é um palíndromo.\n", str);
    } else {
        printf("%s não é um palíndromo.\n", str);
    }
    return 0;
}
