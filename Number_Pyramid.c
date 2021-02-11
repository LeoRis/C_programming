#include <stdio.h>

int main(){

    int rows, space, i;

    int counter = 0;
    int counter1 = 0;
    int k = 0;


    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++){
        for(space = 1; space <= rows - i; ++space){
            printf("  ");
            ++counter;
        }
        while(k != 2 * i - 1){
            if(counter <= rows - 1){
                printf("%d ", i + k);
                ++counter;
            }else{
                ++counter1;
                printf("%d ", (i + k - 2 * counter1));
            }
            ++k;
        }
        counter1 = counter = k = 0;
        printf("\n");
    }
    return 0;
}
