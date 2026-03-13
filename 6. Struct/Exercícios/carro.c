#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[10];
    char marca[30];
    char modelo[30];
    int anoFabricacao;
} Carro;

int main() {

    Carro c;

    printf("Digite a placa: ");
    fgets(c.placa, sizeof(c.placa), stdin);
    c.placa[strcspn(c.placa, "\n")] = '\0';

    printf("Digite a marca: ");
    fgets(c.marca, sizeof(c.marca), stdin);
    c.marca[strcspn(c.marca, "\n")] = '\0';

    printf("Digite o modelo: ");
    fgets(c.modelo, sizeof(c.modelo), stdin);
    c.modelo[strcspn(c.modelo, "\n")] = '\0';

    printf("Digite o ano de fabricacao: ");
    scanf("%d", &c.anoFabricacao);

    printf("\nDados do carro:\n");
    printf("Placa: %s\n", c.placa);
    printf("Marca: %s\n", c.marca);
    printf("Modelo: %s\n", c.modelo);
    printf("Ano de fabricacao: %d\n", c.anoFabricacao);

    return 0;
}