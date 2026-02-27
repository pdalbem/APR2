#include <stdio.h>

#define LIN 5
#define COL 4

int main() {
    int matriz[LIN][COL];
    int temp;

    for(int i = 0; i < LIN; i++) {
        for(int j = 0; j < COL; j++) {
            printf("Digite o valor da linha %d, coluna %d: ",i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    // ---- Troca da linha 1 com a linha 4 ----
    // (considerando índice começando em 0)
    for(int j = 0; j < COL; j++) {
        temp = matriz[1][j];
        matriz[1][j] = matriz[4][j];
        matriz[4][j] = temp;
    }

    // ---- Troca da coluna 0 com a coluna 3 ----
    for(int i = 0; i < LIN; i++) {
        temp = matriz[i][0];
        matriz[i][0] = matriz[i][3];
        matriz[i][3] = temp;
    }

    // Exibição da matriz resultante
    printf("\nMatriz após as trocas:\n");
    for(int i = 0; i < LIN; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}