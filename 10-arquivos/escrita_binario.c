#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main() {
    FILE *fp = fopen("dados.bin", "wb");

    Pessoa p = {1, "Carlos"};

    fwrite(&p, sizeof(Pessoa), 1, fp);

    fclose(fp);
}