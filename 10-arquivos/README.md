# Manipulação de Arquivos em C


## 1. Introdução e conceitos fundamentais

Em C, a manipulação de arquivos é feita por meio de funções da biblioteca padrão declaradas em `<stdio.h>`. Um arquivo pode ser tratado como uma sequência de bytes armazenados em disco — o programa lê ou escreve esses bytes usando funções de alto nível que abstraem o sistema operacional.

Existem dois grandes tipos de arquivos em C:

| Tipo       | Características                                                                 | Uso típico                        |
|------------|---------------------------------------------------------------------------------|-----------------------------------|
| **Texto**  | Dados legíveis por humanos; quebras de linha são traduzidas conforme o SO       | Logs, configs, CSVs, relatórios   |
| **Binário**| Dados brutos em bytes; sem tradução de quebras de linha                         | Imagens, structs, banco de dados simples |

**Fluxo de dados:**

```
Programa C  →  FILE *  →  Buffer interno  →  Sistema operacional  →  Arquivo em disco
```

> **Nota:** O C usa *buffering* automático: os dados não vão direto para o disco a cada escrita. O buffer é descarregado quando está cheio, ao chamar `fflush()`, ou ao fechar o arquivo com `fclose()`.

---

## 2. O ponteiro FILE

O tipo `FILE` é uma estrutura interna da biblioteca C que guarda o estado do arquivo (posição atual, modo, buffer, indicadores de erro e EOF). O programador nunca acessa essa estrutura diretamente — usa apenas um ponteiro para ela.

```c
#include <stdio.h>

int main(void) {
    FILE *fp;                        /* ponteiro para o arquivo      */

    fp = fopen("dados.txt", "w");   /* abre (ou cria) para escrita  */

    if (fp == NULL) {                /* SEMPRE verifique o retorno!  */
        perror("Erro ao abrir");
        return 1;
    }

    fprintf(fp, "Olá, arquivo!\n"); /* escreve no arquivo           */

    fclose(fp);                      /* fecha — descarrega o buffer  */
    return 0;
}
```

> ⚠️ **Nunca** use um `FILE *` sem verificar se `fopen` retornou `NULL`. Isso causa comportamento indefinido e crashes difíceis de depurar.

---

## 3. Modos de abertura

O segundo argumento de `fopen` é uma string que define o modo de acesso. Adicionar `"b"` ao modo (ex.: `"rb"`, `"wb"`) indica arquivo binário.

| Modo         | Operação         | Arquivo existente    | Arquivo inexistente |
|--------------|------------------|----------------------|---------------------|
| `"r"`        | Leitura          | Abre normalmente     | Retorna NULL        |
| `"w"`        | Escrita          | Apaga o conteúdo     | Cria novo           |
| `"a"`        | Append           | Escreve no final     | Cria novo           |
| `"r+"`       | Leitura/Escrita  | Abre normalmente     | Retorna NULL        |
| `"w+"`       | Leitura/Escrita  | Apaga o conteúdo     | Cria novo           |
| `"a+"`       | Leitura/Append   | Lê em qualquer pos.  | Cria novo           |
| `"rb"`, `"wb"`, ... | Equivalente binário | Mesmas regras acima, sem tradução de `\n` | |

---

## 4. Arquivos texto

No modo texto, `\n` é automaticamente convertido para a convenção da plataforma (`CRLF` no Windows, `LF` no Unix). O conteúdo é legível em qualquer editor.

### 4.1 Escrita com fprintf e fputs

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("alunos.txt", "w");
    if (!fp) { perror("fopen"); return 1; }

    /* fprintf funciona como printf, mas escreve no arquivo */
    fprintf(fp, "%-20s %5s %6s\n", "Nome", "Idade", "Nota");
    fprintf(fp, "%-20s %5d %6.2f\n", "Ana Lima",    20, 9.5);
    fprintf(fp, "%-20s %5d %6.2f\n", "Bruno Costa", 22, 7.8);
    fprintf(fp, "%-20s %5d %6.2f\n", "Carla Melo",  19, 8.3);

    /* fputs escreve uma string sem formatação extra */
    fputs("--- Fim do relatório ---\n", fp);

    fclose(fp);
    printf("Arquivo criado com sucesso.\n");
    return 0;
}

/* Conteúdo gerado em alunos.txt:
   Nome                 Idade   Nota
   Ana Lima                20   9.50
   Bruno Costa             22   7.80
   Carla Melo              19   8.30
   --- Fim do relatório --- */
