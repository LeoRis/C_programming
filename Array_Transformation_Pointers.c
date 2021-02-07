#include <stdio.h>

#define MAX 50

// Input array s1[0], s1[1], s1[2]... s1[n - 1] is transformed into
// output array s2[0] = s1[0] + s1[n - 1]
//              s2[1] = s1[1] + s1[n - 2]
//                .
//                .
//                .
//              s2[n] = s1[n - 1] + s1[0]

void transformArray(int *s1, int *s2, int n){
    int i, j;
    for(i = 0, j = 1; i < n, j <= n; i++, j++){
        *(s2 + i) = *(s1 + i) + *(s1 + (n - j));
    }
}

int main(){

    int n, i;

    int s1[MAX], s2[MAX];

    printf("Insert array number of elements: ");
    scanf("%d", &n);

    printf("Insert elements:");
    for(i = 0; i < n; i++){
        scanf("%d", &s1[i]);
    }

    printf("Current array: ");

    for(i = 0; i < n; i++){
        printf("%d ", s1[i]);
    }

    transformArray(&s1, &s2, n);

    printf("\nTransformed array: ");

    for(i = 0; i < n; i++){
        printf("%d ", s2[i]);
    }

    return 0;
}
