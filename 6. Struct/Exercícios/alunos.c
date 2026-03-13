#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 5
#define QTD_NOTAS 3

typedef struct {
    int prontuario;
    char nome[50];
    float notas[QTD_NOTAS];
} Aluno;

int main() {

    Aluno alunos[QTD_ALUNOS];
    float media;

    for(int i = 0; i < QTD_ALUNOS; i++) {
        printf("\nAluno %d\n", i+1);

        printf("Prontuário: ");
        scanf("%d", &alunos[i].prontuario);
        while (getchar()!= '\n'); // remove \n deixado pelo scanf
        
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite as notas:\n");

        for(int j = 0; j < QTD_NOTAS; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }

    for(int i = 0; i < QTD_ALUNOS; i++) {
        float soma = 0.0;

        for(int j = 0; j < QTD_NOTAS; j++)
            soma += alunos[i].notas[j];

        media = soma / QTD_NOTAS;

        printf("\nAluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", media);

        if(media >= 6.0)
            printf("Aprovado\n");
        else if(media >= 4.0)
            printf("IFA\n");
        else
            printf("Reprovado\n");
    }

    return 0;
}