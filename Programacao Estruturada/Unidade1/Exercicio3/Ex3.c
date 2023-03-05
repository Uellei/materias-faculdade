#include<stdio.h>
#include<stdlib.h>

int main(){
	float valor_metros, valor_pes;
	//Lendo uma variável:
	printf("Digite um valor em metros: ");
	scanf("%f",&valor_metros);
	//Testando se o valor em metros é negativo
	if(valor_metros < 0){
		printf("Valor invalido. O valor deve ser positivo.");
	}
	else{
		/*
		Calculando o resultado:
		*/
		valor_pes = valor_metros*3.315;
		//Mostrando o resultado:
		printf("Resultado = %.3f pes", valor_pes);
	}
}