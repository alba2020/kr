#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define MAX 15
#define VSTEPS 15

int main()
{
    int i, j, c, len, state, max;
    int stats[MAX + 1];

    state = OUT;
    len = 0;
    max = 0;

    for (i = 1; i <= MAX; ++i)
        stats[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                ++stats[len];
                len = 0;
            }
        } else {
            state = IN;
            ++len;
        }
    }

    for (i = 1; i <= MAX; ++i)
        if (stats[i] > max)
            max = stats[i];
    printf("max = %d\n", max);

    for (j = VSTEPS; j > 0; --j) {
        for (i = 1; i <= MAX; ++i) {
            if (stats[i] > j * max / VSTEPS)
                printf("[] ");
            else
                printf("   ");
        }
        printf("\n");
    }
    for (i = 1; i <= MAX; ++i)
        printf("%2d ", i);
    printf("\n");

    // for (i = 1; i <= MAX; ++i)
    //     printf("%2d %2d\n", i, stats[i]);
}
