#include <stdio.h>

int main() {
    FILE *origem = fopen("entrada.txt", "r");
    FILE *destino = fopen("saida.txt", "w");

    char c;

    while ((c = fgetc(origem)) != EOF) {
        fputc(c, destino);
    }

    fclose(origem);
    fclose(destino);
}