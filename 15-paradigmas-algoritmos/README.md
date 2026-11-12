# Paradigmas de Projeto de Algoritmos

## 1. Introdução

Um algoritmo é uma sequência finita e organizada de instruções utilizada para resolver um determinado problema.

Entretanto, um mesmo problema pode ser resolvido de diferentes maneiras. Algumas soluções são mais simples de implementar, enquanto outras podem apresentar melhor desempenho, principalmente quando trabalhamos com grandes volumes de dados.

Os **paradigmas de projeto de algoritmos** são estratégias gerais utilizadas para desenvolver soluções computacionais. Cada paradigma apresenta uma maneira particular de decompor, organizar e resolver problemas.

Conhecer esses paradigmas permite ao programador escolher abordagens mais adequadas, considerando fatores como:

- Complexidade temporal;
- Consumo de memória;
- Facilidade de implementação;
- Clareza e manutenção do código;
- Características do problema.

Neste material, estudaremos cinco paradigmas importantes:

1. Força bruta (*Brute Force*);
2. Divisão e conquista (*Divide and Conquer*);
3. Algoritmos gulosos (*Greedy Algorithms*);
4. Programação dinâmica (*Dynamic Programming*);
5. Retrocesso (*Backtracking*).

---

## 2. Força Bruta (Brute Force)

A força bruta é uma das estratégias mais simples de desenvolvimento de algoritmos. Consiste em experimentar sistematicamente todas as possibilidades ou percorrer os elementos disponíveis até encontrar uma solução.

Em geral, não utiliza estratégias sofisticadas para reduzir o espaço de busca.

### Exemplo: encontrar um elemento em um vetor

Considere um vetor com 100 números inteiros. Desejamos verificar se determinado número está presente.

Uma solução por força bruta consiste em percorrer o vetor, elemento por elemento, até encontrar o valor procurado ou chegar ao final.

```c
int buscar(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            return i;
        }
    }

    return -1;
}
```

**Complexidade:**

- Melhor caso: O(1), quando o elemento está na primeira posição.
- Pior caso: O(n), quando o elemento está na última posição ou não existe.

### Quando utilizar?

- Quando o conjunto de possibilidades é pequeno;
- Quando a simplicidade é mais importante que o desempenho;
- Quando não existe uma estratégia conhecida que reduza significativamente a busca;
- Como primeira solução para compreender um problema.

### Outro exemplo: problema dos dois números

Considere um vetor de inteiros e um valor `soma`. Desejamos encontrar dois elementos cuja soma seja igual ao valor informado.

Uma solução por força bruta utiliza dois laços de repetição:

```c
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (v[i] + v[j] == soma) {
            printf("%d e %d\n", v[i], v[j]);
        }
    }
}
```

Nesse caso, a complexidade no pior caso é O(n²).

---

## 3. Divisão e Conquista (Divide and Conquer)

O paradigma de divisão e conquista consiste em dividir um problema maior em problemas menores, resolver cada um deles e combinar os resultados para obter a solução do problema original.

Geralmente, apresenta três etapas:

1. **Dividir:** separar o problema original em subproblemas menores.
2. **Conquistar:** resolver os subproblemas, frequentemente utilizando recursividade.
3. **Combinar:** reunir os resultados para produzir a solução final.

### Exemplo: busca binária

Considere um vetor ordenado e o objetivo de encontrar determinado elemento.

Em vez de verificar todos os elementos, a busca binária compara o valor procurado com o elemento central do vetor.

- Se forem iguais, a busca termina.
- Se o valor procurado for menor, continua na metade esquerda.
- Se for maior, continua na metade direita.

Esse processo se repete até encontrar o elemento ou esgotar o intervalo de busca.

```c
int buscaBinaria(int v[], int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (v[meio] == valor) {
        return meio;
    }

    if (valor < v[meio]) {
        return buscaBinaria(v, inicio, meio - 1, valor);
    }

    return buscaBinaria(v, meio + 1, fim, valor);
}
```

