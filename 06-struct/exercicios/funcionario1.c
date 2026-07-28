#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char nome[50];
    char uf[3];
} Cidade;

typedef struct
{
    char rua[50];
    int numero;
    Cidade cidade;
} Endereco;

typedef struct
{
    char nome[50];
    Data data_admissao;
    Endereco endereco;
} Funcionario;

// Criei variáveis separadas para as structs Data, Cidade e Endereco
// Após a leitura, só faço a atribuição para os campos de Endereco (cidade) 
// e de Funcionario (data_admissao e endereco)
int main()
{
    Data data;
    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    printf("Digite o mÊs: ");
    scanf("%d", &data.mes);

    printf("Digite o ano:");
    scanf("%d", &data.ano);

    while (getchar() != "\n")
        ;

    Cidade cidade;
    printf("Digite o nome da cidade: ");
    fgets(cidade.nome, sizeof(cidade.nome), stdin);
    cidade.nome[strcspn(cidade.nome, "\n")] = '\0';

    printf("Digite a UF: ");
    fgets(cidade.uf, sizeof(cidade.uf), stdin);
    cidade.uf[strcspn(cidade.uf, "\n")] = '\0';

    Endereco endereco;
    printf("Digite a rua: ");
    fgets(endereco.rua, sizeof(endereco.rua), stdin);
    endereco.rua[strcspn(endereco.rua, "\n")] = '\0';

    printf("Digite o número: ");
    scanf("%d", &endereco.numero);

    endereco.cidade = cidade; //faço atribuição da variável cidade para endereco.cidade 

    while (getchar() != "\n")
        ;

    Funcionario funcionario;
    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

    funcionario.data_admissao = data; //atribuição da variável data para funcionario.data_admissao
    funcionario.endereco = endereco; //atribuição da variável endereco para funcionario.endereco

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