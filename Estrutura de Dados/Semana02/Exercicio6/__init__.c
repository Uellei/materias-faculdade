#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// typedef struct p{
//     float x;
//     float y;    
// }ponto;

// float distancia(ponto p1, ponto p2){
//     return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
// }

// int main(){
//     ponto p1,p2;
//     float d;

//     printf("X do p1: "); scanf("%f", &p1.x);
//     printf("Y do p1: "); scanf("%f", &p1.y);
//     printf("X do p2: "); scanf("%f", &p2.x);
//     printf("Y do p2: "); scanf("%f", &p2.y);
//     d = distancia(p1,p2); 
//     printf("Distancia entre os pontos (%.2f, %.2f) e (%.2f, %.2f) = %.2f\n", p1.x, p1.y, p2.x, p2.y, d);
// }


typedef struct p{
    float x;
    float y;
}ponto;

ponto distancia(ponto a, ponto b){
    ponto c;
    c.x = b.x-a.x;
    c.y = b.y-a.y;
    return c;
}

int main(){
    ponto p1,p2,p3;
    printf("X do p1: "); scanf("%f", &p1.x);
    printf("Y do p1: "); scanf("%f", &p1.y);
    printf("X do p2: "); scanf("%f", &p2.x);
    printf("Y do p2: "); scanf("%f", &p2.y);
    p3 = distancia(p1,p2);
    printf("X = %.2f \nY = %.2f\n", p3.x,p3.y);

    return 0;
}
