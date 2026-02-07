# Algoritmos e Programação 2 (APR2)

## 1. Breve histórico da linguagem C


A linguagem C surgiu nos Laboratórios Bell (Bell Labs) da AT&T entre 1969 e 1973, criada por **Dennis Ritchie**. Sua origem está diretamente ligada ao desenvolvimento do sistema operacional **UNIX**. Inicialmente, o Unix foi escrito em linguagem assembly, o que o tornava extremamente dependente do hardware específico para o qual foi criado. Para resolver essa limitação de portabilidade, Ken Thompson, colega de Ritchie, havia desenvolvido a linguagem B, uma versão simplificada da linguagem BCPL. Ritchie, então, partiu da linguagem B para criar uma nova que fosse mais poderosa e eficiente, capaz de reescrever o núcleo do Unix. Essa nova linguagem, que inicialmente apenas acrescentou tipos à B, recebeu o nome de C, representando a evolução natural no alfabeto.

O grande salto para a popularização da linguagem C ocorreu em 1978, com a publicação do livro "The C Programming Language", escrito por Brian Kernighan e Dennis Ritchie. Conhecido carinhosamente no meio como "K&R", o livro se tornou a bíblia dos programadores por mais de uma década, estabelecendo a versão da linguagem que ficou conhecida como "K&R C". O sucesso do Unix em ambientes acadêmicos e, posteriormente, comerciais, carregou consigo a linguagem C, que era apreciada por sua rara combinação de eficiência (próxima à do assembly) e portabilidade (um programa em C podia ser compilado para diferentes máquinas).

À medida que sua adoção crescia globalmente, surgiram dialetos e implementações divergentes. Para frear essa fragmentação, o American National Standards Institute (ANSI) formou um comitê em 1983 para padronizar a linguagem. O resultado, aprovado em 1989, ficou conhecido como ANSI C ou C89. Um ano depois, a Organização Internacional para Padronização (ISO) adotou esse padrão, lançando o ISO C (C90). Essa padronização foi um marco crucial, pois definiu uma base universal e estável para o desenvolvimento de compiladores e programas em todo o mundo.

A linguagem, porém, não ficou estagnada. Em 1999, o padrão foi revisado, resultando no C99. Esta versão trouxe inovações significativas, como comentários de linha única (//), tipos de dados de tamanho fixo (ex: int32_t), arrays de comprimento variável e suporte aprimorado para matemática e internacionalização. A próxima revisão importante, o C11 de 2011, focou em modernizar a linguagem para os desafios da computação contemporânea, introduzindo suporte nativo a concorrência com threads, funções com verificações de segurança e expressões genéricas. Uma revisão técnica menor, o C17/C18, seguiu para corrigir falhas. O padrão mais recente, o C23, finalizado em 2023, trouxe melhorias de sintaxe, como a notação para números binários, atributos mais modernos e aprimoramentos na segurança e usabilidade.

O legado da linguagem C é imensurável. Ela é a espinha dorsal de sistemas operacionais fundamentais como os kernels do Linux, macOS e do próprio Windows em suas partes essenciais, além de dominar o mundo dos sistemas embarcados e de tempo real. Filosoficamente, C foi concebida como uma "linguagem de montagem portável", dando ao programador controle próximo ao hardware sem abrir mão da capacidade de escrever código que pode ser recompilado para diferentes arquiteturas. Essa filosofia de minimalismo, poder e confiança no programador (que traz consigo a responsabilidade pelo gerenciamento manual de recursos como a memória) influenciou profundamente toda uma linhagem de linguagens modernas, incluindo C++, Java, C#, Go, Rust e JavaScript. Mesmo após mais de cinco décadas, C permanece como uma das linguagens de programação mais essenciais, eficientes e influentes da história da computação.

---

## 2. Características da linguagem C

Algumas das principais características da linguagem C são:

- Linguagem **procedural**
- Forte proximidade com o hardware
- Alto desempenho
- Uso explícito de memória (ponteiros)
- Código compacto e eficiente
- Portabilidade entre sistemas
- Compilada (gera código nativo)


---

## 3. Onde a linguagem C é usada atualmente

A linguagem C continua extremamente relevante e é amplamente utilizada em:

- Sistemas operacionais (Linux, Unix, partes do Windows)
- Sistemas embarcados (microcontroladores, IoT)
- Drivers de dispositivos
- Compiladores e interpretadores
- Bancos de dados (MySQL, PostgreSQL)
- Jogos e motores gráficos
- Sistemas que exigem **alto desempenho** e **baixo consumo de recursos**

---

## 4. Vantagens da linguagem C

- Execução rápida e eficiente
- Grande controle sobre memória e hardware
- Base sólida para aprender outras linguagens
- Ampla disponibilidade de bibliotecas
- Código portátil entre diferentes plataformas

Aprender C ajuda o programador a compreender melhor como o computador realmente funciona.

---

## 5. Dificuldades da linguagem C

Apesar das vantagens, C também apresenta desafios:

- Gerenciamento manual de memória
- Maior propensão a erros (ex: ponteiros inválidos)
- Sintaxe menos amigável para iniciantes
- Ausência de recursos modernos nativos (como classes e coleta de lixo)

Essas dificuldades, no entanto, tornam o aprendizado de C extremamente formativo.

---


### Conteúdo:
[1. Introdução à linguagem C]()
* Tipos de dados
* Variáveis e constantes
* Modificadores de tipo
* Conversão de tipos (_casting_)
* Operadores aritméticos
* Operadores relacionais
* Operadores lógicos
* Entrada e saída de dados