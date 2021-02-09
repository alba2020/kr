// Write a program to “fold” long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define N 30
#define WORD_SIZE 100

int is_space(char c);
void print(int c);

int pos;

int main()
{
    extern int pos;
    int c, i, j;
    char word[WORD_SIZE];

    pos = 0;

    while((c = getchar()) != EOF) {
        if (c > 127) // non-printable
            ;
        else if (is_space(c)) { // print space
            print(c);
        } else { // read word
            i = 0;
            while(! is_space(c)) {
                word[i] = c;
                ++i;
                c = getchar();
            }
            if (pos + i <= N) {
                for (j = 0; j < i; ++j) // print word
                    print(word[j]);
            } else {
                putchar('\n');
                pos = 0;
                for (j = 0; j < i; ++j) // print word
                    print(word[j]);
            }
            print(c); // character after word
        }
    }

    return 0;
}

void print(int c)
{
    extern int pos;
    if (c == EOF)
        return;
    putchar(c);
    ++pos;
    if (c == '\n')
        pos = 0;
    if (pos == N) {
        putchar('\n');
        pos = 0;
    }
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == EOF)
        return 1;
    else
        return 0;
}
