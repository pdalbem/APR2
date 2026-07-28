#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("\nIMC = %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificacao: Abaixo do peso\n");
    } 
    else if (imc < 25.0) {
        printf("Classificacao: Peso normal\n");
    } 
    else if (imc < 30.0) {
        printf("Classificacao: Sobrepeso\n");
    } 
    else if (imc < 35.0) {
        printf("Classificacao: Obesidade grau I\n");
    } 
    else if (imc < 40.0) {
        printf("Classificacao: Obesidade grau II\n");
    } 
    else {
        printf("Classificacao: Obesidade grau III\n");
    }

    return 0;
}
