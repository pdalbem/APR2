#include <stdio.h>
#include <string.h>

#define MAX_VEICULOS 100
#define TAM_PLACA 8
#define TAM_MARCA 50

typedef struct {
    char placa[TAM_PLACA];
    char marca[TAM_MARCA];
    float valorDiaria;
    int disponivel;   // 1 = disponível, 0 = indisponível
} Veiculo;


int cadastrarVeiculo(Veiculo veiculos[], int quantidade);
void exibirVeiculos(Veiculo veiculos[], int quantidade);
int buscarVeiculo(Veiculo veiculos[], int quantidade, char placa[]);
void alugarVeiculo(Veiculo veiculos[], int quantidade, char placa[]);
void devolverVeiculo(Veiculo veiculos[], int quantidade, char placa[]);
int removerVeiculo(Veiculo veiculos[], int quantidade, char placa[]);


int main() {
    Veiculo veiculos[MAX_VEICULOS];
    int quantidade = 0;
    int opcao;
    char placa[TAM_PLACA];

    do {
        printf("\nMENU - LOCADORA DE VEICULOS \n");
        printf("1 - Cadastrar veiculo\n");
        printf("2 - Exibir veiculos\n");
        printf("3 - Buscar veiculo\n");
        printf("4 - Alugar veiculo\n");
        printf("5 - Devolver veiculo\n");
        printf("6 - Remover veiculo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                quantidade = cadastrarVeiculo(veiculos, quantidade);
                break;

            case 2:
                exibirVeiculos(veiculos, quantidade);
                break;

            case 3:
                printf("Digite a placa: ");
                scanf("%s", placa);
                int pos = buscarVeiculo(veiculos, quantidade, placa);
                if (pos != -1)
                    printf("\nVeículo encontrado na posição: %d", pos);
                else
                    printf("\nVeículo não encontrado");
                break;

            case 4:
                printf("Digite a placa do veiculo: ");
                scanf("%s", placa);
                alugarVeiculo(veiculos, quantidade, placa);
                break;

            case 5:
                printf("Digite a placa do veiculo: ");
                scanf("%s", placa);
                devolverVeiculo(veiculos, quantidade, placa);
                break;

            case 6:
                printf("Digite a placa do veiculo: ");
                scanf("%s", placa);
                quantidade = removerVeiculo(veiculos, quantidade, placa);
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opçãoo inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}


int cadastrarVeiculo(Veiculo veiculos[], int quantidade) {
    if (quantidade >= MAX_VEICULOS) {
        printf("Nao e possivel cadastrar mais veiculos.\n");
        return quantidade;
    }

    Veiculo novo;

    printf("\nPlaca: ");
    scanf("%s", novo.placa);

    printf("Marca: ");
    scanf("%s", novo.marca);

    printf("Valor da diaria: ");
    scanf("%f", &novo.valorDiaria);

    novo.disponivel = 1;

    // Encontra a posição de inserção
    int posicao = 0;
    while (posicao < quantidade && strcmp(veiculos[posicao].placa, novo.placa) < 0) 
        posicao++;
    

    // Desloca os elementos para a direita
    for (int i = quantidade; i > posicao; i--) 
        veiculos[i] = veiculos[i - 1];
    
    // Insere o novo veículo
    veiculos[posicao] = novo;
    return quantidade + 1;
}


void exibirVeiculos(Veiculo veiculos[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhum veículo cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nPlaca: %s\n", veiculos[i].placa);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Valor da diária: R$ %.2f\n", veiculos[i].valorDiaria);

        if (veiculos[i].disponivel) 
            printf("Disponibilidade: Disponível\n");
         else 
            printf("Disponibilidade: Alugado\n");
        
    }
}


int buscarVeiculo(Veiculo veiculos[], int quantidade, char placa[]) {
    for (int i = 0; i < quantidade; i++) 
        if (strcmp(veiculos[i].placa, placa) == 0) 
            return i;
  
    return -1;
}

void alugarVeiculo(Veiculo veiculos[], int quantidade, char placa[]) {
    int posicao = buscarVeiculo(veiculos, quantidade, placa);

    if (posicao == -1) {
        printf("Veículo não encontrado.\n");
        return;
    }

    if (!veiculos[posicao].disponivel) {
        printf("O veiculo já está alugado.\n");
        return;
    }

    veiculos[posicao].disponivel = 0;
    printf("Veículo alugado com sucesso.\n");
}


void devolverVeiculo(Veiculo veiculos[], int quantidade, char placa[]) {
    int posicao = buscarVeiculo(veiculos, quantidade, placa);

    if (posicao == -1) {
        printf("Veículo não encontrado.\n");
        return;
    }

    if (veiculos[posicao].disponivel) {
        printf("O veículo já está disponível.\n");
        return;
    }

    veiculos[posicao].disponivel = 1;

    printf("Veículo devolvido com sucesso.\n");
}


int removerVeiculo(Veiculo veiculos[], int quantidade, char placa[]) {
    int posicao = buscarVeiculo(veiculos, quantidade, placa);

    if (posicao == -1) {
        printf("Veículo não encontrado.\n");
        return quantidade;
    }

    if (!veiculos[posicao].disponivel) {
        printf("Veículo alugado não pode ser removido.\n");
        return quantidade;
    }

    // Desloca os elementos para a esquerda, se necessário
    for (int i = posicao; i < quantidade - 1; i++) 
        veiculos[i] = veiculos[i + 1];
    

    printf("Veículo removido com sucesso.\n");

    return quantidade - 1;
}