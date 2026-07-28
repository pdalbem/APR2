#include <stdio.h>
#include <string.h>

int main()
{
    char nomes[3][20] = {"Maria", "Joaquim", "Ana"};
    char frutas[][15] = {"banana", "uva"};
    char animais[5][10] = {"Cachorro", "Gato"};
    char cores[3][15] = {
        {'V', 'e', 'r', 'm', 'e', 'l', 'h', 'o', '\0'},
        {'V', 'e', 'r', 'd', 'e', '\0'},
        {'A', 'z', 'u', 'l', '\0'}};

    for (int i = 0; i < 3; i++)
        printf("%s \n", nomes[i]);

    char numeros[3][10];    
    for (int i = 0; i < 3; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        fgets(numeros[i], sizeof(numeros[i]), stdin);
        numeros[i][strcspn(numeros[i], "\n")] = 0; // Remove o \n do final
    }

    return 0;
}