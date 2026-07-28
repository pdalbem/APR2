#include <stdio.h>

int main() {
    int N;
    int i;
    long int a = 0, b = 1, prox;

    printf("Digite a quantidade de termos (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Valor invalido. N deve ser maior que zero.\n");
        return 0;
    }

    if (N >= 1) {
        printf("%ld ", a);
    }
    if (N >= 2) {
        printf("%ld ", b);
    }

    for (i = 3; i <= N; i++) {
        prox = a + b;
        printf("%ld ", prox);
        a = b;
        b = prox;
    }

    printf("\n");
    return 0;
}
