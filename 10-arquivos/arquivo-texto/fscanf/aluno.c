#include <stdio.h>

// formato do arquivo txt:
// 12345;Joao Silva;8.5

int main(void) {
    FILE *arquivo = fopen("aluno.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int prontuario;
    char nome[50];
    float nota;

    if (fscanf(arquivo, "%d;%49[^;];%f",
               &prontuario, nome, &nota) == 3) {
        printf("Prontuario: %d\n", prontuario);
        printf("Nome: %s\n", nome);
        printf("Nota: %.1f\n", nota);
    } else {
        printf("Erro ao ler os dados.\n");
    }

    fclose(arquivo);
    return 0;
}
