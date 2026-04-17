#include <stdio.h>
#include <string.h>

#define SUCESSO 1
#define ERRO 0

typedef struct {
    int numero;
    char nomeTitular[50];
    float saldo;
} Conta;


void lerConta(Conta *c) {
    printf("Número da conta: ");
    scanf("%d", &c->numero);
    while(getchar()!="\n");

    printf("Nome do titular: ");
    fgets(c->nomeTitular, sizeof(c->nomeTitular), stdin);
    c->nomeTitular[strcspn(c->nomeTitular, "\n")] = '\0';

    printf("Saldo inicial: ");
    scanf("%f", &c->saldo);
}


void depositar(Conta *c, float valor) {
    if (valor > 0)
        c->saldo += valor;
}


int sacar(Conta *c, float valor) {
    if (valor > 0 && valor <= c->saldo) {
        c->saldo -= valor;
        return SUCESSO;
    }
    return ERRO;
}


int transferir(Conta *origem, Conta *destino, float valor) {
    if (sacar(origem, valor)) {
        depositar(destino, valor);
        return SUCESSO;
    }
    return ERRO;
}

int main() {
    Conta c1, c2;
    Conta *ptr1 = &c1;
    Conta *ptr2 = &c2;

    float valor;

    printf("Conta 1\n");
    lerConta(ptr1);

    printf("\nConta 2 n");
    lerConta(ptr2);

    printf("\nValor para depósito na Conta 1: ");
    scanf("%f", &valor);
    depositar(ptr1, valor);

    printf("\nValor para saque na Conta 2: ");
    scanf("%f", &valor);
    if (sacar(ptr2, valor))
        printf("Saque realizado com sucesso.\n");
    else
        printf("Erro no saque.\n");

    printf("\nValor para transferência da Conta 1 para Conta 2: ");
    scanf("%f", &valor);
    if (transferir(ptr1, ptr2, valor))
        printf("Transferência realizada com sucesso.\n");
    else
        printf("Erro na transferência.\n");

    printf("\n=== Saldos finais ===\n");
    printf("Conta 1 (%s): %.2f\n", ptr1->nomeTitular, ptr1->saldo);
    printf("Conta 2 (%s): %.2f\n", ptr2->nomeTitular, ptr2->saldo);

    return 0;
}