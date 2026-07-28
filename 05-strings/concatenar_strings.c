#include <stdio.h>
#include <string.h>

int main()
{

    char i, j, str1[100], str2[100];

    printf("Enter first string:");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    while (getchar()!='\n'); //limpa buffer caso ocorra buffer overflow
    
    printf("Enter second string:");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcat(str1, str2);

    printf("Concatenated string is: %s", str1);

    return 0;
}