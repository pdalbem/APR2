#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA 0
#define ARQ_NAO_ENCONTRADO -1

#define ARQUIVO "produtos.bin"

typedef struct
{
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct
{
    Produto *dados;
    int quantidade;
} Estoque;

void inicializarEstoque(Estoque *estoque)
{
    estoque->dados = NULL;
    estoque->quantidade = 0;
}

void liberarEstoque(Estoque *estoque)
{
    free(estoque->dados);
    estoque->dados = NULL;
    estoque->quantidade = 0;
}

int carregarEstoque(Estoque *estoque)
{
    FILE *arquivo = fopen(ARQUIVO, "rb");

    inicializarEstoque(estoque);

    if (arquivo == NULL)
        return ARQ_NAO_ENCONTRADO;

    int resultado = SUCESSO;

    if (fread(&estoque->quantidade, sizeof(int), 1, arquivo) != 1)
        resultado = FALHA;

    if (estoque->quantidade > 0)
    {
        estoque->dados = (Produto *)malloc(estoque->quantidade * sizeof(Produto));

        if (estoque->dados == NULL)
            resultado = FALHA;

        if (fread(estoque->dados, sizeof(Produto), estoque->quantidade, arquivo) != estoque->quantidade)
        {
            liberarEstoque(estoque);
            resultado = FALHA;
        }
    }

    if (fclose(arquivo) == EOF)
        resultado = FALHA;

    return resultado;
}

int adicionarProduto(Estoque *estoque, Produto *produto)
{
    Produto *temp = realloc(estoque->dados, (estoque->quantidade + 1) * sizeof(Produto));

    if (temp == NULL)
        return FALHA;

    estoque->dados = temp;
    estoque->dados[estoque->quantidade] = *produto;
    estoque->quantidade++;

    return SUCESSO;
}

void listarProdutos(Estoque *estoque)
{
    if (estoque->quantidade == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n%-6s %-30s %10s\n", "ID", "Nome", "Preco");
    printf("------------------------------------------------\n");

    for (int i = 0; i < estoque->quantidade; i++)
    {
        printf("%-6d %-30s R$ %8.2f\n",
               estoque->dados[i].id,
               estoque->dados[i].nome,
               estoque->dados[i].preco);
    }
}

int salvarEstoque(Estoque *estoque)
{
    FILE *arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL)
        return FALHA;

    int resultado = SUCESSO;
    if (fwrite(&estoque->quantidade, sizeof(int), 1, arquivo) != 1)
        resultado = FALHA;

    if (estoque->quantidade > 0)
        if (fwrite(estoque->dados, sizeof(Produto), estoque->quantidade, arquivo) != estoque->quantidade)
            resultado = FALHA;

    if (fclose(arquivo) == EOF)
        resultado = FALHA;

    return resultado;
}

int main()
{
    Estoque estoque;
    int opcao;

    int resp = carregarEstoque(&estoque);
    if (resp == FALHA){
        printf("Erro ao carregar os produtos.\n");
        return 1;
    }
    else if (resp == ARQ_NAO_ENCONTRADO)
        printf("Arquivo não encontrado. Iniciando estoque vazio\n");
    else
        printf("Produtos carregados: %d\n", estoque.quantidade);

    do
    {
        printf("\n    MENU \n");
        printf("1 - Listar produtos\n");
        printf("2 - Adicionar produto\n");
        printf("3 - Salvar\n");
        printf("0 - Sair\n");
        printf("Opçãoo: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
        case 1:
            listarProdutos(&estoque);
            break;

        case 2:
        { //abri chaves porque tenho var local aqui dentro
            Produto produto;
            printf("ID: ");
            scanf("%d", &produto.id);

            while (getchar() != '\n');

            printf("Nome: ");
            fgets(produto.nome, sizeof(produto.nome), stdin);
            produto.nome[strcspn(produto.nome, "\n")] = '\0';

            printf("Preço: ");
            scanf("%f", &produto.preco);

            if (adicionarProduto(&estoque, &produto) == SUCESSO)
                printf("Produto adicionado com sucesso.\n");
            else
                printf("Erro ao adicionar produto.\n");

            break;
        }
        case 3:
            if (salvarEstoque(&estoque) == SUCESSO)
                printf("Produtos salvos com sucesso.\n");
            else
                printf("Erro ao salvar os produtos.\n");

            break;

        case 0:
            printf("Saindo sem salvar as alterações.\n");
            break;

        default:
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    liberarEstoque(&estoque);

    return 0;
}