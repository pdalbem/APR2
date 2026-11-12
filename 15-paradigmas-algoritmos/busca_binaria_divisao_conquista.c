#include <stdio.h>

int buscaBinariaRecursiva(int arr[], int esquerda, int direita, int alvo) {
    if (esquerda > direita) {
        return -1; 
    }

    int meio = esquerda + (direita - esquerda) / 2;

    if (arr[meio] == alvo) {
        return meio; 
    }

    if (arr[meio] > alvo) {
        return buscaBinariaRecursiva(arr, esquerda, meio - 1, alvo); 
    }

    return buscaBinariaRecursiva(arr, meio + 1, direita, alvo); 
}

int main() {
    int dados[] = {3, 7, 15, 19, 42, 88}; 
    int n = sizeof(dados) / sizeof(dados[0]);
    int alvo = 19;

    int resultado = buscaBinariaRecursiva(dados, 0, n - 1, alvo);
    if (resultado != -1) {
        printf("Divisão e Conquista: Elemento %d encontrado no índice %d.\n", alvo, resultado);
    } else {
        printf("Divisão e Conquista: Elemento não encontrado.\n");
    }
    return 0;
}