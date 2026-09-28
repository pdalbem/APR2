#include <stdio.h>

int main() {
    int v[3] = {10, 20, 30};
    int (*p)[3] = &v; // p aponta para o array todo
  

    (*p)[1] = 99;  // altera v[1]
    (*p)[0] = 50;  // altera v[0]

    for (int i = 0; i < 3; i++) 
        printf("v[%d] = %d\n", i, (*p)[i]);


    return 0;
}