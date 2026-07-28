#include <stdio.h>

int main()
{
    float fahrenheit, celsius;
    printf("Digite a temperatura em F: ");
    scanf("%f",&fahrenheit);

    celsius = (fahrenheit-32)*5/9;

    printf("Temperatura em Celsius: %.2f \n", celsius);

    return 0;
}