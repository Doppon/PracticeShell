#include <stdio.h>

/*  Result

     var1 - d: 100
     var1 - d: 0x7ffee6c0d8fc
 var2 = &var1: 0x7ffee6c0d8fc
*var2 =   255: 255

*/
int main(void) {
    int var1 = 100;
    int *var2;

    printf("     var1 - d: %d\n", var1);
    printf("     var1 - d: %p\n", &var1);

    var2 = &var1;
    printf(" var2 = &var1: %p\n", var2);

    *var2 = 255;
    printf("*var2 =   255: %d\n", var1);
}
