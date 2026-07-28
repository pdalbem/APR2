#include <stdio.h>
#include <stdlib.h>

void copiarArquivo(const char *origem, const char *destino) {
    FILE *fpOrigem = fopen(origem, "r");
    FILE *fpDestino = fopen(destino, "w");

    if (fpOrigem == NULL) {
        printf("Erro ao abrir o arquivo de origem!\n");
        return;
    }

    if (fpDestino == NULL) {
        printf("Erro ao abrir o arquivo de destino!\n");
        fclose(fpOrigem);
        return;
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), fpOrigem) != NULL) 
        fputs(linha, fpDestino);

    fclose(fpOrigem);
    fclose(fpDestino);

    printf("Arquivo copiado com sucesso!\n");
}

int main() {
    copiarArquivo("origem.txt", "destino.txt");
    return 0;
}