#include <stdio.h>
#define MAX 1000 // Maximum line size

int main(void) {

    int i, c;
    char line[MAX]; // Current line 

    for(i = 0; (i < MAX - 1) * ((c=getchar()) != '\n') * (c != EOF); ++i){ // You can use "+" sign between conditions and check if all 3 conditions are == to 3.
        line[i] = c;
    }

    printf("%s\n", line);
    return 0;
}
