#include <stdio.h>
#define isopen(p) ((p)->flag & (_READ | _WRITE))

int fseek(FILE *fp, long offset, int origin)
{
	if (fp == NULL || !isopen(fp))
		return EOF;
	if (fp->flag & _WRITE) {
		if (fflush(fp))
			return EOF;
	} else {
		offset -= (origin == SEEK_CUR) ? fp->cnt : 0L;
		fp->cnt = 0;
	}
	if (lseek(fp->fd, offset, origin) == -1) {
		fp->flag |= _ERR;
		return EOF;
	} else {
		fp->flag &= ~_EOF;
		return 0;
	}
}

int main(void)
{
	FILE *temp;
	int i;
	char c, *s, tpath[] = "temp-8-4.txt";
	char draft[] = "My Ham is Green and I like to Eat it.\n";

	write(1, "Started with:  ", 15);
	write(1, draft, 38);

	/* Write draft text to temp file */
	if ((temp = fopen(tpath, "w")) == NULL) {
		write(2, "error: failed to open temp to write!\n", 37);
		return 1;
	}
	for (s = draft; *s; s++)
		putc(*s, temp);

	/* edit the temp file */
	fseek(temp, 3L, SEEK_SET);
	for (s = "Dog"; *s; s++)
		putc(*s, temp);

	fseek(temp, 4L, SEEK_CUR);
	for (s = "Beige"; *s; s++)
		putc(*s, temp);

	fseek(temp, -8L, SEEK_END);
	for (s = "Pat"; *s; s++)
		putc(*s, temp);

	fclose(temp);

	write(1, "Ended with:    ", 15);

	/* read temp file and write to stdout */
	if ((temp = fopen(tpath, "r")) == NULL) {
		write(2, "error: failed to open temp to read!\n", 36);
		return 1;
	}
	while ((c = getc(temp)) != EOF)
		putchar(c);
	fflush(stdout);


	/* fseek with read and SEEK_CUR */
	fseek(temp, 0, SEEK_SET);
	write(1, "Read SEEK_CUR: ", 15);
	for (i = 0; i < 22; i++)
		putchar(getc(temp));
	fseek(temp, 8L, SEEK_CUR);
	while ((c = getc(temp)) != EOF)
		putchar(c);

	fclose(stdout);
	fclose(temp);
	return 0;
}
