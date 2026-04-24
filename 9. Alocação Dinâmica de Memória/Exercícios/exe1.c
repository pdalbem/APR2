#include <stdio.h>
#include <stdlib.h>

// cria array dinâmico
int* criarArray(int tamanho) {
    return calloc(tamanho, sizeof(int));
}

// lê valores para o vetor
void lerArray(int *v, int tamanho) {
    printf("Digite %d valores:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v[i]);
    }
}

// exibe o vetor
void exibirArray(int *v, int tamanho) {
    printf("Valores do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n ;
    printf("Digite a capacidade inicial do array: ");
    scanf("%d", &n);

    int *v = criarArray(n);

    if (v == NULL) {
        printf("Erro de alocação\n");
        return 1;
    }

    lerArray(v, n);
    exibirArray(v, n);

    free(v);
    return 0;
}