#include <stdio.h>

// formato do arquivo txt:
// 23.5
// 25.0
// 21.8

int main(void) {
    FILE *arquivo = fopen("temperaturas.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    float temperatura;

    while (fscanf(arquivo, "%f", &temperatura) == 1) {
        printf("Temperatura: %.1f\n", temperatura);
    }

    fclose(arquivo);
    return 0;
}
