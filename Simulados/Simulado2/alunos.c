#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "alunos.dat"

#define SUCCESS 0
#define FAILURE -1
#define FILE_NOT_FOUND 2

typedef struct
{
    char prontuario[10];
    char nome[100];
    float ira;
} Aluno;

typedef struct
{
    Aluno *dados;
    int quantidade;
} Turma;

void inicializarTurma(Turma *turma);
int carregarDados(Turma *turma);
int cadastrarAluno(Turma *turma, Aluno *aluno);
void listarAlunos(Turma *turma);
void ordenarPorProntuario(Turma *turma);
void ordenarPorIRA(Turma *turma);
Aluno *buscarAluno(Turma *turma, char prontuario[]);
int removerAluno(Turma *turma, char prontuario[], Aluno *aluno);
int salvar(Turma *turma);
void liberarMemoria(Turma *turma);

void inicializarTurma(Turma *turma)
{
    turma->dados = NULL;
    turma->quantidade = 0;
}

int carregarDados(Turma *turma)
{
    FILE *fp = fopen(ARQUIVO, "rb");

    if (fp == NULL)
        return FILE_NOT_FOUND;

    fread(&turma->quantidade, sizeof(int), 1, fp);

    if (turma->quantidade > 0)
    {
        turma->dados = (Aluno *)malloc(turma->quantidade * sizeof(Aluno));

        if (turma->dados == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        fread(turma->dados, sizeof(Aluno), turma->quantidade, fp);
    }

    fclose(fp);
    return SUCCESS;
}

int cadastrarAluno(Turma *turma, Aluno *aluno)
{
    Aluno *novo = (Aluno *)realloc(turma->dados, (turma->quantidade + 1) * sizeof(Aluno));

    if (novo == NULL)
            return FAILURE;
    

    turma->dados = novo;
    turma->dados[turma->quantidade] = *aluno;
    turma->quantidade++;

    return SUCCESS;
}

void listarAlunos(Turma *turma)
{
    if (turma->quantidade == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\Lista de alunos:\n");

    for (int i = 0; i < turma->quantidade; i++)
    {
        printf("\nAluno %d\n", i + 1);
        printf("Prontuário: %s\n", turma->dados[i].prontuario);
        printf("Nome: %s\n", turma->dados[i].nome);
        printf("IRA: %.2f\n", turma->dados[i].ira);
    }
}

void trocar(Aluno *a, Aluno *b)
{
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort
void ordenarPorProntuario(Turma *turma)
{
    int trocou;
    for (int i = 0; i < turma->quantidade - 1; i++)
    {
        trocou = 0;
        for (int j = 0; j < turma->quantidade - 1 - i; j++)
        {
            if (strcmp(turma->dados[j].prontuario,turma->dados[j + 1].prontuario) > 0)
            {
                trocar(&turma->dados[j], &turma->dados[j + 1]);
                trocou = 1;
            }
        }

        if (!trocou)
            break;
    }
}

// Bubble sort
void ordenarPorIRA(Turma *turma)
{
    int trocou;
    for (int i = 0; i < turma->quantidade - 1; i++)
    {
        trocou = 0;
        for (int j = 0; j < turma->quantidade - 1 - i; j++)
        {
            if (turma->dados[j].ira > turma->dados[j + 1].ira)
            {
                trocar(&turma->dados[j], &turma->dados[j + 1]);
                trocou = 1;
            }
        }

        if (!trocou)
            break;
    }
}

Aluno *buscarAluno(Turma *turma, char prontuario[])
{
    int inicio = 0;
    int fim = turma->quantidade - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        int cmp = strcmp(
            turma->dados[meio].prontuario,
            prontuario);

        if (cmp == 0)
            return &turma->dados[meio];

        if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return NULL;
}

int removerAluno(Turma *turma, char prontuario[], Aluno *aluno)
{
    for (int i = 0; i < turma->quantidade; i++)
    {
        if (strcmp(turma->dados[i].prontuario, prontuario) == 0)
        {
            *aluno = turma->dados[i];

            for (int j = i; j < turma->quantidade - 1; j++)
                turma->dados[j] = turma->dados[j + 1];

            turma->quantidade--;

            if (turma->quantidade > 0)
            {
                Aluno *novo = (Aluno *)realloc(turma->dados, turma->quantidade * sizeof(Aluno));

                if (novo != NULL)
                    turma->dados = novo;
            }
            else
            {
                free(turma->dados);
                turma->dados = NULL;
            }

            return SUCCESS;
        }
    }

    return FAILURE;
}

int salvar(Turma *turma)
{
    FILE *fp = fopen(ARQUIVO, "wb");

    if (fp == NULL)
        return FAILURE;
   
    fwrite(&turma->quantidade, sizeof(int), 1, fp);

    fwrite(
        turma->dados,
        sizeof(Aluno),
        turma->quantidade,
        fp);

    fclose(fp);

    return SUCCESS;
}

void liberarMemoria(Turma *turma)
{
    free(turma->dados);
    turma->dados = NULL;
    turma->quantidade = 0;
}


int main()
{
    Turma turma;

    inicializarTurma(&turma);

    int resultado = carregarDados(&turma);
    if (resultado == SUCCESS)
        printf("%d aluno(s) carregado(s) do arquivo.\n", turma.quantidade);
    else if (resultado == FILE_NOT_FOUND)
        printf("Arquivo não encontrado. Iniciando turma...\n");
    else
        printf("Erro ao carregar dados.\n");

    int opcao;

    do
    {
        printf("\n MENU \n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Ordenar por IRA\n");
        printf("5 - Ordenar por prontuário\n");
        printf("6 - Remover aluno\n");
        printf("7 - Salvar\n");
        printf("8 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {

        case 1:
        {
            Aluno aluno;

            printf("Prontuário: ");
            fgets(aluno.prontuario, sizeof(aluno.prontuario), stdin);
            aluno.prontuario[strcspn(aluno.prontuario, "\n")] = '\0';

            printf("Nome: ");
            fgets(aluno.nome, 100, stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            printf("IRA: ");
            scanf("%f", &aluno.ira);

            int result = cadastrarAluno(&turma, &aluno);
            if (result == SUCCESS)
                printf("\nAluno cadastrado com sucesso!\n");
             else
               printf("\nErro ao cadastrar aluno.\n");
            
            break;
        }

        case 2:
            listarAlunos(&turma);
            break;

        case 3:
        {
            char prontuario[10];

            printf("Digite o prontuário: ");
            fgets(prontuario, sizeof(prontuario), stdin);
            prontuario[strcspn(prontuario, "\n")] = '\0';

            // Necessário para a busca binária
            ordenarPorProntuario(&turma);

            Aluno *a = buscarAluno(&turma, prontuario);

            if (a != NULL)
            {

                printf("\nAluno encontrado:\n");
                printf("Prontuário: %s\n", a->prontuario);
                printf("Nome: %s\n", a->nome);
                printf("IRA: %.2f\n", a->ira);
            }
            else
            {
                printf("Aluno não encontrado.\n");
            }

            break;
        }

        case 4:
            ordenarPorIRA(&turma);
            printf("\nAlunos ordenador por IRA\n");
            break;

        case 5:
            ordenarPorProntuario(&turma);
            printf("\nAlunos ordenador por Prontuário\n");
            break;

        case 6:
        {
            char prontuario[10];
            Aluno removido;

            printf("Digite o prontuário: ");
            fgets(prontuario, sizeof(prontuario), stdin);
            prontuario[strcspn(prontuario, "\n")] = '\0';

            if (removerAluno(&turma, prontuario, &removido) == SUCCESS)
            {
                printf("\nAluno removido:\n");
                printf("Prontuário: %s\n", removido.prontuario);
                printf("Nome: %s\n", removido.nome);
                printf("IRA: %.2f\n", removido.ira);
            }
            else
                printf("Aluno não encontrado.\n");

            break;
        }

        case 7:{
            int result = salvar(&turma);
            if (result==SUCCESS)
                  printf("\nArquivo salvo com sucesso\n");
               else
                   printf("\nErro ao salvar\n");
            break;
        }
        
        case 8:
            int result = salvar(&turma);
            if (result==SUCCESS)
                  printf("\nArquivo salvo com sucesso\n");
               else
                   printf("\nErro ao salvar\n");

            liberarMemoria(&turma);
            printf("Programa encerrado.\n");

            break;

        default:
            printf("Opção inválida.\n");
        }

    } while (opcao != 8);

    return 0;
}