#include <stdio.h>

// Complexidade:
// Melhor caso: O(1) (quando o elemento está no primeiro índice).
// Caso médio: O(n) (média de iterações necessárias).
// Pior caso: O(n) (quando o elemento está no final ou não está presente).

int linearSearch(int arr[], int n, int target) {

    for (int i = 0; i < n; i++) 
        if (arr[i] == target) 
            return i;
        
    return -1;
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
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    
    printf("\n");
    

    int result = linearSearch(arr, n, target);
    
    printResult(result);
    
    return 0;
}
