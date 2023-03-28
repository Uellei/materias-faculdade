#include <stdio.h>
#include <stdlib.h>
int* uniao(int *x1, int *x2, int n1, int n2, int* qtd){
    int *x3=(int*)malloc(sizeof(int)*(n1+n2));
    int i=0,j=0;
    *qtd=0;
    // Equanto i for menor que n1 e j menor que n2, ou seja, enquanto ainda houver elementos para serem comparados nos vetores x1 e x2
    while(i<n1 && j<n2){
        if(x1[i]<x2[j]){
            x3[*qtd]=x1[i];
            i++;
            (*qtd)++;
        }else if(x2[j]<x1[i]){
            x3[*qtd]=x2[j];
            j++;
            (*qtd)++;
        }else{
            j++;
        }
    }
    while(i<n1){
        x3[*qtd]=x1[i];
        i++;
        (*qtd)++;
    }
    while(j<n2){
        x3[*qtd]=x2[j];
        j++;
        (*qtd)++;
    }
    x3=(int*)realloc(x3,sizeof(int)*(*qtd));
    return x3;
}
void main(){
    int v1[5];
    v1[0]=1;
    v1[1]=3;
    v1[2]=5;
    v1[3]=6;
    v1[4]=7;
    int v2[5];
    v2[0]=1;
    v2[1]=3;
    v2[2]=4;
    v2[3]=6;
    v2[4]=8;
    int quant,i;
    int *r=uniao(&v1,&v2,5,5,&quant);
    for (i = 0; i < quant;i++){
        printf ("r[%i]=%i\n",i,r[i]);
    }
    free(r);
}