#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main() {
    FILE *fp = fopen("dados.bin", "rb");

    Pessoa p;

    fread(&p, sizeof(Pessoa), 1, fp);

    printf("ID: %d\nNome: %s\n", p.id, p.nome);

    fclose(fp);
}