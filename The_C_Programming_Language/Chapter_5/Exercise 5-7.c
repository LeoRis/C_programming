/*Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLENS 100000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines, char lines[], int maxlen);
void writelines(char *lineptr[], int nlines);
void quicksort(char *lineptr[], int left, int right);
int getline(char *s, int i);

int main(void){

	int nlines;
	char lines[MAXLENS];
	if((nlines = readlines(lineptr, MAXLINES, lines, MAXLENS)) >= 0){

		quicksort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}else{

		printf("error: input too big to sort\n");
		return 1;
	}
}

int getline(char s[], int lim){

	int c, i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines, char lines[], int maxlens){

	int len, nlines = 0;
	char *p = lines;
	while((len = getline(p, maxlens + lines - p)) > 0){

		if(nlines < maxlines){

			p[len - 1] = '\0';
			lineptr[nlines++] = p;
			p += len;
		}else{
			return -1;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){

	while(nlines-- > 0){
		printf("%s\n", *lineptr++);
	}
}

void quicksort(char *v[], int left, int right){

	int i, last;
	void swap(char *v[], int i, int j);
	if(left >= right){
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++){
		if(strcmp(v[i], v[left]) < 0){
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

void swap(char *v[], int i, int j){

	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
