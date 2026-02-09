# Estruturas de Decisão em C

As **estruturas de decisão** permitem que um programa em C execute diferentes blocos de código de acordo com o resultado de uma **condição lógica**. Essas condições são avaliadas como **verdadeiras (1)** ou **falsas (0)**.

Em C, as principais estruturas de decisão são:

- `if`
- `if ... else`
- `if ... else if ... else`
- `switch ... case`
- Operador condicional (ternário)

---

## 1. Estrutura `if`

A estrutura `if` executa um bloco de código **somente se a condição for verdadeira**.

### Sintaxe:
```c
if (condicao) {
    // código executado se a condição for verdadeira
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int idade = 20;

    if (idade >= 18) {
        printf("Maior de idade\n");
    }

    return 0;
}
```

---

## 2. Estrutura `if ... else`

Utilizada quando existem **duas possibilidades**: uma para a condição verdadeira e outra para a falsa.

### Sintaxe:
```c
if (condicao) {
    // condição verdadeira
} else {
    // condição falsa
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int numero = 7;

    if (numero % 2 == 0) {
        printf("Numero par\n");
    } else {
        printf("Numero impar\n");
    }

    return 0;
}
```

---

## 3. Estrutura `if ... else if ... else`

Essa estrutura é usada quando há **mais de duas condições possíveis**.

### Sintaxe:
```c
if (condicao1) {
    // código
} else if (condicao2) {
    // código
} else {
    // código padrão
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    float nota;

    printf("Digite a nota: ");
    scanf("%f", &nota);

    if (nota >= 7.0) {
        printf("Aprovado\n");
    } else if (nota >= 5.0) {
        printf("Recuperacao\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
```

> As condições são avaliadas **de cima para baixo**, e apenas **um bloco** será executado.

---

## 4. Operadores Relacionais e Lógicos

### Operadores relacionais

| Operador | Significado |
|--------|-------------|
| `>` | maior que |
| `<` | menor que |
| `>=` | maior ou igual |
| `<=` | menor ou igual |
| `==` | igual |
| `!=` | diferente |

### Operadores lógicos

| Operador | Significado |
|---------|-------------|
| `&&` | E (AND) |
| `||` | OU (OR) |
| `!` | NÃO (NOT) |

### Exemplo:
```c
#include <stdio.h>

int main() {
    int idade = 25;

    if (idade >= 18 && idade <= 65) {
        printf("Idade dentro da faixa permitida\n");
    }

    return 0;
}
```

---

## 5. Estrutura `switch ... case`

A estrutura `switch` é usada quando se deseja comparar **uma única variável** com **valores constantes**.

### Sintaxe:
```c
switch (expressao) {
    case valor1:
        // código
        break;
    case valor2:
        // código
        break;
    default:
        // código
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int opcao;

    printf("1 - Cadastrar\n");
    printf("2 - Alterar\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Opcao Cadastrar\n");
            break;
        case 2:
            printf("Opcao Alterar\n");
            break;
        case 3:
            printf("Opcao Sair\n");
            break;
        default:
            printf("Opcao invalida\n");
    }

    return 0;
}
```

> O comando `break` evita o **efeito de queda** (*fall-through*) entre os `case`.

---

## 6. Operador Condicional (Ternário)

O operador ternário é uma forma **simplificada** de escrever um `if ... else`.

### Sintaxe:
```c
condicao ? valor_se_verdadeiro : valor_se_falso;
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int idade = 16;

    printf("%s\n", idade >= 18 ? "Maior de idade" : "Menor de idade");

    return 0;
}
```

---

## 7. Boas Práticas

- Utilize chaves `{}` mesmo para blocos com uma única instrução
- Evite condições excessivamente longas
- Use `switch` quando houver muitas comparações com valores fixos
- Mantenha o código bem indentado para facilitar a leitura

---

## 8. Conclusão

As estruturas de decisão são fundamentais para o controle do fluxo de execução de um programa em C. O uso adequado dessas estruturas torna o código mais claro, organizado e eficiente.

