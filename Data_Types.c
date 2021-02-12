#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>

int main(){

    printf("The size of a char is: %d\n", sizeof(char));
    printf("The size of a short is: %d\n", sizeof(short));
    printf("The size of an int is: %d\n", sizeof(int));
    printf("The size of a long is: %d\n", sizeof(long int));
    printf("The size of a float is: %d \n", sizeof(float));

    printf("\nThe number of bits in a byte = %d\n", CHAR_BIT);
    printf("\nThe minimum value of Signed CHAR is = %d\n", SCHAR_MIN);
    printf("The maximum value of Signed CHAR is = %d\n", SCHAR_MAX);
    printf("The minimum value of CHAR is = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR is = %d\n", CHAR_MAX);
    printf("The maximum value of Unsigned CHAR is = %u\n", UCHAR_MAX);

    printf("\nThe minimum value of Signed Short is = %d\n", SHRT_MIN);
    printf("The maximum value of Signed Short is = %d\n", SHRT_MAX);
    printf("The maximum value of Unsigned Short is = %u\n", USHRT_MAX);

    printf("\nThe minimum value of Signed INT is = %d\n", INT_MIN);
    printf("The maximum value of Signed INT is = %d\n", INT_MAX);
    printf("The maximum value of Unsigned INT is = %u\n", UINT_MAX);

    printf("\nThe minimum value of Signed LONG is = %ld\n", LONG_MIN);
    printf("The maximum value of Signed LONG is = %ld\n", LONG_MAX);
    printf("The maximum value of Unsigned LONG is = %lu\n", ULONG_MAX);

    printf("\nStorage size for float : %d \n", sizeof(float));

    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
    printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
    printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
    printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
    printf("Precision value: %d\n", FLT_DIG );
}
