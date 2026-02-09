# Estruturas de Repetição em C

As **estruturas de repetição** (ou *laços de repetição*) permitem executar um mesmo bloco de código **várias vezes**, de acordo com uma condição. Elas são essenciais para automatizar tarefas repetitivas e trabalhar com conjuntos de dados, como vetores e matrizes.

Em C, existem três estruturas de repetição principais:

- `while`
- `do ... while`
- `for`

---

## 1. Estrutura `while`

O laço `while` executa um bloco de código **enquanto a condição for verdadeira**. A condição é verificada **antes** da execução do bloco.

### Sintaxe:
```c
while (condicao) {
    // código executado enquanto a condição for verdadeira
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int i = 1;

    while (i <= 5) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

> Se a condição for falsa logo no início, o bloco não será executado nenhuma vez.

---

## 2. Estrutura `do ... while`

A estrutura `do ... while` é semelhante ao `while`, porém a condição é testada **após** a execução do bloco. Isso garante que o código seja executado **ao menos uma vez**.

### Sintaxe:
```c
do {
    // código
} while (condicao);
```

> Observe o ponto e vírgula `;` após o `while`.

### Exemplo:
```c
#include <stdio.h>

int main() {
    int i = 1;

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    return 0;
}
```

---

## 3. Estrutura `for`

O laço `for` é geralmente utilizado quando se conhece previamente a **quantidade de repetições**. Ele reúne, em uma única linha, a inicialização, a condição e o incremento.

### Sintaxe:
```c
for (inicializacao; condicao; incremento) {
    // código
}
```

### Exemplo:
```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

---

## 4. Uso de `break` e `continue`

### Comando `break`

O comando `break` interrompe **imediatamente** a execução do laço.

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            break;
        }
        printf("%d ", i);
    }

    return 0;
}
```

> Saída: `1 2 3 4`

---

### Comando `continue`

O comando `continue` interrompe apenas a **iteração atual**, passando para a próxima repetição do laço.

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}
```

> Saída: `1 2 4 5`

---

## 5. Laços Aninhados

É possível utilizar um laço dentro de outro. Essa técnica é conhecida como **laços aninhados** e é muito comum no uso de matrizes.

### Exemplo:
```c
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 6. Laços Infinitos

Um laço infinito ocorre quando a condição de parada **nunca se torna falsa**.

### Exemplo:
```c
while (1) {
    printf("Loop infinito\n");
}
```

> Esse tipo de laço pode ser útil em sistemas embarcados ou servidores, mas deve ser usado com cuidado.

---

## 7. Comparação entre as Estruturas de Repetição

| Estrutura | Quando utilizar |
|---------|----------------|
| `while` | Quando não se sabe o número exato de repetições |
| `do ... while` | Quando o bloco deve ser executado ao menos uma vez |
| `for` | Quando o número de repetições é conhecido |

---

## 8. Boas Práticas

- Garanta que a condição do laço possa se tornar falsa
- Evite laços muito longos ou difíceis de entender
- Utilize indentação para melhorar a legibilidade
- Prefira `for` para percorrer vetores e matrizes

---

## 9. Conclusão

As estruturas de repetição são fundamentais para a construção de programas eficientes em C. O domínio desses laços permite escrever códigos mais organizados, reutilizáveis e fáceis de m