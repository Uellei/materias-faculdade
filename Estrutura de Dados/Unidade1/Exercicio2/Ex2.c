#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int delta(int a, int b, int c){
    int delta = b*b -4*a*c;
    return delta;
}

int main(){

    int a, b, c, x1, x2;

    printf("a = "); scanf("%i", &a);
    printf("b = "); scanf("%i", &b);
    printf("c = "); scanf("%i", &c);
    
    int delta_resultado = delta(a,b,c);

    if(delta(a,b,c) < 0){
        printf("Delta = %i\n", delta_resultado);
        printf("Nenhuma raiz\n");
    } else if (delta(a,b,c) == 0){
        x1 = -b /(2*a);
        printf("Delta = %i\n", delta_resultado);
        printf("Equação possui uma raíz, x = %i\n", x1);
    } else{
        x1 = (-b + sqrt(delta(a, b, c))) / (2 * a);
        x2 = (-b - sqrt(delta(a, b, c))) / (2 * a);
        printf("Delta = %i\n", delta_resultado);
        printf("Os valores das raízes são\n x' = %i \n x'' = %i\n", x1, x2);
    }

}