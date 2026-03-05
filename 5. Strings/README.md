# Strings em C 

## O que são Strings em C

Diferente de muitas linguagens modernas, **C não possui um tipo de dado
específico para strings**.

Uma **string em C é um vetor de caracteres (`char`) terminado por um
caractere especial chamado terminador nulo (`'\0'`)**.

Esse caractere indica **o final da string na memória**.

Exemplo:

``` c
char nome[] = "Ana";
```

Na memória:

  |Índice |  Conteúdo|
  |--- |---|
  |0  |      'A' |
  |1  |      'n' |
  |2  |      'a' |
  |3 |       '\\0' |


Observe que a string **"Ana" ocupa 4 posições** porque o compilador
adiciona automaticamente o terminador `\0`.

Strings são armazenadas em **blocos contínuos de memória**, exatamente
como vetores.


------------------------------------------------------------------------

# Declarando Strings


``` c
char nome[20];
```

Significa que podem ser armazenados:

-   **até 19 caracteres**
-   **1 posição reservada para `\0`**

------------------------------------------------------------------------

# Declarar e Inicializar

## Inicialização automática

``` c
char nome[] = "Carlos";
```

O compilador calcula o tamanho automaticamente.

Equivalente a:

``` c
char nome[7] = {'C','a','r','l','o','s','\0'};
```

------------------------------------------------------------------------

## Inicialização com tamanho fixo

``` c
char nome[20] = "Carlos";
```

Nesse caso:

-   "Carlos" ocupa 7 posições
-   o restante fica disponível para uso

------------------------------------------------------------------------

## Inicialização caractere por caractere

``` c
char palavra[6] = {'H','e','l','l','o','\0'};
```

------------------------------------------------------------------------

# Atribuição de Strings

Vetores **não podem receber atribuição direta após a declaração**.

❌ Errado

``` c
char nome[20];
nome = "Ana";
```

Isso ocorre porque **arrays não suportam operador de atribuição**.

------------------------------------------------------------------------

## Forma correta

Utilizando `strcpy` da biblioteca `string.h`.

``` c
#include <string.h>

char nome[20];

strcpy(nome, "Ana");
```

------------------------------------------------------------------------

# Leitura de Strings

## Usando scanf

``` c
char nome[50];
scanf("%s", nome);
```

Problema:

`scanf("%s")` **para de ler quando encontra espaço**.

Entrada:

    Joao Silva

Resultado armazenado:

    Joao

------------------------------------------------------------------------

## Usando fgets (forma recomendada)

``` c
char nome[50];

fgets(nome, 50, stdin);
```

Essa função:

-   lê espaços
-   evita overflow
-   lê até o limite especificado

Entrada:

    Joao Silva

Conteúdo armazenado:

    "Joao Silva\n"

Observe que o `\n` também é armazenado.

------------------------------------------------------------------------

# Escrita de Strings

## printf

``` c
printf("%s", nome);
```

------------------------------------------------------------------------

## puts

``` c
puts(nome);
```

Diferença:

`puts` **adiciona automaticamente uma quebra de linha**.

------------------------------------------------------------------------

# Problemas de Buffer

Um dos erros mais comuns em C ao trabalhar com strings é o **buffer
overflow**.

Isso ocorre quando o usuário digita mais caracteres do que o vetor
suporta.

Exemplo:

``` c
char nome[10];
scanf("%s", nome);
```

Se o usuário digitar:

    Alexanderson

A string possui **mais caracteres que o vetor comporta**, causando:

-   escrita fora da memória
-   comportamento indefinido
-   possíveis falhas de segurança

------------------------------------------------------------------------

## Problema ao Misturar scanf e fgets

Outro problema comum ocorre ao **misturar `scanf` e `fgets`**.

Exemplo:

``` c
int idade;
char nome[50];

scanf("%d", &idade);
fgets(nome, 50, stdin);
```

Entrada:

    25
    Joao

Problema:

`scanf` **não consome o caractere de quebra de linha (`\n`) digitado
após o número**.

O `fgets` seguinte **lê apenas esse `\n` que ficou no buffer**,
resultando em uma string vazia.

------------------------------------------------------------------------

## Ilustração do buffer

Após digitar:

    25\n

Buffer de entrada:

    [2][5][\n]

`scanf("%d")` consome apenas:

    [2][5]

O `\n` permanece no buffer.

Então o `fgets` lê:

    \n

------------------------------------------------------------------------

## Solução: Consumir o `\n`

``` c
scanf("%d", &idade);
while((getchar()) != '\n'); // consome o '\n'
fgets(nome, 50, stdin);
```

------------------------------------------------------------------------

# Biblioteca string.h

Biblioteca responsável pela **manipulação de strings**.

``` c
#include <string.h>
```

------------------------------------------------------------------------

# Principais Funções

## strlen

Retorna o tamanho da string **sem contar o `\0`**.

``` c
char nome[] = "Maria";

int t = strlen(nome);
```

Resultado:

    5

------------------------------------------------------------------------

## strcpy

Copia uma string.

``` c
char origem[] = "Ana";
char destino[20];

strcpy(destino, origem);
```

------------------------------------------------------------------------

## strncpy

Copia no máximo **n caracteres**.

``` c
strncpy(destino, origem, 3);
```

------------------------------------------------------------------------

## strcat

Concatena strings.

``` c
char nome[20] = "Ana";

strcat(nome, " Silva");
```

Resultado:

    Ana Silva

------------------------------------------------------------------------

## strncat

Concatena apenas **n caracteres**.

``` c
strncat(nome, "Silva", 3);
```

------------------------------------------------------------------------

## strcmp

Compara strings.

``` c
strcmp("Ana","Ana") // 0
strcmp("Ana","Bia") // negativo
strcmp("Bia","Ana") // positivo
```

Interpretação:

  Resultado   Significado
  ----------- ----------------
  0           strings iguais
  \<0         primeira menor
  \>0         primeira maior

------------------------------------------------------------------------

## strncmp

Compara apenas os **n primeiros caracteres**.

``` c
strncmp("computador","computacao",5);
```

------------------------------------------------------------------------

## strchr

Localiza a primeira ocorrência de um caractere.

``` c
char *p = strchr("banana",'n');
```

Resultado aponta para:

    nana

------------------------------------------------------------------------

## strstr

Procura uma substring.

``` c
char *p = strstr("programacao","gram");
```

Resultado:

    gramacao

------------------------------------------------------------------------

# Biblioteca ctype.h

Biblioteca usada para **classificar e transformar caracteres**.

``` c
#include <ctype.h>
```

------------------------------------------------------------------------

# Funções de Classificação

## isalpha

Verifica se é letra.

``` c
isalpha(c)
```

------------------------------------------------------------------------

## isdigit

Verifica se é número.

``` c
isdigit('5')
```

------------------------------------------------------------------------

## isalnum

Verifica se é **letra ou número**.

------------------------------------------------------------------------

## isspace

Verifica se é **espaço em branco**.

Inclui:

-   espaço
-   tab
-   newline

------------------------------------------------------------------------

## islower

Verifica se é **minúscula**.

------------------------------------------------------------------------

## isupper

Verifica se é **maiúscula**.

------------------------------------------------------------------------

# Funções de Conversão

## tolower

Converte para minúscula.

``` c
char c = tolower('A');
```

------------------------------------------------------------------------

## toupper

Converte para maiúscula.

``` c
char c = toupper('b');
```

