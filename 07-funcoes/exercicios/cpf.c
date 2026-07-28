#include <stdio.h>
#include <string.h>

void formatarCPF(char cpf[]) {
    if (strlen(cpf) != 11) {
        printf("CPF inválido!\n");
        return;
    }

    printf("%.3s.%.3s.%.3s-%.2s\n",
           cpf,        // primeiros 3
           cpf + 3,    // próximos 3
           cpf + 6,    // próximos 3
           cpf + 9);   // últimos 2
}

int main() {
    char cpf[] = "12345678901";
    formatarCPF(cpf);
    return 0;
}