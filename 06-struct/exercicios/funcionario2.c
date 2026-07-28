#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    char uf[3];
} Cidade;

typedef struct {
    char rua[50];
    int numero;
    Cidade cidade;
} Endereco;

typedef struct {
    char nome[50];
    Data data_admissao;
    Endereco endereco;
} Funcionario;

// Neste código, não utilizo variáveis separadas.
// Leitura é feita diretamente nos campos de Funcionario
int main() {
    Funcionario funcionario;

    printf("Nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

    printf("Data de admissão\n");
    printf("Dia: ");
    scanf("%d", &funcionario.data_admissao.dia);

    printf("Mês: ");
    scanf("%d", &funcionario.data_admissao.mes);

    printf("Ano: ");
    scanf("%d", &funcionario.data_admissao.ano);

    while (getchar()!='\n');

    printf("Endereço\n");
    printf("Rua: ");
    fgets(funcionario.endereco.rua, sizeof(funcionario.endereco.rua), stdin);
    funcionario.endereco.rua[strcspn(funcionario.endereco.rua, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &funcionario.endereco.numero);
    while (getchar()!='\n');

    printf("Cidade: ");
    fgets(funcionario.endereco.cidade.nome, sizeof(funcionario.endereco.cidade.nome), stdin);
    funcionario.endereco.cidade.nome[strcspn(funcionario.endereco.cidade.nome, "\n")] = '\0';

    printf("UF: ");
    fgets(funcionario.endereco.cidade.uf, sizeof(funcionario.endereco.cidade.uf), stdin);
    funcionario.endereco.cidade.uf[strcspn(funcionario.endereco.cidade.uf, "\n")] = '\0';

    printf("\nDados do Funcionário\n");

    printf("Nome: %s\n", funcionario.nome);

    printf("Data de admissao: %d/%d/%d\n",
           funcionario.data_admissao.dia,
           funcionario.data_admissao.mes,
           funcionario.data_admissao.ano);

    printf("Endereço: %s, %d\n",
           funcionario.endereco.rua,
           funcionario.endereco.numero);

    printf("Cidade: %s - %s\n",
           funcionario.endereco.cidade.nome,
           funcionario.endereco.cidade.uf);

    return 0;
}