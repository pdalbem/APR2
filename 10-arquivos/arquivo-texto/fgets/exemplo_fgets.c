#include <stdio.h>

// formato do arquivo txt:
// 12345;Joao Silva;8.5

int main(void) {
    FILE *arquivo = fopen("aluno.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[100];

    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("Dados do aluno: %s", linha);
    }

    fclose(arquivo);
    return 0;
}
