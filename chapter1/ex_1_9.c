#include <stdio.h>

// замена каждой строки, состоящей из одного
// или нескольких пробелов, одним пробелом

int main()
{
    int c;
    int blank_line;
    int nspaces;

    blank_line = 0;
    nspaces = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            if (blank_line == 1) { // nl, blank
                putchar(' ');
            } else { // nl, not blank
                blank_line = 1;
            }
            putchar('\n');
            nspaces = 0;
        } else if (blank_line == 1) {// not nl, blank
            if (c == ' ') {
                ++nspaces;
            } else {
                blank_line = 0;
                for (nspaces; nspaces > 0; --nspaces)
                    putchar(' ');
                putchar(c);
            }
        } else { // not nl, not blank
            putchar(c);
        }
    }
}
