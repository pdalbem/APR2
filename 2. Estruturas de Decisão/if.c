#include <stdio.h>

int main()
{
    float nota;
    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);

    if (nota >= 6)
        printf("Aprovado \n");

    return 0;
}

