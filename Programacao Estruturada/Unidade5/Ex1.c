#include <stdio.h>
#include <stdlib.h>

int fat(int n){
    if ( n < 0 ) return(-1);

    if ( n == 0 || n == 1 ) return(1);

    return( n * fat(n-1) );

}

void main(){

    int k;

    printf( "\nFatorial de %i = %i", k, fat(k));

}

// A variavel k nao recebe nenhum valor entao quando é chamada a função pra calcular o fatorial, como é um valor indeterminado ele cai no if do n==0 || n==1 e retorna 0 = 1