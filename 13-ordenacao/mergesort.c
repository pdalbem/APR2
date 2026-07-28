#include <stdio.h>

// Complexidade:
// Melhor caso: O(n log n) (não depende da distribuição inicial dos elementos).
// Pior caso: O(n log n) (não depende da distribuição inicial dos elementos).
// Caso médio: O(n log n) (não depende da distribuição inicial dos elementos).

// Função para mesclar dois subvetores
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    // Cria os subvetores temporários
    int L[n1], R[n2];
    
    // Copia os dados para os subvetores temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    
    // Mescla os subvetores temporários de volta ao vetor original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        // Ordena a primeira metade
        mergeSort(arr, left, middle);
        
        // Ordena a segunda metade
        mergeSort(arr, middle + 1, right);
        
        // Mescla as duas metades ordenadas
        merge(arr, left, middle, right);
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
    
    mergeSort(arr, 0, n - 1);
    
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