```

### 4.2 Leitura com fscanf

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("numeros.txt", "r");
    if (!fp) { perror("fopen"); return 1; }

    int n;
    float soma = 0;
    int qtd = 0;

    /* fscanf retorna o número de itens lidos com sucesso */
    /* EOF é retornado quando o arquivo termina           */
    while (fscanf(fp, "%d", &n) == 1) {
        soma += n;
        qtd++;
    }

    fclose(fp);

    if (qtd > 0)
        printf("Média: %.2f\n", soma / qtd);

    return 0;
}
```

> ⚠️ **Cuidado com fscanf:** ele falha silenciosamente com dados mal formatados. Para leitura robusta de texto, prefira `fgets` seguido de `sscanf`.

### 4.3 Leitura linha a linha com fgets

```c
#include <stdio.h>
#include <string.h>

#define MAX_LINHA 256

int main(void) {
    FILE *fp = fopen("produtos.csv", "r");
    if (!fp) { perror("fopen"); return 1; }

    char linha[MAX_LINHA];
    char nome[64];
    float preco;
    int qtd;

    printf("Produtos com estoque baixo (qtd < 10):\n");

    /* fgets lê até MAX_LINHA-1 caracteres OU até '\n' */
    /* Retorna NULL ao atingir o fim do arquivo (EOF)  */
    while (fgets(linha, MAX_LINHA, fp) != NULL) {

        /* Ignora cabeçalho */
        if (linha[0] == 'N') continue;

        /* sscanf parseia a linha lida */
        if (sscanf(linha, "%63[^,],%f,%d", nome, &preco, &qtd) == 3) {
            if (qtd < 10)
                printf("  %-20s R$%.2f  (qtd: %d)\n", nome, preco, qtd);
        }
    }

    fclose(fp);
    return 0;
}

/* Exemplo de produtos.csv:
   Nome,Preco,Qtd
   Teclado Mecânico,350.00,15
   Mouse Gamer,180.00,7
   Monitor 24",1200.00,3
   Headset USB,220.00,22  */
```

### 4.4 Copiando um arquivo texto

```c
#include <stdio.h>

int copiar_arquivo(const char *origem, const char *destino) {
    FILE *src = fopen(origem,  "r");
    FILE *dst = fopen(destino, "w");

    if (!src || !dst) {
        if (src) fclose(src);
        if (dst) fclose(dst);
        return -1;
    }

    int c;
    /* fgetc retorna int — necessário para comparar com EOF (-1) */
    while ((c = fgetc(src)) != EOF)
        fputc(c, dst);

    fclose(src);
    fclose(dst);
    return 0;
}

int main(void) {
    if (copiar_arquivo("original.txt", "copia.txt") == 0)
        printf("Arquivo copiado com sucesso!\n");
    else
        perror("Erro na cópia");
    return 0;
}
```

---

## 5. Arquivos binários

No modo binário, os dados são escritos exatamente como estão na memória — sem qualquer conversão. Isso é mais eficiente para grandes volumes de dados numéricos ou estruturas complexas, mas o arquivo resultante não é legível em editores de texto comuns.

### 5.1 Escrita com fwrite

```c
/* Protótipo:
   size_t fwrite(const void *ptr, size_t tamanho, size_t n, FILE *fp);
   - ptr:     ponteiro para os dados na memória
   - tamanho: tamanho em bytes de cada elemento
   - n:       número de elementos a escrever
   - fp:      ponteiro para o arquivo
   Retorna: número de elementos escritos com sucesso */

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("numeros.bin", "wb");
    if (!fp) { perror("fopen"); return 1; }

    int valores[] = {10, 20, 30, 40, 50};
    int n = 5;

    /* Escreve o array inteiro de uma vez */
    size_t escritos = fwrite(valores, sizeof(int), n, fp);
    printf("Escritos: %zu elementos\n", escritos);

    fclose(fp);
    return 0;
}

/* No disco, o arquivo tem exatamente 5 × 4 = 20 bytes.
   Cada inteiro ocupa sizeof(int) bytes em representação
   binária nativa da máquina (little-endian ou big-endian). */
```

### 5.2 Leitura com fread

```c
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("numeros.bin", "rb");
    if (!fp) { perror("fopen"); return 1; }

    int valores[10];  /* buffer para até 10 inteiros */

    /* fread retorna quantos elementos foram de fato lidos */
    size_t lidos = fread(valores, sizeof(int), 10, fp);

    printf("Lidos: %zu elementos\n", lidos);
    for (size_t i = 0; i < lidos; i++)
        printf("valores[%zu] = %d\n", i, valores[i]);

    fclose(fp);
    return 0;
}

/* Saída:
   Lidos: 5 elementos
   valores[0] = 10
   valores[1] = 20
   valores[2] = 30
   valores[3] = 40
   valores[4] = 50 */
```

