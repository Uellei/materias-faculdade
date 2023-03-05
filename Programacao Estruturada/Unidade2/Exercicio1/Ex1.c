#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c, delta, x1, x2;

    printf("a = "); scanf("%f", &a);
    printf("b = "); scanf("%f", &b);
    printf("c = "); scanf("%f", &c);

    delta = b*b - 4*a*c;

    if(delta < 0){
        printf("Nenhuma raiz\n");
    } else if (delta == 0){
        x1 = -b /(2*a);
        printf("Equação possui uma raíz, x = %f\n", x1);
    } else{
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("Os valores das raízes são\n x' = %.1f \n x'' = %.1f\n", x1, x2);
    }

}