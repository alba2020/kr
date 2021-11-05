// Write a program to remove all comments from a C program.

// Don’t forget to handle quoted strings and character constants properly. C com-
// ments do not nest.

/* this is comment */

#include <stdio.h>

void quoted(int delimeter)
{
    int c;
    
    putchar(delimeter); /* some comment */
    while (1) {
        putchar(c = getchar());
        if (c == '\\')
            putchar(getchar());
        if (c == delimeter) // non-escaped delimeter
            return;
    }
}
/* skip this comment */
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

void skip_line(int first)
{
    int c;
    while (1) {
        c = getchar();
        if (c == EOF)
            return;
        if (c == '\n') {
            if ( ! first)
                putchar('\n');
            return;
        } else
            ;
    }
}

int main()
{
    int c, c1, first;
    first = 1;

    while ((c = getchar()) != EOF) {
        if (c == '"' || c == '\'') {
            first = 0;
            quoted(c);
        } else if (c == '/') {
            c1 = getchar();
            if (c1 == '*') {
                first = 0;
                skip_comment();
            } else if (c1 == '/') {
                skip_line(first);
            } else {
                putchar(c);
                putchar(c1);
                first = 0;
            }
        } else { // comment
            putchar(c);
            if (c == '\n')
                first = 1;
            else
                first = 0;
        }
    }

    return 0;
}
