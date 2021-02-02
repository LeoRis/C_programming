#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[] = { 1, 2, 3, 4 };

    int *pointerArray;

    pointerArray = &array;

    int *newPointer;

    newPointer = &pointerArray;

    int derefePointer = *pointerArray;

    printf("%u\n", pointerArray);   // Prints out the memory address of "array".
    printf("%d\n", *pointerArray);  // Dereferencing of "pointerArray" - prints out the first element of "array" i.e. 1
    printf("%d\n", derefePointer);  // Dereferencing through another variable.

    char c = 'A';

    char *cPointer = &c;

    printf("%c\n", *cPointer);      // Dereferencing a char - prints out "A"
                                    // If we want to print the ASCII code for "A", we should use %d.

    int nums[] = { 5, 6, 7, 8 };

    int *nPointer = &nums;

    printf("%d\n", nPointer[3]);    // Access to "nums" array via pointer variable "nPointer" and returns the 3rd element;
    printf("%u\t%u", nPointer, nums);

    return 0;
}
