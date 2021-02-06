#include <stdio.h>

// Increase each array element by 1 and print it out.
void printArray(int arr[], int size){

    for(int i = 0; i < size; i++){
        arr[i]++;
        printf("%d ", arr[i]);
    }
}

int main(){

    int piecesOfBread[] = {4, 3, 5, 2, 1, 6, 7};

    int size = sizeof piecesOfBread / sizeof piecesOfBread[0];  // Returns the size of the array --> each element is "int" data type.
                                                                // This array has 7 elements thus 7 X 4 = 28. Or, 28 / 4 = 7 ==> the size of the array.

    printf("This array has %d elements.\nHere they are: ", size);

    printArray(piecesOfBread, size);

    return 0;
}
