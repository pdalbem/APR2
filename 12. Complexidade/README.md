# Complexidade de Algoritmos em C

---

# Introdução

Ao desenvolver programas, não basta apenas que eles funcionem corretamente.
Também é importante avaliar:

- quanto tempo levam para executar;
- quanta memória consomem;
- como se comportam quando os dados aumentam.

A área responsável por esse estudo é chamada de **Análise de Algoritmos**.

---

# O que é Complexidade de Algoritmos

A complexidade mede o custo de execução de um algoritmo.

Esse custo normalmente considera:

- tempo de execução;
- uso de memória.

A análise é feita em função do tamanho da entrada, geralmente representado por:

```text
n
```

Exemplo:

- vetor com 10 elementos → n = 10
- vetor com 1000 elementos → n = 1000

---

# Complexidade de Tempo

A complexidade de tempo mede quantas operações um algoritmo executa.

## Exemplo

```c
#include <stdio.h>

int main() {

    int i;

    for(i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Se o laço dependesse de `n`:

```c
for(i = 0; i < n; i++)
```

A quantidade de execuções cresceria proporcionalmente a `n`.

Complexidade:

```text
O(n)
```

---

# Complexidade de Espaço

A complexidade de espaço mede a quantidade de memória utilizada por um algoritmo.

É importante distinguir:

- memória da entrada;
- memória auxiliar (extra).

Na prática, normalmente analisamos a **memória auxiliar**.

---

## Exemplo sem espaço auxiliar O(1)

```c
int soma(int v[], int n) {

    int soma = 0;

    for(int i = 0; i < n; i++)
        soma += v[i];

    return soma;
}
```

O vetor `v` já faz parte da entrada.

A função utiliza apenas algumas variáveis:

- `soma`
- `i`

Logo, o espaço auxiliar é:

```text
O(1)
```

---

## Exemplo com espaço auxiliar O(n)

```c
void copiar(int origem[], int n) {

    int copia[n];

    for(int i = 0; i < n; i++)
        copia[i] = origem[i];
}
```

Nesse caso, o vetor `copia` é criado pelo algoritmo.

A memória extra cresce proporcionalmente a `n`.

Complexidade espacial:

```text
O(n)
```

---

## Espaço na Recursão

Funções recursivas utilizam pilha de chamadas.

```c
int fatorial(int n) {

    if(n == 0)
        return 1;

    return n * fatorial(n - 1);
}
```

A profundidade da recursão é `n`.

Complexidade espacial:

```text
O(n)
```

---

# Como Calcular Complexidade

Existem duas formas principais.

---

# Análise Empírica

Consiste em executar o programa e medir:

- tempo;
- memória;
- desempenho.

## Exemplo usando `clock()`

```c
#include <stdio.h>
#include <time.h>

int main() {

    clock_t inicio, fim;

    inicio = clock();

    for(long i = 0; i < 100000000; i++);

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo: %f segundos\n", tempo);

    return 0;
}
```

## Vantagens

- mede desempenho real;
- simples de testar.

## Desvantagens

O resultado depende:

- do hardware;
- do compilador;
- do sistema operacional;
- da carga da máquina.

---

# Análise Teórica (Assintótica)

A análise assintótica avalia o crescimento do algoritmo conforme o tamanho da entrada aumenta.

Ela ignora:

- constantes;
- detalhes do hardware;
- pequenas diferenças de implementação.

O foco é o crescimento do algoritmo.

---

# Notação Big-O

A notação Big-O representa o crescimento assintótico do algoritmo.

## Exemplo

```c
for(i = 0; i < n; i++)
```

Complexidade:

```text
O(n)
```

---

## Ignorando constantes

```c
for(i = 0; i < 2*n; i++)
```

Continua sendo:

```text
O(n)
```

---

## Ignorando termos menores

Expressão:

```text
n² + n + 10
```

A parte dominante é:

```text
n²
```

Logo:

```text
O(n²)
```

---

# Principais Classes de Complexidade

---

# Complexidade Constante — O(1)

O tempo não depende do tamanho da entrada.

## Exemplo

```c
int primeiro(int v[]) {
    return v[0];
}
```

---

# Complexidade Logarítmica — O(log n)

O problema é reduzido pela metade a cada passo.

## Busca Binária

```c
int busca_binaria(int v[], int n, int x) {

    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if(v[meio] == x)
            return meio;

        if(x < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}
```

Complexidade:

```text
O(log n)
```

---

# Complexidade Linear — O(n)

## Exemplo

```c
int soma(int v[], int n) {

    int soma = 0;

    for(int i = 0; i < n; i++)
        soma += v[i];

    return soma;
}
```

Complexidade:

```text
O(n)
```

---

# Complexidade Linearítmica — O(n log n)

Muito comum em algoritmos eficientes de ordenação.

## Exemplos

- Merge Sort
- Quick Sort (caso médio)

### Merge Sort

```c
void merge_sort(int v[], int inicio, int fim) {

    if(inicio < fim) {

        int meio = (inicio + fim) / 2;

        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}
```

Complexidade:

```text
O(n log n)
```

---

# Complexidade Quadrática — O(n²)

Normalmente ocorre com laços aninhados.

## Exemplo

```c
for(i = 0; i < n; i++) {

    for(j = 0; j < n; j++) {
        printf("%d %d\n", i, j);
    }
}
```

Complexidade:

```text
O(n²)
```

---

## Bubble Sort

```c
void bubble_sort(int v[], int n) {

    int i, j, temp;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - 1 - i; j++) {

            if(v[j] > v[j + 1]) {

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
```

Complexidade:

```text
O(n²)
```

---

# Complexidade Cúbica — O(n³)

## Exemplo

```c
for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
        for(k = 0; k < n; k++)
            printf("%d\n", i+j+k);
```

Complexidade:

```text
O(n³)
```

---

# Complexidade Exponencial — O(2^n)

## Fibonacci Recursivo

```c
int fibonacci(int n) {

    if(n <= 1)
        return n;

    return fibonacci(n-1) + fibonacci(n-2);
}
```

Complexidade:

```text
O(2^n)
```

---

# Complexidade Fatorial — O(n!)

Muito custosa.

Aparece em problemas envolvendo permutações.

---

# Comparação entre Complexidades

Da melhor para a pior:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2^n)
O(n!)
```

---

# Melhor Caso, Pior Caso e Caso Médio

---

## Melhor Caso

Situação mais favorável.

Exemplo: busca linear encontrando o elemento na primeira posição.

```text
O(1)
```

---

## Pior Caso

Situação mais desfavorável.

Exemplo: elemento está na última posição.

```text
O(n)
```

---

## Caso Médio

Comportamento esperado em média.

---

## Exemplo

```c
int busca(int v[], int n, int x) {

    for(int i = 0; i < n; i++) {

        if(v[i] == x)
            return i;
    }

    return -1;
}
```

- melhor caso → O(1)
- pior caso → O(n)
- caso médio → O(n)

---

# Regras Práticas para Calcular Complexidade

---

## Sequência de comandos

```c
a = b + c;
d = a * 2;
```

Complexidade:

```text
O(1)
```

---

## Um laço

```c
for(i = 0; i < n; i++)
```

Complexidade:

```text
O(n)
```

---

## Dois laços aninhados

```c
for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
```

Complexidade:

```text
O(n²)
```

---

## Divisão pela metade

```c
while(n > 1)
    n = n / 2;
```

Complexidade:

```text
O(log n)
```