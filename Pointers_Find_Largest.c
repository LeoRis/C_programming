#include <stdio.h>

#define N 5

void find_largeset(int *p, int n){
    int i, max;

    max = *p;

    for(i = 0; i < n; i++){
        if(*p > max){
            max = *p;
        }
        p++;
    }
    printf("The largest number is: %d", max);
}

int main(){

    int b[N] = {8, 9, 1, 4, 17};

    find_largeset(&b[0], N);

    return 0;
}
