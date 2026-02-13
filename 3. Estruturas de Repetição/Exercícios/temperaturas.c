#include <stdio.h>

#define QTD_DIAS 7

int main() {
    float temp;
    float soma = 0;
    float maior, menor;

    for (int i = 1; i <= QTD_DIAS; i++) {
        printf("Digite a temperatura do dia %d: ", i);
        scanf("%f", &temp);

        soma += temp;

        if (i == 1) {
            maior = temp;
            menor = temp;
        } else {
            if (temp > maior) {
                maior = temp;
            }
            if (temp < menor) {
                menor = temp;
            }
        }
    }

    printf("\nMedia das temperaturas: %.2f\n", soma / QTD_DIAS);
    printf("Temperatura mais alta: %.2f\n", maior);
    printf("Temperatura mais baixa: %.2f\n", menor);

    return 0;
}