### 5.3 Salvando e recuperando structs

Este é um dos usos mais comuns de arquivos binários em C: persistir registros de dados estruturados de forma compacta e eficiente.

```c
#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define ARQ "funcionarios.dat"

typedef struct {
    int    id;
    char   nome[MAX_NOME];
    float  salario;
    int    ativo;          /* 1 = ativo, 0 = inativo */
} Funcionario;

/* ---- salva um funcionário no final do arquivo ---- */
int salvar(const Funcionario *f) {
    FILE *fp = fopen(ARQ, "ab");
    if (!fp) return -1;
    fwrite(f, sizeof(Funcionario), 1, fp);
    fclose(fp);
    return 0;
}

/* ---- lista todos os funcionários ativos ---- */
void listar(void) {
    FILE *fp = fopen(ARQ, "rb");
    if (!fp) { printf("Nenhum registro.\n"); return; }

    Funcionario f;
    printf("%-4s %-25s %10s\n", "ID", "Nome", "Salário");
    printf("%.44s\n", "--------------------------------------------");

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (f.ativo)
            printf("%-4d %-25s R$%9.2f\n", f.id, f.nome, f.salario);
    }
    fclose(fp);
}

/* ---- busca por ID e exibe ---- */
int buscar(int id) {
    FILE *fp = fopen(ARQ, "rb");
    if (!fp) return -1;

    Funcionario f;
    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (f.id == id) {
            printf("Encontrado: %s (R$%.2f)\n", f.nome, f.salario);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    printf("ID %d não encontrado.\n", id);
    return -1;
}

int main(void) {
    Funcionario f1 = {1, "Ana Lima",    4500.00, 1};
    Funcionario f2 = {2, "Bruno Costa", 3800.00, 1};
    Funcionario f3 = {3, "Carla Melo",  5200.00, 0}; /* inativa */

    salvar(&f1);
    salvar(&f2);
    salvar(&f3);

    printf("\n--- Funcionários ativos ---\n");
    listar();

    printf("\n--- Busca por ID 2 ---\n");
    buscar(2);

    return 0;
}
```

> ⚠️ **Atenção ao padding:** o compilador pode inserir bytes de alinhamento na struct. Use `__attribute__((packed))` (GCC) ou garanta que a mesma struct seja usada para leitura e escrita. Arquivos binários com structs *não são portáveis* entre arquiteturas diferentes.

---


## 6. Texto vs. Binário — comparativo final

| Critério              | Arquivo Texto                          | Arquivo Binário                        |
|-----------------------|----------------------------------------|----------------------------------------|
| Legibilidade          | Legível em qualquer editor             | Ilegível sem programa específico       |
| Tamanho               | Maior (números viram strings)          | Compacto (dados brutos da memória)     |
| Velocidade            | Mais lento (precisa converter)         | Mais rápido (cópia direta)             |
| Portabilidade         | Portável entre SOs e arquiteturas      | Pode variar entre arquiteturas         |
| Acesso aleatório      | Difícil (registros de tamanho variável)| Fácil (registros de tamanho fixo)      |
| Funções típicas       | `fprintf`, `fscanf`, `fgets`, `fputs`  | `fwrite`, `fread`                      |
| Modo de abertura      | `"r"`, `"w"`, `"a"`                    | `"rb"`, `"wb"`, `"ab"`                 |
| Uso ideal             | Configs, logs, CSVs, relatórios        | Bancos simples, imagens, structs       |

> 💡 Para aplicações que precisam de **acesso aleatório eficiente a registros**, o arquivo binário com structs de tamanho fixo é a escolha natural em C — é o princípio que fundamentou bancos de dados por décadas.



## 7. Posicionamento: fseek, ftell e rewind

Cada arquivo aberto tem um *indicador de posição* — um cursor que aponta para onde a próxima leitura ou escrita ocorrerá. As funções abaixo permitem mover esse cursor livremente, habilitando **acesso aleatório**.

| Função                        | Descrição                                                       |
|-------------------------------|-----------------------------------------------------------------|
| `fseek(fp, offset, origem)`   | Move o cursor `offset` bytes a partir de `origem`              |
| `ftell(fp)`                   | Retorna a posição atual (em bytes desde o início)              |
| `rewind(fp)`                  | Volta o cursor para o início (`fseek(fp, 0, SEEK_SET)`)        |

Origens para `fseek`:

- `SEEK_SET` — início do arquivo
- `SEEK_CUR` — posição atual
- `SEEK_END` — fim do arquivo

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int  id;
    char nome[50];
    float salario;
    int  ativo;
} Funcionario;

