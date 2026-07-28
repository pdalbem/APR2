#include <stdio.h>

int main() {
    FILE *fp = fopen("dados.txt", "w");

    if (fp == NULL) return 1;

    fprintf(fp, "Nome: Maria\n");
    fprintf(fp, "Idade: %d\n", 30);

    fclose(fp);
}