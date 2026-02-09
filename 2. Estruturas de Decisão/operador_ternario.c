#include <stdio.h>

int main()
{
    float nota;
    printf("Difite a nota do aluno: ");
    scanf("%f", &nota);

    (nota>=6) ?  printf("Aprovado \n") : printf("Reprovado \n");  

    // OU
    // printf("%s \n", nota>=6 ? "Aprovado" : "Reprovado");

    return 0;
}

