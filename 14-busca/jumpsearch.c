
#include <stdio.h>
#include <math.h>

// Complexidade:
// Melhor caso: O(1).
// Caso médio: O(sqrt(n)).
// Pior caso: O(sqrt(n)).
// Espaço auxiliar: O(1).

int jumpSearch(int arr[], int n, int chave) {
    if (n <= 0)
        return -1;

    int salto = (int)sqrt(n);
    int inicio = 0;
    int fim = salto;

    // Avança de bloco em bloco.
    while (inicio < n && arr[(fim < n ? fim : n) - 1] < chave) {
        inicio = fim;
        fim += salto;

        if (inicio >= n)
            return -1;
    }

    // Busca linear dentro do bloco encontrado.
    if (fim > n)
        fim = n;

    for (int i = inicio; i < fim; i++) {
        if (arr[i] == chave)
            return i;

        if (arr[i] > chave)
            return -1;
    }

    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 23;

    printf("Vetor: ");
    printArray(arr, n);

    int indice = jumpSearch(arr, n, chave);

    if (indice != -1)
        printf("Elemento %d encontrado no indice %d.\n", chave, indice);
    else
        printf("Elemento %d nao encontrado.\n", chave);

    return 0;
}
