#include <stdio.h>

int main()
{

    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 != 0) // testa se i é impar
            continue;

        printf("%d \n", i); //mostra somente os pares
    }

    return 0;
}
