#include <stdio.h>

int main() {
    int a = 5;
    int b = 2;

    float media_sem_cast = a / b;
    float media_com_cast = (float)a / b;

    printf("Sem casting: %.2f\n", media_sem_cast);
    printf("Com casting: %.2f\n", media_com_cast);

    return 0;
}
