#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{
    int c;
    int state = OUT;

    while((c = getchar()) != EOF) {
        if (c != '\n' && c != '\t' && c != ' ') {
            state = IN;
            putchar(c);
        } else {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
    }
}
