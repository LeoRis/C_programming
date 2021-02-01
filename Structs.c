#include <stdio.h>
#include <stdlib.h>

// Defining a struct called fraction.
typedef struct {

  int numerator;
  int denomonator;

} fraction;

// Prints out the elements of a certain fraction struct.
void printFraction(fraction f){
    printf("%d/%d\n", f.numerator, f.denomonator);
}

int main(){

    fraction myFraction;

    myFraction.numerator = 1;
    myFraction.denomonator = 2;

    fraction otherFraction;

    otherFraction.numerator = 2;
    otherFraction.denomonator = 5;

    fraction fArray[] = {myFraction, otherFraction};

    for(int i = 0; i < 2; i++){
        printFraction(fArray[i]);
    }

    return 0;
}
