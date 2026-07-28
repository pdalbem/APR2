# Recursividade em C

## Conceito

Recursividade é uma técnica onde uma função chama a si mesma para
resolver um problema dividido em partes menores.

------------------------------------------------------------------------

## Estrutura básica

Para que uma função recursiva não rode eternamente (causando um Stack Overflow), ela precisa de dois componentes essenciais:

- Caso Base (Condição de Parada): É a condição que interrompe as chamadas recursivas. Sem isso, o programa entra em um loop infinito até esgotar a memória.

- Caso Recursivo: É onde a função chama a si própria, geralmente aproximando o argumento do "Caso Base".

``` c
int funcao(int n) {
    if (condicao_base)
        return valor;

    return funcao(problema_menor);
}
```

------------------------------------------------------------------------

## Exemplo 1: Fatorial

O fatorial de um número $n$ ($n!$) é definido como $n \times (n-1)!$, sendo que $0! = 1$.


A versão iterativa é:

``` c
#include <stdio.h>

int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++)
        resultado *= i;
    return resultado;
}

int main() {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, fatorial(num));
    return 0;
}
```

A versão **recursiva** é:

``` c
#include <stdio.h>

int fatorial(int n) {
    // Caso base: fatorial de 0 ou 1 é 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso recursivo: n! = n * (n-1)!
    return n * fatorial(n - 1);
}

int main() {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, fatorial(num));
    return 0;
}
```
O que acontece para fatorial(5):

```text
fatorial(5) = 5 * fatorial(4)
            = 5 * (4 * fatorial(3))
            = 5 * (4 * (3 * fatorial(2)))
            = 5 * (4 * (3 * (2 * fatorial(1))))
            = 5 * (4 * (3 * (2 * 1)))
            = 120
```

Quando você chama fatorial(5), o computador empilha as chamadas:

fatorial(5) espera o resultado de 5 * fatorial(4)

fatorial(4) espera o resultado de 4 * fatorial(3)

fatorial(3) espera o resultado de 3 * fatorial(2)

fatorial(2) espera o resultado de 2 * fatorial(1)

fatorial(1) espera o resultado de 1 * fatorial(0)

fatorial(0) retorna 1 (Caso Base).

A partir daí, ele "desempilha" multiplicando os valores de volta.


------------------------------------------------------------------------

## Exemplo 2: Fibonacci

A recursão para calcular a sequência de Fibonacci em C é um exemplo clássico, onde cada termo é a soma dos dois anteriores, com casos base F(0)=0 e F(1)=1. É simples de implementar, mas ineficiente para valores grandes devido ao alto número de chamadas repetidas.

A função fibonacci(n) retorna:

* 0 se n = 0

* 1 se n = 1

* fibonacci(n-1) + fibonacci(n-2) caso contrário

### Recursivo

``` c
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;      // Caso base 1
    if (n == 1) return 1;      // Caso base 2
    return fibonacci(n - 1) + fibonacci(n - 2);  // Chamada recursiva
}

int main() {
    int num = 6;
    printf("Fibonacci(%d) = %d\n", num, fibonacci(num));  // Saída: 8
    return 0;
}
```

Para n=6, a execução expande como: fib(6) = fib(5) + fib(4) = [fib(4)+fib(3)] + [fib(3)+fib(2)], até os casos base.

------------------------------------------------------------------------

## Exemplo 3: Soma de vetor

``` c
int soma(int v[], int n) {
    if (n == 0)
        return 0;
    return v[n-1] + soma(v, n-1);
}
```

------------------------------------------------------------------------

## Exemplo 4: Potência

``` c
int potencia(int x, int n) {
    if (n == 0)
        return 1;
    return x * potencia(x, n - 1);
}
```

------------------------------------------------------------------------

## A Pilha de Execução (Stack)
Cada vez que uma função é chamada em C, um bloco de memória chamado Stack Frame é alocado na Pilha (Stack) para armazenar as variáveis locais e o endereço de retorno.

O estouro de pilha (stack overflow) é o principal risco da recursão em C, ocorrendo quando chamadas excessivas esgotam o espaço limitado da pilha de execução. Cada chamada recursiva aloca um novo quadro na pilha para variáveis locais e endereço de retorno, levando a falha do programa em profundidades altas.

### Causas Principais
* Recursão infinita: Falta de caso base ou condição inalcançável, criando chamadas sem fim.

* Profundidade excessiva: Entradas grandes em funções como Fibonacci simples (ex: n>40), com árvores de chamadas exponenciais.

* Recursos limitados: Varia por sistema/compilador; em embedded ou threads, o limite é ainda menor.

------------------------------------------------------------------------

## Vantagens da recursividade
* Código mais limpo e fácil de entender para problemas naturalmente recursivos

* Facilidade para resolver problemas como árvores, grafos, backtracking

* Abordagem matemática elegante para certos problemas

## Desvantagens e cuidados
*   Stack overflow
*   Maior consumo de memória
*   Pode ser lenta

------------------------------------------------------------------------

## Quando usar?

A recursividade é brilhante para problemas que têm uma natureza naturalmente recursiva, como:

Cálculos matemáticos (Fibonacci, Fatorial).

Algoritmos de ordenação eficientes (Quick Sort, Merge Sort).

Percorrer estruturas de dados complexas, como Árvores Binárias ou sistemas de arquivos.

------------------------------------------------------------------------