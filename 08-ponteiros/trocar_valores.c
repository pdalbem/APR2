#include <stdio.h>
void trocar(int *a, int *b) {  
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    trocar(&x, &y); 
    printf("x=%d, y=%d", x, y); 


    printf("\n\n");
    return 0;
}