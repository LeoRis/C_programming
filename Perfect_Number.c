#include <stdio.h>
#include <math.h>

int main() {

    int number, i, remainder, sum = 0;

    printf("Insert a number: ");
    scanf("%d", &number);

    for(i = 1; i < number; i++){
        remainder = number % i;
        if(remainder == 0){
            sum += i;
        }
    }

    if(sum == number){
        printf("The number %d is a perfect number.\n", number);
    }else{
        printf("The number %d is NOT a perfect number.\n", number);
    }

    return 0;
}
