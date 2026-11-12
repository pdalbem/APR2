#include <stdio.h>
#include <stdbool.h>

#define N 9

// Função para imprimir a grade do Sudoku
void imprimirSudoku(int grade[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++)
            printf("%2d ", grade[r][d]);
        printf("\n");
    }
}

// Verifica se é seguro colocar 'num' na posição [linha][coluna]
bool ehSeguroSudoku(int grade[N][N], int linha, int coluna, int num) {
    // 1. Verifica a linha
    for (int c = 0; c < N; c++)
        if (grade[linha][c] == num) return false;

    // 2. Verifica a coluna
    for (int r = 0; r < N; r++)
        if (grade[r][coluna] == num) return false;

    // 3. Verifica a subgrade 3x3
    int inicioLinha = linha - linha % 3;
    int inicioColuna = coluna - coluna % 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (grade[inicioLinha + r][inicioColuna + c] == num) return false;

    return true;
}

// Função principal de Backtracking para o Sudoku
bool resolverSudoku(int grade[N][N]) {
    int linha = -1, coluna = -1;
    bool vazio = false;

    // Encontra uma célula vazia (representada por 0)
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grade[r][c] == 0) {
                linha = r;
                coluna = c;
                vazio = true;
                break;
            }
        }
        if (vazio) break;
    }

    // Se não há células vazias, o Sudoku foi resolvido com sucesso!
    if (!vazio) return true;

    // Tenta números de 1 a 9
    for (int num = 1; num <= 9; num++) {
        if (ehSeguroSudoku(grade, linha, coluna, num)) {
            grade[linha][coluna] = num; // Escolha

            if (resolverSudoku(grade)) return true; // Avança recursivamente

            grade[linha][coluna] = 0; // Backtrack (desfaz a escolha)
        }
    }

    return false; // Acionará o retrocesso na pilha de chamadas
}

int main() {
    int grade[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (resolverSudoku(grade)) {
        printf("Sudoku resolvido com sucesso via Backtracking:\n\n");
        imprimirSudoku(grade);
    } else {
        printf("Não há solução para esta instância de Sudoku.\n");
    }

    return 0;
}