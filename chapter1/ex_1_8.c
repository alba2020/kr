#include <stdio.h>

int main()
{
    int c, nspaces, ntabs, nnewlines;

    nspaces = ntabs = nnewlines = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') ++nspaces;
        if (c == '\t') ++ntabs;
        if (c =='\n') ++nnewlines;
    }

    printf("spaces %d\n", nspaces);
    printf("tabs %d\n", ntabs);
    printf("newlines %d\n", nnewlines);
}
