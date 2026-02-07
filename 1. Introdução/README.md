
# Introdução à Linguagem C

## 1. Estrutura básica de um programa em C

A seguir, é apresentado um programa básico em  C:

```c
#include <stdio.h>

int main() {
    printf("Olá, mundo!\n");
    return 0;
}
```

Um programa em C é organizado de maneira modular e segue uma estrutura predefinida que permite ao compilador entender e traduzir corretamente o código. Embora existam variações, todo programa C funcional compartilha elementos essenciais.

1. Diretivas de Pré-processador

    São instruções processadas antes da compilação propriamente dita. Geralmente, são definidas no começo do arquivo e começam com o símbolo #.
    O pré-processador atua antes do compilador, realizando substituições e inclusões de código, sem gerar código executável por si só.
Tudo o que começa com # não é exatamente "código" de execução, mas sim instruções para o compilador. A mais comum é a #include, que traz ferramentas externas para o seu código.
No exemplo, diretiva `#include <stdio.h>` está solicitando a inclusão da biblioteca **stdio.h** (abreviação de _Standard Input-Output_ - Entrada-Saída padrão). Sem isso, o computador não saberia como mostrar textos na tela ou ler o que você digita.


2. Função main() - O Coração do Programa

    Todo programa em C é organizado em funções. A principal e obrigatória é a `main()`. É o ponto de entrada do programa em C.

    Todo programa em C começa a executar pela função main.

    O tipo de retorno int indica que a função retorna um valor inteiro para o sistema operacional, indicando se o programa foi finalizado com sucesso ou erro. É convenção que  o retorno 0 (zero) indica sucesso e qualquer coisa diferente disso indica erro.

3. Corpo das Funções

    Contém instruções executáveis, delimitadas por `{ }`

    Toda instrução em C é encerrada por ponto-e-vírgula (;). Sua ausência gera erro de compilação.
    
    A linguagem é _case-sensitive_, ou seja,  diferencia letras maiúsculas de minúsculas. `Main` é diferente de `main`.


---

## 2. Tipos de dados em C

C é uma linguagem **fortemente tipada**, ou seja, toda variável possui um tipo bem definido.

### Tipos primitivos mais comuns:

- `int` → números inteiros
- `float` → números reais (precisão simples)
- `double` → números reais (precisão dupla)
- `char` → caracteres
- `void` → Representa a ausência de valor. É muito comum em funções que não devolvem nenhuma resposta ao usuário, apenas executam uma tarefa.


Exemplo:

```c
int idade = 20;
float altura = 1.75;
char sexo = 'F';
```


Em C clássico, não existe um tipo "String" nativo para textos longos. É usado um "array de chars" (uma fila de caracteres) para formar palavras e frases.

O tipo booleano também não existe no C clássico. O valor `0` representa `false` e qualquer coisa diferente disso representa `true`. 

Entretanto,  no C99 foi introduzido o tipo `bool`, o qual aceita os valores `true` ou `false`. Basta adicionar a biblioteca `<stdbool.h>`. Mesmo usando bool, o C continua tratando valores lógicos como inteiros.


```c
#include <stdbool.h>

int main()
{
    bool ligado = true;
    return 0;
} 
```



---

Em C, o tipo de uma variável determina:

- O espaço de memória ocupado
- As operações permitidas
- Como o valor será interpretado

### Vantagens da tipagem forte:

- Detecção de erros em tempo de compilação
- Código mais previsível e seguro
- Melhor desempenho
- Maior clareza e legibilidade

---



## 3. Variáveis em C
Variável é uma região nomeada de memória usada para guardar algum dado, o qual
pode ser alterado pelo programa durante sua execução.
Toda variável em C deve ser declarada antes de ser utilizada. A forma geral de
declaração é **tipo_de_dado nome_da_variável;**

```c
int a;    // Declaração apenas, NÃO inicializada → valor "lixo" da memória
a = 10;  // Inicializada

float salario = 3500.57;  // Declara e inicializada

// Declaração de múltiplas variáveis de um mesmo tipo
int p, q, r;

// Declaração  inicialização de múltiplas variáveis de um mesmo tipo
int x = 1, y = 2, z = 3;

//Inicialização em sequência. Todos recebem o mesmo valor
int j = k = m = 20;

//NÃO existe atribuição múltipla em C
int b,c,d = 30; // Apenas d recebe 30
int e,f;
e,f = 10,20 // Apenas f recebe 10
```

### Nomes de variáveis em C
C é _case-sensitive_: Letras maiúsculas e minúsculas são distintas (ex: idade é diferente de
Idade);

Podem ter qualquer tamanho;

Devem conter apenas letras, números ou underscore (_);

