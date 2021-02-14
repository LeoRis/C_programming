#include<stdio.h>
#include<string.h>

#define MAXLINE 10000
#define LIMIT 20

int getline(char s[], int lim);
int cut(char s[], int start);

int main(){

	int length;
	char string[MAXLINE];

	while((length = getline(string,MAXLINE)) > 0){
		if(length > LIMIT){
			cut(string, 0);
			printf("%s",string);
		}
		else{
			printf("%s",string);
		}
	}
	return 0;
}

int cut(char s[], int start){
	int i;

	for(i=start+LIMIT; i > start && s[i] != ' ' && s[i] != '\t'; --i){
        if(i == start){
            for(i=start; s[i] != ' ' && s[i] != '\t'; ++i);
            s[i] = '\n';
        }
        if((strlen(s) - i) <= LIMIT){
            s[i] = '\n';
        }
        else if(i > start && i != start){
            s[i] = '\n';
            cut(s, i);
        }
	}
	return 0;
}

int getline(char s[], int lim){
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
