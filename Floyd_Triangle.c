#include <stdio.h>

// Program to print Floyd's Triangle.
int main(){

    int rows, i, j, n;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    n = 1;

    for(i = 0; i < rows; i++){
        for(j = 0; j <= i; j++){
            printf("%d ", n);
            n++;
        }
        printf("\n");
    }

    return 0;
}
