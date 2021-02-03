#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char name;      // The size is 1 byte
    int age;        // The size is 1 byte
    float score;    // The size is 1 byte
    short quote;    // The size is 1 byte

} client;

int main(){

    client cl;

    printf("%d\n", sizeof(client)); // Returns the size of the client struct.

    int i = 5;
    int x = 7;

    int *myPointer = &i;
    int *pointer = &x;

    printf("%d\n%d\n", *myPointer, *(myPointer - 1)); // Prints out the values of i and x.

    int arr[] = { 1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14 };
    printf("Number of elements:%lu\n", sizeof(arr) / sizeof(arr[0]));

    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(double));
}
