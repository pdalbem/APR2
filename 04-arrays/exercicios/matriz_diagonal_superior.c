#include <stdio.h>

#define TAMANHO 3

int main() {
    int matriz[TAMANHO][TAMANHO];

    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            printf("Digite o elementos da linha %d, coluna %d: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nElementos acima da diagonal principal (inclusive):\n");

    for(int i = 0; i < TAMANHO; i++) 
        for(int j = 0; j < TAMANHO; j++) 
            if(j >= i)  // condição para estar acima da diagonal principal
                printf("%d ", matriz[i][j]);

    
    return 0;
}