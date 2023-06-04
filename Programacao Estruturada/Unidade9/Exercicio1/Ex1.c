#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int ID;
    char Nome[30];
    float salario
}func;

void imprime(func funcionario){
    printf('Funcionario: \n');
    printf('ID: \n');
    printf('Salario: \n');
}

int main(){
    func f1;
    f1.ID = 1;
    strcpy(f1.Nome, "Weslley");
    f1.salario = 5000;
}