#include <stdio.h>

float fahrenheitParaCelsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}

int main() {
    float f, c;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &f);

    c = fahrenheitParaCelsius(f);

    printf("Temperatura em Celsius: %.2f\n", c);

    return 0;
}