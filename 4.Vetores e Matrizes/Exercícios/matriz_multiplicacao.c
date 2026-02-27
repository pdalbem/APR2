#include <stdio.h>

#define TAM 2

int main() {
    int M[TAM][TAM];
    int R[TAM][TAM];
    int maior;

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("Digite o valor da linha %d, coluna %d: ",i,j);
            scanf("%d", &M[i][j]);
        }
        printf("\n");
    }

    // Inicializa o maior com o primeiro elemento
    maior = M[0][0];

    // Encontra o maior elemento da matriz
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(M[i][j] > maior) {
                maior = M[i][j];
            }
        }
    }

    // Calcula a matriz resultante R
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            R[i][j] = M[i][j] * maior;
        }
    }

    // Exibe a matriz R
    printf("\nMaior elemento: %d\n", maior);
    printf("Matriz resultante R:\n");

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}