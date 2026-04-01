#include <stdio.h>

#define ESCOLAS 4
#define CATEGORIAS 3
#define JURADOS 2

//Nas funções, eu forneço o tamanho da primeira dimensão da matriz apenas para deixar mais claro o entendimento.
//Poderia omitir, conforme visto em aula:
//void lerNotas(float notas[][CATEGORIAS][JURADOS]); 
//float calcularSomaEscola(float notas[][CATEGORIAS][JURADOS], int escola);
//float calcularMediaCategoria(float notas[][CATEGORIAS][JURADOS], int escola, int categoria);
//void exibirResultados(float notas[][CATEGORIAS][JURADOS]);

void lerNotas(float notas[ESCOLAS][CATEGORIAS][JURADOS]) {
    for (int e = 0; e < ESCOLAS; e++) {
        printf("\nEscola %d:\n", e + 1);
        for (int c = 0; c < CATEGORIAS; c++) 
            for (int j = 0; j < JURADOS; j++) {
                printf("Categoria %d - Jurado %d: ", c + 1, j + 1);
                scanf("%f", &notas[e][c][j]);
            }
        
    }
}

float calcularSomaEscola(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola) {
    float soma = 0;

    for (int c = 0; c < CATEGORIAS; c++) 
        for (int j = 0; j < JURADOS; j++) 
            soma += notas[escola][c][j];
        
    return soma;
}

float calcularMediaCategoria(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola, int categoria) {
    float soma = 0;

    for (int j = 0; j < JURADOS; j++) 
        soma += notas[escola][categoria][j];
    
    return soma / JURADOS;
}


void exibirResultados(float notas[ESCOLAS][CATEGORIAS][JURADOS]) {
    for (int e = 0; e < ESCOLAS; e++) {
        printf("\n Escola %d \n", e + 1);

        // Soma total
        float total = calcularSomaEscola(notas, e);
        printf("Total de pontos: %.2f\n", total);

        // Médias por categoria
        for (int c = 0; c < CATEGORIAS; c++) {
            float media = calcularMediaCategoria(notas, e, c);
            printf("Media da categoria %d: %.2f\n", c + 1, media);
        }
    }
}

int main() {
    float notas[ESCOLAS][CATEGORIAS][JURADOS];

    lerNotas(notas);
    exibirResultados(notas);

    return 0;
}