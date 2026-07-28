# Alocação Dinâmica de Memória em C 


Em C, existem duas formas principais de alocar memória: estática e dinâmica

### Alocação Estática
A memória é alocada em tempo de compilação e permanece fixa durante toda a execução. A alocação ocorre an _stack_

Exemplo:
```c
int x = 10;
int v[5];
```

#### Características
- Alocação automática
- Ocorre no __stack__
- Tempo de vida limitado ao escopo
- Liberação automática
- Muito rápida

#### Vantagens
- Simples
- Sem vazamento de memória
- Melhor desempenho

#### Desvantagens
- Tamanho limitado
- Não cresce dinamicamente
- Não persiste fora da função

---

### Alocação Dinâmica
A memória é alocada em tempo de execução na _heap_.

Exemplo:
```c
#include <stdlib.h>

int *p = malloc(sizeof(int));
```

### Características
- Controlada manualmente
- Ocorre no __Heap__
- Persiste até `free`
- Flexível

### Vantagens
- Tamanho dinâmico
- Permite estruturas complexas

### Desvantagens
- Mais lenta
- Sujeita a erros (memory leak, segfault)

---

# Funções da Biblioteca stdlib.h
A biblioteca <stdlib.h> fornece 4 principais funções para lidarmos com alocação dinâmica de memória: malloc(), calloc(), realloc() e free().
A seguir, veremos cada uma delas.

## Função malloc() 
A função malloc (abreviatura de _memory allocation_) aloca size bytes de memória não inicializada.

Assinatura:
```c
void *malloc(size_t size);
```

### Características: 
- Aloca um bloco contínuo de memória
- NÃO inicializa (conteúdo = lixo)
- Retorna void* (precisa cast em C++)
- Retorna NULL se falhar

Exemplo:
```c
int *p = (int*)malloc(5 * sizeof(int));
if (p == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}
```

---

## Função calloc()
A função calloc (abreviatura de _contiguous allocation_) aloca memória para um vários elementos, cada um com o mesmo tamanho especificado.
Inicializa todos os bytes com zero.

Assinatura:
```c
void *calloc(size_t num, size_t size);
```
Exemplo:
```c
int *p = calloc(5, sizeof(int));
if (p == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}
```
### Características
- Inicializa todos os bytes com zero
- Pode ser mais lento que malloc (por inicializar)

---

## Função realloc()
A função realloc (abreviatura de _reallocation_) redimensiona memória já alocada.
Ela tenta expandir o bloco no mesmo endereço. Caso não consiga, ele aloca um novo bloco em outro endereço, copia os dados antigos e libera o bloco anterior automaticamente.

Assinatura:
```c
void *realloc(void *ptr, size_t new_size);
```
Exemplo:
```c
int *p = (int*)malloc(5 * sizeof(int));
if (p == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

int *temp = realloc(p, 10 * sizeof(int));
if (temp != NULL) {
    v = temp;
}
```

### Características
- Pode mover o bloco para outro endereço
- Mantém os dados antigos (até o limite)
- Pode crescer ou diminuir

---

## Função free()
A função free libera memória da heap.
Assinatura: 
```c
void free(void *ptr);
```

Exemplo: 
```c
free(p);
p = NULL;
```

### Características
- Não apaga dados, apenas marca como livre.
- Não altera automaticamente o ponteiro.
---

# Arrays Dinâmicos

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        v[i] = i * 2;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    free(v);
}
```

---

# Função realloc() na prática

```c
int *v = malloc(5 * sizeof(int));

int *temp = realloc(v, 10 * sizeof(int));
if (temp != NULL) {
    v = temp;
}
```

---

# Matrizes Dinâmicas

## Método 1

```c
int **mat = malloc(linhas * sizeof(int*));

for (int i = 0; i < linhas; i++) {
    mat[i] = malloc(colunas * sizeof(int));
}
```

## Liberação

```c
for (int i = 0; i < linhas; i++) {
    free(mat[i]);
}
free(mat);
```

---

## Método 2 (contíguo)

```c
int *mat = malloc(linhas * colunas * sizeof(int));

mat[i * colunas + j] = 10;
```

---

# Struct Dinâmica

```c
typedef struct {
    int id;
    float preco;
} Produto;

Produto *p = malloc(sizeof(Produto));
```

---

# Struct com String Dinâmica

```c
typedef struct {
    int id;
    char *nome;
} Produto;

Produto *p = malloc(sizeof(Produto));

p->nome = malloc(20);
strcpy(p->nome, "Notebook");
```

---

# Exemplo Completo

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *nome;
} Produto;

int main() {
    int n = 2;
    Produto *lista = malloc(n * sizeof(Produto));

    for (int i = 0; i < n; i++) {
        lista[i].id = i + 1;

        char temp[50];
        sprintf(temp, "Produto %d", i + 1);

        lista[i].nome = malloc(strlen(temp) + 1);
        strcpy(lista[i].nome, temp);
    }

    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", lista[i].id, lista[i].nome);
    }

    for (int i = 0; i < n; i++) {
        free(lista[i].nome);
    }

    free(lista);
}
```

---

# Erros Comuns

```c
int *p;
*p = 10; // ERRO
```

```c
free(p);
free(p); // double free
```

```c
free(p);
*p = 10; // uso após free
```

---

# Melhores Práticas e Segurança
Para garantir a integridade dos seus programas, siga estas diretrizes:

* Validação de Retorno: Sempre verifique se o ponteiro retornado pela alocação é NULL. O sistema pode estar sem memória disponível.

* Dangling Pointers: Após chamar free(ptr), o endereço contido em ptr torna-se inválido. Boas práticas ditam definir ptr = NULL; imediatamente após o free para evitar acessos acidentais.

* Segurança no Realloc: Nunca sobrescreva o ponteiro original diretamente com o retorno do realloc (ptr = realloc(ptr, size)). Se o realloc falhar, ele retorna NULL e você perde o endereço da memória original, causando um vazamento irreversível. Use um ponteiro auxiliar conforme mostrado no exemplo C.

* Cálculo de Tamanho: Utilize sempre o operador sizeof(tipo) em vez de valores numéricos fixos para garantir portabilidade entre arquiteturas (32-bit vs 64-bit).