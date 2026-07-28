#include <stdio.h>

int main() {

    /* ==========================================
       DECLARAÇÃO (sem inicialização)
       ========================================== */
    int v1[5];

    /* ==========================================
       INICIALIZAÇÃO COMPLETA
       (todos os elementos informados)
       ========================================== */
    int v2[5] = {1, 2, 3, 4, 5};

    /* ==========================================
       INICIALIZAÇÃO PARCIAL
       (restante recebe 0 automaticamente)
       ========================================== */
    int v3[5] = {10, 20};
    /*
       Fica assim na memória:
       {10, 20, 0, 0, 0}
    */

    /* ==========================================
       INICIALIZAÇÃO COM TAMANHO INFERIDO
       (compilador calcula automaticamente)
       ========================================== */
    int v4[] = {7, 8, 9, 10}; //Tamanho automaticamente definido como 4
 

    /* ==========================================
       LEITURA VIA TECLADO
       ========================================== */
    int v5[5];

    printf("Digite 5 valores para o vetor v5:\n");

    for(int i = 0; i < 5; i++) {
        printf("v5[%d]: ", i);
        scanf("%d", &v5[i]);
    }

    /* ==========================================
       ACESSO A ELEMENTO
       ========================================== */
    printf("\nElemento v2[3] = %d\n", v2[3]);

    /* ==========================================
       PERCURSO DO VETOR
       ========================================== */
    printf("\nPercorrendo v5:\n");

    for(int i = 0; i < 5; i++) {
        printf("%d ", v5[i]);
    }

    printf("\n");

    return 0;
}