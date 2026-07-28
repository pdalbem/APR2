#include <stdio.h>

int main() {
    float X, V1, V2, P;
    float valorTotal;

    printf("Digite a distancia limite X (km): ");
    scanf("%f", &X);

    printf("Digite o valor por km ate X (V1): ");
    scanf("%f", &V1);

    printf("Digite o valor por km acima de X (V2): ");
    scanf("%f", &V2);

    printf("Digite a quantidade de km percorridos (P): ");
    scanf("%f", &P);

    if (P <= X) {
        valorTotal = P * V1;
    } else {
        valorTotal = P * V2;
    }

    printf("Valor total da viagem: R$ %.2f\n", valorTotal);

    return 0;
}
