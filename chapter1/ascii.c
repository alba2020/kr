#include <stdio.h>

int main()
{
    int i;
    for(i = 33; i < 128; ++i)
        printf("%d %c\n", i, i);
}
