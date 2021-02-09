// Write a program to “fold” long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

// #define N 10
#define BUF_SIZE 10

int is_space(char c);
int read_from_buf();
int update_buf();
void rewrite_buf();

char buffer[BUF_SIZE];
int buf_index;
int buf_size;

int main()
{
    int c, len;

    buf_index = buf_size = len = 0;

    while((c = read_from_buf()) != EOF) {
        if (is_space(c))
            putchar(c);
        else {
            len = word_len();
        }
    }

    return 0;
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return 1;
    else
        return 0;
}

// int read_from_buf()
// {
//     int c;

//     if (buf_index >= buf_size)
//         update_buf();

//     c = buffer[buf_index];
//     ++buf_index;

//     return c;
// }

// int update_buf()
// {
//     int c;
//     c = getchar();
//     buffer[buf_size] = c;
//     ++buf_size;
//     if (buf_size >= BUF_SIZE) {
//         rewrite_buf();
//     }
//     return c;
// }

// void rewrite_buf()
// {
//     if (buf_index <= 0) {
//         printf("Buffer overflow\n");
//         return;
//     }

//     printf("<rewrite buf>");

//     int i;
//     for (i = 0; buf_index + i < buf_size; ++i) {
//         buffer[i] = buffer[buf_index + i];
//     }
//     buf_size = i;
//     buf_index = 0;
//     printf("[buf_index %d buf_size %d]", buf_index, buf_size);
// }
