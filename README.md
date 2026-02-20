# Algoritmos e Programação 2 (APR2)

Material da disciplina Algoritmos e Programação 2 (APR2)

## 🛠️ Guia de Configuração do Ambiente 

Este guia tem como objetivo ajudar você a configurar seu computador para compilar e executar os códigos da disciplina de **APR2**. Siga os passos abaixo de acordo com o seu sistema operacional.


### 1. Instalação do Compilador (GCC)

O compilador é essencial para transformar seu código-fonte em um programa executável.

### **Windows**
A forma mais recomendada é através do **MSYS2**. 

Veja o tutorial completo de instalação [aqui neste link](https://code.visualstudio.com/docs/cpp/config-mingw).

1. Baixe e instale o [MSYS2](https://www.msys2.org/).
2. Abra o terminal do MSYS2 e execute o comando:  
   `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`
3. Adicione o caminho da pasta `bin` (geralmente `C:\msys64\ucrt64\bin`) às **Variáveis de Ambiente (PATH)** do Windows para que o comando `gcc` funcione em qualquer terminal.

### **Linux**
A maioria das distribuições já possui ou facilita muito a instalação:
* **Ubuntu/Debian:** `sudo apt update && sudo apt install build-essential`
* **Fedora:** `sudo dnf groupinstall "Development Tools"`

### **macOS**
Instale as ferramentas de linha de comando do Xcode:
1. Abra o Terminal e digite:
   `xcode-select --install`

---

### 2. Editor de Código Recomendado: VS Code

Utilizaremos o **Visual Studio Code** pela sua versatilidade. Acesse o [site](https://code.visualstudio.com/) para efetuar o download. Após instalá-lo, abra-o e procure na aba de **Extensions (Ctrl+Shift+X)** por:

**C/C++ Extension Pack (Microsoft):** Oferece realce de sintaxe, IntelliSense (autocompletar) e suporte a depuração.


---

### 3. Usando o Terminal

Embora existam botões que facilitam o trabalho, é fundamental saber compilar seus programas via linha de comando. 

### **Comandos Básicos**

Navegue até a pasta do seu arquivo pelo terminal e utilize:

**Para programas em C:**
```bash
# Compila o código
gcc programa.c -o programa

# Executa o programa
./programa
``` 

## Conteúdo:
[1. Introdução à linguagem C](https://github.com/pdalbem/APR2/tree/main/1.%20Introdu%C3%A7%C3%A3o)
* Breve histórico de C
* Tipos de dados
* Variáveis e constantes
* Modificadores de tipo
* Conversão de tipos (_casting_)
* Operadores aritméticos
* Operadores relacionais
* Operadores lógicos
* Entrada e saída de dados

[2. Estruturas de Decisão](https://github.com/pdalbem/APR2/tree/main/2.%20Estruturas%20de%20Decis%C3%A3o)
* `if`
* `if-else`
* `if-else-if`
* `switch-case`
* Operador ternário

[3. Estruturas de Repetição](https://github.com/pdalbem/APR2/tree/main/3.%20Estruturas%20de%20Repeti%C3%A7%C3%A3o)
* `while`
* `do-while`
* `for`
* `break` e `continue`

[4. Vetores e Matrizes](https://github.com/pdalbem/APR2/tree/main/4.Vetores%20e%20Matrizes)
*  Variável composta homogênea
*  Vetores
*  Matrizes
*  Declaração, inicialização, acesso e percurso 