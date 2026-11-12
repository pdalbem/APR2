#include <stdio.h>


int buscaForcaBruta(int arr[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == alvo) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int dados[] = {42, 7, 19, 88, 3, 15};
    int n = sizeof(dados) / sizeof(dados[0]);
    int alvo = 88;

    int resultado = buscaForcaBruta(dados, n, alvo);
    if (resultado != -1) {
        printf("Força Bruta: Elemento %d encontrado no índice %d.\n", alvo, resultado);
    } else {
        printf("Força Bruta: Elemento não encontrado.\n");
    }
    return 0;
}