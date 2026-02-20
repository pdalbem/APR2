#include <stdio.h>

int main()
{
    int numeros[2][3];

    // =============================
    // INICIALIZAÇÃO
    // =============================
    numeros[0][0] = 10;
    numeros[0][1] = 20;
    numeros[0][2] = 30;

    numeros[1][0] = 40;
    numeros[1][1] = 50;
    numeros[1][2] = 60;

    // =============================
    // PERCURSO
    // =============================
    printf("Valores inicializados:\n");

    for(int i = 0; i < 2; i++)
       for(int j = 0; j < 3; j++)
           printf("numeros[%d][%d] = %d\n", i, j, numeros[i][j]);
        
    

    printf("\nDigite novos valores:\n");

    for(int i = 0; i < 2; i++)
       for(int j = 0; j < 3; j++)
        {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &numeros[i][j]);
        }
    

    printf("\nValores digitados:\n");

    for(int i = 0; i < 2; i++)
       for(int j = 0; j < 3; j++)
           printf("numeros[%d][%d] = %d\n", i, j, numeros[i][j]);

    return 0;
}