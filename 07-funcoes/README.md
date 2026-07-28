# Funções em C


## Introdução

Muitas vezes, ao escrever um programa, precisamos repetir o mesmo trecho de código (algoritmo) para entradas diferentes.

Consequentemente:

- fica difícil manter a consistência caso o algoritmo mude  
- o código fica extenso e confuso  
- a manutenção se torna mais difícil  

---

### Exemplo de código repetitivo

```c
#include <stdio.h>

int main() {
    float nota1, nota2, media;

    printf("**************************\n");
    printf("*** Inicio do programa ***\n");
    printf("**************************\n");

    printf("Digite a primeira nota: ");
    do {
        scanf("%f", &nota1);
        if (nota1 < 0 || nota1 > 10) {
            printf("Nota invalida. Digite novamente: ");
        }
    } while (nota1 < 0 || nota1 > 10);

    printf("Digite a segunda nota: ");
    do {
        scanf("%f", &nota2);
        if (nota2 < 0 || nota2 > 10) {
            printf("Nota invalida. Digite novamente: ");
        }
    } while (nota2 < 0 || nota2 > 10);

    media = (nota1 + nota2) / 2;
    printf("Media: %.2f\n", media);

    if (media >= 6) {
        printf("Aprovado\n");
    } else if (media >= 4) {
        printf("IFA\n");
    } else {
        printf("Reprovado\n");
    }

    printf("**************************\n");
    printf("**** Fim do programa *****\n");
    printf("**************************\n");

    return 0;
}
```

---

## Modularização

Modularizar significa dividir um programa grande em partes menores e independentes. Cada parte (módulo) resolve uma tarefa específica.

Benefícios da modularização:

* Reduz a complexidade do programa

* Torna o código mais compreensível

* Facilita a manutenção e correção de erros

* Permite reutilizar código em diferentes partes

As *funções* são a principal ferramenta para modularizar programas em C.



---


## Estrutura geral de uma função

```c
tipo_retorno nome_funcao(lista_de_parametros) {
    // corpo da função
    return valor; // opcional
}
```

### Exemplo

```c
int somar(int a, int b) {
    return a + b;
}
```

## Tipos de funções

As funções podem ser classificadas conforme combinam **parâmetros** e **retorno**.

A combinação desses dois aspectos dá origem a **quatro tipos de funções**, cada uma com um propósito específico dentro do programa.

De forma geral:

Funções sem parâmetros são utilizadas quando não é necessário receber dados externos

Funções com parâmetros permitem trabalhar com diferentes valores, tornando o código mais flexível

Funções sem retorno são usadas para executar ações (como imprimir ou exibir informações)

Funções com retorno são utilizadas quando é necessário produzir e devolver um resultado


Assim, cada tipo de função atende a uma necessidade diferente, e saber quando usar cada um deles é fundamental para escrever programas bem estruturados.

### Sem retorno e sem parâmetros

Executa uma tarefa simples, sem receber ou devolver dados.

```c
void mostrarMenu() {
    printf("1 - Opcao 1\n");
    printf("2 - Opcao 2\n");
    printf("3 - Sair\n");
}

int main() {
    mostrarMenu();
    return 0;
}
```

---

### Sem retorno e com parâmetros

Recebe dados para processar, mas não devolve resultado.

```c
void imprimirMensagem(char texto[]) {
    printf("Mensagem: %s\n", texto);
}

void imprimirSoma(int a, int b) {
    printf("Soma = %d\n", a + b);
}

int main() {
    imprimirMensagem("Ola, seja bem-vindo!");
    imprimirSoma(2, 3);

    return 0;
}
```

---

### Com retorno e sem parâmetros

Devolve um valor obtido internamente.


```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumero() {
    return rand() % 100; // número entre 0 e 99
}

int main() {
    srand(time(NULL)); // inicializa a semente

    int numero = gerarNumero();
    printf("Numero gerado: %d\n", numero);

    return 0;
}
```


---

### Com retorno e com parâmetros

Recebe dados, processa e devolve um resultado.


```c
int somar(int a, int b) {
    return a + b;
}

int main() {
    int r = somar(4, 5);
    return 0;
}
```

---

## Refatorando o exemplo inicial
Vamos transformar o código repetitivo em um programa modular com funções.

```c
float lerNotaValida() {
    float nota;
    do {
        scanf("%f", &nota);
        if (nota < 0 || nota > 10) {
            printf("Nota invalida. Digite novamente: ");
        }
    } while (nota < 0 || nota > 10);
    return nota;
}

float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2;
}

void exibirSituacao(float media) {
    if (media >= 6) {
        printf("Aprovado\n");
    } else if (media >= 4) {
        printf("IFA\n");
    } else {
        printf("Reprovado\n");
    }
}

void imprimirMensagem(char texto[]) {
    printf("**************************\n");
    printf("*** %s ***\n", texto);
    printf("**************************\n");
}

int main() {
    float nota1, nota2, media;

    imprimirMensagem("Inicio do programa");

    printf("Digite a primeira nota: ");
    nota1 = lerNotaValida();

    printf("Digite a segunda nota: ");
    nota2 = lerNotaValida();

    media = calcularMedia(nota1, nota2);
    printf("Media: %.2f\n", media);
    exibirSituacao(media);

    imprimirMensagem("Fim do programa");

    return 0;
}
```



## Protótipo de função



O compilador C lê o código de cima para baixo. Quando encontra uma chamada de função, ele precisa saber:

* Se a função existe

* Qual tipo de valor ela retorna

