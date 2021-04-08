#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE (1 << 10)

enum errors {
	NO_ERROR = 0,
	UNEXPECTED_ARG_COUNT,
	FILE_OPEN_ERROR,
	FILE_READ_ERROR
};

static char *subnull(char *s);
static int chkargc(int argc);
static FILE *chkfopen(char *file, char *modes);
static char *chkfgets(char *s, int n, FILE *iop, char *path);
static void close(void);

static FILE *file1, *file2;
static char errormsg[MAXLINE];

int main(int argc, char *argv[])
{
	char line1[MAXLINE], line2[MAXLINE];
	char *modes = "r";
	char *path1, *path2;
	char *rslt1, *rslt2;
	int lncount = 0;

	chkargc(argc);
	file1 = chkfopen(path1 = argv[1], modes);
	file2 = chkfopen(path2 = argv[2], modes);
	do {
		lncount++;
		rslt1 = chkfgets(line1, MAXLINE, file1, path1);
		rslt2 = chkfgets(line2, MAXLINE, file2, path2);
	} while ((rslt1 != NULL) && (rslt2 != NULL) && !strcmp(rslt1, rslt2));

	if (!(rslt1 == NULL && rslt2 == NULL))
		printf("line: %d\n< %s---\n> %s", lncount, subnull(rslt1),
		       subnull(rslt2));
	close();
	exit(NO_ERROR);
}

static char *subnull(char *s)
{
	return (s == NULL) ? "<EOF>\n" : s;
}

int chkargc(int argc)
{
	int expected = 3;
	if (argc == expected)
		return argc;
	fprintf(stderr, "error: Expected %d arguments, got %d\n", expected,
		argc);
	exit(UNEXPECTED_ARG_COUNT);
}

FILE *chkfopen(char *file, char *modes)
{
	FILE *fp = fopen(file, modes);
	if (fp != NULL)
		return fp;
	sprintf(errormsg, "error: Failed to open file: '%s'", file);
	perror(errormsg);
	close();
	exit(FILE_OPEN_ERROR);
}

char *chkfgets(char *s, int n, FILE *iop, char *path)
{
	char *r = fgets(s, n, iop);
	if (!ferror(iop))
		return r;
	sprintf(errormsg, "error: Failed to read file: '%s'", path);
	perror(errormsg);
	close();
	exit(FILE_READ_ERROR);
}

void close(void)
{
	if (file1 != NULL)
		fclose(file1);
	if (file2 != NULL)
		fclose(file2);
}
