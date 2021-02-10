#include <stdio.h>
#include <string.h>

#define MAX 100

void printArray(char *s);

int main(){

    char s[MAX];

    printArray(s);

    printf("\nThis string is %d characters long.\n", strlen(s));

    return 0;
}

void printArray(char *s){
    int i = 0;
    char c;

    while((c = getchar()) != '\n'){
        *(s + i++) = c;
    }
    *(s + i) = '\0';

    printf("%s\n", s);
}
