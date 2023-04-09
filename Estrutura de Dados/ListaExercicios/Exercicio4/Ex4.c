#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
float* duplica_vetor(float v[ ], int tam){
    int i;
    float *vet;
    vet = (float *) calloc (tam, sizeof(float));
    for (i = 0; i < tam; i++) {
        vet[i]=v[i];
    }
    return vet;
}

void main(){
    float v[TAM];
    int i;
    srand(time(NULL));
    printf ("vetor original\n");
    for(i=0;i<TAM;i++){
        v[i]=rand()%100;
        printf("v[%i]=%f\n",i,v[i]);
    }
    float *r=duplica_vetor(v,TAM);
    printf ("\nvetor duplicado\n");
    for (i = 0; i < TAM;i++){
        printf ("r[%i]=%f\n",i,r[i]);
    }
    free(r);
}