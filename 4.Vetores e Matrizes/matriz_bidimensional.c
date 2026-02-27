#include <stdio.h>

int main() {

    /* ==========================================
       DECLARAÇÃO (sem inicialização)
       ========================================== */
    int m1[2][3];

    /* ==========================================
       INICIALIZAÇÃO COMPLETA
       (todos os elementos informados)
       ========================================== */
    int m2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    /* ==========================================
       INICIALIZAÇÃO PARCIAL
       (restante recebe 0 automaticamente)
       ========================================== */
    int m3[2][3] = {
        {10, 20},
        {30}
    };
    /*
       Fica assim na memória:
       {10, 20, 0}
       {30,  0, 0}
    */

    /* ==========================================
       INICIALIZAÇÃO EM LINHA
       (preenchimento sequencial)
       ========================================== */
    int m4[2][3] = {1, 2, 3, 4, 5, 6};
    /*
       Equivalente a:
       {1, 2, 3}
       {4, 5, 6}
    */

    /* ==========================================
       LEITURA VIA TECLADO
       ========================================== */
    int m5[2][3];

    printf("Digite 6 valores para a matriz m5 (2x3):\n");

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("m5[%d][%d]: ", i, j);
            scanf("%d", &m5[i][j]);
        }
    }

    /* ==========================================
       ACESSO A ELEMENTO
       ========================================== */
    printf("\nElemento m2[1][2] = %d\n", m2[1][2]);

    /* ==========================================
       PERCURSO DA MATRIZ
       ========================================== */
    printf("\nPercorrendo m5:\n");

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m5[i][j]);
        }
        printf("\n");
    }

    return 0;
}