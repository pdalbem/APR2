#include <stdio.h>

#define TAM 3

int main() {
    int matriz[TAM][TAM];

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("Digite o elementos da linha %d, coluna %d: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nElementos acima da diagonal principal (inclusive):\n");

    for(int i = 0; i < TAM; i++) 
        for(int j = 0; j < TAM; j++) 
            if(j >= i)  // condição para estar acima da diagonal principal
                printf("%d ", matriz[i][j]);

    
    return 0;
}