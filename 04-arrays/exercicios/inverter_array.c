#include <stdio.h>

#define TAM 6

int main(){
    int vet[TAM];

    for (int i=0;i<TAM;i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vet[i]);
    }

    int aux;
    for (int i=0;i<TAM/2;i++){
        aux = vet[i];
        vet[i] = vet[TAM-1-i];
        vet[TAM-1-i] = aux;
    }

    for (int i=0;i<TAM;i++)
        printf("%d ", vet[i]);

    
    return 0;
}