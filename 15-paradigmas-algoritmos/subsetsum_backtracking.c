#include <stdio.h>
#include <stdbool.h>

// Função para imprimir o subconjunto válido encontrado
void imprimirSubconjunto(int conjunto[], int tamanho) {
    printf("{ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", conjunto[i]);
    }
    printf("}\n");
}

// Função recursiva de Backtracking para Soma de Subconjuntos
void resolverSomaSubconjuntos(int conjunto[], int n, int indice, int alvo, int atual[], int tamanhoAtual, int somaAtual) {
    // Caso base: se a soma atual atingir o alvo, encontramos um subconjunto válido
    if (somaAtual == alvo) {
        printf("Subconjunto encontrado: ");
        imprimirSubconjunto(atual, tamanhoAtual);
        return; // Retorna para explorar outras combinações
    }

    // Poda: se ultrapassarmos o alvo ou esgotarmos os elementos do conjunto, encerramos este ramo
    if (somaAtual > alvo || indice >= n) {
        return;
    }

    // Escolha 1: Inclui o elemento atual no subconjunto
    atual[tamanhoAtual] = conjunto[indice];
    resolverSomaSubconjuntos(conjunto, n, indice + 1, alvo, atual, tamanhoAtual + 1, somaAtual + conjunto[indice]);

    // Escolha 2 (Backtrack): Exclui o elemento atual e avança para o próximo sem adicioná-lo
    resolverSomaSubconjuntos(conjunto, n, indice + 1, alvo, atual, tamanhoAtual, somaAtual);
}

int main() {
    int conjunto[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    int alvo = 35;
    
    int atual[100]; // Vetor auxiliar para armazenar o estado do subconjunto atual

    printf("Buscando subconjuntos que somam %d via Backtracking:\n\n", alvo);
    resolverSomaSubconjuntos(conjunto, n, 0, alvo, atual, 0, 0);

    return 0;
}