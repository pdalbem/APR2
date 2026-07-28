#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    float preco;
} Produto;

void salvarProduto(Produto p);
void listarProdutos();

int main()
{
    Produto p1 = {1, "Teclado Mecânico", 249.90};
    Produto p2 = {2, "Mouse Gamer", 99.90};

    salvarProduto(p1);
    salvarProduto(p2);

    listarProdutos();

    return 0;
}

void salvarProduto(Produto p)
{
    FILE *arq = fopen("produtos.txt", "a");
    if (arq == NULL)
        exit(1);

    fprintf(arq, "%d;%s;%.2f\n", p.id, p.nome, p.preco);

    fclose(arq);
}

void listarProdutos()
{
    FILE *arq = fopen("produtos.txt", "r");

    if (arq == NULL)
    {
        printf("Arquivo nao encontrado\n");
        return;
    }

    int id;
    char nome[50];
    float preco;

    while (fscanf(arq, "%d;%[^;];%f\n", &id, nome, &preco) == 3)
    {
        printf("Id: %d\n", id);
        printf("Nome: %s\n", nome);
        printf("Preço: R$ %.2f\n", preco);
        printf("----------------------\n");
    }

    fclose(arq);
}

// Outra forma de ler, caso quisesse mostrar a linha sem formatação
// void listarProdutos() {
//     FILE *arq = fopen("produtos.txt", "r");

//     if (arq == NULL) 
//         exit(1);
    
//     char linha[100];
//     while (fgets(linha, sizeof(linha), arq)) {
//         linha[strcspn(linha, "\n")] = '\0';
//         printf("%s\n", linha);
//     }

//     fclose(arq);
// }
