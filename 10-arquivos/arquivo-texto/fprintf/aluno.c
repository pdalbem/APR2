#include <stdio.h>

int main(void) {
    int prontuario = 12345;
    char nome[] = "Maria";
    float nota = 8.5;

    FILE *arquivo = fopen("aluno.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "%d;%s;%.1f\n",
            prontuario, nome, nota);

    fclose(arquivo);

    return 0;
}