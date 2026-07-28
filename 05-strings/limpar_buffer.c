#include <stdio.h>
#include <string.h>

int main()
{
    char nome[30];
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);  //usuário pode digitar mais que 29 chars. O fgets captura somente 29 chars, deixando resto no buffer
    nome[strcspn(nome, "\n")] = '\0'; // remove \n do final
    
    while (getchar() != '\n'); //limpeza de buffer

    char curso[20];
    printf("Digite seu curso: ");
    fgets(curso, sizeof(curso), stdin);
    printf("%s, seu curso é %s \n", nome, curso);

    return 0;
}