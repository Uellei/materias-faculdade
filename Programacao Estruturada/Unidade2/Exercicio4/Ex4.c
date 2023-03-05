#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	char letra;
	int contador, contaO, contaB, contaR, contaU;
	
	contador = 0;
	contaO = 0;
	contaB = 0;
	contaR = 0;
	contaU = 0;
	
	do{
		printf("Digite uma resposta (O, B, R, U): ");
		
		scanf("%c", &letra);
        if(letra != 'O' || letra != 'B' || letra != 'R' || letra != 'U'){
            printf("Digite uma letra valida\n");
        }
		fflush(stdin);
		
		if(letra!='-'){
			if(letra == 'O' || letra == 'B' || letra == 'R' || letra == 'U') contador++;
			if(letra == 'O') contaO++;
			if(letra == 'B') contaB++;
			if(letra == 'R') contaR++;
			if(letra == 'U') contaU++;
			}
			
	}while(letra!='-');
	if(contador != 0){
		printf("Numero de respostas: %i \n", contador);
		printf("Numero de otimos: %i - %.1f%% \n", contaO,((contaO*1.0)/contador)*100);
		printf("Numero de bons: %i - %.1f%% \n", contaB,((contaB*1.0)/contador)*100);
		printf("Numero de regulares: %i - %.1f%% \n", contaR,((contaR*1.0)/contador)*100);
		printf("Numero de ruins: %i - %.1f%% \n", contaU,((contaU*1.0)/contador)*100);
		if(contaO+contaB > contaR+contaU){
			printf("Houve mais respondentes otimos e bons que regulares e ruins");
		}
		else{
			printf("Houve mais respondentes regulares e ruins que otimos e bons");
		}
		
		
		
	}

	
	
}