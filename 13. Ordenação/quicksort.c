#include <stdio.h>

// Complexidade:
// Melhor caso: O(n log n) (quando o pivô divide o vetor de maneira balanceada).
// Pior caso: O(n²) (quando o pivô é sempre o menor ou maior elemento).
// Caso médio: O(n log n) (quando o pivô divide o vetor de forma razoavelmente balanceada).

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o índice do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // O último elemento como pivô
    int i = (low - 1);  // Índice do menor elemento
    
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;  // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);  // Troca arr[i] e arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Troca o pivô com o elemento na posição i+1
    return (i + 1);  // Retorna a posição do pivô
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô
        int pi = partition(arr, low, high);
        
        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    quickSort(arr, 0, n - 1);
    
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
