# Algoritmos de Ordenação em C

---

# Introdução

Ordenar dados é uma das tarefas mais importantes da Computação.

Muitos algoritmos trabalham melhor quando os dados estão ordenados.

Exemplos:

- buscas;
- relatórios;
- bancos de dados;
- processamento de listas;
- sistemas de recomendação.

Os algoritmos de ordenação organizam elementos em uma determinada ordem:

- crescente;
- decrescente;
- alfabética;
- cronológica.

---

# O que são Algoritmos de Ordenação

Um algoritmo de ordenação reorganiza os elementos de uma estrutura de dados.

Exemplo:

Antes:

```text
8 3 1 9 5
```

Depois:

```text
1 3 5 8 9
```

---

# Critérios para Comparação

Os algoritmos de ordenação podem ser comparados por:

- complexidade de tempo;
- complexidade de espaço;
- estabilidade;
- simplicidade de implementação.

---

## Estabilidade

Um algoritmo é estável quando mantém a ordem relativa de elementos iguais.

Exemplo:

```text
(5,A) (3,B) (5,C)
```

Após ordenação estável:

```text
(3,B) (5,A) (5,C)
```

A ordem entre A e C foi preservada.

---

# Bubble Sort

## Ideia

O Bubble Sort compara elementos adjacentes e troca suas posições quando estão fora de ordem.

Os maiores elementos “borbulham” para o final do vetor.

---

## Funcionamento

Vetor:

```text
8 3 5 1
```

Passo 1:

```text
8 3 → troca
3 8 5 1
```

Passo 2:

```text
8 5 → troca
3 5 8 1
```

Passo 3:

```text
8 1 → troca
3 5 1 8
```

O maior elemento foi para o final.

---

## Implementação em C

```c
#include <stdio.h>

void bubble_sort(int v[], int n) {

    int i, j, temp;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - 1 - i; j++) {

            if(v[j] > v[j + 1]) {

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(n) * |
| Caso médio | O(n²) |
| Pior caso | O(n²) |
| Espaço auxiliar | O(1) |

\* considerando otimização com verificação de troca.

---

## Características

- simples;
- fácil de entender;
- pouco eficiente para grandes volumes de dados.

---

# Selection Sort

## Ideia

O Selection Sort procura o menor elemento e o coloca na posição correta.

---

## Funcionamento

Vetor:

```text
8 3 5 1
```

Menor elemento:

```text
1
```

Troca com a primeira posição:

```text
1 3 5 8
```

O processo continua para o restante do vetor.

---

## Implementação em C

```c
#include <stdio.h>

void selection_sort(int v[], int n) {

    int i, j, menor, temp;

    for(i = 0; i < n - 1; i++) {

        menor = i;

        for(j = i + 1; j < n; j++) {

            if(v[j] < v[menor]) {
                menor = j;
            }
        }

        temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(n²) |
| Caso médio | O(n²) |
| Pior caso | O(n²) |
| Espaço auxiliar | O(1) |

---

## Características

- simples;
- realiza poucas trocas;
- ainda é ineficiente para grandes conjuntos.

---

# Insertion Sort

## Ideia

O Insertion Sort funciona de forma semelhante à ordenação de cartas em uma mão.

Cada elemento é inserido na posição correta.

---

## Funcionamento

Vetor:

```text
8 3 5 1
```

Inserindo o 3:

```text
3 8 5 1
```

Inserindo o 5:

```text
3 5 8 1
```

Inserindo o 1:

```text
1 3 5 8
```

---

## Implementação em C

```c
#include <stdio.h>

void insertion_sort(int v[], int n) {

    int i, j, chave;

    for(i = 1; i < n; i++) {

        chave = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > chave) {

            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(n) |
| Caso médio | O(n²) |
| Pior caso | O(n²) |
| Espaço auxiliar | O(1) |

---

## Características

- eficiente para pequenos conjuntos;
- eficiente para listas quase ordenadas;
- simples de implementar.

---

# Merge Sort

## Ideia

O Merge Sort utiliza a estratégia de divisão e conquista.

O vetor é dividido em partes menores até possuir apenas um elemento.

Depois, as partes são intercaladas ordenadamente.

---

## Funcionamento

Vetor:

```text
8 3 5 1
```

Divisão:

```text
8 3 | 5 1
```

Novas divisões:

```text
8 | 3 | 5 | 1
```

Intercalação:

```text
3 8 | 1 5
```

Resultado final:

```text
1 3 5 8
```

---

## Implementação em C

### Função merge

```c
void merge(int v[], int inicio, int meio, int fim) {

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[fim - inicio + 1];

    while(i <= meio && j <= fim) {

        if(v[i] <= v[j]) {
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j++];
        }
    }

    while(i <= meio) {
        temp[k++] = v[i++];
    }

    while(j <= fim) {
        temp[k++] = v[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
    }
}
```

---

### Função merge_sort

```c
void merge_sort(int v[], int inicio, int fim) {

    if(inicio < fim) {

        int meio = (inicio + fim) / 2;

        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(n log n) |
| Caso médio | O(n log n) |
| Pior caso | O(n log n) |
| Espaço auxiliar | O(n) |

---

## Características

- muito eficiente;
- estável;
- utiliza memória auxiliar.

---

# Quick Sort

## Ideia

O Quick Sort escolhe um pivô e reorganiza o vetor.

Elementos menores ficam à esquerda.

Elementos maiores ficam à direita.

Depois, o processo é repetido recursivamente.

---

## Funcionamento

Vetor:

```text
8 3 5 1
```

Pivô:

```text
8
```

Particionamento:

```text
3 5 1 | 8
```

O processo continua nos subvetores.

---

## Implementação em C

### Função particionar

```c
int particionar(int v[], int inicio, int fim) {

    int pivo = v[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++) {

        if(v[j] < pivo) {

            i++;

            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}
```

---

### Função quick_sort

```c
void quick_sort(int v[], int inicio, int fim) {

    if(inicio < fim) {

        int pivo = particionar(v, inicio, fim);

        quick_sort(v, inicio, pivo - 1);
        quick_sort(v, pivo + 1, fim);
    }
}
```

---

## Complexidade

| Caso | Complexidade |
|---|---|
| Melhor caso | O(n log n) |
| Caso médio | O(n log n) |
| Pior caso | O(n²) |
| Espaço auxiliar | O(log n) |

---

## Características

- muito rápido na prática;
- amplamente utilizado;
- pior caso ocorre com pivôs ruins.

---

# Comparação entre os Algoritmos

| Algoritmo | Melhor Caso | Caso Médio | Pior Caso | Espaço |
|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
