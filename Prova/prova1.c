#include <stdio.h>
#include <string.h>

#define MAX 10

// a) Struct Paciente
typedef struct {
    char nome[100];
    float peso;
    float altura;
    float imc;
} Paciente;

// b) Função para calcular IMC de um paciente
float calcularIMC(Paciente p) {
    return p.peso / (p.altura * p.altura);
}

// c) Função para calcular média dos IMCs
float calcularMediaIMC(Paciente v[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i].imc;
    }
    return soma / n;
}

// d) Função para ler pacientes e calcular IMC automaticamente
void lerPacientes(Paciente v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPaciente %d\n", i + 1);
    
        printf("Nome: ");
        fgets(v[i].nome, sizeof(v[i].nome), stdin);
        v[i].nome[strcspn(v[i].nome, "\n")] = '\0'; 

        printf("Peso: ");
        scanf("%f", &v[i].peso);

        printf("Altura: ");
        scanf("%f", &v[i].altura);

        // calcular IMC automaticamente
        v[i].imc = calcularIMC(v[i]);
     
        while (getchar() != '\n');  
    }
}

// e) Retornar paciente com maior IMC >= média
Paciente maiorIMCAcimaMedia(Paciente v[], int n) {
    float media = calcularMediaIMC(v, n);
    Paciente paciente;
    float maiorIMC = -1;

    for (int i = 0; i < n; i++) 
        if (v[i].imc >= media) 
            if (v[i].imc > maiorIMC) { 
                paciente = v[i];
                maiorIMC = v[i].imc;
            }
        
    return paciente;
}

// f) Buscar pacientes por nome e mostrar se IMC >= média
void buscarPacientes(Paciente v[], int n, char nomeBusca[]) {
    float media = calcularMediaIMC(v, n);
    int encontrou = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].nome, nomeBusca) == 0) {
            encontrou = 1;

            if (v[i].imc >= media) {
                printf("\nPaciente encontrado:\n");
                printf("Nome: %s\n", v[i].nome);
                printf("Peso: %.2f\n", v[i].peso);
                printf("Altura: %.2f\n", v[i].altura);
                printf("IMC: %.2f\n", v[i].imc);
            }
        }
    }

    if (!encontrou) {
        printf("\nNenhum paciente encontrado com esse nome que tenha IMC maior que média.\n");
    }
}

// Função auxiliar para exibir paciente
void exibirPaciente(Paciente p) {
    printf("\nNome: %s\n", p.nome);
    printf("Peso: %.2f\n", p.peso);
    printf("Altura: %.2f\n", p.altura);
    printf("IMC: %.2f\n", p.imc);
}


int main() {
    Paciente pacientes[MAX];
    int n;
    char nomeBusca[100];

    printf("Quantidade de pacientes (<= %d): ", MAX);
    scanf("%d", &n);
    while (getchar() != '\n');  

    lerPacientes(pacientes, n);

    float media = calcularMediaIMC(pacientes, n);
    printf("\nMedia dos IMCs: %.2f\n", media);

    Paciente p = maiorIMCAcimaMedia(pacientes, n);
    printf("\nPaciente com maior IMC >= media:\n");
    exibirPaciente(p);

    printf("\nDigite o nome para busca: ");
    getchar();
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    buscarPacientes(pacientes, n, nomeBusca);

    return 0;
}