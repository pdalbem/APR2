#include <stdio.h>

void dataExtenso(int dia, int mes, int ano) {
    char *meses[] = {
        "janeiro", "fevereiro", "março", "abril",
        "maio", "junho", "julho", "agosto",
        "setembro", "outubro", "novembro", "dezembro"
    };

    // validação básica
    if (mes < 1 || mes > 12) {
        printf("Data inválida!\n");
        return;
    }

    printf("%d de %s de %d\n", dia, meses[mes - 1], ano);
}

int main() {
    dataExtenso(20, 3, 2026);
    return 0;
}