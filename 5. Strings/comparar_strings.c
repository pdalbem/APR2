#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Hello";
    char s2[] = "Hello";

    if (strcmp(s1, s2) == 0)
        printf("Strings iguais");
    else
        printf("Strings diferentes");

    return 0;
}