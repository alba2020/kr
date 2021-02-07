#include <stdio.h>

#define FIRST '!'
#define LAST '~'
#define COUNT (LAST - FIRST + 1)
#define VSTEPS 15

int main()
{
    int i, j, c, max;
    int stats[COUNT];

    for (i = 0; i < COUNT; ++i)
        stats[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= FIRST && c <= LAST)
            ++stats[c - FIRST];

    max = stats[0];
    for (i = 1; i < COUNT; ++i)
        if (stats[i] > max)
            max = stats[i];
    printf("max = %d\n", max);

    for (j = VSTEPS; j > 0; --j) {
        for (i = 0; i < COUNT; ++i) {
            if (stats[i] > max * j / VSTEPS)
                printf("_");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (i = 0; i < COUNT; ++i)
        printf("%c", i + FIRST);
    printf("\n");
}
