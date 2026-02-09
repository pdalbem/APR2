#include <stdio.h>

int main()
{
    int a,b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número (diferente do primeiro): ");
    scanf("%d", &b);
    
    int maior = (a > b) ? a : b;

    printf("Maior número: %d \n", maior);


    return 0;
}

