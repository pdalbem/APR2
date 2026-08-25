#include <stdio.h>
#include <string.h>

int main()
{
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade); //deixou \n no buffer

    while (getchar()!='\n');
    
    char nome[30];
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin); // usuário pode digitar mais que 29 chars. O fgets captura somente 29 chars, deixando resto no buffer

    //procura \n para saber se houve buffer overflow
    if (strchr(nome, '\n') == NULL)
        while (getchar() != '\n'); // \n não encontrado, buffer overflow
    else
        nome[strcspn(nome, "\n")] = '\0'; // \n encontrado (não ocorreu buffer overflow) e substituído

    char curso[20];
    printf("Digite seu curso: ");
    fgets(curso, sizeof(curso), stdin);
    printf("%s, seu curso é %s \n", nome, curso);

    return 0;
}