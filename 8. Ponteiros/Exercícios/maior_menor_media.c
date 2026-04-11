#include <stdio.h>

float estatisticas(int v[], int n, int *maior, int *menor) {
    int soma = 0;

    *maior = v[0];
    *menor = v[0];

    for (int i = 0; i < n; i++) {
        soma += v[i];

        if (v[i] > *maior)
            *maior = v[i];

        if (v[i] < *menor)
            *menor = v[i];
    }

    return (float)soma / n;
}


int main() {
    int v[] = {10, 5, 8, 20, 3};
    int n = 5;

    int maior, menor;
    float media;

    media = estatisticas(v, n, &maior, &menor);

    printf("Media: %.2f\n", media);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}
