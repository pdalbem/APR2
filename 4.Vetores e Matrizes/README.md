# Vetores e Matrizes em C

Vetores e matrizes são estruturas de dados fundamentais em C que permitem armazenar múltiplos valores do mesmo tipo em uma única variável, organizados de forma sequencial na memória.



# Vetores (_Arrays_ Unidimensionais)

Os vetores em C são identificados pela existência de **\[ \]** logo após
o nome da variável no momento da declaração. Dentro dos colchetes, é
especificado o tamanho do vetor.

Um vetor é uma estrutura que armazena vários elementos do **mesmo
tipo**, organizados em **posições indexadas**.

Cada elemento é acessado por um índice, que sempre começa em **0**.


## Declaração

Para criar um vetor em C, precisamos informar ao compilador três informações essenciais: o tipo de dados que será armazenado, o nome da variável e a quantidade de elementos que ela poderá conter. A declaração reserva um espaço contíguo na memória para armazenar todos os elementos do vetor.

``` c
tipo nome[tamanho];
```

Exemplo:

``` c
int idade[5];
```


Neste momento, o vetor foi apenas declarado e não inicializado. 
Logo, o conteúdo inicial será qualquer valor que estivesse na memória antes (lixo).

## Inicialização

Após declarar um vetor, podemos atribuir valores iniciais aos seus elementos. A inicialização pode ser feita no momento da declaração, atribuindo valores entre chaves, ou posteriormente, elemento por elemento. É importante notar que, se não inicializarmos um vetor, ele conterá "lixo de memória" - valores aleatórios que estavam naquela posição de memória.


```c
// Declaração e inicialização
float medias[10] = {0.0};           // Inicializa todos com 0.0
int valores[] = {1, 2, 3, 4, 5};    // Tamanho 5 inferido automaticamente
int meuVetor[5] = {10,20}                  // Inicialização parcial: {10, 20, 0, 0, 0}

// Inicialização posterior
int vetor[3];
vetor[0] = 100;
vetor[1] = 200;
vetor[2] = 300;
```

## Acesso aos elementos

O acesso aos elementos de um vetor é feito através de um índice numérico, que indica a posição do elemento dentro da estrutura. É fundamental lembrar que em C os índices sempre começam em 0, ou seja, o primeiro elemento está na posição 0, o segundo na posição 1, e assim sucessivamente. Tentar acessar uma posição além do tamanho do vetor (índice maior ou igual ao tamanho) é um erro grave que pode causar comportamento indefinido no programa.

``` c
 int vetor[5] = {10, 20, 30, 40, 50};
    
// Acesso direto aos elementos
printf("Primeiro elemento (índice 0): %d\n", vetor[0]);     // 10
printf("Terceiro elemento (índice 2): %d\n", vetor[2]);     // 30
printf("Último elemento (índice 4): %d\n", vetor[4]);       // 50
    
// Modificando valores através do índice
vetor[1] = 25;  // Altera o segundo elemento
printf("Novo valor na posição 1: %d\n", vetor[1]);          // 25
```


## Percurso em Vetor

Percorrer um vetor significa acessar sequencialmente cada um de seus elementos, geralmente para realizar alguma operação como leitura, escrita, soma ou busca. A estrutura de repetição `for` é a mais adequada para esta tarefa, pois conhecemos previamente o tamanho do vetor. 


``` c
#include <stdio.h>

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    
    // Percorrendo para exibir os valores
    printf("Elementos do vetor:\n");
    for(int i = 0; i < 5; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    
    // Percorrendo para somar os valores
    int soma = 0;
    for(int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
    printf("Soma dos elementos: %d\n", soma);
    
    // Percorrendo para preencher o vetor
    int novoVetor[5];
    printf("\nDigite 5 números:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &novoVetor[i]);
    }
    
    return 0;
}
```

------------------------------------------------------------------------

# Matrizes (_Arrays_ Multidimensionais)
Diferentemente dos vetores que organizam dados em uma única dimensão, as matrizes permitem representar dados em duas, três ou mais dimensões. 
Uma matriz é essencialmente um vetor de vetores, organizada em linhas e colunas. 
As matrizes em C são identificadas pela existência de dois ou mais pares de colchetes [ ] após o nome da variável no momento da declaração.
Cada par de colchetes representa uma dimensão.

