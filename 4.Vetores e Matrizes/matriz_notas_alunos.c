#include <stdio.h>

#define ALUNOS 10
#define AVALIACOES 3

int main() {

    float notas[AVALIACOES][ALUNOS];

    /* ===============================
       LEITURA DAS NOTAS
       =============================== */
    for(int i = 0; i < AVALIACOES; i++) {
        printf("\nAvaliacao %d\n", i + 1);

        for(int j = 0; j < ALUNOS; j++) {
            printf("Nota do aluno %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    /* ===============================
       MÉDIA DE CADA ALUNO
       =============================== */
    printf("\n===== MEDIA DE CADA ALUNO =====\n");

    for(int j = 0; j < ALUNOS; j++) {

        float soma = 0;

        for(int i = 0; i < AVALIACOES; i++) {
            soma += notas[i][j];
        }

        printf("Aluno %d: %.2f\n", j + 1, soma / AVALIACOES);
    }

    /* ===============================
       MÉDIA DE CADA AVALIACAO
       =============================== */
    printf("\n===== MEDIA DE CADA AVALIACAO =====\n");

    for(int i = 0; i < AVALIACOES; i++) {

        float soma = 0;

        for(int j = 0; j < ALUNOS; j++) {
            soma += notas[i][j];
        }

        printf("Avaliacao %d: %.2f\n", i + 1, soma / ALUNOS);
    }

    return 0;
}