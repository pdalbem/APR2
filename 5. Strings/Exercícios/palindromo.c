#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    int inicio = 0;
    int fim;
    int ehPalindromo = 1;

    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    fim = strlen(palavra) - 1;

    while (inicio < fim) {
        if (palavra[inicio] != palavra[fim]) {
            ehPalindromo = 0;
            break;
        }

        inicio++;
        fim--;
    }

    if (ehPalindromo)
        printf("A palavra eh um palindromo.\n");
    else
        printf("A palavra NAO eh um palindromo.\n");

    return 0;
}