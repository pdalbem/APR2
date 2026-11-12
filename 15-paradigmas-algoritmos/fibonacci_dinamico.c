long long fibonacciDinamico(int n) {
    if (n <= 1) return n;

    long long *tabela = (long long *)malloc((n + 1) * sizeof(long long));
    tabela[0] = 0;
    tabela[1] = 1;

    for (int i = 2; i <= n; i++) {
        tabela[i] = tabela[i - 1] + tabela[i - 2]; // Subestrutura ótima
    }

    long long resultado = tabela[n];
    free(tabela); 
    return resultado;
}

int main() {
    int n = 50; 
    printf("Programação Dinâmica: O %dº termo de Fibonacci é %lld.\n", n, fibonacciDinamico(n));
    return 0;
}