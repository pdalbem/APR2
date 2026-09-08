#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

void lerFrase(char frase[]);
int contarVogais(char frase[]);
int contarPalavras(char frase[]);
int ehPalindromo(char frase[]);

int main() {
    char frase[MAX + 1];

    lerFrase(frase);

    printf("\nQuantidade de vogais: %d\n", contarVogais(frase));
    printf("Quantidade de palavras: %d\n", contarPalavras(frase));

    if (ehPalindromo(frase)) {
        printf("A frase é um palíndromo.\n");
    } else {
        printf("A frase não é um palíndromo.\n");
    }

    return 0;
}

void lerFrase(char frase[]) {
    printf("Digite uma frase: ");
    fgets(frase, MAX + 1, stdin);
    frase[strcspn(frase, "\n")] = '\0';
}

int contarVogais(char frase[]) {
    int quantidade = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') 
            quantidade++;
        
    }

    return quantidade;
}

int contarPalavras(char frase[]) {
    int quantidade = 0;
    int dentroDaPalavra = 0;

    for (int i = 0; frase[i] != '\0'; i++) {

        if (!isspace(frase[i])) 
            if (!dentroDaPalavra) {
                quantidade++;
                dentroDaPalavra = 1;
            }
         else 
            dentroDaPalavra = 0;     
    }

    return quantidade;
}

int ehPalindromo(char frase[]) {
    int inicio = 0;
    int fim = strlen(frase) - 1;

    while (inicio < fim) {

        // Ignora espaços no início
        while (inicio < fim && isspace(frase[inicio])) 
            inicio++;
        
        // Ignora espaços no final
        while (inicio < fim && isspace(frase[fim])) 
            fim--;
        
        char esquerda = tolower(frase[inicio]);
        char direita = tolower(frase[fim]);

        if (esquerda != direita) 
            return 0;
        
        inicio++;
        fim--;
    }

    return 1;
}