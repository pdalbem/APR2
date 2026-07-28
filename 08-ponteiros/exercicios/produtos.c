#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    float preco;
} Produto;

void lerProduto(Produto *p)
{
    printf("ID: ");
    scanf("%d", &p->id);
    while (getchar() != '\n')
        ;

    printf("Nome: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Preço: ");
    scanf("%f", &p->preco);
}


void atualizarPreco(Produto *p, float porcentagem)
{
    p->preco = p->preco + (p->preco * porcentagem / 100.0);
}


int obterMaisCaro(Produto *p1, Produto *p2)
{
    if (p1->preco > p2->preco)
        return 1;
    else if (p2->preco > p1->preco)
        return 2;
    else
        return 0;
}

int main()
{
    Produto p1, p2;
    Produto *ptr1 = &p1;
    Produto *ptr2 = &p2;

    float porcentagem;

    printf("Produto 1\n");
    lerProduto(ptr1);

    printf("\nProduto 2\n");
    lerProduto(ptr2);

    printf("\nDigite a porcentagem de reajuste para o Produto 1: ");
    scanf("%f", &porcentagem);
    atualizarPreco(ptr1, porcentagem);

    printf("\nDigite a porcentagem de reajuste para o Produto 2: ");
    scanf("%f", &porcentagem);
    atualizarPreco(ptr2, porcentagem);

    int resultado = obterMaisCaro(ptr1, ptr2);

    printf("\n=== Resultado ===\n");
    if (resultado == 1)
        printf("Produto 1 é mais caro.\n");
    else if (resultado == 2)
        printf("Produto 2 é mais caro.\n");
    else
        printf("Os dois produtos têm o mesmo preço.\n");

    return 0;
}