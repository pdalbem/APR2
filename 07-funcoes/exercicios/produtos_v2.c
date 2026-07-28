#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// versão 2 do exercício.
// Agora, lê apenas 1 produto e o retorna
Produto lerProduto() {
    Produto p;

    printf("\nProduto\n");

    printf("Nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Preco: ");
    scanf("%f", &p.preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade);
    while (getchar() != '\n');

    return p;
}

void exibirProdutos(Produto p[], int n) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Nome: %s\n", p[i].nome);
        printf("Preco: %.2f\n", p[i].preco);
        printf("Quantidade: %d\n", p[i].quantidade);
    }
}

Produto atualizarEstoque(Produto p, int novoEstoque) {
    p.quantidade = novoEstoque;
    return p;
}

void reajustarPrecos(Produto p[], int n, float percentual) {
    for (int i = 0; i < n; i++) {
        p[i].preco += p[i].preco * (percentual / 100.0);
    }
}

int main() {
    Produto produtos[TAM];
    int opcao;

    // estrutura de repetição para chamar a função TAM vezes
    for (int i = 0; i < TAM; i++) {
        printf("\nProduto %d\n", i + 1);
        produtos[i] = lerProduto();
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Exibir produtos\n");
        printf("2 - Atualizar estoque\n");
        printf("3 - Reajustar precos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        switch (opcao) {
            case 1:
                exibirProdutos(produtos, TAM);
                break;

            case 2: {
                int indice, novaQtd;

                printf("Digite o numero do produto (1 a %d): ", TAM);
                scanf("%d", &indice);

                if (indice >= 1 && indice <= TAM) {
                    printf("Digite a nova quantidade: ");
                    scanf("%d", &novaQtd);

                    produtos[indice - 1] = atualizarEstoque(produtos[indice - 1], novaQtd);
                } else {
                    printf("Produto invalido!\n");
                }

                break;
            }

            case 3: {
                float percentual;
                printf("Digite o percentual de reajuste: ");
                scanf("%f", &percentual);

                reajustarPrecos(produtos, TAM, percentual);
                printf("Precos atualizados!\n");
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}