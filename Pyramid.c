#include <stdio.h>

int main(){

    int rows, i, j, k, l;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++){
        for(k = rows; k >= i; k--){
            printf(" ");
        }
        for(j = 0; j <= i; j++){
            printf("*");
        }
        for(l = 1; l <= i; l++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int i, j, n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++){
        for(j = 0; j <= 2 * n - 1; j++){
            if(j >= n - (i - 1) && j <= n + (i - 1)){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
