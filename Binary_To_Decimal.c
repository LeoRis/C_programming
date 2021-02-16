#include <stdio.h>

int main(){

    int decimal = 0, binary, base = 1, remainder, number;

    printf("Enter binary number: ");
    scanf("%d", &binary);

    number = binary;

    while(binary){
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal equivalent of the binary number %d is %d.", number, decimal);

    return 0;
}
