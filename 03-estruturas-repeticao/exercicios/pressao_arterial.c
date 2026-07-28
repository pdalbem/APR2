#include <stdio.h>

int main() {
    int qtd_pacientes, qtd_dias;
    float sistolica, diastolica;
    float somaSis, somaDia;
    float mediaSis, mediaDia;

    printf("Digite a quantidade de pacientes: ");
    scanf("%d", &qtd_pacientes);

    printf("Digite a quantidade de dias: ");
    scanf("%d", &qtd_dias);

    for (int i = 1; i <= qtd_pacientes; i++) {

        somaSis = 0;
        somaDia = 0;

        printf("\nPaciente %d\n", i);

        for (int j = 1; j <= qtd_dias; j++) {
            printf("Dia %d - Pressao sistolica: ", j);
            scanf("%f", &sistolica);

            printf("Dia %d - Pressao diastolica: ", j);
            scanf("%f", &diastolica);

            somaSis += sistolica;
            somaDia += diastolica;
        }

        mediaSis = somaSis / qtd_dias;
        mediaDia = somaDia / qtd_dias;

        printf("Media sistolica: %.2f\n", mediaSis);
        printf("Media diastolica: %.2f\n", mediaDia);

        if (mediaSis <= 12 && mediaDia <= 8) {
            printf("Classificacao: Normal\n");
        } else {
            printf("Classificacao: Hipertenso\n");
        }
    }

    return 0;
}
