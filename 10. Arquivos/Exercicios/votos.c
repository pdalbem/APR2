#include <stdio.h>
#include <stdlib.h>


void apurarVotos(int votos[], int *nulos);
void mostrarResultado(int votos[], int nulos);

int main() {
    int votos[3] = {0}; // inicializa com zeros
    int votosNulos = 0;

    apurarVotos(votos, &votosNulos);
    mostrarResultado(votos, votosNulos);

    return 0;
}

void apurarVotos(int votos[], int *nulos) {
    FILE *arq = fopen("votos.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int voto;

    while (fscanf(arq, "%d", &voto) == 1) {

        if (voto == 100)
            votos[0]++;
        else if (voto == 200)
            votos[1]++;
        else if (voto == 300)
            votos[2]++;
        else
            (*nulos)++;
    }

    fclose(arq);
}

void mostrarResultado(int votos[], int nulos) {
    int codigos[3] = {100, 200, 300};

    printf("\nResultado da Eleição\n");

    for (int i = 0; i < 3; i++) 
        printf("Candidato %d: %d votos\n", codigos[i], votos[i]);
    

    printf("Votos nulos: %d\n", nulos);
}