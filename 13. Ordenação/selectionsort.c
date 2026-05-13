#include <stdio.h>

// Complexidade
// Melhor caso: O(n²) (o número de comparações não depende da ordenação inicial).
// Pior caso: O(n²) (como no caso médio, o número de comparações não muda).
// Caso médio: O(n²) (como no pior caso, o número de comparações é o mesmo).

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    
      for (i = 0; i < n - 1; i++) {
        minIdx = i;
        
        // Encontra o menor elemento na parte não ordenada do vetor
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
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
    
    printf("Vetor original: \n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
