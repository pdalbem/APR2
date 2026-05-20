#include <stdio.h>

// Complexidade:
// Melhor caso: O(n log n) (dependendo da sequência de gaps).
// Pior caso: O(n²).
// Caso médio: entre O(n^1.3) e O(n^1.5), dependendo da sequência de gaps.
//
// O Shell Sort é uma melhoria do Insertion Sort.
// Ele compara elementos distantes entre si usando um intervalo (gap),
// reduzindo gradualmente esse intervalo até chegar em 1.

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Define os gaps: n/2, n/4, ..., 1
    for (gap = n / 2; gap > 0; gap /= 2) {

        // Faz um insertion sort considerando o gap atual
        for (i = gap; i < n; i++) {

            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}