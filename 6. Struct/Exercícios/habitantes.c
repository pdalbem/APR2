#include <stdio.h>
#include <ctype.h>

#define QTD_HAB 5

typedef struct {
    float salario;
    char sexo;
    int idade;
    int numFilhos;
} Habitante;

int main() {

    Habitante hab[QTD_HAB];

    float somaSalarios = 0;
    float somaFilhos = 0;
    float maiorSalario, menorSalario;

    int qtdMulheres = 0;
    int qtdMulheresSalarioAcima2000 = 0;

    for(int i = 0; i < QTD_HAB; i++) {
        printf("\nHabitante %d\n", i+1);

        printf("Salário: ");
        scanf("%f", &hab[i].salario);

        printf("Sexo (M/F): ");
        scanf(" %c", &hab[i].sexo);

        printf("Idade: ");
        scanf("%d", &hab[i].idade);

        printf("Numero de filhos: ");
        scanf("%d", &hab[i].numFilhos);

        somaSalarios += hab[i].salario;
        somaFilhos += hab[i].numFilhos;

        if(i == 0){
            maiorSalario = hab[i].salario;
            menorSalario = hab[i].salario;
        }

        if(hab[i].salario > maiorSalario)
            maiorSalario = hab[i].salario;

        if(hab[i].salario < menorSalario)
            menorSalario = hab[i].salario;

        if(tolower(hab[i].sexo) == 'f') {
            qtdMulheres++;

            if(hab[i].salario > 2000)
                qtdMulheresSalarioAcima2000++;
        }
    }

    float mediaSalarios = somaSalarios / QTD_HAB;
    float mediaFilhos = somaFilhos / QTD_HAB;

    float percentualMulheres = 0;

    if(qtdMulheres > 0)
        percentualMulheres = (qtdMulheresSalarioAcima2000 * 100.0) / qtdMulheres;


    printf("Média de salários: %.2f\n", mediaSalarios);
    printf("Média de filhos: %.2f\n", mediaFilhos);

    printf("Maior salário: %.2f\n", maiorSalario);
    printf("Menor salário: %.2f\n", menorSalario);

    printf("Percentual de mulheres com salario > 2000: %.2f%%\n", percentualMulheres);

    return 0;
}