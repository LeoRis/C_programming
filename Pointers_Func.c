#include <stdio.h>

void change_number(int *x);

int main()
{

    int x;
    printf("Give number x: ");
    scanf("%d", &x);

    printf("In main program: x = %d\n", x);

    change_number(&x);

    printf("In main program: x = %d\n", x);

    return 0;

}

void change_number(int *x)
{

    int *pointer_x;

    pointer_x = &x;

    *x = *x + 3;

    printf("In sub program: x = %d\n", *pointer_x);

}
