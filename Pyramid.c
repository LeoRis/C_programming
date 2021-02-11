#include <stdio.h>

int main(){

    int rows, i, j, k;
    char space = ' ';

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++){
        for(k = rows; k >= i; k--){
            printf(" ");
        }
        for(j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
