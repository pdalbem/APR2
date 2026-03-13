#include <stdio.h>

#define QTD_PRODUTOS 10

int main(){
    float salarios[QTD_PRODUTOS];
    float soma=0;

    for (int i=0; i<QTD_PRODUTOS; i++){
        printf("Digite o salário %d: ", i+1);
        scanf("%f", &salarios[i]);
        soma+=salarios[i];
    }

    float media = soma/QTD_PRODUTOS;
    printf("\nMédia dos salários: %.2f", media);

    for (int i=0;i<QTD_PRODUTOS;i++){
        printf("\nSalário atual: %.2f", salarios[i]);
        if (salarios[i]>=media)
           salarios[i] = salarios[i] * 1.05;
          else
           salarios[i] = salarios[i] * 1.10;
        printf("\nSalário reajustado: %.2f", salarios[i]);
    }
         
           
    return 0;
}