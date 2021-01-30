#include <stdio.h>

void escape(char s[], char t[])	{

	int i;

	for(i = 0; s[i] != '\0'; ++i){
		switch(s[i]){
			case '\n':
				t[i] = '\\';
				t[++i] = 'n';
				break;
			case '\t':
				t[i] = '\\';
				t[++i] = 't';
				break;
            case '\b':
                t[i] = '\\';
                t[++i] = 'b';
                break;
			default:
				t[i] = s[i];
				break;
		}
	}

	t[i] = '\0';
}

void unEscape(char s[], char t[]){

	int i;

	for(i = 0; s[i] != '\0'; ++i){
		switch(s[i]){
			case '\\':
				switch(s[i]){
					case 'n':
						t[i++] = '\n';
						break;
					case 't':
						t[i++] = '\t';
						break;
					case 'b':
						t[i++] = '\b';
						break;
				}
			default:
				t[i] = s[i];
				break;
		}
	}

	t[i] = '\0';
}

int main(){

    char s[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char t[51];

    printf("Original string:\n%s\n", s);

    escape(s, t);
    printf("Escaped string:\n%s\n", t);

    unEscape(s, t);
    printf("Unescaped string:\n%s\n", s);

    return 0;
}
