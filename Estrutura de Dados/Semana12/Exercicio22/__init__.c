#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    float A = (sqrt(5)-1)/2;
    float val = chave * A;
    val = val-(int) val;
    return(int) (TABLE_SIZE * val);
}

int main(){
    printf("Chave 61 - posicao %i\n", chaveMultiplicacao(61, 1000));
    printf("Chave 62 - posicao %i\n", chaveMultiplicacao(62, 1000));
    printf("Chave 63 - posicao %i\n", chaveMultiplicacao(63, 1000));
    printf("Chave 64 - posicao %i\n", chaveMultiplicacao(64, 1000));
    printf("Chave 65 - posicao %i\n", chaveMultiplicacao(65, 1000));
    return 0;
}