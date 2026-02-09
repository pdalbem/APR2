#include <stdio.h>

int main()
{
    int dia = 4;
    switch (dia)
    {
    case 1:
        printf("Domingo\n");
        break;
    case 2 ... 6: // intervalo de valores
        printf("Dia útil\n");
        break;
    case 7:
        printf("Sábado\n");
        break;
    default:
        printf("Dia inválido\n");
    }

    return 0;
}

