#include <stdio.h>

int main(){

    int slices = 20;

    int *p = &slices;

    printf("Slices: %d\n", slices);
    printf("Slices (thorough pointer) : %d\n", *p);

    slices = 21;

    printf("Slices: %d\n", slices);
    printf("Slices (thorough pointer) : %d\n", *p);

    *p = 25;

    printf("Slices: %d\n", slices);
    printf("Slices (thorough pointer) : %d\n", *p);

    slices++;
    (*p)++; // If we neglect the brackets the program does this: *(p++)
            // because ++ has higher priority than *.

    printf("Slices: %d\n", slices);
    printf("Slices (thorough pointer) : %d\n", *p);

    return 0;
}
