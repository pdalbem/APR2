#include <stdio.h>

int main() {
    int nota;

    printf("Digite a nota (0 a 10): ");
    scanf("%d", &nota);

    switch (nota) {
        case 10:
        case 9:
            printf("Conceito A\n");
            break;
        case 8:
        case 7:
            printf("Conceito B\n");
            break;
        case 6:
            printf("Conceito C\n");
            break;
        default:
            printf("Conceito insuficiente\n");
    }

    return 0;
}
