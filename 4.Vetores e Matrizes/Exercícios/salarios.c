#include <stdio.h>

#define TAM 10

int main(){
    float salarios[TAM];
    float soma=0;

    for (int i=0; i<TAM; i++){
        printf("Digite o salário %d: ", i+1);
        scanf("%f", &salarios[i]);
        soma+=salarios[i];
    }

    float media = soma/TAM;
    printf("\nMédia dos salários: %.2f", media);

    for (int i=0;i<TAM;i++){
        printf("\nSalário atual: %.2f", salarios[i]);
        if (salarios[i]>=media)
           salarios[i] = salarios[i] * 1.05;
          else
           salarios[i] = salarios[i] * 1.10;
        printf("\nSalário reajustado: %.2f", salarios[i]);
    }
         
           
    return 0;
}