#include <stdio.h>

#define ESCOLAS 4
#define CATEGORIAS 3
#define JURADOS 2

void lerNotas(float notas[ESCOLAS][CATEGORIAS][JURADOS]);
float totalEscola(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola);
float mediaCategoria(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola, int categoria);
void escolasCampeas(float notas[ESCOLAS][CATEGORIAS][JURADOS]);

int main() {

    float notas[ESCOLAS][CATEGORIAS][JURADOS];

    lerNotas(notas);

    for (int escola = 0; escola < ESCOLAS; escola++) {
        printf("Total da escola %d: %.2f\n",
               escola + 1,
               totalEscola(notas, escola));
    }

    printf("\nMédia da categoria 2 da escola 1: %.2f\n", mediaCategoria(notas, 0, 1));

    escolasCampeas(notas);

    return 0;
}

void lerNotas(float notas[ESCOLAS][CATEGORIAS][JURADOS]) {

    for (int escola = 0; escola < ESCOLAS; escola++) {
        printf("\nEscola %d\n", escola + 1);
        for (int categoria = 0; categoria < CATEGORIAS; categoria++) {
            for (int jurado = 0; jurado < JURADOS; jurado++) {
                printf("Categoria %d - Jurado %d: ", categoria + 1, jurado + 1);
                scanf("%f", &notas[escola][categoria][jurado]);
            }
        }
    }
}

float totalEscola(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola) {
    float total = 0;
    for (int categoria = 0; categoria < CATEGORIAS; categoria++) 
        for (int jurado = 0; jurado < JURADOS; jurado++) 
            total += notas[escola][categoria][jurado];
 
    return total;
}

float mediaCategoria(float notas[ESCOLAS][CATEGORIAS][JURADOS], int escola, int categoria) {
    float soma = 0;

    for (int jurado = 0; jurado < JURADOS; jurado++) 
        soma += notas[escola][categoria][jurado];
    
    return soma / JURADOS;
}

void escolasCampeas(float notas[ESCOLAS][CATEGORIAS][JURADOS]) {
    float maiorTotal = totalEscola(notas, 0);

    // Descobre a nota maior
    for (int escola = 1; escola < ESCOLAS; escola++) {
        float total = totalEscola(notas, escola);

        if (total > maiorTotal) 
            maiorTotal = total;
        
    }

    // Exibe todas as escolas com o maior total
    printf("\nEscola(s) campeã(s):\n");

    for (int escola = 0; escola < ESCOLAS; escola++) 
        if (totalEscola(notas, escola) == maiorTotal) 
            printf("Escola %d\n", escola + 1);      
    
}

int escolaCampea(float notas[ESCOLAS][CATEGORIAS][JURADOS]) {
    int campea = 0;
    float maiorTotal = totalEscola(notas, 0);

    for (int escola = 1; escola < ESCOLAS; escola++) {
        float total = totalEscola(notas, escola);
        if (total > maiorTotal) {
            maiorTotal = total;
            campea = escola;
        }
    }

    return campea;
}