* Quantos e quais tipos de parâmetros espera

Sem essa informação, o compilador não consegue verificar se a função está sendo usada corretamente.

### O problema

```c
#include <stdio.h>

int main() {
    int resultado = somar(5, 3); // ERRO! Função não declarada
    exibirResultado(resultado); //ERRO Função não declarada
    return 0;
}

int somar(int a, int b) {
    return a + b;
}

void exibirResultado(int valor) {
    printf("Resultado: %d\n", valor);
}
```
Erro: O compilador encontra somar(5, 3) mas ainda não "viu" a função. O mesmo ocorre com a chamada para a função exibirResultado(resultado).

Existem 2 soluções para este problema.

A primeira consiste em implementar a função antes de usá-la, como nos exemplos anteriores.

Já a segunda solução consiste em usar **protótipo de função**.
O protótipo de uma função é uma declaração antecipada que informa ao compilador: o nome da função, o tipo de retorno
e os tipos dos parâmetros.

```c
#include <stdio.h>

// Protótipos
int somar(int a, int b);
void exibirResultado(int valor);

int main() {
    int resultado = somar(5, 3);
    exibirResultado(resultado);
    return 0;
}

// Implementações
int somar(int a, int b) {
    return a + b;
}

void exibirResultado(int valor) {
    printf("Resultado: %d\n", valor);
}
```

### Benefícios dos protótipos
1. Organização do código
Permite colocar as implementações depois do main, deixando a lógica principal no início.

2. Verificação de tipos pelo compilador
O compilador verifica se você está usando a função corretamente.

3. Facilita trabalho com múltiplos arquivos
Em projetos grandes, os protótipos vão para arquivos .h (cabeçalho).

4. Documentação implícita
Os protótipos funcionam como uma documentação rápida das funções disponíveis

---

## Arrays como parâmetros

Em C, é possível passar vetores (arrays unidimensionais) e matrizes (arrays multidimensionais) como parâmetros para funções.

Para passar um vetor como parâmetro, precisamos informar o vetor e seu tamanho, pois a função não sabe quantos elementos o vetor possui.

```c
#include <stdio.h>

void exibirVetor(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};

    exibirVetor(numeros, 5);

    return 0;
}
```

Ao passar matrizes, é possível omitir a primeira dimensão.
O número de linhas pode ser passado como parâmetro.

```c
#include <stdio.h>

void exibirMatriz(int m[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    exibirMatriz(matriz, 2);

    return 0;
}
```

## Struct como parâmetro

Também podemos passar estruturas (struct) como parâmetro para funções.

```c
#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float notas[3];
} Aluno;

void exibirAluno(Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);

    printf("Notas: ");
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", a.notas[i]);
    }
    printf("\n");
}

int main() {
    Aluno aluno = {"Ana", 20, {7.5, 8.0, 6.5}};

    exibirAluno(aluno);

    return 0;
}
```
## Mais sobre passagem de parâmetros


Na linguagem C, a forma como os dados entram em uma função define como o programa gerencia a memória e a segurança das variáveis. 
Existem duas formas principais de realizar essa comunicação:
1. Passagem por Valor (O Padrão do C)
2. Passagem por Referência (Simulada com Ponteiros)

### Passagem por valor

Na passagem por valor, a função recebe uma cópia dos dados. Isso significa que alterações dentro da função não afetam a variável original.

Esse comportamento se aplica aos tipos primitivos (int, float, double, char) e a struct.

```c
#include <stdio.h>

void alterar(int x) {
    x = 100;
}

int main() {
    int a = 10;

    alterar(a);

    printf("a = %d\n", a); // continua 10

    return 0;
}
```

A struct também é copiada, incluindo todos os seus campos.

```c
#include <stdio.h>

typedef struct {
   char nome[50];
   int idade;
   float notas[3];
}Aluno;

void alterarIdade(Aluno a) {  
    a.idade++; // a.idade vale 21 (só na cópia)
}

int main(){
   Aluno aluno1 = {"João Silva", 20, {7.5, 8.0, 9.2}};
   alterarIdade(aluno1);
   printf(“%d”, aluno1.idade) //Ainda mostra 20  
   return 0;
}
```

### Como alterar usando passagem por valor?
A única forma de modificar o original com passagem por valor é retornar o valor modificado e atribuir à variável original:

```c
#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float notas[3];
} Aluno;

// Função que recebe cópia, modifica e RETORNA
Aluno fazerAniversario(Aluno a) {
    a.idade++;
    return a;  // Retorna a cópia modificada
}

int main() {
    Aluno aluno = {"João", 20, {7.5, 8.0, 9.2}};
    
    printf("Antes: %d\n", aluno.idade);
    aluno = fazerAniversario(aluno);  // Atribui o retorno
    printf("Depois: %d\n", aluno.idade);  // Agora é 21!
    
    return 0;
}
```

### Arrays (comportamento diferente)

Ao trabalhar com arrays (vetores e matrizes) em funções, o comportamento do C muda drasticamente. Arrays nunca são copiados. A função recebe o endereço de memória e trabalha diretamente com o array original.

Logo, qualquer alteração no array dentro da função será refletida no original. 
(Esse comportamento será melhor compreendido ao estudar ponteiros.)

```c
#include <stdio.h>

void alterarVetor(int v[]) {
    v[0] = 100;
}

int main() {
    int numeros[3] = {1, 2, 3};

    alterarVetor(numeros);

    printf("%d\n", numeros[0]); // agora é 100

    return 0;
}
```