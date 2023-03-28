#include<stdio.h>
#include<stdlib.h>

int teste(float nota){
    if((nota >=0) && (nota <=10))
        return 1;
    else
        return 0;
}

int main(){
    float notas[100];
    int i, j, n, percentuais[10];

    for(i=0;i<10;i++){
        percentuais[i]=0;
    }


    printf("Digite o numero de notas desejado: ");
    scanf("%i", &n);

    for(i=0;i<n;i++){
        printf("Digite a %ia. nota: ", i+1);
        scanf("%f", &notas[i]);
        if(teste(notas[i])){
            if((notas[i]>=0) && (notas[i]<1))
                percentuais[0]++;
            else
                if((notas[i]>=1) && (notas[i]<2))
                    percentuais[1]++;
            else
                if((notas[i]>=2) && (notas[i]<3))
                    percentuais[2]++;
            else
                if((notas[i]>=3) && (notas[i]<4))
                    percentuais[3]++;
            else
                if((notas[i]>=4) && (notas[i]<5))
                    percentuais[4]++;
            else
                if((notas[i]>=5) && (notas[i]<6))
                    percentuais[5]++;
            else
                if((notas[i]>=6) && (notas[i]<7))
                    percentuais[6]++;
            else
                if((notas[i]>=7) && (notas[i]<8))
                    percentuais[7]++;
            else
                if((notas[i]>=8) && (notas[i]<9))
                    percentuais[8]++;
            else
                if((notas[i]>=9) && (notas[i]<=10))
                    percentuais[9]++;
        }
        else{
            printf("Nota invalida!!!\n");
            i--;
        }
    }

    for(i=0;i<10;i++){
            printf("(%i..%i): ", i, i+1);
        for(j=0;j<percentuais[i];j++){
            printf("H");
        }
        printf("\n");
    }
}