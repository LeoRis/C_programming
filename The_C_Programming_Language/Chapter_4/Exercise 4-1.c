#include <stdio.h>
#include <string.h>

int strindex(const char s[], const char t[]);

int main(){
	printf("%d\n", strindex("I stopped dreaming a long long time ago", "long"));
	return 0;
}

int strindex(const char s[], const char t[]){
	for(int i = strlen(s) - 1, j; i >= 0; i--){
		for(j = 0; s[i + j] == t[j]; j++);
		if(!t[j]){
			return i;
		}
	}
	return -1;
}
