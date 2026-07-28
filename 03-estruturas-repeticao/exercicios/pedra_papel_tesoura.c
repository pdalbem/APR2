#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcaoUsuario;
    int opcaoComputador;

    // Inicializa o gerador de numeros aleatorios
    srand(time(NULL));

    do {
        printf("\n=== Pedra, Papel ou Tesoura ===\n");
        printf("1 - Pedra\n");
        printf("2 - Papel\n");
        printf("3 - Tesoura\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoUsuario);

        if (opcaoUsuario == 0) {
            printf("Encerrando o jogo...\n");
            break;
        }

        if (opcaoUsuario < 1 || opcaoUsuario > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        // Escolha aleatoria do computador (1 a 3)
        opcaoComputador = rand() % 3 + 1;

        // Exibe escolhas
        printf("\nVoce escolheu: ");
        if (opcaoUsuario == 1) printf("Pedra\n");
        else if (opcaoUsuario == 2) printf("Papel\n");
        else printf("Tesoura\n");

        printf("Computador escolheu: ");
        if (opcaoComputador == 1) printf("Pedra\n");
        else if (opcaoComputador == 2) printf("Papel\n");
        else printf("Tesoura\n");

        // Resultado
        if (opcaoUsuario == opcaoComputador) {
            printf("Resultado: Empate!\n");
        }
        else if ((opcaoUsuario == 1 && opcaoComputador == 3) ||
                 (opcaoUsuario == 2 && opcaoComputador == 1) ||
                 (opcaoUsuario == 3 && opcaoComputador == 2)) {
            printf("Resultado: Voce venceu!\n");
        }
        else {
            printf("Resultado: Voce perdeu!\n");
        }

    } while (opcaoUsuario!=0);

    return 0;
}
