#include <stdio.h>

int main() {
    float cotacaoDolar, valorDolar, valorReais;

    printf("Digite a cotacao do dolar em reais: ");
    scanf("%f", &cotacaoDolar);

    printf("Digite o valor em dolar: ");
    scanf("%f", &valorDolar);

    valorReais = cotacaoDolar * valorDolar;

    printf("\nValor em reais: R$ %.2f\n", valorReais);

    return 0;
}
