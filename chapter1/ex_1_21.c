// Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the
// same tab stops as for detab. When either a tab or a single blank would suffice
// to reach a tab stop, which should be given preference?

#include <stdio.h>

#define N 4

int get_piece(char s[], int size);
void entab(char s[], int size);

int main()
{
	int len, i, j;
	i = 0;

    char piece[N + 1];

    for (j = 0; j <= N; ++j)
        piece[j] = '\0';

	while ((len = get_piece(piece, N + 1) > 0)) {
        entab(piece, N + 1);
        printf("%s", piece);
	}
    return 0;
}

void entab(char s[], int size)
{
    int i;
    for (i = size - 2; i >= 0 && s[i] == ' '; --i) {
        s[i] = '\t';
        s[i + 1] = '\0';
    }
}

int get_piece(char s[], int size)
{
    int c, i;
    for (i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}