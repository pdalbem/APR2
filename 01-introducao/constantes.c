#include <stdio.h>

#define PI_MACRO 3.14159

int main() {
    const float PI_CONST = 3.14159;

    printf("PI (macro): %.2f\n", PI_MACRO);
    printf("PI (const): %.2f\n", PI_CONST);

    return 0;
}
