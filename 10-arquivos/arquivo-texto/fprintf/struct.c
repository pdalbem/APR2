#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main(void) {
    Pessoa p = {"Joaquim", 25, 1.78};

    FILE *arquivo = fopen("pessoa.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "%s;%d;%.2f\n",
            p.nome, p.idade, p.altura);

    fclose(arquivo);

    return 0;
}