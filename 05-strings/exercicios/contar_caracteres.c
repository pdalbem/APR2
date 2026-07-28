#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int cont = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    while (str[cont] != '\0') 
        cont++;
    

    printf("Quantidade de caracteres: %d\n", cont);

    return 0;
}