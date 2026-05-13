#include <stdio.h>

// Complexidade:
// Melhor caso: O(n) (quando o vetor já está ordenado).
// Pior caso: O(n²) (quando o vetor está ordenado de forma inversa).
// Caso médio: O(n²) (quando o vetor tem uma distribuição aleatória de elementos).

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
  
        int trocou = 0;
        
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        

        if (!trocou) {
            break;
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
    
    bubbleSort(arr, n);
    
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
