#include <stdio.h>

#define ALUNOS 10

int main() {

    float notas[ALUNOS];
    float soma = 0;
    float media;

    /* ===============================
       LEITURA DAS NOTAS
       =============================== */
    for(int i = 0; i < ALUNOS; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    /* ===============================
       CÁLCULO DA MÉDIA
       =============================== */
    media = soma / ALUNOS;

    printf("\nMedia da turma: %.2f\n", media);

    /* ===============================
       MOSTRAR NOTAS ACIMA DA MÉDIA
       =============================== */
    printf("\nNotas acima da media:\n");

    for(int i = 0; i < ALUNOS; i++) {
        if(notas[i] > media) {
            printf("Aluno %d: %.2f\n", i + 1, notas[i]);
        }
    }

    return 0;
}