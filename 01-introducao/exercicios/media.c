#include <stdio.h>

int main() {
    float nota1, nota2, nota3;
    float peso1, peso2, peso3;
    float media;

    /* Leitura das notas */
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    /* Leitura dos pesos */
    printf("Digite o peso da primeira nota: ");
    scanf("%f", &peso1);

    printf("Digite o peso da segunda nota: ");
    scanf("%f", &peso2);

    printf("Digite o peso da terceira nota: ");
    scanf("%f", &peso3);

    /* Cálculo da média ponderada */
    media = (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) /
            (peso1 + peso2 + peso3);

    /* Saída */
    printf("A media ponderada do aluno eh: %.2f\n", media);

    return 0;
}
