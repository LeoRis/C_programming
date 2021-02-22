#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);
int mygetline(char s[], int maxl);

int main(){
	char line[MAXLINE];

	while(mygetline(line, MAXLINE) > 0){
		printf("\t%f\n", atof(line));
	}
	return 0;
}


double atof(char s[])
{
	double val, power;
	int i, sign, esign, exp;

	for(i = 0; isspace(s[i]); i++){
		;
	}

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-'){
		i++;
	}

	for(val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}

	power = 1.0;

	if(s[i] == '.'){
		i++;

		for(; isdigit(s[i]); i++){
			val = 10.0 * val + (s[i] - '0');
			power *= 10;
		}
	}
	if(s[i] == 'e' || s[i] == 'E'){
		i++;
	}

	esign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-'){
		i++;
	}

	for(exp = 0; isdigit(s[i]); i++){
		exp = 10 * exp + s[i] - '0';
	}

	for(i = 0; i < exp; i++){
		power *= (esign == -1) ? 10.0 : 0.1;
	}

	return sign * val / power;
}


int mygetline(char s[], int maxl){
	unsigned char c;
	int i = 0;

	while(i <= maxl && (c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}
