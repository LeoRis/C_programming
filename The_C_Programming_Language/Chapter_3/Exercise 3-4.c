#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void itoa(long n, char s[]);
void reverse(char s[]);

int main(){
    char buffer[20];

    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buffer);
    printf("Buffer : %s\n", buffer);

    return 0;
}

void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(long n, char s[]){
    long i, sign;
    sign = n;

    i = 0;
    do{
        s[i++] = abs(n % 10) + '0';
    }while(n /= 10);

    if(sign < 0){
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}
