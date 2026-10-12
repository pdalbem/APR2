#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("arquivo.txt", "r");
    if (fp == NULL) 
       return 1;

    int c, letras=0, digitos=0;
    while ((c = fgetc(fp)) != EOF) 
       if (isalpha(c)) 
             letras++;
       else if (isdigit(c)) 
                  digitos++;
       
    fclose(fp);
    return 0;
}