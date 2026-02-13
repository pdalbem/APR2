#include <stdio.h>

//versão não otimizada

int main() {
    int num, i, divisores = 0;

    
    do {
        printf("Digite um numero inteiro maior que 1: ");
        scanf("%d", &num);

        if (num <= 1) {
            printf("Valor invalido! ");
        }
    } while (num <= 1);

    // conta quantos divisores o número possui entre 1 e ele mesmo
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        printf("O numero %d eh PRIMO.\n", num);
    } else {
        printf("O numero %d NAO eh primo.\n", num);
    }

    return 0;
}