#include <stdio.h>

#define LIN 4
#define COL 3

int main() {
    int matriz[LIN][COL];

    for(int i = 0; i < LIN; i++) {
        for(int j = 0; j < COL; j++) {
            printf("Digite o valor da linha %d, coluna %d: ",i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nQuantidade de numeros pares por linha:\n");
    for(int i = 0; i < LIN; i++) {
        int qtdPares = 0;

        for(int j = 0; j < COL; j++) 
            if(matriz[i][j] % 2 == 0) 
                qtdPares++;
            
        

        printf("Linha %d: %d pares\n", i, qtdPares);
    }

    // Média por coluna
    printf("\nMedia dos numeros por coluna:\n");
    for(int j = 0; j < COL; j++) {
        int soma = 0;

        for(int i = 0; i < LIN; i++) 
            soma += matriz[i][j];
        

        float media = (float)soma / LIN;
        printf("Coluna %d: %.2f\n", j, media);
    }

    return 0;
}