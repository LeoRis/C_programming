#include <stdio.h>
#include <math.h>

#define MAX 100

void swap(int *x, int *y){
    int t;

    t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort(int *s, int length){
    int i, j;

    for(i = 1; i < length; i++){
        for(j = 0; j < length - i; j++){
            if(*(s + j) > *(s + j + 1)){
                swap(s + j, s + j + 1);
            }
        }
    }
}

void selectionSort(int *s, int length, int m){

    if(length - m == 1){
        return ;
    }else{
        int smallest = *(s + m);
        int indexSmallest = m;
        int i;
        for(i = m; i < length; i++){
            if(*(s + i) < smallest){
                smallest = *(s + i);
                indexSmallest = i;
            }
        }
        swap(s + m, s + indexSmallest);
        selectionSort(s, length, m + 1);
    }
}

void insertionSort(int *s, int length){
    int i, j;

    for(i = 1; i < length; i++){
        int temp = *(s + i);
        j = i - 1;
        while(temp < *(s + j) && j >= 0){
            *(s + j + 1) = *(s + j);
            j--;
        }
        *(s + j + 1) = temp;
    }
}

void insert(int *s, int n){
    int i;
    printf("Start entering: \n");
    for(i = 0; i < n; i++){
        scanf("%d", (s + i));
    }
}

void print(int *s, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", *(s + i));
    }
    printf("\n");
}

int main(){

    int s[MAX];
    int n;

    printf("Array length: \n");
    scanf("%d", &n);

    insert(s, n);
    printf("This is the array: ");
    print(s, n);

    bubbleSort(s, n);
    printf("This is the array using bubbleSort method: ");
    print(s, n);

    selectionSort(s, n, 0);
    printf("This is the array using selectionSort method: ");
    print(s, n);

    insertionSort(s, n);
    printf("This is the array using insertionSrort method: ");
    print(s, n);

    return 0;
}
