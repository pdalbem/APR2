#include <stdio.h>

int main() {
    int d1, m1, a1;
    int d2, m2, a2;

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &d1, &m1, &a1);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &d2, &m2, &a2);

    if (a1 > a2) {
        printf("A primeira data e mais recente.\n");
    } else if (a1 < a2) {
        printf("A segunda data e mais recente.\n");
    } else { // anos iguais
        if (m1 > m2) {
            printf("A primeira data e mais recente.\n");
        } else if (m1 < m2) {
            printf("A segunda data e mais recente.\n");
        } else { // meses iguais
            if (d1 > d2) {
                printf("A primeira data e mais recente.\n");
            } else if (d1 < d2) {
                printf("A segunda data e mais recente.\n");
            } else {
                printf("As duas datas sao iguais.\n");
            }
        }
    }

    return 0;
}
