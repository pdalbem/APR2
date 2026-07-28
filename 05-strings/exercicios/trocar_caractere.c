#include <stdio.h>
#include <string.h>

int main() {

    char str[200];
    char caractere;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite um caractere: ");
    scanf("%c", &caractere);

    for (int i = 0; str[i] != '\0'; i++) 
        if (str[i] == caractere) 
            str[i] = '*';
        
    

    printf("String resultante: %s\n", str);

    return 0;
}