## Declaração de Matrizes
Para declarar uma matriz, precisamos especificar o tipo dos elementos, o nome e o tamanho para cada dimensão.

Sintaxe básica:

``` c
tipo nome[d1][d2]...[dN];
```

sendo N o número de dimensões e d<sub>_i_</sub>, _i_=1..N, o tamanho de cada dimensão _i_.



```c
// Exemplos - Matrizes Bidimensionais (2D)
int matriz2D[3][4];           // 3 linhas, 4 colunas (12 elementos)
float notas[5][3];            // 5 alunos, 3 notas cada
char tabuleiro[8][8];         // Tabuleiro 8x8

// Exemplos - Matrizes Tridimensionais (3D)
int matriz3D[2][3][4];        // 2 blocos, 3 linhas, 4 colunas (24 elementos)
float temperaturas[12][31][24]; // 12 meses, 31 dias, 24 horas

// Exemplos - Matrizes Quadridimensionais (4D)
int matriz4D[3][4][5][2];     // 3 * 4 * 5 * 2 = 120 elementos
float imagens[10][1024][768][3]; // 10 imagens, 1024x768 pixels, 3 canais RGB
```


## Inicialização

A inicialização de matrizes multidimensionais pode ser feita usando chaves aninhadas, onde cada nível de chaves corresponde a uma dimensão. Quanto mais dimensões, mais níveis de chaves precisamos. A inicialização ajuda a visualizar a estrutura dimensional e evita trabalhar com valores indefinidos.


``` c
#include <stdio.h>

int main() {
    // MATRIZ BIDIMENSIONAL (2D)
    // Inicialização linha por linha
    int matriz2D[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Inicialização sequencial (menos legível para 2D)
    int matriz2D_seq[2][3] = {1, 2, 3, 4, 5, 6};
    // Equivalente a: {{1, 2, 3}, {4, 5, 6}}
    
    // MATRIZ TRIDIMENSIONAL (3D)
    // Inicialização com três níveis de chaves
    int matriz3D[2][3][4] = {
        {                       // Primeiro bloco (índice 0)
            {1, 2, 3, 4},       // Primeira linha do bloco 0
            {5, 6, 7, 8},       // Segunda linha do bloco 0
            {9, 10, 11, 12}     // Terceira linha do bloco 0
        },
        {                       // Segundo bloco (índice 1)
            {13, 14, 15, 16},   // Primeira linha do bloco 1
            {17, 18, 19, 20},   // Segunda linha do bloco 1
            {21, 22, 23, 24}    // Terceira linha do bloco 1
        }
    };
    
    // MATRIZ QUADRIDIMENSIONAL (4D)
    // Inicialização parcial (elementos não especificados são 0)
    int matriz4D[2][2][2][2] = {
        {                       // Primeira dimensão [0]
            {                    // Segunda dimensão [0]
                {1, 2},          // Terceira dimensão [0] - quarta [0] e [1]
                {3, 4}           // Terceira dimensão [1] - quarta [0] e [1]
            },
            {                    // Segunda dimensão [1]
                {5, 6},          // Terceira dimensão [0]
                {7, 8}           // Terceira dimensão [1]
            }
        },
        {                       // Primeira dimensão [1]
            {                    // Segunda dimensão [0]
                {9, 10},         // Terceira dimensão [0]
                {11, 12}         // Terceira dimensão [1]
            },
            {                    // Segunda dimensão [1]
                {13, 14},        // Terceira dimensão [0]
                {15, 16}         // Terceira dimensão [1]
            }
        }
    };
    
    // Inicializando todos com 0 (qualquer dimensão)
    int matriz3D_zeros[3][4][5] = {{{0}}};
    
    return 0;
}
```

## Acesso aos elementos

O acesso a um elemento específico de uma matriz multidimensional é feito fornecendo um índice para cada dimensão, sempre começando em 0. 

