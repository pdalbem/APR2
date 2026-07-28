#include <stdio.h>
#include <string.h>


void lerString(char str[], int tamanho) {
    printf("Digite uma string: ");
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void substituirChar(char str[], char antigo, char novo) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == antigo) {
            str[i] = novo;
        }
    }
}

int main() {
    char str[100];
    char antigo, novo;

    lerString(str, 100);

    printf("Digite o caractere a ser substituído: ");
    scanf(" %c", &antigo);

    printf("Digite o novo caractere: ");
    scanf(" %c", &novo);

    substituirChar(str, antigo, novo);

    printf("String resultante: %s\n", str);

    return 0;
}