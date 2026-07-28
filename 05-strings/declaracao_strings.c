#include <stdio.h>
#include <string.h>

int main()
{

    // Diferentes formas de declarar strings

    char str1[] = "Hello"; // memoria: ['H']['e']['l']['l']['o']['\0']

    char str2[20] = "Hello"; // Array de 20 chars, mas somente 5 são usados

    // Caractere por caractere
    char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // IMPORTANTE: incluir '\0' manualmente

    char str4[10] = {'H', 'e', 'l', 'l', 'o'}; // completa restante com \0 neste caso

    char str5[] = {'H', 'e', 'l', 'l', 'o'}; // SEM \0 (string inválida) e tamanho do array não foi especificado

    // PROBLEMA! Sem espaço para o \0 (comportamento indefinido)
    char str6[5] = "Hello";

    return 0;
}