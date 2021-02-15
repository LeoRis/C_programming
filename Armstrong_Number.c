#include <stdio.h>

int numberLength(int n);

int power(int m, int n);

int main(){

    int number, i, remainder, result, realNumberLength, realNumber;

    printf("Insert the test number: ");
    scanf("%d", &number);

    realNumber = number;

    realNumberLength = numberLength(number);

    result = 0;
    for(i = 0; i < realNumberLength; i++){
        remainder = number % 10;
        result += power(remainder, realNumberLength);
        number /= 10;
    }

    if(realNumber == result){
        printf("This is an Armstrong number.\n");
    }else{
        printf("This is NOT an Armstrong number.\n");
    }

    return 0;
}

int numberLength(int n){
    int counter = 0;

    while(n){
        n /= 10;
        counter++;
    }

    return counter;
}

int power(int m, int n){

    int result1 = 1;

    while(n > 0){
        result1 *= m;
        n--;
    }

    return result1;
}
