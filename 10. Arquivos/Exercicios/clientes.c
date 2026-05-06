#include <stdio.h>
#include <stdlib.h>

#define QTD 5

void gravarClientes()
{
    FILE *fp = fopen("clientes.txt", "w");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    char nome[100];
    char email[100];

    for (int i = 0; i < QTD; i++)
    {
        printf("Nome: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        // Grava no arquivo
        fprintf(fp, "Nome: %s", nome);
        fprintf(fp, "Email: %s", email);
    }

    fclose(fp);
    printf("\nDados gravados com sucesso!\n");
}

void lerClientes()
{
    FILE *fp = fopen("clientes.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    char linha[200];

    while (fgets(linha, sizeof(linha), fp) != NULL)
        printf("%s", linha);
    

    fclose(fp);
}

int main()
{
    gravarClientes();
    lerClientes();

    return 0;
}