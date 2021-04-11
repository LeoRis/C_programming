static int sisupper(int c);

int sisupper(int c)
{
	switch ('A') {
	case 0x41: /* ASCII */
		return 'A' <= c && c <= 'Z';
	case 0xC1: /* EBCDIC */
		return (('A' <= c && c <= 'I') || ('J' <= c && c <= 'R') ||
			('S' <= c && c <= 'Z'));
	default:
		fprintf(stderr, "error: Can't guess encoding. 'A'=0x%X\n", 'A');
		exit(1);
	}
}

////////////////////////////////////////////////////////////////////////

static int tisupper(int c);
static int map[UCHAR_MAX];
static void tisupper_init(void);

int tisupper(int c)
{
	return *(map + (unsigned char)c);
}

void tisupper_init(void)
{
	int i;

	for (i = 0; i < UCHAR_MAX; i++)
		map[i] = sisupper(i);
}
