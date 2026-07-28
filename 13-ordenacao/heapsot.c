#include <stdio.h>

// Complexidade:
// Melhor caso: O(n log n)
// Pior caso: O(n log n)
// Caso médio: O(n log n)
//
// O Heap Sort utiliza uma estrutura chamada Heap.
// Neste exemplo usamos uma Max Heap,
// onde o maior elemento fica na raiz.

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {

    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Verifica filho esquerdo
    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    // Verifica filho direito
    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);

        // Continua ajustando
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {

    // Constrói a Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Remove elementos da heap
    for (int i = n - 1; i > 0; i--) {

        // Move a raiz (maior elemento) para o final
        trocar(&arr[0], &arr[i]);

        // Reorganiza a heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}