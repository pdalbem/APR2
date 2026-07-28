#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    int i = 0;
    int vogais = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    while (str[i] != '\0') {

        char c = tolower(str[i]);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            vogais++; 

        i++;
    }

    printf("Quantidade de vogais: %d\n", vogais);

    return 0;
}