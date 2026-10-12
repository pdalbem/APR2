#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void salvar_aluno(Aluno a) {
    FILE *arq = fopen("alunos.txt", "a");
    if (arq == NULL) return;
    fprintf(arq, "%s;%d;%.2f\n", a.nome, a.idade, a.nota);
    fclose(arq);
}

void listar_alunos() {
    FILE *arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    char linha[100];
    while (fgets(linha, sizeof(linha), arq)) {
        // Remove o newline
        linha[strcspn(linha, "\n")] = 0;
        printf("%s\n", linha);
    }
    fclose(arq);
}

int main() {
    Aluno a1 = {"Maria", 22, 9.5};
    Aluno a2 = {"Pedro", 20, 8.0};
    salvar_aluno(a1);
    salvar_aluno(a2);
    listar_alunos();
    return 0;
}