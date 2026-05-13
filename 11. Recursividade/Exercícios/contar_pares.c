#include <stdio.h>

int contar_pares(int *v, int n) {
    if (n == 0)
        return 0;

    if (*v % 2 == 0)
        return 1 + contar_pares(v + 1, n - 1);

    return contar_pares(v + 1, n - 1);
}

int main() {
    int v[] = {1, 2, 3, 4, 6, 7, 8, 10};

    int tamanho = sizeof(v) / sizeof(v[0]);

    int qtd = contar_pares(v, tamanho);

    printf("Quantidade de números pares: %d\n", qtd);

    return 0;
}