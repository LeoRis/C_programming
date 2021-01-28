#include <stdio.h>
#include <ctype.h>

#define MAX 20 // Maximum size of string.

void lower(char s[]){

    int i = 0;
    int c;

    while((c = s[i]) != '\n'){
        (c >= 'A' && c <= 'Z') ? s[i++] += 'a' - 'A' : i++;
    }
}

int main(){

    char c;
    int i;
    char s[MAX];

    i = 0;
    while((c = getchar()) != '\n'){
        s[i++] = c;
    }

    lower(s);

    printf("%s", s);

    return 0;
}
