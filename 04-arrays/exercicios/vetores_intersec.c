#include <stdio.h>

#define TAMANHO 5

int main()
{
    int v1[TAMANHO], v2[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Digite o valor %d do primeiro vetor: ", i + 1);
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Digite o valor %d do segundo vetor: ", i + 1);
        scanf("%d", &v2[i]);
    }

    printf("\nValores que aparecem em ambos os vetores:\n");

    int encontrou;
    for (int i = 0; i < TAMANHO; i++)
    {
        encontrou = 0;

        for (int j = 0; j < TAMANHO; j++)
        {
            if (v1[i] == v2[j])
            {
                encontrou = 1;
                break;
            }
        }

        if (encontrou)
        {
            printf("%d ", v1[i]);
        }
    }

    return 0;
}