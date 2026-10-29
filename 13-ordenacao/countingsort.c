
#include <stdio.h>
#include <stdlib.h>

// Complexidade:
// Melhor caso: O(n + k).
// Caso médio: O(n + k).
// Pior caso: O(n + k).
// n = quantidade de elementos.
// k = maior valor do vetor + 1.
// Espaço auxiliar: O(k).

// Counting Sort
int countingSort(int arr[], int n)
{
    if (n <= 1)
        return 1;

    int maior = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            return 0;

        if (arr[i] > maior)
            maior = arr[i];
    }

    if (maior < 0)
        return 0;

    int *contagem = calloc((size_t)maior + 1, sizeof(int));

    if (contagem == NULL)
        return 0;

    // Conta as ocorrências de cada valor
    for (int i = 0; i < n; i++)
        contagem[arr[i]]++;

    // Reconstrói o vetor em ordem crescente
    int indice = 0;

    for (int i = 0; i <= maior; i++)
    {
        while (contagem[i] > 0)
        {
            arr[indice] = i;
            indice++;
            contagem[i]--;
        }
    }

    free(contagem);
    return 1;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    if (countingSort(arr, n))
    {
        printf("Vetor ordenado:\n");
        printArray(arr, n);
    }
    else
    {
        printf("Erro: valores inválidos ou falta de memória.\n");
    }

    return 0;
}
