#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main() {
    FILE *fp = fopen("pessoas.bin", "wb");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo para escrita!\n");
        return 1;
    }

    Pessoa pessoas[3] = {
        {1, "Ana"},
        {2, "Carlos"},
        {3, "Mariana"}
    };

    // grava os 3 registros de uma vez
    size_t escritos = fwrite(pessoas, sizeof(Pessoa), 3, fp);

    if (escritos != 3) {
        printf("Erro ao gravar dados!\n");
    } else {
        printf("Dados gravados com sucesso!\n");
    }

    fclose(fp);
    return 0;
}