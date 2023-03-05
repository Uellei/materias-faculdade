#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float a,b,y;
	int xi,xf,i,x;
	
	printf("Digite o valor de a para y=a*x+b:");
	scanf("%f",&a);
	printf("Digite o valor de b para y=a*x+b:");
	scanf("%f",&b);
	printf("Digite o valor inicial de x: ");
	scanf("%i",&xi);
	printf("Digite o valor final de x: ");
	scanf("%i",&xf);
	printf("Digite o incremento de x: ");
	scanf("%i",&i);
	for(x=xi;x<=xf;x=x+i){
		printf("x = %i\nf(x) = %f \n", x, a*x+b);
	}
}