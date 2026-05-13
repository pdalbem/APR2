# Algoritmos de Busca em C

---

# Introdução

Buscar informações é uma das operações mais importantes da Computação.

Sistemas de:

- bancos de dados;
- redes sociais;
- comércio eletrônico;
- bibliotecas;
- sistemas operacionais;
- aplicativos de mensagens;

realizam buscas constantemente.

Os algoritmos de busca permitem localizar elementos dentro de estruturas de dados.

---

# O que são Algoritmos de Busca

Um algoritmo de busca tenta localizar um elemento dentro de uma coleção de dados.

Exemplo:

Vetor:

```text
8 3 5 1 9
```

Buscar o valor:

```text
5
```

Resultado:

```text
Encontrado na posição 2
```

---

# Busca Linear (Sequencial)

## Ideia

A Busca Linear percorre os elementos um por um até encontrar o valor desejado.

---

## Funcionamento

Vetor:

```text
8 3 5 1 9
```

Buscando o valor:

```text
1
```

Comparações:

```text
8 → não
3 → não
5 → não
1 → encontrado
```

---

## Características

- simples;
- funciona em vetores ordenados ou não ordenados;
- pode ser lenta para grandes volumes de dados.

---

## Implementação em C

```c
#include <stdio.h>

int busca_linear(int v[], int n, int valor) {

    for(int i = 0; i < n; i++) 
        if(v[i] == valor) 
            return i;
        
    return -1;
}
```

---

## Exemplo de Uso

```c
#include <stdio.h>

int busca_linear(int v[], int n, int valor);

int main() {

    int v[] = {8, 3, 5, 1, 9};

    int posicao = busca_linear(v, 5, 1);

    if(posicao != -1)
        printf("Valor encontrado na posição %d\n", posicao);
    else
        printf("Valor não encontrado\n");

    return 0;
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(1) |
| Caso médio | O(n) |
| Pior caso | O(n) |
| Espaço auxiliar | O(1) |

---

## Melhor Caso

O elemento está logo na primeira posição.

---

## Pior Caso

O elemento está:

- na última posição;
- ou não existe.

---

# Busca Binária

## Ideia

A Busca Binária divide o problema pela metade a cada passo.

Ela só funciona em vetores ordenados.

---

## Funcionamento

Vetor ordenado:

```text
1 3 5 8 9 12 15
```

Buscar:

```text
8
```

Elemento central:

```text
8
```

Valor encontrado imediatamente.

---

## Outro Exemplo

Buscar:

```text
3
```

Passo 1:

```text
Meio = 8
```

Como:

```text
3 < 8
```

Busca apenas na metade esquerda.

Novo vetor considerado:

```text
1 3 5
```

Novo meio:

```text
3
```

Elemento encontrado.

---

## Características

- muito eficiente;
- reduz o problema pela metade;
- exige vetor ordenado.

---

## Implementação Iterativa em C

```c
#include <stdio.h>

int busca_binaria(int v[], int n, int valor) {

    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if(v[meio] == valor) {
            return meio;
        }

        if(valor < v[meio]) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    return -1;
}
```

---

## Exemplo de Uso

```c
#include <stdio.h>

int busca_binaria(int v[], int n, int valor);

int main() {

    int v[] = {1, 3, 5, 8, 9, 12, 15};

    int posicao = busca_binaria(v, 7, 9);

    if(posicao != -1)
        printf("Valor encontrado na posição %d\n", posicao);
    else
        printf("Valor não encontrado\n");

    return 0;
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(1) |
| Caso médio | O(log n) |
| Pior caso | O(log n) |
| Espaço auxiliar | O(1) |

---

## Por que O(log n)?

A cada etapa, metade do vetor é descartada.

Exemplo:

```text
n
n/2
n/4
n/8
...
```

O número de divisões até chegar a 1 elemento é:

```text
log₂ n
```

---

# Busca Binária Recursiva

## Implementação em C

```c
int busca_binaria_recursiva(int v[], int inicio, int fim, int valor) {

    if(inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;

    if(v[meio] == valor)
        return meio;

    if(valor < v[meio]) {
        return busca_binaria_recursiva(v, inicio, meio - 1, valor);
    }

    return busca_binaria_recursiva(v, meio + 1, fim, valor);
}
```

---

## Complexidade

| Tipo | Complexidade |
|---|---|
| Tempo | O(log n) |
| Espaço | O(log n) |

---

## Espaço na versão recursiva

A versão recursiva utiliza pilha de chamadas.

A profundidade da recursão é proporcional a:

```text
log n
```

---

# Comparação entre os Algoritmos

| Algoritmo | Vetor Ordenado? | Melhor Caso | Pior Caso | Caso Médio |
|---|---|---|---|---|
| Busca Linear | Não | O(1) | O(n) | O(n) |
| Busca Binária | Sim | O(1) | O(log n) | O(log n) |

---

# Busca em Vetores Ordenados e Não Ordenados

## Vetor Não Ordenado

Exemplo:

```text
8 2 9 1 5
```

A Busca Binária não funciona corretamente.

Deve-se utilizar:

```text
Busca Linear
```

---

## Vetor Ordenado

Exemplo:

```text
1 2 5 8 9
```

Pode-se utilizar:

```text
Busca Binária
```

Obtendo desempenho muito melhor.

---

# Melhor Caso, Pior Caso e Caso Médio

---

## Busca Linear

### Melhor Caso

Elemento na primeira posição.

```text
O(1)
```

### Pior Caso

Elemento na última posição ou inexistente.

```text
O(n)
```

### Caso Médio

```text
O(n)
```

---

## Busca Binária

### Melhor Caso

Elemento no meio.

```text
O(1)
```

### Pior Caso

Necessidade de várias divisões.

```text
O(log n)
```

### Caso Médio

```text
O(log n)
```

---

# Comparação Prática

Considere:

```text
1.000.000 elementos
```

---

## Busca Linear

Pode precisar verificar:

```text
1.000.000 elementos
```

---

## Busca Binária

Aproximadamente:

```text
20 comparações
```

Pois:

```text
log₂(1.000.000) ≈ 20
```

---

# Vantagens e Desvantagens

## Busca Linear

### Vantagens

- simples;
- funciona em qualquer vetor.

### Desvantagens

- lenta para grandes conjuntos.

---

## Busca Binária

### Vantagens

- extremamente eficiente.

### Desvantagens

- exige vetor ordenado.

---