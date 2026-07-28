#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;      // Caso base 1
    if (n == 1) return 1;      // Caso base 2
    return fibonacci(n - 1) + fibonacci(n - 2);  // Chamada recursiva
}

int main() {
    int num = 6;
    printf("Fibonacci(%d) = %d\n", num, fibonacci(num));  // Saída: 8
    return 0;
}