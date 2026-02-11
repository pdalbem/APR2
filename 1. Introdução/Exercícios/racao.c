#include <stdio.h>

int main() {
    float pesoSacoKg;
    int racaoGato1, racaoGato2; 
    float consumoTotalKg, restanteKg;

    printf("Digite o peso do saco de racao (em kg): ");
    scanf("%f", &pesoSacoKg);

    printf("Digite a quantidade diaria de racao do gato 1 (em gramas): ");
    scanf("%d", &racaoGato1);

    printf("Digite a quantidade diaria de racao do gato 2 (em gramas): ");
    scanf("%d", &racaoGato2);

    /* Consumo total em 5 dias (gramas -> quilos) */
    consumoTotalKg = ( (racaoGato1 + racaoGato2) * 5 ) / 1000.0;

    restanteKg = pesoSacoKg - consumoTotalKg;

    printf("\nQuantidade de racao restante apos 5 dias: %.2f kg\n", restanteKg);

    return 0;
}
