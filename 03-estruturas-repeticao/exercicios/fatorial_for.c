#include <stdio.h>

int main() {
    int n;
    long int fatorial = 1;

    do
    {
        printf("Digite um numero inteiro nao negativo: ");
        scanf("%d", &n);

        if (n < 0)
           printf("Nao existe fatorial de numero negativo.\n");

        
    } while (n < 0);

    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }

    printf("Fatorial de %d = %lld\n", n, fatorial);

    return 0;
}
