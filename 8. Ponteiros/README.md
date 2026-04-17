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

O tipo indica **o tipo de dado apontado**

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

## Ponteiro para struct

É bastante útil utilizar ponteiros para struct:
- evita cópias desnecessárias (melhor desempenho)
- permite modificar a struct dentro de funções
- é essencial para estruturas dinâmicas (listas, árvores, etc.)

Existem duas formas para acessar os campos de uma struct via ponteiro:

- Forma tradicional (com desreferência)
```c
(*p).idade = 30;
```
- Forma mais usada (operador seta ->)
```c
p->idade = 30; //equivalente a (*p).idade
```


### Usando ponteiro para struct em funções

Aqui está o ponto mais importante 

- Passagem por valor

Uma cópia da struct é criada em memória e passada para a função. Qualquer alteração nesta cópia não será refletida no restante do código:

```c
void alterar(struct Pessoa p) {
    p.idade = 50; // não altera o original
}
```

- Passagem por referência (com ponteiro) 

Agora a função recebe o endereço de memória da variável do tipo struct. Qualquer alteração é refletida na variável original:
```c
void alterar(struct Pessoa *p) {
    p->idade = 50;
}
```

Chamada:
```c
alterar(&p1);
```

Exemplo completo:

``` c
#include <stdio.h>
#include <string.h>

#define MAX_NOTAS 3

typedef struct
{
    int id;
    char nome[100];
    float notas[MAX_NOTAS];
} Aluno;

void lerDados(Aluno *a)
{
    printf("\nDigite o ID: ");
    scanf("%d", &a->id);
    while (getchar() != '\n');

    printf("Digite o nome: ");
    fgets(a->nome, sizeof(a->nome), stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0';

    for (int i = 0; i < MAX_NOTAS; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &a->notas[i]);
    }
}

void mostrarDados(Aluno *a)
{
    printf("\nId: %d", a->id);
    printf("\nNome: %s", a->nome);
    for (int i = 0; i < MAX_NOTAS; i++)
        printf("\nNota %d: %.2f", i + 1, a->notas[i]);
    printf("\n");    
}

float calcularMedia(Aluno *a){
    float soma=0;
    for (int i=0;i<MAX_NOTAS;i++)
        soma += a->notas[i];
    return soma/MAX_NOTAS;    
}

int main()
{
   Aluno a1;
   Aluno *ptr1 = &a1;
   lerDados(ptr1);
   
   mostrarDados(ptr1);
   printf("Média de notas: %.2f", calcularMedia(ptr1)); 

    return 0;
}
```