**Complexidade:** O(log n).

Observe que, a cada chamada, o algoritmo descarta aproximadamente metade dos elementos restantes.

### Exemplo: Merge Sort

O Merge Sort é um algoritmo de ordenação baseado em divisão e conquista.

Seu funcionamento pode ser resumido em três etapas:

1. Divide o vetor em duas metades;
2. Ordena recursivamente cada metade;
3. Combina as duas metades ordenadas.

**Complexidade:** O(n log n).

### Quando utilizar?

- Quando o problema pode ser dividido em subproblemas menores;
- Quando os subproblemas podem ser resolvidos independentemente;
- Quando a combinação dos resultados é viável;
- Quando a divisão reduz significativamente o tamanho do problema.

---

## 4. Algoritmos Gulosos (Greedy Algorithms)

Um algoritmo guloso resolve um problema tomando, em cada etapa, a decisão que parece ser a melhor naquele momento.

A estratégia é escolher a alternativa localmente mais vantajosa, esperando que a sequência dessas escolhas produza uma solução globalmente ótima.

Uma característica importante é que, normalmente, as decisões tomadas não são desfeitas.

### Exemplo: problema do troco

Imagine que precisamos devolver R$ 36,00 utilizando o menor número possível de moedas e cédulas.

Considere as denominações:

- R$ 20,00;
- R$ 10,00;
- R$ 5,00;
- R$ 1,00.

O algoritmo guloso escolhe sempre a maior denominação possível.

| Etapa | Escolha | Valor restante |
|---|---:|---:|
| 1 | R$ 20,00 | R$ 16,00 |
| 2 | R$ 10,00 | R$ 6,00 |
| 3 | R$ 5,00 | R$ 1,00 |
| 4 | R$ 1,00 | R$ 0,00 |

Resultado: quatro cédulas/moedas.

Uma implementação simplificada em C:

```c
int moedas[] = {20, 10, 5, 1};
int quantidade = 0;
int valor = 36;

for (int i = 0; i < 4; i++) {
    quantidade += valor / moedas[i];
    valor %= moedas[i];
}

printf("Quantidade: %d\n", quantidade);
```

### Atenção: nem sempre a estratégia gulosa funciona!

Considere agora as denominações:

- R$ 1,00;
- R$ 3,00;
- R$ 4,00.

Precisamos devolver R$ 6,00.

A estratégia gulosa escolhe:

- R$ 4,00;
- R$ 1,00;
- R$ 1,00.

Total: três moedas.

Entretanto, a solução ótima é:

- R$ 3,00;
- R$ 3,00.

Total: duas moedas.

Portanto, a escolha localmente melhor nem sempre conduz à solução globalmente ótima.

### Quando utilizar?

O paradigma guloso é adequado quando o problema apresenta propriedades que garantem que as escolhas locais levam a uma solução global ótima.

Alguns exemplos conhecidos:

- Seleção de atividades;
- Algoritmo de Kruskal;
- Algoritmo de Prim;
- Algoritmo de Dijkstra, para grafos com pesos não negativos;
- Problemas de escalonamento.

---

## 5. Programação Dinâmica (Dynamic Programming)

A programação dinâmica é uma estratégia utilizada para resolver problemas que podem ser decompostos em subproblemas menores que se repetem.

Em vez de resolver várias vezes os mesmos subproblemas, o algoritmo armazena os resultados já calculados para reutilizá-los posteriormente.

Dessa forma, evita cálculos redundantes e pode reduzir significativamente a complexidade temporal.

Existem duas abordagens comuns:

- **Memoização (Top-Down):** utiliza recursividade e armazena os resultados dos subproblemas já resolvidos.
- **Tabulação (Bottom-Up):** resolve os subproblemas menores primeiro, armazenando os resultados em uma estrutura, geralmente um vetor ou matriz.

### Exemplo: sequência de Fibonacci

A sequência de Fibonacci é definida da seguinte maneira:

F(0) = 0

F(1) = 1

F(n) = F(n-1) + F(n-2), para n ≥ 2.

