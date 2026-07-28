#include <stdio.h>

int main() {
    FILE *fp = fopen("dados.txt", "r");

    char nome[50];
    int idade;

    fscanf(fp, "Nome: %s\n", nome);
    fscanf(fp, "Idade: %d", &idade);

    printf("%s tem %d anos\n", nome, idade);

    fclose(fp);
}