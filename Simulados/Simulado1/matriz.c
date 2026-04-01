#include <stdio.h>

#define LIN 3
#define COL 2


void lerMatriz(int A[][COL]) {
    for (int i = 0; i < LIN; i++) 
        for (int j = 0; j < COL; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    
}

void exibirMatriz(int A[][COL]) {
    printf("\nMatriz A:\n");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) 
            printf("%4d ", A[i][j]);
        
        printf("\n");
    }
}


int encontrarMaior(int A[][COL]) {
    int maior = A[0][0];

    for (int i = 0; i < LIN; i++) 
        for (int j = 0; j < COL; j++) 
            if (A[i][j] > maior) 
                maior = A[i][j];
            
    return maior;
}


void multiplicarPorValor(int A[][COL], int valor) {
    for (int i = 0; i < LIN; i++) 
        for (int j = 0; j < COL; j++) 
            A[i][j] *= valor;
          
}

//A é a matriz original e At é a transposta
void gerarTransposta(int A[][COL], int At[][LIN]) {
    for (int i = 0; i < LIN; i++) 
        for (int j = 0; j < COL; j++) 
            At[j][i] = A[i][j];
}

// função para exibir a transposta. Repareo parâmetro é At[COL][LIN] agora
void exibirTransposta(int At[][LIN]) {
    printf("\nMatriz transposta de A:\n");
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < LIN; j++) {
            printf("%4d ", At[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[LIN][COL];

    lerMatriz(A);
    exibirMatriz(A);

    int maior = encontrarMaior(A);
    printf("\nMaior elemento: %d\n", maior);

    multiplicarPorValor(A, maior);

    printf("\nMatriz A após multiplicação pelo maior valor:\n");
    exibirMatriz(A);

    int At[COL][LIN];
    gerarTransposta(A, At);

    exibirTransposta(At);

    return 0;
}