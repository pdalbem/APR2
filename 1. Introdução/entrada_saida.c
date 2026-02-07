#include <stdio.h>

int main() {
    int a;
    float b;
    double c;
    char d; 

    printf("Digite valor para variável a: ");
    scanf("%d", &a);

    printf("Digite valor para variável b: ");
    scanf("%f", &b);

    printf("Digite valor para variável c: ");
    scanf("%lf", &c);

    printf("Digite valor para variável d: ");
    scanf(" %c", &d);


    printf("Variável a: %d\n", a);
    printf("Variável b: %.2f\n", b);
    printf("Variável c: %f\n", c);
    printf("Variável d: %c\n", d);

    return 0;
}
