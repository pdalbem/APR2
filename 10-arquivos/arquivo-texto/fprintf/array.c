#include <stdio.h>

int main(void) {
    float temperaturas[] = {22.5, 24.0, 23.7, 21.8};
    int quantidade = 4;

    FILE *arquivo = fopen("temperaturas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%.1f\n", temperaturas[i]);
    }

    fclose(arquivo);

    return 0;
}