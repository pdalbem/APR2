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
    inicializarEstoque(estoque);

    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL)
        return ARQ_NAO_ENCONTRADO;

    int quantidade;

    if (fread(&quantidade, sizeof(int), 1, arquivo) != 1 || quantidade < 0)
    {
        fclose(arquivo);
        return FALHA;
    }

    if (quantidade > 0)
    {
        Produto *dados = malloc(quantidade * sizeof(Produto));
        if (dados == NULL)
        {
            fclose(arquivo);
            return FALHA;
        }

        if (fread(dados, sizeof(Produto), quantidade, arquivo) != quantidade)
        {
            free(dados);
            fclose(arquivo);
            return FALHA;
        }

        // Tudo OK, campos da struct recebem variáveis
        estoque->dados = dados;
        estoque->quantidade = quantidade;
    }

    fclose(arquivo);
    return SUCESSO;
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

int removerProduto(Estoque *estoque, int id, Produto *produto)
{
    for (int i = 0; i < estoque->quantidade; i++)
    {
        if (estoque->dados[i].id == id)
        {
            *produto = estoque->dados[i];

            // Desloca os elementos seguintes uma posição para trás
            for (int j = i; j < estoque->quantidade - 1; j++)
                estoque->dados[j] = estoque->dados[j + 1];

            estoque->quantidade--;

            // Redimensiona o array
            if (estoque->quantidade == 0)
            {
                free(estoque->dados);
                estoque->dados = NULL;
            }
            else
            {
                Produto *temp = realloc(estoque->dados, estoque->quantidade * sizeof(Produto));
                if (temp != NULL)
                    estoque->dados = temp;
            }

            return SUCESSO;
        }
    }

    return FALHA;
}

Produto *buscarProduto(Estoque *estoque, int id)
{
    for (int i = 0; i < estoque->quantidade; i++)
        if (estoque->dados[i].id == id)
            return &estoque->dados[i]; // retornando o endereço

    return NULL;
}

int alterarPreco(Estoque *estoque, int id, float novoPreco)
{
    Produto *produto = buscarProduto(estoque, id); // reuso de função

    if (produto == NULL)
        return FALHA;

    produto->preco = novoPreco;

    return SUCESSO;
}

float calcularMediaPrecos(Estoque *estoque)
{
    if (estoque->quantidade == 0)
        return 0.0;

    float soma = 0.0;
    for (int i = 0; i < estoque->quantidade; i++)
        soma += estoque->dados[i].preco;

    return soma / estoque->quantidade;
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
    
    if (fwrite(&estoque->quantidade, sizeof(int), 1, arquivo) != 1){
        fclose(arquivo);
        return FALHA;
    }
    
    if (estoque->quantidade > 0)
        if (fwrite(estoque->dados, sizeof(Produto), estoque->quantidade, arquivo) != estoque->quantidade){
            fclose(arquivo);
            return FALHA;
        }

    if (fclose(arquivo) == EOF)
        return FALHA;

    return SUCESSO;
}

int main()
{
    Estoque estoque;
    int opcao;

    int resp = carregarEstoque(&estoque);
    if (resp == FALHA)
    {
        printf("Erro ao carregar os produtos.\n");
        return 1;
    }
    else if (resp == ARQ_NAO_ENCONTRADO)
        printf("Arquivo não encontrado. Iniciando estoque vazio.\n");
    else
        printf("Produtos carregados: %d\n", estoque.quantidade);

    do
    {
        printf("\n    MENU \n");
        printf("1 - Listar produtos\n");
        printf("2 - Adicionar produto\n");
        printf("3 - Salvar\n");
        printf("4 - Remover produto\n");
        printf("5 - Buscar produto\n");
        printf("6 - Alterar preço\n");
        printf("7 - Calcular média de preços\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n')
            ;

        switch (opcao)
        {
        case 1:
            listarProdutos(&estoque);
            break;

        case 2:
        { // abri chaves porque tenho var local aqui dentro
            Produto produto;

            printf("ID: ");
            scanf("%d", &produto.id);

            while (getchar() != '\n')
                ;

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

        case 4:
        { // abri chaves porque tenho var local aqui dentro
            int id;
            Produto produto;

            printf("ID do produto a remover: ");
            scanf("%d", &id);

            if (removerProduto(&estoque, id, &produto) == SUCESSO)
            {
                printf("\nProduto removido com sucesso.\n");
                printf("ID: %d\n", produto.id);
                printf("Nome: %s\n", produto.nome);
                printf("Preço: R$ %.2f\n", produto.preco);
            }
            else
                printf("Produto não encontrado.\n");

            break;
        }

        case 5:
        { // abri chaves porque tenho var local aqui dentro
            int id;

            printf("ID do produto: ");
            scanf("%d", &id);

            Produto *produto = buscarProduto(&estoque, id);

            if (produto != NULL)
            {
                printf("\nProduto encontrado:\n");
                printf("ID: %d\n", produto->id);
                printf("Nome: %s\n", produto->nome);
                printf("Preço: R$ %.2f\n", produto->preco);
            }
            else
                printf("Produto não encontrado.\n");

            break;
        }

        case 6:
        { // abri chaves porque tenho var local aqui dentro
            int id;
            float novoPreco;

            printf("ID do produto: ");
            scanf("%d", &id);

            printf("Novo preço: ");
            scanf("%f", &novoPreco);

            if (alterarPreco(&estoque, id, novoPreco) == SUCESSO)
                printf("Preço alterado com sucesso.\n");
            else
                printf("Produto não encontrado.\n");

            break;
        }

        case 7:
        { // abri chaves porque tenho var local aqui dentro
            float media = calcularMediaPrecos(&estoque);
            printf("Média de preços: R$ %.2f\n", media);
            break;
        }

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