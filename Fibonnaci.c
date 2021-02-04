#include <stdio.h>

int fibonacci(int n1, int n2){

    int sum;

    while(n2 < 100){
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        printf("%d\n", n1);
        return fibonacci(n1, sum);
    }
}

int main(){

    int n1 = 1;
    int n2 = 1;

    fibonacci(n1, n2);

    return 0;
}
