// Write a program to “fold” long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define N 10
#define BUF_SIZE 100

void zero_buf();
int is_space(char c);
int get_char_buf();

char buffer[BUF_SIZE];
int buf_index;
int buf_size;

int main()
{
    int c;

    zero_buf();
    while((c = get_char_buf()) != EOF) {
        putchar(c);
    }

    return 0;
}

void zero_buf()
{
    int j;
    extern char buffer[BUF_SIZE];
    extern int buf_index, buf_size;

    buf_index = buf_size = 0;

    for (j = 0; j < BUF_SIZE; ++j)
        buffer[j] = '\0';
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return 1;
    else
        return 0;
}

int read_from_buf()
{
    int c;

    if (buf_index >= buf_size)
        update_buf();

    c = buffer[buf_index];
    ++buf_index;

    return c;
}

int update_buf()
{
    buffer[buf_size] = getchar();
    ++buf_size;
    if (buf_size >= BUF_SIZE) {
        rewrite_buf();
    }
}
