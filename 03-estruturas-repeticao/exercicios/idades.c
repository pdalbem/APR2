#include <stdio.h>

int main() {
    int idade;
    int totalPessoas = 0;
    int maiores21 = 0;
    int idosos = 0;

   
    do {
        printf("Digite a idade (valor negativo para encerrar):\n");
        scanf("%d", &idade);

        if (idade >= 0) {
            totalPessoas++;

            if (idade >= 21) {
                maiores21++;
            }

            if (idade > 65) {
                idosos++;
            }
        }

    } while (idade >= 0);

    if (totalPessoas == 0) {
        printf("Nenhuma idade valida foi informada.\n");
    } else {
        printf("Quantidade de pessoas com 21 anos ou mais: %d\n", maiores21);
        printf("Porcentagem de pessoas idosas: %.2f%%\n",
               (idosos * 100.0) / totalPessoas);
    }

    return 0;
}
