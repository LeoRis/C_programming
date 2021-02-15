#include <stdio.h>
#include <math.h>

int main(){

    int number1, number2;

    printf("Enter first number: ");
    scanf("%d", &number1);

    printf("Enter second number: ");
    scanf("%d", &number2);

    while(number2){
        number1++;
        number2--;
    }

    printf("The sum of the 2 numbers is: %d", number1);

    return 0;
}
