#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define ARQ "funcionarios.dat"

typedef struct {
    int    id;
    char   nome[MAX_NOME];
    float  salario;
    int    ativo;          /* 1 = ativo, 0 = inativo */
} Funcionario;

/* ---- salva um funcionário no final do arquivo ---- */
int salvar(const Funcionario *f) {
    FILE *fp = fopen(ARQ, "ab");
    if (!fp) return -1;
    fwrite(f, sizeof(Funcionario), 1, fp);
    fclose(fp);
    return 0;
}

/* ---- lista todos os funcionários ativos ---- */
void listar(void) {
    FILE *fp = fopen(ARQ, "rb");
    if (!fp) { printf("Nenhum registro.\n"); return; }

    Funcionario f;
    printf("%-4s %-25s %10s\n", "ID", "Nome", "Salário");
    printf("%.44s\n", "--------------------------------------------");

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (f.ativo)
            printf("%-4d %-25s R$%9.2f\n", f.id, f.nome, f.salario);
    }
    fclose(fp);
}

/* ---- busca por ID e exibe ---- */
int buscar(int id) {
    FILE *fp = fopen(ARQ, "rb");
    if (!fp) return -1;

    Funcionario f;
    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (f.id == id) {
            printf("Encontrado: %s (R$%.2f)\n", f.nome, f.salario);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    printf("ID %d não encontrado.\n", id);
    return -1;
}

int main(void) {
    Funcionario f1 = {1, "Ana Lima",    4500.00, 1};
    Funcionario f2 = {2, "Bruno Costa", 3800.00, 1};
    Funcionario f3 = {3, "Carla Melo",  5200.00, 0}; /* inativa */

    salvar(&f1);
    salvar(&f2);
    salvar(&f3);

    printf("\n--- Funcionários ativos ---\n");
    listar();

    printf("\n--- Busca por ID 2 ---\n");
    buscar(2);

    return 0;
}