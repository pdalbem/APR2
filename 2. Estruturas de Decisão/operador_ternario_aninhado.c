#include <stdio.h>

// Cuidado com a legibilidade!

int main() {
    int a = 10, b = 25, c = 15;

    // Lógica: Se a > b, testa a contra c. Senão, testa b contra c.
    int maior = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    printf("O maior numero eh: %d\n", maior);
    return 0;
}