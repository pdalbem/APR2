#include <stdio.h>

int main(){
    printf("Tipos inteiros\n");
    printf("char                 : %2zu byte(s)\n", sizeof(char));
    printf("signed char          : %2zu byte(s)\n", sizeof(signed char));
    printf("unsigned char        : %2zu byte(s)\n", sizeof(unsigned char));

    printf("\n");
    printf("short                : %2zu byte(s)\n", sizeof(short));
    printf("short int            : %2zu byte(s)\n", sizeof(short int));
    printf("signed short         : %2zu byte(s)\n", sizeof(signed short));
    printf("unsigned short       : %2zu byte(s)\n", sizeof(unsigned short));

    printf("\n");
    printf("int                  : %2zu byte(s)\n", sizeof(int));
    printf("signed int           : %2zu byte(s)\n", sizeof(signed int));
    printf("unsigned int         : %2zu byte(s)\n", sizeof(unsigned int));

    printf("\n");
    printf("long                 : %2zu byte(s)\n", sizeof(long));
    printf("long int             : %2zu byte(s)\n", sizeof(long int));
    printf("signed long          : %2zu byte(s)\n", sizeof(signed long));
    printf("unsigned long        : %2zu byte(s)\n", sizeof(unsigned long));

    printf("\n");
    printf("long long            : %2zu byte(s)\n", sizeof(long long));
    printf("long long int        : %2zu byte(s)\n", sizeof(long long int));
    printf("signed long long     : %2zu byte(s)\n", sizeof(signed long long));
    printf("unsigned long long   : %2zu byte(s)\n", sizeof(unsigned long long));

    printf("\nTipos de ponto flutuante\n");
    printf("float                : %2zu byte(s)\n", sizeof(float));
    printf("double               : %2zu byte(s)\n", sizeof(double));
    printf("long double          : %2zu byte(s)\n", sizeof(long double));

    return 0;
}