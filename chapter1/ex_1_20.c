// Write a program detab that replaces tabs in the input with the
// proper number of blanks to space to the next tab stop. Assume a fixed set of

// tab stops, say every n columns. Should n be a variable or a symbolic parame-
// ter?

#include <stdio.h>

#define N 4

int main()
{
	int c, i, j, fill;
	i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar(c);
			i = 0;
		} else if (c == '\t') {
			fill = N - (i % N);
			for (j = 0; j < fill; ++j) {
				putchar(' ');
				++i;
			}
		} else {
			putchar(c);
			++i;
		}
	}
	return 0;
}
