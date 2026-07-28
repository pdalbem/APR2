#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //Converte para maiúscula
    char str[] = "hello world!";
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);

    puts(str); // HELLO WORLD!


    //Converte para minúscula
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);

    puts(str); // hello world!

    return 0;
}