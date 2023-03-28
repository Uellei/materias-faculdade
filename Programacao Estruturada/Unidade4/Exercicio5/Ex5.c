#include <stdio.h>

int segundos_entre_instantes(int h1, int m1, int s1, int h2, int m2, int s2) {
    int total_segundos1 = h1 * 3600 + m1 * 60 + s1;
    int total_segundos2 = h2 * 3600 + m2 * 60 + s2;
    return total_segundos2 - total_segundos1;
}

int main() {
    int h1, m1, s1, h2, m2, s2;
    printf("Digite o primeiro instante (hora, minuto e segundo separados por espaços): ");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("Digite o segundo instante (hora, minuto e segundo separados por espaços): ");
    scanf("%d %d %d", &h2, &m2, &s2);
    int segundos = segundos_entre_instantes(h1, m1, s1, h2, m2, s2);
    printf("O número de segundos decorridos entre os instantes é: %d\n", segundos);
    return 0;
}
