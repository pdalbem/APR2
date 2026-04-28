#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char telefone[20];
} Contato;

void adicionar_contato() {
    Contato c;
    printf("ID: "); scanf("%d", &c.id);
    printf("Nome: "); scanf("%s", c.nome);
    printf("Telefone: "); scanf("%s", c.telefone);

    FILE *arq = fopen("agenda.bin", "ab");
    fwrite(&c, sizeof(Contato), 1, arq);
    fclose(arq);
}

void listar_contatos() {
    FILE *arq = fopen("agenda.bin", "rb");
    if (!arq) return;
    Contato c;
    while (fread(&c, sizeof(Contato), 1, arq)) {
        printf("%d - %s - %s\n", c.id, c.nome, c.telefone);
    }
    fclose(arq);
}

void buscar_contato(int id) {
    FILE *arq = fopen("agenda.bin", "rb");
    if (!arq) return;
    Contato c;
    while (fread(&c, sizeof(Contato), 1, arq)) {
        if (c.id == id) {
            printf("Encontrado: %s - %s\n", c.nome, c.telefone);
            fclose(arq);
            return;
        }
    }
    printf("Não encontrado.\n");
    fclose(arq);
}

int main() {
    adicionar_contato();
    listar_contatos();
    buscar_contato(1);
    return 0;
}