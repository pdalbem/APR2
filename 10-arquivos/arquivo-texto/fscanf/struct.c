#include <stdio.h>

// formato do arquivo txt:
// Maria;35

int main(void) {
    FILE *arquivo = fopen("pessoa.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char nome[50];
    int idade;

    if (fscanf(arquivo, "%49[^;];%d", nome, &idade) == 2) {
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
    } else {
        printf("Erro ao ler os dados.\n");
    }

    fclose(arquivo);
    return 0;
}
