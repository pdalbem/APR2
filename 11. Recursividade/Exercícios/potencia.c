#include <stdio.h>

int potencia(int x, int n) {
    if (n == 0)
        return 1;

    return x * potencia(x, n - 1);
}

int main() {
    int x = 2;
    int n = 5;

    int resultado = potencia(x, n);

    printf("%d elevado a %d = %d\n", x, n, resultado);

    return 0;
}