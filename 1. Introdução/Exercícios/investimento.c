#include <stdio.h>
#include <math.h>

int main() {
    float capital, taxa, montante_total;
    int tempo, i;
    
  
    printf("Informe o capital inicial: R$ ");
    scanf("%f", &capital);
    
    printf("Informe a taxa de juros anual (%%): ");
    scanf("%f", &taxa);
    taxa = taxa / 100;  // Convertendo para decimal
    
    printf("Informe o periodo em anos: ");
    scanf("%d", &tempo);
    

    montante_total = capital * pow(1 + taxa, tempo);
    

    printf("Montante final:  R$ %.2f \n", montante_total);

    
    return 0;
}