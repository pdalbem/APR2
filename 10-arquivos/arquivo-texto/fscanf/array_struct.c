#include <stdio.h>

// formato do arquivo txt:
// 1;Ana;52.3
// 2;Carlos;48.7
// 3;Marina;55.1

int main(void) {
    FILE *arquivo = fopen("corrida.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero;
    char nome[50];
    float tempo;

    while (fscanf(arquivo, "%d;%49[^;];%f",
                  &numero, nome, &tempo) == 3) {
        printf("Numero: %d\n", numero);
        printf("Nome: %s\n", nome);
        printf("Tempo: %.1f\n\n", tempo);
    }

    fclose(arquivo);
    return 0;
}
