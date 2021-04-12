#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

static void filecopy(int ifd, char *ipath, int ofd, char *opath);
static void error(char *fmt, ...);

int main(int argc, char *argv[])
{
	int fd;
	char *path;

	if (argc == 1) {
		fd = 0;
		path = "<stdin>";
	} else if ((fd = open(path = argv[1], O_RDONLY, 0)) == -1) {
		error("%s: can't open %s\n", argv[0], path);
	}
	filecopy(fd, path, 1, "<stdout>");
	if (fd)
		close(fd);
	return 0;
}

void filecopy(int ifd, char *ipath, int ofd, char *opath)
{
	static char buf[BUFSIZ];
	int n;

	while ((n = read(ifd, buf, BUFSIZ)) > 0)
		if (write(ofd, buf, n) != n)
			error("Problem writing to '%s'", opath);
	if (n == -1)
		error("Problem reading from '%s'", ipath);
}

void error(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
