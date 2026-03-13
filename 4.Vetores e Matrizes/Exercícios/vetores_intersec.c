#include <stdio.h>

#define QTD_PRODUTOS 5

int main()
{
    int v1[QTD_PRODUTOS], v2[QTD_PRODUTOS];

    for (int i = 0; i < QTD_PRODUTOS; i++)
    {
        printf("Digite o valor %d do primeiro vetor: ", i + 1);
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < QTD_PRODUTOS; i++)
    {
        printf("Digite o valor %d do segundo vetor: ", i + 1);
        scanf("%d", &v2[i]);
    }

    printf("\nValores que aparecem em ambos os vetores:\n");

    int encontrou;
    for (int i = 0; i < QTD_PRODUTOS; i++)
    {
        encontrou = 0;

        for (int j = 0; j < QTD_PRODUTOS; j++)
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