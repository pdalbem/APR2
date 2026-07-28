#include <stdio.h>

int main()
{
    int n;
    long int fatorial = 1;

    do
    {
        printf("Digite um numero inteiro nao negativo: ");
        scanf("%d", &n);

        if (n < 0)
           printf("Nao existe fatorial de numero negativo.\n");

        
    } while (n < 0);

    int i = 1;
    while (i <= n)
    {
        fatorial *= i;
        i++;
    }

    printf("Fatorial de %d = %ld\n", n, fatorial);

    return 0;
}
