#include <stdio.h>
#include <stdbool.h>

#define N 4

void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", tabuleiro[i][j] ? 'R' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Verifica se é seguro posicionar uma rainha em tabuleiro[linha][coluna]
// Como preenchemos coluna por coluna da esquerda para a direita, basta checar o lado esquerdo
bool ehSeguro(int tabuleiro[N][N], int linha, int coluna) {
    int i, j;

    // 1. Verifica a mesma linha à esquerda
    for (i = 0; i < coluna; i++) {
        if (tabuleiro[linha][i]) {
            return false;
        }
    }

    // 2. Verifica a diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j]) {
            return false;
        }
    }

    // 3. Verifica a diagonal inferior esquerda
    for (i = linha, j = coluna; j >= 0 && i < N; i++, j--) {
        if (tabuleiro[i][j]) {
            return false;
        }
    }

    return true;
}

// Função recursiva que aplica o Backtracking coluna por coluna
bool resolverNRainhas(int tabuleiro[N][N], int coluna) {
    // Caso base: todas as rainhas foram posicionadas com sucesso
    if (coluna >= N) {
        return true;
    }

    // Tenta posicionar a rainha em cada linha da coluna atual
    for (int i = 0; i < N; i++) {
        if (ehSeguro(tabuleiro, i, coluna)) {
            // Escolha (avança na árvore de estados)
            tabuleiro[i][coluna] = 1;

            // Explora recursivamente o restante do tabuleiro
            if (resolverNRainhas(tabuleiro, coluna + 1)) {
                return true;
            }

            // Backtrack (desfaz a escolha se o caminho não levou a uma solução)
            tabuleiro[i][coluna] = 0;
        }
    }

    // Não foi possível posicionar a rainha em nenhuma linha desta coluna
    return false;
}

int main() {
    int tabuleiro[N][N] = {0};

    if (resolverNRainhas(tabuleiro, 0)) {
        printf("Backtracking (%d-Rainhas): Solução encontrada!\n\n", N);
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Backtracking (%d-Rainhas): Não existe solução.\n", N);
    }

    return 0;
}