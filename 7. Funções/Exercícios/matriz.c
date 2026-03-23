#include <stdio.h>

#define TAM 5

void lerMatriz(int m[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void mostrarMatriz(int m[TAM][TAM]) {
    printf("\nMatriz:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatriz(int m[TAM][TAM], int valor) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            m[i][j] *= valor;
        }
    }
}

int main() {
    int matriz[TAM][TAM];
    int fator;

    lerMatriz(matriz);

    mostrarMatriz(matriz);

    printf("\nDigite um valor inteiro para multiplicar a matriz: ");
    scanf("%d", &fator);

    multiplicarMatriz(matriz, fator);

    printf("\nMatriz após multiplicação:\n");
    mostrarMatriz(matriz);

    return 0;
}