Não podem começar com números;

Não se deve usar palavras reservadas como nome de variáveis;


### Onde Variáveis Podem Ser Declaradas em C

Em C, o local onde uma variável é declarada determina seu escopo (onde ela pode ser acessada), tempo de vida (quanto tempo existe na memória) e visibilidade. Existem três locais principais onde variáveis podem ser declaradas.

**Variáveis Locais (dentro de uma função)**

São declaradas dentro do corpo de uma função e só existem enquanto a função está executando.

Escopo: Limitado ao bloco {} onde foi declarada

Tempo de vida: Existe apenas durante a execução da função/bloco

Armazenamento: Normalmente na pilha (stack)

Inicialização: NÃO são automaticamente inicializadas (contêm "lixo" da memória)

Exemplo:
```c
int main() {
    int x = 5, y = 3;
      
    return 0;
}
```

**Variáveis Locais (parâmetros de função)**

São variáveis declaradas na lista de parâmetros de uma função. Funcionam como variáveis locais, mas recebem valores dos argumentos passados na chamada.

Escopo: Local à função

Tempo de vida: Duração da execução da função

Passagem: Por valor (cópia) ou por referência (ponteiro)

Inicialização: Inicializadas com os valores dos argumentos

Exemplo:
```c
#include <stdio.h>

// a e b são parâmetros (variáveis locais da função)
int soma(int a, int b) {
    int resultado = a + b;  // Variável local adicional
    a = 100;  // Modifica apenas a cópia local
    return resultado;
}

int main() {
    int x = 5, y = 3;
    int total = soma(x, y);
    
    printf("Soma: %d\n", total);   // 8
    printf("x ainda vale: %d\n", x); // 5 (não foi alterado)
    
    return 0;
}
```


**Variáveis Globais**

São declaradas fora de todas as funções, normalmente no início do arquivo. Podem ser acessadas por todas as funções do arquivo (e de outros arquivos, com extern).

Escopo: Todo o arquivo (ou programa, com extern)

Tempo de vida: Existe durante toda a execução do programa

Armazenamento: Segmento de dados (data segment)

Inicialização: Automaticamente inicializadas com zero (se não inicializadas explicitamente)

Exemplo:
```c
#include <stdio.h>

// Variáveis globais (fora de todas as funções)
int contador_global = 0;
const float PI = 3.14159;

void incrementa() {
    contador_global++;  // Pode ser acessada aqui
    printf("Contador: %d\n", contador_global);
}

void decrementa() {
    contador_global--;  // E aqui também
    printf("Contador: %d\n", contador_global);
}

int main() {
    printf("PI = %.2f\n", PI);
    
    incrementa();
    incrementa();
    decrementa();
    
    printf("Valor final: %d\n", contador_global);
    return 0;
}

```

---


## 4. _Casting_ (conversão de tipos)

**Casting** é a conversão explícita de um tipo de dado para outro.

Exemplo:

```c
int a = 5;
int b = 2;
float media = (float)a / b;
```
O casting é aplicado antes da divisão, fazendo com que a operação seja realizada em ponto flutuante.
Sem o casting, a divisão seria inteira (a e b são int) e o resultado seria `2`.

Casting deve ser usado com cuidado, pois conversões inadequadas podem gerar perda de dados.

---

## 5. Modificadores de tipo

C permite modificar tipos básicos para alterar seu comportamento. Esses modificadores influenciam o intervalo de valores e o uso de memória

### Modificadores mais comuns:

- `short` → Reduz o espaço de memória ocupado pela variável (geralmente para 2 bytes). É ideal para economizar memória quando você tem certeza de que os números não serão muito grandes (limite aproximado de $-32.768$ a $32.767$).
- `long` → Aumenta a capacidade de armazenamento da variável (geralmente para 4 ou 8 bytes, dependendo do sistema). É usado quando o int padrão não é suficiente para o tamanho do número que você precisa manipular.
- `signed` → Define que o número terá sinal (negativo/positivo). É o padrão para a maioria dos tipos (como o int), então raramente você precisará escrever essa palavra explicitamente.
- `unsigned` → Define que o número será somente positivo (incluindo o zero), o que dobra o limite positivo do alcance. Como você não "gasta" um bit para o sinal de menos, ganha mais espaço para números positivos.

Exemplos:

