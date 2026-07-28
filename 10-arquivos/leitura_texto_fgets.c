#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("dados.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char linha[100];
    char nome[50];
    int idade;

    // Lê a linha "Nome: ..."
    fgets(linha, sizeof(linha), fp);

    // Extrai apenas o nome (remove "Nome: ")
    sscanf(linha, "Nome: %[^\n]", nome);

    // Lê a linha "Idade: ..."
    fgets(linha, sizeof(linha), fp);

    // Extrai a idade
    sscanf(linha, "Idade: %d", &idade);

    printf("%s tem %d anos\n", nome, idade);

    fclose(fp);
}