#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main() {
    FILE *fp = fopen("pessoas.bin", "rb");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return 1;
    }

    Pessoa pessoas[3];

    size_t lidos = fread(pessoas, sizeof(Pessoa), 3, fp);

    if (lidos == 0) {
        printf("Erro ao ler dados!\n");
        fclose(fp);
        return 1;
    }

    printf("Registros lidos: %zu\n\n", lidos);

    for (size_t i = 0; i < lidos; i++) {
        printf("ID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("-----------------\n");
    }

    fclose(fp);
    return 0;
}