# Structs em C

Em C, uma **struct (structure)** é um tipo de dado composto que permite
agrupar várias variáveis dentro de uma única estrutura lógica.

Uma `struct` é considerada uma **variável composta heterogênea**, pois
permite armazenar **dados de tipos diferentes** dentro de um mesmo
conjunto.

Exemplo de dados heterogêneos:

-   texto (`char`)
-   números inteiros (`int`)
-   números reais (`float`)

As `structs` são muito utilizadas para representar **entidades do mundo
real**, como alunos, produtos, funcionários, etc.

------------------------------------------------------------------------

### Definição de uma struct

Antes de usar uma `struct`, precisamos **definir seu formato**.

``` c
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;
```

Aqui estamos criando um **novo tipo de dado chamado `Aluno`**.

Esse tipo possui três campos:

-   `nome`
-   `idade`
-   `media`

------------------------------------------------------------------------

### Declaração de variáveis do tipo struct

Depois de definida a estrutura, podemos declarar variáveis desse tipo.

``` c
Aluno a1;
Aluno a2;
```

Cada variável possui seus próprios dados.

------------------------------------------------------------------------

### Declaração e inicialização

Podemos inicializar a struct no momento da declaração.

``` c
Aluno a1 = {"Maria", 20, 8.5};
```

Também é possível usar inicialização nomeada:

``` c
Aluno a2 = {.nome="João", .idade=21, .media=7.8};
```

------------------------------------------------------------------------

### Atribuição de valores usando operador ponto

Os campos de uma struct são acessados usando o **operador ponto (`.`)**.

``` c
Aluno a1;

a1.idade = 20;
a1.media = 8.5;
```

------------------------------------------------------------------------

### Leitura do teclado

Também podemos atribuir valores através da leitura do teclado.

``` c
Aluno a1;

printf("Nome: ");
fgets(a1.nome, sizeof(a1.nome), stdin);
a1.nome[strcspn(a1.nome, "\n")] = '\0';

printf("Idade: ");
scanf("%d", &a1.idade);

printf("Media: ");
scanf("%f", &a1.media);
```

------------------------------------------------------------------------

### Atribuição direta de structs

Em C é possível copiar uma struct inteira usando o operador `=`.

``` c
Aluno a1 = {"Maria", 20, 8.5};
Aluno a2;

a2 = a1;
```

Nesse caso **todos os campos são copiados automaticamente**.

Importante:

-   alterar `a1` **não altera `a2`**
-   alterar `a2` **não altera `a1`**

Ou seja, trata-se de **uma cópia independente**.

------------------------------------------------------------------------

# Array dentro de struct

Uma struct também pode possuir **arrays como campos**.

Isso é muito comum quando um registro precisa armazenar vários valores do mesmo tipo, como notas de um aluno.

``` c
typedef struct {
    char nome[50];
    int idade;
    float notas[3];
} Aluno;
```

### Declaração

``` c
Aluno a1;
```

### Inicialização

``` c
Aluno a1 = {"Maria", 20, {8.5, 9.0, 7.5}};
```

### Entrada de dados via teclado
Exemplo de leitura dos dados de um aluno:
```c
#include <stdio.h>
#include <string.h>

Aluno a1;

printf("Nome: ");
fgets(a1.nome, sizeof(a1.nome), stdin);
a1.nome[strcspn(a1.nome, "\n")] = '\0';

printf("Idade: ");
scanf("%d", &a1.idade);

printf("Digite as 3 notas:\n");

for(int i = 0; i < 3; i++){
    printf("Nota %d: ", i+1);
    scanf("%f", &a1.notas[i]);
}
```

### Acesso aos elementos
O acesso aos campos da struct ocorre com o operador ponto (.).

Para acessar o array, segue o padrão **variavel.campo[indice]**

``` c
strcpy(a1.nome,"Joaquim");
a1.idade = 20;
a1.notas[0] = 8.5;
a1.notas[1] = 9.0;
a1.notas[2] = 7.5;

printf("Nome: %s\n", a1.nome);
printf("Idade: %d\n", a1.idade);

for(int i = 0; i < 3; i++){
    printf("Nota %d: %.2f\n", i+1, a1.notas[i]);
}
```

------------------------------------------------------------------------

### Atribuição direta mesmo com array dentro da struct

Mesmo que exista um array dentro da struct, a atribuição direta continua
funcionando.

``` c
Aluno a1 = {"Maria", 20, {8,9,7}};
Aluno a2;

a2 = a1;
```

O compilador copia **todo o bloco de memória da struct**, incluindo o
array.

------------------------------------------------------------------------

# Array de structs

Também podemos criar **vetores de structs**.

### Declaração

``` c
Aluno alunos[5];
```

### Inicialização

``` c
Aluno alunos[2] = {
    {"Maria",20,{8,9,7}},
    {"João",21,{7,6,8}}
};
```

### Acesso aos dados

``` c
alunos[0].idade = 20;
alunos[1].notas[2] = 8.0;
```

Nesse caso:

-   `alunos[i]` representa um aluno
-   `alunos[i].campo` acessa um atributo do aluno

------------------------------------------------------------------------

# Structs aninhadas

Uma struct pode conter **outra struct dentro dela**.

### Definição

``` c
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[50];
    int numero;
} Endereco;

typedef struct {
    char nome[50];
    Data data_admissao;
    Endereco endereco;
} Funcionario;
```

------------------------------------------------------------------------

### Declaração

``` c
Funcionario f1;
```

------------------------------------------------------------------------

### Inicialização

``` c
Funcionario f1 = {
    "Maria",
    {10, 3, 2024},
    {"Rua A", 123}
};
```

------------------------------------------------------------------------

### Acesso aos campos

Quando temos structs aninhadas, usamos vários operadores ponto.

``` c
f1.data_admissao.ano = 2025;
f1.endereco.numero = 200;
```
------------------------------------------------------------------------

### Leitura de dados via teclado

``` c
Funcionario f;

printf("Nome do funcionario: ");
fgets(f.nome, sizeof(f.nome), stdin);
f.nome[strcspn(f.nome, "\n")] = '\0';

printf("\nData de admissao\n");

printf("Dia: ");
scanf("%d", &f.data_admissao.dia);

printf("Mes: ");
scanf("%d", &f.data_admissao.mes);

printf("Ano: ");
scanf("%d", &f.data_admissao.ano);

while(getchar()!='\n'); // limpa o \n do buffer

printf("\nEndereco\n");

printf("Rua: ");
fgets(f.endereco.rua, sizeof(f.endereco.rua), stdin);
f.endereco.rua[strcspn(f.endereco.rua, "\n")] = '\0';

printf("Numero: ");
scanf("%d", &f.endereco.numero);

printf("\n--- Dados do Funcionario ---\n");

printf("Nome: %s\n", f.nome);

printf("Data de admissao: %02d/%02d/%d\n",
       f.data_admissao.dia,
       f.data_admissao.mes,
       f.data_admissao.ano);

printf("Endereco: %s, %d\n",
       f.endereco.rua,
       f.endereco.numero);
```