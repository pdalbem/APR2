#include <stdio.h>
#include <string.h>

// definição da struct
typedef struct {
    char nome[50];
    int idade;
    float media[3];
} Aluno;

int main() {

    // Declaração de variável
    Aluno a1;

    // Declaração e inicialização 
    Aluno a2 = {"Maria", 20, {8.5, 9.0, 7.5}};

    // Declaração e inicialização com inicializador designado
    Aluno a3 = {
        .nome = "João",
        .idade = 22,
        .media = {7.5, 8.0, 6.5}
    };

    // Inicialização parcial
    // campos não especificados recebem 0
    Aluno a4 = {
        .nome = "Ana"
    };

    // Atribuição 
    Aluno a5;

    strcpy(a5.nome, "Carlos");
    a5.idade = 25;

    a5.media[0] = 7.0;
    a5.media[1] = 8.5;
    a5.media[2] = 9.0;

    // Atribuição via leitura do teclado
    Aluno a6;

    printf("Digite o nome: ");
    scanf("%s", a6.nome);

    printf("Digite a idade: ");
    scanf("%d", &a6.idade);

    printf("Digite as 3 medias:\n");
    for(int i = 0; i < 3; i++){
        scanf("%f", &a6.media[i]);
    }

    // Exibindo alguns dados
    printf("\nAluno a2: %s %d %.1f %.1f %.1f\n",
           a2.nome, a2.idade,
           a2.media[0], a2.media[1], a2.media[2]);

    printf("\nAluno a3: %s %d %.1f %.1f %.1f\n",
           a3.nome, a3.idade,
           a3.media[0], a3.media[1], a3.media[2]);

    printf("\nAluno a5: %s %d %.1f %.1f %.1f\n",
           a5.nome, a5.idade,
           a5.media[0], a5.media[1], a5.media[2]);

    return 0;
}