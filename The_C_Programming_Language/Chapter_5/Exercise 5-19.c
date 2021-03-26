
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"
#define MAXTOKEN 100
#define MAXPOINTERS 10

enum { NAME, PARENS, BRACKETS };


int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char out[1000]; /* output string */

/* undcl: convert word description to declaration */
int main(void)
{
	int type;
	int i, c;
	int pcount;
	char temp[MAXTOKEN];
	char p[MAXPOINTERS]; /* space for 9 pointers */
	while (gettoken() != EOF){
		strcpy(out, token);
		pcount = 0;
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS){
				strcat(out, token);
			} else if (type == '*'){
				pcount++;
				while ((c = getch()) == '*' || c == ' '){
					if (c == '*'){
						if (pcount < (MAXPOINTERS - 1))
							pcount++;
						else
							break;
					}
				}
				ungetch();
				for (i = 0; i < pcount; i++){
					p[i] = '*';
				}
				p[i] = '\0';
				pcount = 0;
				sprintf(temp, "(%s%s)", p, out);
				strcpy(out, temp);
			} else if (type == NAME){
				sprintf(temp, "%s%s", token, out);
				strcpy(out, temp);
			} else {
				printf("invalid input at %s\n", token);
			}
		printf("%s\n", out);
	}
	return 0;
}

int gettoken(void)
{
	int c;
	char *p = token;
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '('){
		if ((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch();
			return tokentype = '(';
		}
	} else if (c == '['){
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch();
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}

#include <stdio.h>
#define BUFSIZE 1000
static char line[BUFSIZE]; /* buffer for line */
static int bufp = 0; /* position in buf */
static int readflag = 1;
static int get_line(char *s, int max_length);
/* getch: read a character */
int getch(void)
{
	int length = 0;
	do {
		if (readflag == 1){
			/* prime the line array */
			if ((length = get_line(line,BUFSIZE)) > 0){
				if(length >= (BUFSIZE - 1)){
					printf("ERROR: line buffer exceeded\n");
					return EOF;
				}
			}else{
				return EOF;
			}
			bufp = 0;
			readflag = 0;
		}
		if (line[bufp] == '\0')
			readflag = 1; /* need to read a new line */
	} while (readflag);
	return line[bufp++];
}
/* ungetch: push character back on input */
void ungetch(void)
{
	if (bufp > 0)
		--bufp;
}
/*
 * print_source: print out the contents of the line read
 */
void print_source(void)
{
	printf("%s", line);
}

int get_line(char *s, int max_length)
{
	int c;
	char *start = s; /* save pointer to start of buffer s */
	char *end = s + (max_length - 2); /* point near to end of buffer s */
	while((c = getchar()) != EOF && c != '\n' && s < end){
		*s++ = c;
	}
	/* store last character read */
	if(c != EOF)
		*s++ = c;
	*s = '\0';/* terminate the line */
	return s - start; /* number of characters read */
}

#ifndef GETCH
#define GETCH
int getch(void);
void ungetch(void);
void print_source(void);
#endif
