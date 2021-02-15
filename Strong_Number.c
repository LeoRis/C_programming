#include <stdio.h>

int factorial(int n);

int main(){

    int number, digit, realNumber, sum = 0;

    printf("Insert the test case number: ");
    scanf("%d", &number);

    realNumber = number;

    while(number){
        digit = number % 10;
        sum += factorial(digit);
        number /= 10;
    }

    if(realNumber == sum){
        printf("This is a strong number.\n");
    }else{
        printf("This is NOT a strong number.");
    }

    return 0;
}

int factorial(int n){
    if(!n){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}
