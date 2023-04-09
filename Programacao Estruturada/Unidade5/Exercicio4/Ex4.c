#include <stdlib.h>
#include <stdio.h>

int pascal(int lin, int col){
    if(col == 1 || lin == col) return 1;
    else return pascal(lin-1,col) + pascal(lin-1,col-1);
}

void main(){
    int a, b;
    printf("Linha: "); scanf("%i", &a);
    printf("Coluna: "); scanf("%i", &b);
    printf("Valor: %i", pascal(a,b));
}