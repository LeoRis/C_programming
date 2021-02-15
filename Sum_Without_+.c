#include <stdio.h>
#include <math.h>

int main(){

    int number1, number2;

    printf("Enter first number: ");
    scanf("%d", &number1);

    printf("Enter second number: ");
    scanf("%d", &number2);
    
    if(number2 > 0){
        while(number2){
            number1++;
            number2--;
        }
    }else if(number2 < 0){
        while(number2){
            number1--;
            number2++;
        }
    }

    printf("The sum of the 2 numbers is: %d", number1);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int a, b, sum, carry;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);
    
    while(b != 0){
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    }

    printf("The sum of the 2 numbers is: %d", sum);

    return 0;
}
