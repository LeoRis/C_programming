#include <stdio.h>

#define MAX 20 // Maximum size of string.
#define YES	 1
#define NO	 0

void squeeze(char s1[], char s2[]) {

	int i, j, n, flag;

	for(i = j = 0; s1[i] != '\0'; ++i){
		flag = NO;
		for(n = 0; s2[n] != '\0'; ++n){
			if (s1[i] == s2[n]){
				flag = YES;
			}
		}
		if(!flag){
			s1[j++] = s1[i];
		}
	}

	s1[j] = '\0';
}

int main(){
    int c, i, j;
    char firstString[MAX];
    char secondString[MAX];

    printf("What is the first string?\n");

    i = 0;
    while((c = getchar()) != EOF){
        firstString[i] = c;
        i++;
    }

    printf("What is the second string?\n");

    j = 0;
    while((c = getchar()) != EOF){
        secondString[j] = c;
        j++;
    }

    squeeze(firstString, secondString);

    printf("%s\n", firstString);

    return 0;
}
