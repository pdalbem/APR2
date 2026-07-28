#include <stdio.h>
#include <string.h>

// definição da struct
typedef struct {
    char nome[50];
    int idade;
    float media[3];
} Aluno;

int main() {

    // Declaração de array de struct
    Aluno turma1[3];

    // Declaração e inicialização 
    Aluno turma2[2] = {
        {"Maria", 20, {8.5, 9.0, 7.5}},
        {"João", 22, {7.5, 8.0, 6.5}}
    };

    // Inicialização usando inicializador designado
    Aluno turma3[2] = {
        {.nome="Ana", .idade=19, .media={9.0, 8.5, 9.5}},
        {.nome="Carlos", .idade=21, .media={7.0, 6.5, 8.0}}
    };

    // Atribuição manual (hard coded)
    strcpy(turma1[0].nome, "Pedro");
    turma1[0].idade = 23;
    turma1[0].media[0] = 7.5;
    turma1[0].media[1] = 8.0;
    turma1[0].media[2] = 9.0;

    // Leitura de dados via teclado
    for(int i = 1; i < 3; i++) {

        printf("\nAluno %d\n", i+1);

        printf("Nome: ");
        scanf("%s", turma1[i].nome);

        printf("Idade: ");
        scanf("%d", &turma1[i].idade);

        printf("Digite as 3 medias:\n");

        for(int j = 0; j < 3; j++) {
            scanf("%f", &turma1[i].media[j]);
        }
    }

    // Exibindo dados
    printf("\n--- Dados da turma1 ---\n");

    for(int i = 0; i < 3; i++) {

        printf("\nAluno: %s\n", turma1[i].nome);
        printf("Idade: %d\n", turma1[i].idade);

        printf("Medias: ");

        for(int j = 0; j < 3; j++) {
            printf("%.1f ", turma1[i].media[j]);
        }

        printf("\n");
    }

    return 0;
}