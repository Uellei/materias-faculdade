#include<stdio.h>
#include<stdlib.h>

int main(){
	int num1, num2, num3;
	printf("Digite os 3 numeros:\n");
	scanf("%i", &num1);
	scanf("%i", &num2);
	scanf("%i", &num3);
	if(num1>=num2 && num1>=num3){
		printf("O maior = %i\n", num1);
	}
	else{
		if(num2>=num1 && num2>=num3){
			printf("O maior = %i\n", num2);
		}
		else{
			if(num3>=num1 && num3>=num2){
				printf("O maior = %i\n", num3);
			}
		}
	}
}