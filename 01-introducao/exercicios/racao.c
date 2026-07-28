#include <stdio.h>

int main() {
    float pesoSacoKg;
    int racaoGato1, racaoGato2; 
    float consumoGato1Kg, consumoGato2Kg;
    float consumoTotalKg, restanteKg;

    printf("Digite o peso do saco de racao (em kg): ");
    scanf("%f", &pesoSacoKg);

    printf("Digite a quantidade diaria de racao do gato 1 (em gramas): ");
    scanf("%d", &racaoGato1);

    printf("Digite a quantidade diaria de racao do gato 2 (em gramas): ");
    scanf("%d", &racaoGato2);

    /* Consumo de cada gato em 5 dias (gramas -> quilos) */
    consumoGato1Kg = (racaoGato1 * 5) / 1000.0;
    consumoGato2Kg = (racaoGato2 * 5) / 1000.0;

    /* Consumo total dos dois gatos */
    consumoTotalKg = consumoGato1Kg + consumoGato2Kg;

    restanteKg = pesoSacoKg - consumoTotalKg;

    printf("\nConsumo do gato 1 em 5 dias: %.2f kg\n", consumoGato1Kg);
    printf("Consumo do gato 2 em 5 dias: %.2f kg\n", consumoGato2Kg);
    printf("Quantidade de racao restante apos 5 dias: %.2f kg\n", restanteKg);

    return 0;
}
