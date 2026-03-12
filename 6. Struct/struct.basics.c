#include <stdio.h>
#include <string.h>

// definição da struct
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    // Declaração de variável
    Aluno a1;

    // Declaração e inicialização 
    Aluno a2 = {"Maria", 20, 8.5};

    // Declaração e inicialização com inicializador designado
    Aluno a3 = {
        .nome = "João",
        .idade = 22,
        .media = 7.8
    };

    // Inicialização parcial com inicializador designado
    // campos não especificados recebem 0
    Aluno a4 = {
        .nome = "Ana"
    };

    // Atribuição 
    Aluno a5;
    strcpy(a5.nome, "Joaquim");
    a5.idade = 25;
    a5.media = 6.9;

    // Atribuição via leitura do teclado
    Aluno a6;

    printf("Digite o nome: ");
    scanf("%s", a6.nome);

    printf("Digite a idade: ");
    scanf("%d", &a6.idade);

    printf("Digite a media: ");
    scanf("%f", &a6.media);

    // Exibindo 
    printf("\nAluno a2: %s %d %.2f\n", a2.nome, a2.idade, a2.media);
    printf("Aluno a3: %s %d %.2f\n", a3.nome, a3.idade, a3.media);
    printf("Aluno a4: %s %d %.2f\n", a4.nome, a4.idade, a4.media);
    printf("Aluno a5: %s %d %.2f\n", a5.nome, a5.idade, a5.media);
    printf("Aluno a6: %s %d %.2f\n", a6.nome, a6.idade, a6.media);

    return 0;
}