//versão simples, não otimizada

#include <stdio.h>

#define MAX_SIZE 1000

void inicializarVetor(int v[], int n) {
    for (int i = 0; i <= n; i++) 
        v[i] = i;

    v[0] = 0;
    v[1] = 0;
}


void crivo(int v[], int n) {
    for (int i = 2; i * i <= n; i++) 
        if (v[i] != 0) 
            for (int j = i * i; j <= n; j += i) // equivalente a for (int i = 2; i <= sqrt(n); i++) 
                v[j] = 0;         
}


void exibirPrimos(int v[], int n) {
    printf("Numeros primos entre 2 e %d:\n", n);
    for (int i = 2; i <= n; i++) 
        if (v[i] != 0) 
            printf("%d ", v[i]);
            
    printf("\n");
}

int main() {
    int N;
    int v[MAX_SIZE];

    printf("Digite o valor de N (max %d): ", MAX_SIZE-1);
    scanf("%d", &N);

    if (N < 2) {
        printf("Nao existem numeros primos nesse intervalo.\n");
        return 0;
    }

    if (N > MAX_SIZE) {
        printf("Valor excede o limite permitido.\n");
        return 0;
    }

    inicializarVetor(v, N);
    crivo(v, N);
    exibirPrimos(v, N);

    return 0;
}