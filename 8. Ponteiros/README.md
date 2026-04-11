# Ponteiros em C

## O que é um ponteiro?

Um **ponteiro** é uma variável cujo valor é um **endereço de memória**.
Em vez de armazenar diretamente um dado, ele armazena **onde o dado
está**.


Ponteiros são essenciais em C para: 
- evitar cópias desnecessárias de
dados 
- permitir modificação de variáveis em funções 
- manipular
estruturas dinâmicas (listas, árvores)
 - trabalhar diretamente com
memória

------------------------------------------------------------------------

##  Declaração

``` c
int *p;
float *f;
char *c;
```

👉 O tipo indica **o tipo de dado apontado**

------------------------------------------------------------------------

##  Inicialização

``` c
int x = 10;
int *p = &x;
```

###  Diagrama em memória

    x: 10        p: 1000
    [1000] ----> [10]

------------------------------------------------------------------------

##  Operadores fundamentais

  Operador   Significado
  ---------- ---------------------
  `&`        endereço de memória
  `*`        desreferência

------------------------------------------------------------------------

##  Desreferência

Desreferência é o ato de acessar o valor armazenado no endereço apontado por um ponteiro.

Se um ponteiro guarda um endereço, desreferenciar significa:
“ir até esse endereço e pegar (ou alterar) o valor que está lá.”

``` c
int x = 5;
int *p = &x;
*p = 20;
printf("%d", *p);
```


------------------------------------------------------------------------

##  Ponteiro NULL

Indica que o ponteiro não aponta para lugar válido

``` c
int *p = NULL;
```


------------------------------------------------------------------------

##  Passagem de parâmetro por referência
Passagem de parâmetro por referência é quando uma função recebe o endereço de uma variável, permitindo que ela modifique diretamente o valor original.

Em vez de enviar uma cópia do valor, você envia onde o valor está na memória.

Linguagem C não tem referência “nativa”, então usamos ponteiros.

``` c
void f(int *x) {
    *x = *x + 10;
}

int main() {
    int a=5;
    int *p=&a;
    f(p); // ou simplesmente f(&a);
    printf("a: %d, a); //mostra 15;
    return 0;
}
```

Outro exemplo:

```c
#include <stdio.h>

// função para trocar os valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Antes da troca:\n");
    printf("x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("Depois da troca:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
```


------------------------------------------------------------------------

## 🔹 Ponteiro para struct

``` c
struct Aluno {
    char nome[100];
    int idade;
    int notas[3];
};

struct Aluno a = {"Joaquim",20, {8.5, 9.0, 9.5}};
struct Aluno *p = &a;

p->idade = 21;
p->notas[0] = 8.7;
```


