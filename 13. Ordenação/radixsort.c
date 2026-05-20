#include <stdio.h>

// Complexidade:
// Melhor caso: O(d * (n + k))
// Pior caso: O(d * (n + k))
// Caso médio: O(d * (n + k))
//
// Onde:
// n = quantidade de elementos
// d = quantidade de dígitos do maior número
// k = base numérica (no decimal, k = 10)
//
// O Radix Sort ordena os números dígito por dígito,
// começando pelo menos significativo.

int getMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Counting Sort considerando um dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Conta ocorrências dos dígitos
    for (int i = 0; i < n; i++) {
        int indice = (arr[i] / exp) % 10;
        count[indice]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Monta o vetor ordenado (de trás para frente para manter estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        int indice = (arr[i] / exp) % 10;
        output[count[indice] - 1] = arr[i];
        count[indice]--;
    }

    // Copia para o vetor original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}