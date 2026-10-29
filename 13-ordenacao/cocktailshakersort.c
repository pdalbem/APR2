
#include <stdio.h>

// Complexidade:
// Melhor caso: O(n) (quando o vetor já está ordenado).
// Pior caso: O(n²).
// Caso médio: O(n²).
// Espaço auxiliar: O(1).

// Cocktail Shaker Sort
void cocktailSort(int arr[], int n)
{
    int inicio = 0;
    int fim = n - 1;
    int trocou = 1;

    while (trocou)
    {
        trocou = 0;

        // Percorre da esquerda para a direita
        for (int i = inicio; i < fim; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                trocou = 1;
            }
        }

        // Se não houve trocas, o vetor está ordenado
        if (!trocou)
            break;

        // O maior elemento já está na última posição
        fim--;

        trocou = 0;

        // Percorre da direita para a esquerda
        for (int i = fim; i > inicio; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;

                trocou = 1;
            }
        }

        // O menor elemento já está na primeira posição
        inicio++;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    cocktailSort(arr, n);

    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}
