#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int matricula;
    char nome[50];
    float salario;
} Funcionario;

// Lê todos os "TAM" funcionários de uma vez
void lerFuncionarios(Funcionario f[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nFuncionário %d\n", i + 1);

        printf("Matrícula: ");
        scanf("%d", &f[i].matricula);

        while (getchar() != '\n' );

        printf("Nome: ");
        fgets(f[i].nome, sizeof(f[i].nome), stdin);
        f[i].nome[strcspn(f[i].nome, "\n")] = '\0';

        printf("Salario: ");
        scanf("%f", &f[i].salario);

        while (getchar() != '\n' ); //limpo o buffer antes de voltar para a main. Lá vou ler outra sting, poderia dar problema
    }
}


void exibirFuncionarios(Funcionario f[], int n)
{
    printf("\nLista de Funcionarios:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nMatrícula: %d\n", f[i].matricula);
        printf("Nome: %s\n", f[i].nome);
        printf("Salário: %.2f\n", f[i].salario);
    }
}

void buscarPorNome(Funcionario f[], int n, char nomeBusca[])
{
    int encontrou = 0;

    for (int i = 0; i < n; i++)
       if (strcmp(f[i].nome, nomeBusca) == 0)
        {
            printf("\nFuncionario encontrado:\n");
            printf("Matricula: %d\n", f[i].matricula);
            printf("Nome: %s\n", f[i].nome);
            printf("Salario: %.2f\n", f[i].salario);
            encontrou = 1;
        }
    

    if (!encontrou)
         printf("\nNenhum funcionário encontrado com esse nome.\n");
    
}


void reajustarSalario(Funcionario f[], int n, int matricula, float percentual)
{
    for (int i = 0; i < n; i++)
       if (f[i].matricula == matricula)
        {
            f[i].salario += f[i].salario * (percentual / 100.0);
            printf("\nSalário reajustado com sucesso!\n");
            return;
        }
    

    printf("\nFuncionario nao encontrado.\n");
}


float calcularMedia(Funcionario f[], int n)
{
    float soma = 0;

    for (int i = 0; i < n; i++)
            soma += f[i].salario;
    
    return soma / n;
}

// encontra e retorna o funcionário com maior salário.
// se houver mais que um, retorna o primeiro que encontrar
Funcionario encontrarMaiorSalario(Funcionario f[], int n)
{
    Funcionario maior = f[0];

    for (int i = 1; i < n; i++)
            if (f[i].salario > maior.salario)
                 maior = f[i];
        
    
    return maior;
}

int main()
{
    Funcionario funcionarios[TAM];

    lerFuncionarios(funcionarios, TAM);
   
    exibirFuncionarios(funcionarios, TAM);

    // Busca por nome
    char nomeBusca[50];
    printf("\nDigite o nome para busca: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    buscarPorNome(funcionarios, TAM, nomeBusca);

    // Reajuste salarial
    int mat;
    float perc;

    printf("\nDigite a matricula para reajuste: ");
    scanf("%d", &mat);

    printf("Digite o percentual de reajuste: ");
    scanf("%f", &perc);

    reajustarSalario(funcionarios, TAM, mat, perc);

    exibirFuncionarios(funcionarios, TAM);

    float media = calcularMedia(funcionarios, TAM);
    printf("\nMédia salarial: %.2f\n", media);

    // Maior salário
    Funcionario maior = encontrarMaiorSalario(funcionarios, TAM);
    printf("\nFuncionário com maior salário:\n");
    printf("Matrícula: %d\n", maior.matricula);
    printf("Nome: %s\n", maior.nome);
    printf("Salário: %.2f\n", maior.salario);

    return 0;
}