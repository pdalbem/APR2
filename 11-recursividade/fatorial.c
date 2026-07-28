#include <stdio.h>

// Função recursiva para calcular fatorial
int fatorial(int n) {
    // Caso base: fatorial de 0 ou 1 é 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso recursivo: n! = n * (n-1)!
    return n * fatorial(n - 1);
}

int main() {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, fatorial(num));
    return 0;
}