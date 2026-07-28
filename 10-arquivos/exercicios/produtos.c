#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;


void salvarProduto(Produto p);
void listarProdutos();
float calcularMediaPrecos();
int buscarProdutoPorId(int id, Produto *resultado);

int main() {
    Produto p1 = {1, "Teclado Mecânico", 249.90};
    Produto p2 = {2, "Mouse Gamer", 99.90};

    salvarProduto(p1);
    salvarProduto(p2);

    listarProdutos();

    float media = calcularMediaPrecos();
    printf("\nMédia dos preços: %.2f\n", media);

    int idBusca = 2;
    Produto encontrado;

    if (buscarProdutoPorId(idBusca, &encontrado)) {
        printf("\nProduto encontrado:\n");
        printf("ID: %d\nNome: %s\nPreço: %.2f\n",
               encontrado.id, encontrado.nome, encontrado.preco);
    } else 
        printf("\nProduto com ID %d não encontrado.\n", idBusca);
    

    return 0;
}


void salvarProduto(Produto p) {
    FILE *arq = fopen("produtos.txt", "a");

    if (arq == NULL)
        return;

    fprintf(arq, "%d;%s;%.2f\n", p.id, p.nome, p.preco);

    fclose(arq);
}

void listarProdutos() {
    FILE *arq = fopen("produtos.txt", "r");

    if (arq == NULL)
        return;

    char linha[100];

    while (fgets(linha, sizeof(linha), arq)) {
        linha[strcspn(linha, "\n")] = '\0';
        printf("%s\n", linha);
    }

    fclose(arq);
}

float calcularMediaPrecos() {
    FILE *arq = fopen("produtos.txt", "r");

    if (arq == NULL)
        return 0;

    int id;
    char nome[50];
    float preco;

    float soma = 0;
    int qtd = 0;

    while (fscanf(arq, "%d;%49[^;];%f\n", &id, nome, &preco) == 3) {
        soma += preco;
        qtd++;
    }

    fclose(arq);

    if (qtd == 0)
        return 0;

    return soma / qtd;
}

int buscarProdutoPorId(int idBusca, Produto *resultado) {
    FILE *arq = fopen("produtos.txt", "r");

    if (arq == NULL)
        return 0;

    Produto temp;

    while (fscanf(arq, "%d;%49[^;];%f\n", &temp.id, temp.nome, &temp.preco) == 3) {
        if (temp.id == idBusca) {
            *resultado = temp;
            fclose(arq);
            return 1; // encontrado
        }
    }

    fclose(arq);
    return 0; // não encontrado
}