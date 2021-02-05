#include <stdio.h>

void swap(int *n1, int *n2){
    int temp;
    temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

int main(){

    int number1, number2;

    printf("Insert number 1:");
    scanf("%d", &number1);

    printf("Insert number 2:");
    scanf("%d", &number2);

    swap(&number1, &number2);

    printf("New number 1 is %d.\n", number1);
    printf("New number 2 is %d.\n", number2);

    return 0;
}
