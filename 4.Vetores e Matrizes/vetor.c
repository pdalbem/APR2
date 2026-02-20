#include <stdio.h>

int main()
{
    // =============================
    // DECLARAÇÃO
    // =============================
    int numeros[5];

    // =============================
    // INICIALIZAÇÃO
    // =============================
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    numeros[3] = 40;
    numeros[4] = 50;

    // =============================
    // INICIALIZAÇÃO NA DECLARAÇÃO
    // ============================= 
    float notas[4]={9.5, 7.8, 8.6, 9.0};


    // =============================
    // PERCURSO 
    // =============================
    printf("Valores do vetor:\n");

    for(int i = 0; i < 5; i++)
        printf("numeros[%d] = %d\n", i, numeros[i]);
    


    printf("\nDigite novos valores:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nValores digitados:\n");

    for(int i = 0; i < 5; i++)
        printf("numeros[%d] = %d\n", i, numeros[i]);
    

    return 0;
}