#include <stdio.h>


float calcularMedia(int v[], int n) {
    if (n <= 0) return 0;

    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }

    return (float)soma / n;
}


int calcularMaior(int v[], int n) {
    if (n <= 0) return 0;

    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior)
            maior = v[i];
    }

    return maior;
}


int calcularMenor(int v[], int n) {
    if (n <= 0) return 0;

    int menor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < menor)
            menor = v[i];
    }

    return menor;
}


float estatisticas(int v[], int n, int *maior, int *menor) {
    *maior = calcularMaior(v, n);
    *menor = calcularMenor(v, n);
    return calcularMedia(v, n);
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
