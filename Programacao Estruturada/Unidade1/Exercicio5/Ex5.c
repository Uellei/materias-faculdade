#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float peso, maior_peso, menor_peso, soma_pesos;
	int id,id_maior,id_menor,contador;
	
	contador = 0;
	soma_pesos = 0;
	
	do{
		printf("Digite o id do boi: ");
		scanf("%i", &id);
		if(id!=0){
			printf("Digite o peso do boi: ");
			scanf("%f", &peso);
			contador = contador + 1;
			soma_pesos = soma_pesos + peso;
			if(contador == 1){
				maior_peso = peso;
				id_maior = id;
				menor_peso = peso;
				id_menor = id;
			}
			else{
				if(peso>maior_peso){
					maior_peso = peso;
					id_maior = id;
				}
				if(peso<menor_peso){
					menor_peso = peso;
					id_menor = id;
				}
			}
		}
	}while(id!=0);
	if(contador != 0){
		printf("Numero de bois: %i \n", contador);
		printf("Identificador maior boi: %i \n", id_maior);
		printf("Peso maior boi: %.3f \n", maior_peso);
		printf("Identificador menor boi: %i \n", id_menor);
		printf("Peso menor boi: %.3f \n", menor_peso);
		printf("Media dos pesos: %.4f", soma_pesos/contador);
	}

	
	
}