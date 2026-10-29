
#include <stdio.h>

// Complexidade:
// Melhor caso: O(n²) nesta implementação.
// Caso médio: O(n²).
// Pior caso: O(n²).
// Espaço auxiliar: O(1).

// Inverte os elementos do vetor entre os índices 0 e fim
void inverter(int arr[], int fim)
{
    int inicio = 0;

    while (inicio < fim)
    {
        int temp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = temp;

        inicio++;
        fim--;
    }
}

// Retorna o índice do maior elemento entre 0 e n - 1
int indiceMaior(int arr[], int n)
{
    int maior = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[maior])
            maior = i;
    }

    return maior;
}

// Pancake Sort
void pancakeSort(int arr[], int n)
{
    for (int tamanho = n; tamanho > 1; tamanho--)
    {
        // Encontra o maior elemento na parte não ordenada
        int maior = indiceMaior(arr, tamanho);

        // Se o maior já estiver no final da parte não ordenada,
        // não precisamos movê-lo
        if (maior == tamanho - 1)
            continue;

        // Leva o maior elemento para o início do vetor
        if (maior > 0)
            inverter(arr, maior);

        // Leva o maior elemento para o final da parte não ordenada
        inverter(arr, tamanho - 1);
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

    pancakeSort(arr, n);

    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}