/* Atualiza o salário do funcionário na posição 'indice' */
int atualizar_salario(const char *arq, int indice, float novo_salario) {
    FILE *fp = fopen(arq, "r+b");   /* r+b: leitura e escrita binária */
    if (!fp) return -1;

    /* Calcula o offset em bytes até o registro desejado */
    long offset = (long)indice * sizeof(Funcionario);

    /* Move o cursor diretamente para aquele registro */
    if (fseek(fp, offset, SEEK_SET) != 0) {
        fclose(fp); return -1;
    }

    Funcionario f;

    /* Lê o registro */
    if (fread(&f, sizeof(Funcionario), 1, fp) != 1) {
        fclose(fp); return -1;
    }

    printf("Antes: %s — R$%.2f\n", f.nome, f.salario);

    /* Atualiza o salário */
    f.salario = novo_salario;

    /* Volta para a posição do registro e reescreve */
    fseek(fp, offset, SEEK_SET);
    fwrite(&f, sizeof(Funcionario), 1, fp);

    printf("Depois: %s — R$%.2f\n", f.nome, f.salario);

    fclose(fp);
    return 0;
}

/* Descobre quantos registros existem no arquivo */
long contar_registros(const char *arq) {
    FILE *fp = fopen(arq, "rb");
    if (!fp) return -1;

    fseek(fp, 0, SEEK_END);          /* vai para o fim */
    long tamanho = ftell(fp);        /* posição = tamanho total em bytes */
    fclose(fp);

    return tamanho / (long)sizeof(Funcionario);
}

int main(void) {
    printf("Total de registros: %ld\n", contar_registros("funcionarios.dat"));
    atualizar_salario("funcionarios.dat", 1, 4200.00); /* índice 1 = Bruno */
    return 0;
}
```

---

## 8. Tratamento de erros

```c
#include <stdio.h>
#include <errno.h>   /* errno, strerror */
#include <string.h>

int main(void) {
    FILE *fp = fopen("dados.bin", "rb");

    if (fp == NULL) {
        /* perror imprime a mensagem do sistema para errno atual */
        perror("Erro ao abrir dados.bin");
        /* Ou use strerror para montar a mensagem manualmente: */
        /* fprintf(stderr, "Erro: %s\n", strerror(errno)); */
        return 1;
    }

    int buf[8];
    size_t lidos;

    while ((lidos = fread(buf, sizeof(int), 8, fp)) > 0) {
        /* processa buf[0..lidos-1] */
    }

    /* Verifica se parou por erro ou por EOF */
    if (ferror(fp)) {
        fprintf(stderr, "Erro de leitura no arquivo!\n");
        clearerr(fp);   /* limpa os indicadores de erro e EOF */
    } else if (feof(fp)) {
        printf("Arquivo lido até o fim com sucesso.\n");
    }

    fclose(fp);
    return 0;
}

/* Funções úteis:
   feof(fp)    — retorna != 0 se o fim do arquivo foi atingido
   ferror(fp)  — retorna != 0 se ocorreu um erro de I/O
   clearerr(fp)— limpa os flags de erro e EOF
   perror(msg) — imprime msg + descrição do último erro do SO */
```

> ⚠️ **Armadilha comum:** verificar `feof(fp)` *antes* de tentar ler, e não depois. O flag EOF só é setado após uma tentativa de leitura além do fim — não antes.

---

## 9. Exemplo completo 

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char telefone[20];
} Contato;

void adicionar_contato() {
    Contato c;
    printf("ID: "); scanf("%d", &c.id);
    printf("Nome: "); scanf("%s", c.nome);
    printf("Telefone: "); scanf("%s", c.telefone);

    FILE *arq = fopen("agenda.bin", "ab");
    fwrite(&c, sizeof(Contato), 1, arq);
    fclose(arq);
}

void listar_contatos() {
    FILE *arq = fopen("agenda.bin", "rb");
    if (!arq) return;
    Contato c;
    while (fread(&c, sizeof(Contato), 1, arq)) {
        printf("%d - %s - %s\n", c.id, c.nome, c.telefone);
    }
    fclose(arq);
}

void buscar_contato(int id) {
    FILE *arq = fopen("agenda.bin", "rb");
    if (!arq) return;
    Contato c;
    while (fread(&c, sizeof(Contato), 1, arq)) {
        if (c.id == id) {
            printf("Encontrado: %s - %s\n", c.nome, c.telefone);
            fclose(arq);
            return;
        }
    }
    printf("Não encontrado.\n");
    fclose(arq);
}

int main() {
    adicionar_contato();
    listar_contatos();
    buscar_contato(1);
    return 0;
}
```
---
