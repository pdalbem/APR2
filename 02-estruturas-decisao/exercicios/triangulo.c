#include <stdio.h>

int main() {
    int a, b, c;

    printf("Digite as medidas dos tres lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);

      if (a + b > c && a + c > b && b + c > a) {
    
        if (a == b && b == c) {
            printf("Triangulo Equilatero\n");
        } else if (a == b || a == c || b == c) {
            printf("Triangulo Isosceles\n");
        } else {
            printf("Triangulo Escaleno\n");
        }

    } else {
        printf("Os valores informados nao formam um triangulo.\n");
    }

    return 0;
}
