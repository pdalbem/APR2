#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    float peso;
    float altura;
    float imc;
} Paciente;


float calcularIMC(Paciente paciente);
float calcularMediaIMC(Paciente pacientes[], int n);
void lerPacientes(Paciente pacientes[], int n);
void buscarPaciente(Paciente pacientes[], int n, char nome[]);


int main() {
    Paciente pacientes[MAX_PACIENTES];
    int n;
    char nome[TAM_NOME];

    printf("Quantidade de pacientes (máx: %d): ", MAX_PACIENTES);
    scanf("%d", &n);

    lerPacientes(pacientes, n);

    while (getchar()!='\n');

    printf("\nDigite o nome para busca: ");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    buscarPaciente(pacientes, n, nome);

    return 0;
}


/* Calcula e retorna o IMC de um paciente */
float calcularIMC(Paciente paciente) {
    return paciente.peso / (paciente.altura * paciente.altura);
}


/* Calcula e retorna a média dos IMCs */
float calcularMediaIMC(Paciente pacientes[], int n) {
    float soma = 0;

    for (int i = 0; i < n; i++) {
        soma += pacientes[i].imc;
    }

    return soma / n;
}


/* Lê os dados dos pacientes e calcula o IMC */
void lerPacientes(Paciente pacientes[], int n) {

    for (int i = 0; i < n; i++) {
        while (getchar()!='\n');

        printf("\nPaciente: %d\n", i + 1);

        printf("Nome: ");
        fgets(pacientes[i].nome, TAM_NOME, stdin);
        pacientes[i].nome[strcspn(pacientes[i].nome, "\n")] = '\0';

        printf("Peso: ");
        scanf("%f", &pacientes[i].peso);

        printf("Altura: ");
        scanf("%f", &pacientes[i].altura);

        pacientes[i].imc = calcularIMC(pacientes[i]); //calcula automaticamente
    }
}


/* Busca pacientes pelo nome e exibe aqueles
   cujo IMC seja maior ou igual à média */
void buscarPaciente(Paciente pacientes[], int n, char nome[]) {
    float media = calcularMediaIMC(pacientes, n);
    printf("\nMédia dos IMCs: %.2f\n", media);
    int encontrado = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(pacientes[i].nome, nome) == 0 && pacientes[i].imc >= media) {
            encontrado = 1;
            printf("\nPaciente encontrado:\n");
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Peso: %.2f kg\n", pacientes[i].peso);
            printf("Altura: %.2f m\n", pacientes[i].altura);
            printf("IMC: %.2f\n", pacientes[i].imc);
        }
    }

    if (!encontrado) 
        printf("\nNenhum paciente com esse nome e IMC acima ou igual à média.\n");
    
}