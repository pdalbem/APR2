#include <stdio.h>

typedef struct {
    int numero;
    char nome[50];
    float tempo;
} Participante;

int main(void) {
    Participante participantes[] = {
        {101, "Maria", 52.4},
        {102, "Joaquim", 48.7},
        {103, "João", 50.2}
    };

    int quantidade = 3;

    FILE *arquivo = fopen("corrida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%s;%.1f\n",
                participantes[i].numero,
                participantes[i].nome,
                participantes[i].tempo);
    }

    fclose(arquivo);

    return 0;
}