```c
int x; // Tamanho aproximado: 4 bytes, alcance: -2.147.483.648 até 2.147.483.647

unsigned int y; // Tamanho aproximado: 4 bytes, alcance: 0 até 4.294.967.295

short int z; // Tamanho aproximado: 2 bytes, alcance: -32.768 até 32.767

unsigned short int p; // Tamanho aproximado: 2 bytes, alcance: 0 até 65.535

long int q; // Tamanho aproximado: 4 bytes (32 bits) ou 8 bytes (64 bits), 
            // alcance típico (8 bytes): -9.223.372.036.854.775.808  até 9.223.372.036.854.775.807

unsigned long int r; // Tamanho aproximado: 4 bytes (32 bits) ou 8 bytes (64 bits),  
                    // alcance: 0 até 18.446.744.073.709.551.615
```

Para o tipo `float`, nenhum modificado pode ser aplicado. Ele segue, quase que universalmente, o padrão IEEE 754, o qual define uma estrutura fixa. Já possui sinal, expoente e mantissa.


Para o `double`, apenas o modificador `long` pode ser usado.
Assim como o `float`, o `double` segue o padrão IEEE 754 e, portanto, possui estrutura fixa. Logo, não poderia aplicar o modificador `unsigned`. E não faz sentido aplicar o modificar `short` no double. Se quiser usar algo menor, já tem o float disponível. 

|Modificador|int|char|float|double|
|---|---|---|---|---|
|short|✅|❌|❌|❌|
|long|✅|❌|❌|✅|
|signed|✅|✅|❌|❌|
|unsigned|✅|✅|❌|❌|
---



## 6. Constantes em C

Uma constante é um valor que não deve ser alterado durante a execução do programa. Em C, é possível declarar constantes de 2 maneiras:

**I. Constantes com `#define (macro)`**

São definidas como diretivas do pré-processador. 
O pré-processador atua antes do compilador, realizando substituições e inclusões de código, sem gerar código executável por si só.
Portanto, desta forma Ocorre uma substituição textual feita pelo pré-processador.
Não ocupa memória como variável.
Não tem tipo, muito rápida e pode ser usada em qualquer contexto.


```c
#define PI 3.14159
#define TAM 10
```

**II. Constantes com `const`**

Variável tipada é criada em memória. Valor não pode ser alterado.

```c
int main()
{
    const float PI = 3.14159; 
    return 0;
}
```

**Boas práticas**

Prefira const quando quiser segurança de tipo

Use #define para valores globais e tamanhos fixos

Evite números mágicos no código

---


## 7. Operadores aritméticos


Usados para cálculos matemáticos:

- `+` adição
- `-` subtração
- `*` multiplicação
- `/` divisão
- `%` resto da divisão inteira

Exemplo:

```c
int a = 10, b = 3;
int soma = a + b;
int resto = a % b;
```

---

## 8. Operadores relacionais

Usados para comparar valores:

- `==` igual
- `!=` diferente
- `>` maior que
- `<` menor que
- `>=` maior ou igual
- `<=` menor ou igual

Resultado sempre será **verdadeiro (1)** ou **falso (0)**.

---

## 9. Operadores lógicos

Usados para combinar expressões booleanas:

- `&&` (E lógico)
- `||` (OU lógico)
- `!` (NÃO lógico)

Exemplo:

```c
if (idade >= 18 && idade <= 65) {
    printf("Idade válida");
}
```


## 10. Entrada e saída de dados em C

A interação com o usuário em C é feita, principalmente, por meio das funções `printf` e `scanf`, ambas pertencentes à biblioteca `stdio.h`.

---

### 10.1 Saída de dados com `printf`

A função `printf` é utilizada para **exibir informações na tela**.

Exemplo:

```c
int idade = 20;
printf("Idade: %d", idade);
```

#### Principais especificadores de formato:

- `%d` → inteiro (`int`)
- `%f` → real (`float` ou `double`)
- `%c` → caractere (`char`)
- `%s` → string (cadeia de caracteres)

Exemplo:

```c
float altura = 1.75;
printf("Altura: %.2f metros", altura);
```

---

### 10.2 Entrada de dados com `scanf`

A função `scanf` é utilizada para **ler dados digitados pelo usuário**.

Exemplo:

```c
int idade;
printf("Digite sua idade: ");
scanf("%d", &idade);
```

⚠️ Observe o uso do operador `&` (endereço de memória). Ele é necessário para que o `scanf` saiba **onde armazenar** o valor digitado.

Exemplo com número real:

```c
float salario;
printf("Digite o salário: ");
scanf("%f", &salario);
```
#### Principais especificadores de formato para leitura de dados:

- `%d` → inteiro (`int`)
- `%f` → `float` 
* `%lf` → `double`
- `%c` → caractere (`char`)
- `%s` → string (cadeia de caracteres)
---

### 10.3 Exemplo completo de entrada e saída

```c
#include <stdio.h>

int main() {
    int idade;
    float altura;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("Idade informada: %d \n", idade);
    printf("Altura informada: %.2f \n", altura);

    return 0;
}
```
---