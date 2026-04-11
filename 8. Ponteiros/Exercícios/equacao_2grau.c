#include <math.h>
#include <stdio.h>

int resolverEquacao(double a, double b, double c, double *r1, double *r2) {
    if (a == 0) {
        return -1; // 1 raiz
    }

    double delta = b*b - 4*a*c;

    if (delta < 0) 
        return 0; // não há raízes reais
    

    if (delta == 0) {
        *r1 = -b / (2*a);
        return 1; // uma raiz
    }

    double raizDelta = sqrt(delta);

    *r1 = (-b + raizDelta) / (2*a);
    *r2 = (-b - raizDelta) / (2*a);

    return 2; // duas raízes distintas
}


int main() {
    double r1, r2;
    int resultado;

    resultado = resolverEquacao(1, -5, 6, &r1, &r2);

    if (resultado == 2)
        printf("Duas raízes: %.2lf e %.2lf\n", r1, r2);
    else if (resultado == 1)
        printf("Uma raiz: %.2lf\n", r1);
    else if (resultado == 0)
        printf("Não há raízes reais\n");
    else
        printf("Não é equação do 2º grau\n");

    return 0;
}
