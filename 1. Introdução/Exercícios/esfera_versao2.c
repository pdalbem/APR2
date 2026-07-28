#include <stdio.h>
#include <math.h>

/*
Este código utiliza a função pow(base,expoente) da biblioteca <math.h>
Para compilá-lo, é preciso utilizar -lm
Faça isso no terminal para compilar: gcc esfera_versao2.c -o esfera_versao2 -lm 
Faça isso no terminal para executar: ./esfera_versao2   
*/

#define PI 3.14159

int main() {
    float raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    area = 4 * PI * pow(raio,2);
    volume = (4.0 / 3.0) * PI * pow(raio,3);

    printf("\nArea da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    return 0;
}
