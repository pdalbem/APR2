
#include <stdio.h>

// Complexidade:
// Melhor caso: O(1).
// Caso médio: O(log(n)).
// Pior caso: O(log(n)).
// Espaço auxiliar: O(1), na versão iterativa.

int binarySearch(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == chave)
            return meio;

        if (arr[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int chave) {
    if (n <= 0)
        return -1;

    if (arr[0] == chave)
        return 0;

    int limite = 1;

    // Dobra o índice até encontrar um limite adequado.
    while (limite < n && arr[limite] < chave)
        limite *= 2;

    // Busca binária no intervalo delimitado.
    int inicio = limite / 2;
    int fim = (limite < n) ? limite : n - 1;

    return binarySearch(arr, inicio, fim, chave);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 45;

    printf("Vetor: ");
    printArray(arr, n);

    int indice = exponentialSearch(arr, n, chave);

    if (indice != -1)
        printf("Elemento %d encontrado no indice %d.\n", chave, indice);
    else
        printf("Elemento %d nao encontrado.\n", chave);

    return 0;
}
