
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Pessoa;

int main(void) {
    FILE *fp = fopen("pessoas.bin", "rb");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Vai para o final do arquivo
    if (fseek(fp, 0, SEEK_END) != 0) {
        printf("Erro ao posicionar no arquivo!\n");
        fclose(fp);
        return 1;
    }

    // Descobre o tamanho do arquivo em bytes
    long tamanho = ftell(fp);

    if (tamanho < 0) {
        printf("Erro ao obter tamanho do arquivo!\n");
        fclose(fp);
        return 1;
    }

    // Verifica se o tamanho corresponde a registros completos
    if (tamanho % sizeof(Pessoa) != 0) {
        printf("Arquivo possui tamanho invalido!\n");
        fclose(fp);
        return 1;
    }

    // Calcula a quantidade de registros
    size_t quantidade = (size_t)tamanho / sizeof(Pessoa);

    // Volta ao início do arquivo
    rewind(fp);

    // Aloca espaço para todos os registros
    Pessoa *pessoas = NULL;

    if (quantidade > 0) {
        pessoas = malloc(quantidade * sizeof(Pessoa));

        if (pessoas == NULL) {
            printf("Erro ao alocar memoria!\n");
            fclose(fp);
            return 1;
        }
    }

    // Lê todos os registros de uma vez
    size_t lidos = fread(pessoas, sizeof(Pessoa), quantidade, fp);

    if (lidos != quantidade || ferror(fp)) {
        printf("Erro ao ler os registros!\n");
        free(pessoas);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    // Exibe os registros
    for (size_t i = 0; i < quantidade; i++) {
        printf("ID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("-----------------\n");
    }

    printf("Total de pessoas: %zu\n", quantidade);

    free(pessoas);
    return 0;
}

