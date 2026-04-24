#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {100, 200, 300};  
    int *pointer = array;
    printf("Elementos: %d %d %d\n", array[0], array[1], array[2]);
    printf("Elementos: %d %d %d\n", *pointer, *(pointer + 1), *(pointer + 2));

    return 0;
}
