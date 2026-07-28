#include <stdio.h>
#include <math.h>

/*
Este código utiliza a função pow(base,expoente) da biblioteca <math.h>
Para compilá-lo, é preciso utilizar -lm
Faça isso no terminal para compilar: gcc imc_versao2.c -o imc_versao2 -lm 
Faça isso no terminal para executar: ./imc_versao2   
*/

int main() {
    float peso, altura, imc;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    imc = peso / pow(altura,2);

    printf("O IMC da pessoa eh: %.2f\n", imc);

    return 0;
}
