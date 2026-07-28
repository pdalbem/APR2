#include <stdio.h>

#define QTD_PRODUTOS 3

int main() {
    int matriz[QTD_PRODUTOS][QTD_PRODUTOS];

    for(int i = 0; i < QTD_PRODUTOS; i++) {
        for(int j = 0; j < QTD_PRODUTOS; j++) {
            printf("Digite o elementos da linha %d, coluna %d: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nElementos acima da diagonal principal (inclusive):\n");

    for(int i = 0; i < QTD_PRODUTOS; i++) 
        for(int j = 0; j < QTD_PRODUTOS; j++) 
            if(j >= i)  // condição para estar acima da diagonal principal
                printf("%d ", matriz[i][j]);

    
    return 0;
}