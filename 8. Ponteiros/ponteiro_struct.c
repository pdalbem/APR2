#include <stdio.h>
#include <string.h>

#define MAX_NOTAS 3

typedef struct
{
    int id;
    char nome[100];
    float notas[MAX_NOTAS];
} Aluno;

void lerDados(Aluno *a)
{
    printf("\nDigite o ID: ");
    scanf("%d", &a->id);
    while (getchar() != '\n')
        ;

    printf("Digite o nome: ");
    fgets(a->nome, sizeof(a->nome), stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0';

    for (int i = 0; i < MAX_NOTAS; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &a->notas[i]);
    }
}

void mostrarDados(Aluno *a)
{
    printf("\nId: %d", a->id);
    printf("\nNome: %s", a->nome);
    for (int i = 0; i < MAX_NOTAS; i++)
        printf("\nNota %d: %.2f", i + 1, a->notas[i]);
    printf("\n");    
}

float calcularMedia(Aluno *a){
    float soma=0;
    for (int i=0;i<MAX_NOTAS;i++)
        soma += a->notas[i];
    return soma/MAX_NOTAS;    
}

int main()
{
   Aluno a1;
   Aluno *ptr1 = &a1;
   lerDados(ptr1);
   
   mostrarDados(ptr1);
   printf("Média de notas: %.2f", calcularMedia(ptr1)); 

    return 0;
}