Uma implementação recursiva simples:

```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

Embora simples, essa implementação apresenta muitas chamadas repetidas.

Por exemplo, para calcular F(5), o algoritmo calcula F(3) mais de uma vez, F(2) várias vezes etc.

Sua complexidade temporal é O(2ⁿ), como limite superior.

### Solução com programação dinâmica

Podemos armazenar os resultados anteriores em um vetor:

```c
int fibonacci(int n) {
    int f[n + 1];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
```

**Complexidade:**

- Tempo: O(n);
- Espaço: O(n).

Observe que cada posição do vetor é calculada apenas uma vez.

Uma implementação ainda mais econômica poderia utilizar somente duas variáveis auxiliares, reduzindo o consumo de memória para O(1).

### Quando utilizar?

- Quando existem subproblemas sobrepostos;
- Quando os resultados intermediários podem ser armazenados;
- Quando uma solução recursiva simples apresenta cálculos repetidos;
- Quando desejamos otimizar problemas de contagem, combinação ou otimização.

Outros exemplos conhecidos:

- Problema da mochila (*Knapsack Problem*);
- Maior subsequência comum (*Longest Common Subsequence*);
- Caminhos mínimos em determinadas estruturas;
- Distância de edição entre strings.

---

## 6. Retrocesso (Backtracking)

O paradigma de retrocesso consiste em construir uma solução gradualmente, tomando decisões a cada etapa.

Quando uma decisão conduz a uma situação inválida ou impossível de completar, o algoritmo retorna à etapa anterior, desfaz a decisão e tenta outra alternativa.

É como explorar diferentes caminhos em uma árvore de possibilidades.

As etapas principais são:

1. Escolher uma possibilidade;
2. Verificar se ela respeita as restrições;
3. Continuar a construção da solução;
4. Caso não seja possível prosseguir, desfazer a escolha;
5. Experimentar outra possibilidade.

### Exemplo: encontrar uma combinação de números

Considere o vetor:

```c
int v[] = {2, 4, 6, 8};
```

Desejamos verificar se existe uma combinação de elementos cuja soma seja igual a 10.

Uma solução utilizando retrocesso pode explorar diferentes combinações:

- 2 + 4 = 6;
- 2 + 6 = 8;
- 2 + 8 = 10.

Ao encontrar a soma desejada, a solução é identificada.

Uma implementação simplificada:

```c
int encontrarSoma(int v[], int n, int pos, int soma) {
    if (soma == 10) {
        return 1;
    }

    if (pos == n || soma > 10) {
        return 0;
    }

    // Escolhe o elemento atual
    if (encontrarSoma(v, n, pos + 1, soma + v[pos])) {
        return 1;
    }

    // Não escolhe o elemento atual
    return encontrarSoma(v, n, pos + 1, soma);
}
```

A função explora duas possibilidades para cada elemento:

- Incluir o elemento na combinação;
- Não incluir o elemento na combinação.

Quando uma possibilidade não produz uma solução, o algoritmo retorna e experimenta outra.

Nesse exemplo, a complexidade no pior caso é O(2ⁿ), pois cada elemento possui duas possibilidades de decisão.

### Quando utilizar?

- Quando precisamos explorar diferentes combinações;
- Quando existem restrições que determinam quais soluções são válidas;
- Quando uma solução pode ser construída progressivamente;
- Quando precisamos experimentar alternativas e desfazer decisões.

Exemplos conhecidos:

- Problema das oito rainhas;
- Resolução de labirintos;
- Sudoku;
- Problema da soma de subconjuntos;
- Geração de permutações e combinações.

---

## 7. Comparação entre os paradigmas

| Paradigma | Estratégia principal | Exemplos |
|---|---|---|
| Força bruta | Testar possibilidades sistematicamente | Busca linear |
| Divisão e conquista | Dividir, resolver e combinar | Merge Sort, busca binária |
| Guloso | Escolher a melhor alternativa local | Kruskal, Prim |
| Programação dinâmica | Armazenar resultados de subproblemas | Fibonacci, mochila |
| Retrocesso | Explorar alternativas e desfazer decisões | Sudoku, labirintos |

É importante observar que não existe um paradigma universalmente melhor. A escolha depende das características do problema.

Também é possível que diferentes paradigmas sejam utilizados para resolver o mesmo problema, apresentando diferentes custos computacionais.

---

## 8. Paradigmas de projeto versus algoritmos de busca e ordenação

É importante não confundir paradigmas de projeto com algoritmos específicos.

Por exemplo:

- Busca linear é um algoritmo que pode ser implementado por força bruta.
- Busca binária é um algoritmo baseado em divisão e conquista.
- Merge Sort é um algoritmo de ordenação baseado em divisão e conquista.
- Selection Sort é um algoritmo de ordenação que utiliza escolhas sucessivas do menor elemento, mas não é, por isso, um algoritmo guloso no sentido clássico da otimização.
- Dijkstra é um algoritmo de caminhos mínimos que utiliza uma estratégia gulosa.

Os paradigmas representam estratégias mais gerais, enquanto os algoritmos são procedimentos específicos desenvolvidos para resolver problemas.

---

## 9. Considerações finais

O desenvolvimento de algoritmos não consiste apenas em encontrar uma sequência de instruções que produza o resultado esperado.

É necessário também pensar na estratégia utilizada, na quantidade de operações realizadas e nos recursos computacionais consumidos.

Problemas simples podem ser resolvidos por força bruta, enquanto problemas mais complexos podem exigir estratégias como divisão e conquista, programação dinâmica ou retrocesso.

O conhecimento dos paradigmas permite ao programador analisar diferentes soluções e escolher aquela que apresenta o melhor equilíbrio entre simplicidade, eficiência e adequação ao problema.

---

# 10. Exercícios de fixação

**1.** Qual paradigma consiste em experimentar sistematicamente as possibilidades de solução de um problema?

a) Programação dinâmica.  
b) Força bruta.  
c) Divisão e conquista.  
d) Retrocesso.  
e) Algoritmo guloso.

**2.** A busca binária é um exemplo de algoritmo baseado em qual paradigma? Qual característica dos dados é indispensável para sua utilização?

**3.** Explique a diferença entre um algoritmo guloso e um algoritmo baseado em programação dinâmica.

**4.** Considere um algoritmo que precisa encontrar a menor quantidade de moedas para formar determinado valor. Explique por que uma estratégia gulosa pode não produzir a solução ótima.

**5.** Um algoritmo resolve um problema dividindo-o em partes menores, resolvendo cada parte recursivamente e combinando os resultados. Identifique o paradigma utilizado e cite um algoritmo que emprega essa estratégia.

**6.** Qual é a principal vantagem da programação dinâmica em relação a uma solução recursiva que recalcula os mesmos subproblemas?

**7.** Um programa precisa encontrar todas as possíveis configurações de um Sudoku, respeitando as regras do jogo. Qual paradigma pode ser utilizado? Justifique.

**8.** Considere o problema de encontrar dois elementos de um vetor cuja soma seja igual a um valor informado.

a) Como resolver esse problema utilizando força bruta?  
b) Qual seria a complexidade temporal no pior caso?  
c) Que estrutura de dados ou estratégia poderia ser utilizada para melhorar o desempenho?

**9.** Analise as situações e indique o paradigma mais adequado:

a) Ordenar um vetor utilizando Merge Sort.  
b) Encontrar a menor quantidade de moedas em um sistema monetário no qual a estratégia gulosa não garante a solução ótima.  
c) Encontrar uma combinação de elementos que satisfaça determinadas restrições.  
d) Calcular a sequência de Fibonacci evitando cálculos repetidos.  
e) Procurar um elemento percorrendo sequencialmente um vetor.

**10.** Desenvolva um pequeno programa em C que utilize retrocesso para encontrar uma combinação de elementos de um vetor cuja soma seja igual a um valor informado pelo usuário.