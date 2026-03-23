#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[10];
    char marca[30];
    char modelo[30];
    int ano;
} Veiculo;

Veiculo lerVeiculo() {
    Veiculo v;

    printf("Digite a placa: ");
    fgets(v.placa, sizeof(v.placa), stdin);
    v.placa[strcspn(v.placa, "\n")] = '\0';

    printf("Digite a marca: ");
    fgets(v.marca, sizeof(v.marca), stdin);
    v.marca[strcspn(v.marca, "\n")] = '\0';

    printf("Digite o modelo: ");
    fgets(v.modelo, sizeof(v.modelo), stdin);
    v.modelo[strcspn(v.modelo, "\n")] = '\0';

    printf("Digite o ano de fabricacao: ");
    scanf("%d", &v.ano);
    while(getchar()!="\n");

    return v;
}

void exibirVeiculo(Veiculo v) {
    printf("\n--- Dados do Veiculo ---\n");
    printf("Placa: %s\n", v.placa);
    printf("Marca: %s\n", v.marca);
    printf("Modelo: %s\n", v.modelo);
    printf("Ano: %d\n", v.ano);
}

Veiculo atualizarVeiculo(Veiculo v) {
    printf("\nAtualizando dados do veiculo...\n");
    v = lerVeiculo();
    return v;
}

int main() {
    Veiculo v;

    printf("=== Cadastro de Veiculo ===\n");
    v = lerVeiculo();

    exibirVeiculo(v);

    printf("\nDeseja atualizar os dados? (s/n): ");
    char op;
    scanf(" %c", &op);
    while(getchar()!="\n");

    if (op == 's' || op == 'S') {
        v = atualizarVeiculo(v);
        exibirVeiculo(v);
    }

    return 0;
}