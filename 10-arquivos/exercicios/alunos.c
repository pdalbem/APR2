#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int prontuario;
    char nome[50];
    float notas[3];
} Aluno;

Aluno *lerAlunos(int *n);
void gravarAlunos(const char *arquivo, Aluno *v, int n);
Aluno *lerArquivo(const char *arquivo, int *n);
float calcularMedia(Aluno a);
void mostrarAlunos(Aluno *v, int n);

int main()
{
    int n;

    Aluno *alunos = lerAlunos(&n);

    gravarAlunos("alunos.dat", alunos, n);

    free(alunos);

    alunos = lerArquivo("alunos.dat", &n);

    mostrarAlunos(alunos, n);

    free(alunos);

    return 0;
}

Aluno *lerAlunos(int *n)
{
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", n);
    getchar();

    Aluno *v = (Aluno *)malloc((*n) * sizeof(Aluno));

    if (v == NULL)
    {
        printf("Erro de alocação!\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\nAluno %d\n", i + 1);

        printf("Prontuario: ");
        scanf("%d", &v[i].prontuario);
        getchar();

        printf("Nome: ");
        fgets(v[i].nome, sizeof(v[i].nome), stdin);
        v[i].nome[strcspn(v[i].nome, "\n")] = '\0';

        for (int j = 0; j < 3; j++)
        {
            printf("Nota %d: ", j + 1);
            scanf("%f", &v[i].notas[j]);
        }
    }

    return v;
}

void gravarAlunos(const char *arquivo, Aluno *v, int n)
{
    FILE *fp = fopen(arquivo, "wb");

    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo para escrita!\n");
        return;
    }

    // outra abordagem: gravar quantidade primeiro
    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao gravar quantidade!\n");
        fclose(fp);
        return;
    }

    // grava vetor inteiro
    if (n > 0)
    {
        if (fwrite(v, sizeof(Aluno),  n,fp) != n)
        {
            printf("Erro ao gravar alunos!\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

// 🔹 Lê o arquivo inteiro para um array
Aluno *lerArquivo(const char *arquivo, int *n)
{
    FILE *fp = fopen(arquivo, "rb");

    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo para leitura!\n");
        return NULL;
    }

    // lê quantidade. Assim não preciso usar fkeek, ftell e rewind
    if (fread(n, sizeof(int), 1,  fp) != 1)
    {
        printf("Erro ao ler quantidade!\n" );
        fclose(fp);
        return NULL;
    }


    Aluno *v = (Aluno *)malloc((*n) * sizeof(Aluno));

    if (v == NULL)
    {
        printf("Erro de alocação!\n");
        exit(1);
    }

    // lê vetor inteiro
     if (fread(v, sizeof(Aluno), *n,fp) != *n)
        {
            printf("Erro ao ler alunos!\n");
            free(v);
            fclose(fp);
            return NULL;
        }

    fclose(fp);

    return v;
}

float calcularMedia(Aluno a)
{
    float soma = 0;

    for (int i = 0; i < 3; i++)
    {
        soma += a.notas[i];
    }

    return soma / 3;
}

void mostrarAlunos(Aluno *v, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\nProntuario: %d\n", v[i].prontuario);
        printf("Nome: %s\n", v[i].nome);

        printf("Notas: ");
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", v[i].notas[j]);
        }

        printf("\nMédia: %.2f\n", calcularMedia(v[i]));
    }
}