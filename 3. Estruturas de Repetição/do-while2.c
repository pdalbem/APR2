#include <stdio.h>

int main()
{
    int numero;

    do
    {
        printf("Digite um número positivo: ");
        scanf("%d", &numero);

    } while (numero <= 0);

    printf("Você digitou: %d\n", numero);
    return 0;
}
