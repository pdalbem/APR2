#include <stdio.h>
#include <math.h>

#define TAM 10

void lerVetor(float v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &v[i]);
    }
}

void exibirVetor(float v[], int n) {
    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");
}

float calcularMedia(float v[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

float calcularVariancia(float v[], int n, float media) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += pow(v[i] - media, 2);
    }
    return soma / n;
}

float calcularDesvioPadrao(float variancia) {
    return sqrt(variancia);
}

void atualizarAbaixoMedia(float v[], int n, float media, float percentual) {
    for (int i = 0; i < n; i++) {
        if (v[i] < media) {
            v[i] += v[i] * (percentual / 100.0);
        }
    }
}

int main() {
    float vetor[TAM];
    float media, variancia, desvio, percentual;

    lerVetor(vetor, TAM);

    exibirVetor(vetor, TAM);

    media = calcularMedia(vetor, TAM);
    printf("Media: %.2f\n", media);

    variancia = calcularVariancia(vetor, TAM, media);
    printf("Variancia: %.2f\n", variancia);

    desvio = calcularDesvioPadrao(variancia);
    printf("Desvio padrao: %.2f\n", desvio);

    printf("Digite o percentual de aumento: ");
    scanf("%f", &percentual);

    atualizarAbaixoMedia(vetor, TAM, media, percentual);

    printf("Vetor atualizado:\n");
    exibirVetor(vetor, TAM);

    return 0;
}