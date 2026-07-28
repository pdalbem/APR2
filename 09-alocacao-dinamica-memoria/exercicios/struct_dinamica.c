#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char *nome;
    float preco;
} Produto;

Produto *criar_produto(int id, char *nome, float preco)
{
    Produto *p = malloc(sizeof(Produto));
    if (p == NULL)
        return NULL;

    p->nome = malloc(strlen(nome) + 1);
    if (p->nome == NULL)
    {
        free(p);
        return NULL;
    }

    strcpy(p->nome, nome);
    p->id = id;
    p->preco = preco;

    return p;
}

int alterar_nome(Produto *p, char *novoNome)
{
    if (p == NULL || novoNome == NULL)
        return 0;

    char *temp = realloc(p->nome, strlen(novoNome) + 1);
    if (temp == NULL)
        return 0; // falha, mantém nome antigo

    p->nome = temp;
    strcpy(p->nome, novoNome);

    return 1;
}

void liberar_produto(Produto *p)
{
    if (p != NULL)
    {
        free(p->nome);
        free(p);
    }
}

void exibir_produto(Produto *p)
{
    if (p != NULL)
    {
        printf("\nID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("Preco: %.2f\n", p->preco);
    }
}

int main()
{
    int id;
    char nome[100];
    float preco;

    printf("Digite o id: ");
    scanf("%d", &id);

    getchar(); // consome o '\n' deixado pelo scanf

    printf("Digite o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o preco: ");
    scanf("%f", &preco);

    Produto *meu_produto = criar_produto(id, nome, preco);

    if (meu_produto == NULL)
    {
        printf("Erro ao criar produto\n");
        return 1;
    }

    exibir_produto(meu_produto);

    char novoNome[100];

    printf("Digite o novo nome: ");
    getchar();
    fgets(novoNome, sizeof(novoNome), stdin);
    novoNome[strcspn(novoNome, "\n")] = '\0';

    if (!alterar_nome(meu_produto, novoNome))
        printf("Erro ao alterar nome\n");
        
    exibir_produto(meu_produto);

    return 0;
}