#include <stdio.h>

int main() {
    float salarioMinimo, qtdQuilowatts;
    float valorQuilowatt, valorTotal;

    printf("Digite o valor do salario minimo: ");
    scanf("%f", &salarioMinimo);

    printf("Digite a quantidade de quilowatts consumida: ");
    scanf("%f", &qtdQuilowatts);

    valorQuilowatt = salarioMinimo / 5;
    valorTotal = valorQuilowatt * qtdQuilowatts;

    printf("\nValor de cada quilowatt: R$ %.2f\n", valorQuilowatt);
    printf("Valor a ser pago pela residencia: R$ %.2f\n", valorTotal);

    return 0;
}
