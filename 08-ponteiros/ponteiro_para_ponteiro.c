#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;
    int **q = &p;

    **q = 20;

    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**q = %d\n", **q);

    printf("Endereço de x = %p\n", &x);
    printf("Conteúdo de p = %p\n", p);
    printf("Endereço de p = %p\n", &p);
    printf("Conteúdo de q = %p\n", q);
    printf("Endereço de q = %p\n", &q);
    

    return 0;
}