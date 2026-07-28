#include <stdio.h>

int main() {
    float n1, n2, media;
    float maiorMedia = 0.0;

    for (int aluno = 1; aluno <= 5; aluno++) {

        // Primeira nota
        do {
            printf("Aluno %d - Digite a primeira nota: ", aluno);
            scanf("%f", &n1);
        } while (n1 < 0 || n1 > 10);

        // Segunda nota
        do {
            printf("Aluno %d - Digite a segunda nota: ", aluno);
            scanf("%f", &n2);
        } while (n2 < 0 || n2 > 10);

        media = (n1 + n2) / 2;

        printf("Media do aluno %d: %.2f - ", aluno, media);

        if (media >= 6.0) {
            printf("Aprovado\n");
        } else if (media >= 4.0) {
            printf("IFA\n");
        } else {
            printf("Reprovado\n");
        }

        if (media > maiorMedia) {
            maiorMedia = media;
        }
    }

    printf("\nMaior media obtida: %.2f\n", maiorMedia);

    return 0;
}
