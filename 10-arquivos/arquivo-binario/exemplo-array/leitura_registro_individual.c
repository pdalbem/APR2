#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main() {
    FILE *fp = fopen("pessoas.bin", "rb");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    Pessoa p;

    while (fread(&p, sizeof(Pessoa), 1, fp) == 1) {
        printf("ID: %d\n", p.id);
        printf("Nome: %s\n", p.nome);
        printf("-----------------\n");
    }

    fclose(fp);
    return 0;
}