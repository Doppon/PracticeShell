#include <stdio.h>

int main(void) {
    int var1 = 100;
    int *var2;

    printf("    var1 - d: %d\n", var1);
    printf("    var1 - d: %p\n", &var1);

    var2 = &var1;
    printf("var2 = &var1: %p\n", var2);

    *var2 = 255;
    printf(" *var2 = 255: %d\n", var1);
}
