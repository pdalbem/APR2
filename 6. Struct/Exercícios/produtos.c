#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

#define QTD_PRODUTOS 5

int main() {

    Produto produtos[QTD_PRODUTOS];
    float somaPrecos = 0.0, media;

    // leitura dos dados
    for(int i = 0; i < QTD_PRODUTOS; i++) {

        printf("\nProduto %d\n", i+1);

        printf("Nome: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Preço: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);

        while(getchar()!= '\n'); // remove o \n deixado pelo scanf

        somaPrecos += produtos[i].preco;
    }


    media = somaPrecos / QTD_PRODUTOS;

    printf("\n Capital financeiro em estoque \n");

    for(int i = 0; i < QTD_PRODUTOS; i++) {
        float capital = produtos[i].preco * produtos[i].quantidade;
        printf("%s: R$ %.2f\n", produtos[i].nome, capital);
    }

    printf("\nMédia dos precos: %.2f\n", media);

    printf("\n Produtos com preço acima da média \n");

    for(int i = 0; i < QTD_PRODUTOS; i++) 
        if(produtos[i].preco > media) {
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n\n", produtos[i].quantidade);
        }
    

    return 0;
}