
#include <stdio.h>

// Complexidade:
// Melhor caso: O(1).
// Caso médio: O(log(log(n))) para dados uniformemente distribuídos.
// Pior caso: O(n).
// Espaço auxiliar: O(1).

int interpolationSearch(int arr[], int n, int chave) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim &&
           chave >= arr[inicio] &&
           chave <= arr[fim]) {

        // Evita divisão por zero quando os extremos são iguais.
        if (arr[inicio] == arr[fim]) {
            if (arr[inicio] == chave)
                return inicio;

            return -1;
        }

        // Estima a posição provável da chave.
        int pos = inicio +
            (int)(((double)(chave - arr[inicio]) /
                   (arr[fim] - arr[inicio])) *
                  (fim - inicio));

        if (arr[pos] == chave)
            return pos;

        if (arr[pos] < chave)
            inicio = pos + 1;
        else
            fim = pos - 1;
    }

    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 70;

    printf("Vetor: ");
    printArray(arr, n);

    int indice = interpolationSearch(arr, n, chave);

    if (indice != -1)
        printf("Elemento %d encontrado no indice %d.\n", chave, indice);
    else
        printf("Elemento %d nao encontrado.\n", chave);

    return 0;
}
