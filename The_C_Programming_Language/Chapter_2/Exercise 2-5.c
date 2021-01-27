#include <stdio.h>

#define MAX 20 // Maximum string length

int any(char s1[], char s2[]){

    int i, j;

    for(i = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0'; j++){
            if(s1[i] == s2[j]){
                return i;
            }
        }
    }

    return -1;
}

int main(){

    char s1[MAX], s2[MAX], c;
    int answer;

    int i, j;

    printf("Insert first string:\n");

    i = 0;
    while((c = getchar()) != '\n'){
        s1[i++] = c;
    }

    printf("Insert second string:\n");

    j = 0;
    while((c = getchar()) != '\n'){
        s2[j++] = c;
    }

    answer = any(s1, s2);

    if(answer >= 0){
		printf("First match is \"%c\" in position %d of s1.\n",
            s1[answer], answer);
    }else{
        printf("\"%s\" contains no characters from \"%s\"\n", s1, s2);
    }

    return 0;
}
