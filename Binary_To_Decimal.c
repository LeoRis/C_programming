#include <stdio.h>
#include <math.h>

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    int binary, temp, remainder, result, counter, digit;
    remainder = result = counter = digit = 0;

    printf("Enter a binary number : ");
    scanf("%d",&binary);

    temp = binary;

    while(temp){
        temp /= 10;
        counter++;
    }

    for(int i = 0; i < counter; i++){
        remainder = binary % 10;
        digit = remainder * pow(2, i);
        result += digit;
        binary /= 10;
    }
    printf("%d is the required decimal number.", result);
    return 0;
}
