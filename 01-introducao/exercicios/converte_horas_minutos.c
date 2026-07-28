#include <stdio.h>

int main() {
    int minutos;
    float horas;
    
    printf("Digite a quantidade de minutos: ");
    scanf("%d", &minutos);
    
    horas = minutos / 60.0;
    
    printf("%d minutos equivalem a %.2f horas\n", minutos, horas);
    
    return 0;
}