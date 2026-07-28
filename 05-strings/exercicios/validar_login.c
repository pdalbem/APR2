#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char usuario[100];
    int valido = 1;

    printf("Digite o nome de usuário: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    int tamanho = strlen(usuario);

    /* regra 1: tamanho */
    if (tamanho < 5 || tamanho > 15)
        valido = 0;

    /* regra 2: começar com letra */
    if (!isalpha(usuario[0]))
        valido = 0;

    /* regra 3: não conter espaços */
    for (int i = 0; usuario[i] != '\0'; i++) {
        if (usuario[i] == ' ') {
            valido = 0;
            break;
        }
    }

    if (valido)
        printf("Usuário válido.\n");
    else
        printf("Usuário inválido.\n");

    return 0;
}