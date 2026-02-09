#include <stdio.h>

int main()
{
    float nota;
    printf("Difite a nota do aluno: ");
    scanf("%f", &nota);

    if (nota >= 6)
        printf("Aprovado \n");
    else if (nota>= 4)
            printf("Recuperação \n");
        else 
            printf("Reprovado \n");
    
    return 0;
}
