#include <stdio.h>

int main() {
    int valor;
    int n100, n50, n20, n10, n5, n2;
    int resto;

    printf("Digite o valor do saque: ");
    scanf("%d", &valor);

    if (valor < 2) {
        printf("Valor invalido! O saque deve ser um inteiro positivo.\n");
        return 0;
    }

    resto = valor;

    n100 = resto / 100;
    resto = resto % 100;

    n50 = resto / 50;
    resto = resto % 50;

    n20 = resto / 20;
    resto = resto % 20;

    n10 = resto / 10;
    resto = resto % 10;

    n5 = resto / 5;
    resto = resto % 5;

    n2 = resto / 2;
    resto = resto % 2;

    if (resto != 0) {
        printf("Nao e possivel sacar o valor exato com as notas disponiveis.\n");
    } else {
        printf("Notas entregues:\n");
        printf("100: %d\n", n100);
        printf("50 : %d\n", n50);
        printf("20 : %d\n", n20);
        printf("10 : %d\n", n10);
        printf("5  : %d\n", n5);
        printf("2  : %d\n", n2);
    }

    return 0;
}
