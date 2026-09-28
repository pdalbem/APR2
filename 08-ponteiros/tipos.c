#include <stdio.h>

int main() {
    char   c = 'A';
    int    i = 42;
    double d = 3.14;

    char   *pc = &c;
    int    *pi = &i;
    double *pd = &d;
    printf("sizeof(char)   = %zu byte\n", sizeof(char));
    printf("sizeof(int)    = %zu bytes\n", sizeof(int));
    printf("sizeof(double) = %zu bytes\n", sizeof(double));

    printf("sizeof(pc) = %zu (aponta para char)\n",   sizeof(pc));
    printf("sizeof(pi) = %zu (aponta para int)\n",    sizeof(pi));
    printf("sizeof(pd) = %zu (aponta para double)\n", sizeof(pd));

    return 0;
}