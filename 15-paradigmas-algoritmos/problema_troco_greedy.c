#include <stdio.h>

void calcularTrocoGuloso(int moedas[], int numMoedas, int valorTroco) {
    printf("Troco guloso para R$ %d:\n", valorTroco);
    
    for (int i = 0; i < numMoedas; i++) {
        if (valorTroco >= moedas[i]) {
            int qtd = valorTroco / moedas[i];
            valorTroco %= moedas[i];
            printf("- %d moeda(s) de R$ %d\n", qtd, moedas[i]);
        }
    }
}

int main() {
    int moedas[] = {20, 10, 5,  1}; 
    int numMoedas = sizeof(moedas) / sizeof(moedas[0]);
    int valorTrocoEmCentavos = 36; 

    calcularTrocoGuloso(moedas, numMoedas, valorTrocoEmCentavos);
    return 0;
}