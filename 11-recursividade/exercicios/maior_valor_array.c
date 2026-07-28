#include <stdio.h>

//A função compara o primeiro elemento (*v)
//com o maior valor do restante do vetor.
int maior_valor(int *v, int n) {
    if (n == 1)
        return *v;

    int maior_resto = maior_valor(v + 1, n - 1);

    if (*v > maior_resto)
        return *v;

    return maior_resto;
}

int main() {
    int v[] = {7, 3, 15, 2};

    int maior = maior_valor(v, 4);

    printf("Maior valor: %d\n", maior);

    return 0;
}