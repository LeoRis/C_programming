#include <stdio.h>

// Calculate the sum of: 1! + (1 + 2)! + (1 + 2 + 3)! ... (1 + 2 + ... + n)!

int factorial(int n){
    if(!n){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}

int sum(int m){
    if(!m){
        return 0;
    }else{
        return m + sum(m - 1);
    }
}

int main(){

    int m, i;

    int score = 0;

    printf("Insert length: \n");
    scanf("%d", &m);

    if(m > 0){
        for(i = 1; i < m; i++){
            score += factorial(sum(i));
            printf("%d! + ", sum(i));
        }
        score += factorial(sum(m));
        printf("%d! = %d", sum(m), score);
    }else{
        printf("Wrong value!");
    }

    return 0;
}
