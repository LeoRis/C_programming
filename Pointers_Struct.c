#include <stdio.h>

typedef struct{

    char *name;
    char *email;
    int age;

} client;

int main(){

    client c1;

    c1.name = "Jack Sparrow";
    c1.email = "theblackpear@gmail.com";
    c1.age = 35;

    printf("%c\n", c1.name[1]); // Prints out the element at index 1 because pointer is the exact same thing as an array.

    return 0;
}
