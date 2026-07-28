#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um número positivo: ");
    scanf("%d", &numero);
    
    while (numero <= 0) {
        printf("Número inválido! Digite um número positivo: ");
        scanf("%d", &numero);
    }
    
    printf("Você digitou: %d\n", numero);
    return 0;
}

