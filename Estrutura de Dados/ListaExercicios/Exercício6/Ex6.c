#define Y 2 // Cria uma constante Y com valor 2
#define X 2 // Cria uma constante X com valor 2
int main(int argc, char *argv[]){ // Função Principal
    int **A; // Declara um ponteiro de ponteiro
    int i,j; // Declara duas variáveis inteiras i e j 
    A = (int**)malloc(Y * sizeof(int*)); // Aloca Y espaços de ponteiro do tipo int
    for(i = 0; i < Y; i++){ // Para cada linha enquanto i < Y
        A[i] = (int*)malloc(X * sizeof(int)); // grava em cada posição do vetor A, um ponteiro que aponta para um vetor de X (2) tamanho
    }
    for(i = 0; i < Y; i++){ // Para cada linha enquanto i < Y
        for(j = 0; j < X; j++){ // Para cada linha enquanto j < Y
            A[i][j]=i+j; // Soma i+j e armazena o resultado na posição [i][j] do array A
        }
    }
    for(i = 0; i < Y; i++){ // Para cada linha enquanto i < Y
        for(j = 0; j < X; j++);{ // Para cada linha enquanto i < Y
            printf("%d\t",A[i][j]); // Imprime o valor da posição [i][j] do Array A
        }
    }
    for(i = 0; i < Y; i++){ // Para cada linha enquanto i < Y
        free(A[i]); // Libera espaço alocado para a posição A[i]
    }
    free(A); // Libera o espaço alocado para o array A
    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}