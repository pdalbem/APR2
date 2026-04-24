#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 50;
    int *pointerA = &a; // declara um ponteiro para variável a

    // desreferência
    *pointerA = 100;
   printf("Conteúdo de a: %d \n", a);
   printf("Endereço de a: %p\n", &a);
   
   printf("Conteúdo de a via desreferência (*pointerA): %d \n", *pointerA);
   printf("Conteúdo de *pointerA: %p\n", pointerA);
    printf("Endereço de *pointerA: %p\n", &pointerA);

  
    pointerA++; // Isso não soma 1 byte, soma sizeof(int) - geralmente 4 bytes
    printf("Novo endereço apontado por pointerA: %p\n", pointerA);
    // *pointerA - a desreferência agora é indefinida (lixo ou segment fault)   

    int *ptr;
    // *ptr=10; Cuidado, ptr não foi inicializado

   
    return 0;
}