```c
#include <stdio.h>

int main() {
    // MATRIZ BIDIMENSIONAL (2D)
    int matriz2D[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("MATRIZ 2D:\n");
    printf("Elemento [0][0] (linha 1, coluna 1): %d\n", matriz2D[0][0]);  // 1
    printf("Elemento [1][1] (linha 2, coluna 2): %d\n", matriz2D[1][1]);  // 5
    printf("Elemento [2][2] (linha 3, coluna 3): %d\n", matriz2D[2][2]);  // 9
    
    // Modificando um elemento
    matriz2D[0][2] = 30;  // Linha 1, coluna 3 agora vale 30
    
    // MATRIZ TRIDIMENSIONAL (3D)
    int matriz3D[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };
    
    printf("\nMATRIZ 3D:\n");
    printf("Elemento [0][0][0] (bloco 1, linha 1, col 1): %d\n", matriz3D[0][0][0]);   // 1
    printf("Elemento [0][1][2] (bloco 1, linha 2, col 3): %d\n", matriz3D[0][1][2]);   // 7
    printf("Elemento [1][2][3] (bloco 2, linha 3, col 4): %d\n", matriz3D[1][2][3]);   // 24
    
    // MATRIZ QUADRIDIMENSIONAL (4D)
    int matriz4D[2][2][2][2] = {{{{{1,2},{3,4}},{{5,6},{7,8}}},{{{9,10},{11,12}},{{13,14},{15,16}}}}};
    
    printf("\nMATRIZ 4D:\n");
    printf("Elemento [0][0][0][0]: %d\n", matriz4D[0][0][0][0]);   // 1
    printf("Elemento [1][0][1][1]: %d\n", matriz4D[1][0][1][1]);   // 12? (depende da inicialização)
    
    return 0;
}
```

## Percurso em Matriz

Para percorrer todos os elementos de uma matriz multidimensional, precisamos de uma estrutura de repetição para cada dimensão. O número de loops aninhados é igual ao número de dimensões. A ordem dos loops geralmente segue a ordem das dimensões, com o primeiro loop para a dimensão mais externa e o último para a mais interna.

```c
#include <stdio.h>

int main() {
    // PERCORRENDO MATRIZ BIDIMENSIONAL (2D)
    int matriz2D[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Matriz 2D (3x4):\n");
    for(int i = 0; i < 3; i++) {          // Percorre as linhas (dimensão 0)
        for(int j = 0; j < 4; j++) {      // Percorre as colunas (dimensão 1)
            printf("%3d ", matriz2D[i][j]);
        }
        printf("\n");
    }
    
    // PERCORRENDO MATRIZ TRIDIMENSIONAL (3D)
    int matriz3D[2][3][4];
    int contador = 1;
    
    // Preenchendo a matriz 3D
    for(int i = 0; i < 2; i++) {          // Blocos (dimensão 0)
        for(int j = 0; j < 3; j++) {      // Linhas (dimensão 1)
            for(int k = 0; k < 4; k++) {  // Colunas (dimensão 2)
                matriz3D[i][j][k] = contador++;
            }
        }
    }
    
    // Exibindo a matriz 3D
    printf("\nMatriz 3D (2x3x4):\n");
    for(int i = 0; i < 2; i++) {
        printf("Bloco %d:\n", i);
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                printf("%3d ", matriz3D[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // PERCORRENDO MATRIZ QUADRIDIMENSIONAL (4D)
    int matriz4D[2][2][3][2];
    contador = 1;
    
    // Preenchendo a matriz 4D
    for(int i = 0; i < 2; i++) {          // Dimensão 0
        for(int j = 0; j < 2; j++) {      // Dimensão 1
            for(int k = 0; k < 3; k++) {  // Dimensão 2
                for(int l = 0; l < 2; l++) { // Dimensão 3
                    matriz4D[i][j][k][l] = contador++;
                }
            }
        }
    }
    
    // Exibindo parcialmente a matriz 4D
    printf("\nMatriz 4D (2x2x3x2) - primeiros elementos:\n");
    printf("Elemento [0][0][0][0] = %d\n", matriz4D[0][0][0][0]);
    printf("Elemento [0][0][0][1] = %d\n", matriz4D[0][0][0][1]);
    printf("Elemento [0][0][1][0] = %d\n", matriz4D[0][0][1][0]);
    printf("Total de elementos: 2x2x3x2 = %d\n", contador-1);
    
    return 0;
}
```