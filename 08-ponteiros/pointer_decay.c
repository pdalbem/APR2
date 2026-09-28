#include <stdio.h>

int main()
{
    int v[3] = {10, 20, 30};
    int *p = v; // p aponta para o primeiro elemento de v

    *(p + 1) = 99; // altera v[1]
    *p = 50;       // altera v[0]

    printf("Acessando os elementos via ponteiro:\n");
    for (int i = 0; i < 3; i++)
            printf("v[%d] = %d - endereço = %p\n",i, *(p + i), (p + i));
    

    printf("\nAcessando os elementos via array:\n");
    for (int i = 0; i < 3; i++)
            printf("v[%d] = %d - endereco = %p\n",i, v[i], &v[i]);
    
    return 0;
}