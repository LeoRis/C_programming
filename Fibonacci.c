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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int a = 0;
    int b = 1;
    int i, n, result;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++){
        printf("%d ", a);

        result = a + b;
        a = b;
        b = result;
    }
    return 0;
}
