#include <stdio.h>

#define QTD_PRODUTOS 2

int main() {
    int M[QTD_PRODUTOS][QTD_PRODUTOS];
    int R[QTD_PRODUTOS][QTD_PRODUTOS];
    int maior;

    for(int i = 0; i < QTD_PRODUTOS; i++) {
        for(int j = 0; j < QTD_PRODUTOS; j++) {
            printf("Digite o valor da linha %d, coluna %d: ",i,j);
            scanf("%d", &M[i][j]);
        }
        printf("\n");
    }

    // Inicializa o maior com o primeiro elemento
    maior = M[0][0];

    // Encontra o maior elemento da matriz
    for(int i = 0; i < QTD_PRODUTOS; i++) {
        for(int j = 0; j < QTD_PRODUTOS; j++) {
            if(M[i][j] > maior) {
                maior = M[i][j];
            }
        }
    }

    // Calcula a matriz resultante R
    for(int i = 0; i < QTD_PRODUTOS; i++) {
        for(int j = 0; j < QTD_PRODUTOS; j++) {
            R[i][j] = M[i][j] * maior;
        }
    }

    // Exibe a matriz R
    printf("\nMaior elemento: %d\n", maior);
    printf("Matriz resultante R:\n");

    for(int i = 0; i < QTD_PRODUTOS; i++) {
        for(int j = 0; j < QTD_PRODUTOS; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}