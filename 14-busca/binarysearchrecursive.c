#include <stdio.h>

// Complexidade:
// Melhor caso: O(1)
// Caso médio: O(log n)
// Pior caso: O(log n)

// Função recursiva para a busca binária
int binarySearch(int arr[], int low, int high, int target) {
    // Caso base: o intervalo de busca é inválido
    if (low > high) {
        return -1; // Elemento não encontrado
    }

    int mid = low + (high - low) / 2;

    // Se o valor procurado for encontrado no meio
    if (arr[mid] == target) {
        return mid;
    }
    // Se o valor procurado for menor que o valor no meio, buscar na metade esquerda
    else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    }
    // Se o valor procurado for maior que o valor no meio, buscar na metade direita
    else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

void printResult(int result) {
    if (result == -1)
        printf("Elemento não encontrado!\n");
    else
        printf("Elemento encontrado na posição %d.\n", result);
}

int main() {
    int arr[] = {11, 12, 22, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 25;  // Elemento a ser procurado
    
    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Chama a função de busca binária
    int result = binarySearch(arr, 0, n - 1, target);
    
    // Exibe o resultado
    printResult(result);
    
    return 0;
}