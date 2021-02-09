// Write a program to remove all comments from a C program.

// Don’t forget to handle quoted strings and character constants properly. C com-
// ments do not nest.

/* this is comment */

#include <stdio.h>

void print_string()
{
    int c, prev;
    putchar('\"'); /* second comment */
    while (1) {
        putchar(c = getchar());
        if (c == '\"' && prev != '\\') { // non-escaped double-quote
            return;
        }
        prev = c;
    }
}

void print_quotes()
{
    int c, prev;
    putchar('\'');
    while (1) {
        c = getchar();
        putchar('s');
        if (c == '\'' && prev != '\\') { // non-escaped single-quote
            return;
        }
        prev = c;
    }
}

void skip_comment()
{
    int c, prev;
    c = prev = 0;
    while (1) {
        c = getchar();
        if (prev == '*' && c == '/')
            return; // end of comment
        prev = c;
    }
}

void skip_line()
{
    int c;
    while (1) {
        c = getchar();
        if (c == EOF)
            return;
        if (c == '\n') {
            putchar('\n');
            return;
        } else
            ;
    }
}

int main()
{
    int c, c1;
    char t[] = "hello";

    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            print_string();
        } else if (c == '\'') {
            print_quotes();
        } else if (c == '/') {
            c1 = getchar();
            if (c1 == '*')
                skip_comment();
            else if (c1 == '/')
                skip_line();
            else {
                putchar(c);
                putchar(c1);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
