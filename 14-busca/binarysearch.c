#include <stdio.h>

// Complexidade:
// Melhor caso: O(1) (quando o elemento está no meio).
// Pior caso: O(log n) (quando o elemento é encontrado após várias divisões).
// Caso médio: O(log n) (para a maioria das distribuições de dados).


// Função para realizar a busca binária em um vetor ordenado
int binarySearch(int arr[], int n, int chave) {
    int inicio = 0, fim = n - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if (arr[meio] == chave) 
            return meio;  // Encontrou a chave
                
        if (arr[meio] < chave) 
            inicio = meio + 1;  // Pesquisa na metade direita
          else 
            fim = meio - 1;  // Pesquisa na metade esquerda
        
    }
    
    return -1;  // Não encontrado
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
    int result = binarySearch(arr, n, target);
    
    // Exibe o resultado
    printResult(result);
    
    return 0;
}
