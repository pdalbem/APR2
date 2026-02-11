#include <stdio.h>

int main()
{
    float base, altura, area;

    printf("Digite a base: ");
    scanf("%f", &base);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    area = base * altura;
    printf("Área do retângulo: %.2f \n", area);

    return 0;
}