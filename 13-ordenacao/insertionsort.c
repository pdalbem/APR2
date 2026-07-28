#include <stdio.h>

// Complexidade:
// Melhor caso: O(n) (quando o vetor já está ordenado).
// Pior caso: O(n²) (quando o vetor está ordenado de forma inversa).
// Caso médio: O(n²) (quando o vetor tem uma distribuição aleatória).

void insertionSort(int arr[], int n) {
    int i, j, key;
    
    // Começa a partir do segundo elemento
    for (i = 1; i < n; i++) {
        key = arr[i];  // Elemento a ser inserido na parte ordenada
        j = i - 1;
        
        // Move os elementos maiores que o key uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Coloca o key na posição correta
        arr[j + 1] = key;
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
    
    insertionSort(arr, n);
    
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
