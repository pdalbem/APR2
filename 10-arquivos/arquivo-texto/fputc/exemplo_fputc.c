#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("texto.txt", "w");
    if (fp == NULL) 
        return 1;

    char frase[] = "programando em c";
    for (int i = 0; frase[i] != '\0'; i++) 
        fputc(toupper(frase[i]), fp);  // escreve em maiúsculo
    
    fputc('\n', fp);

    fclose(fp);
    return 0;
}