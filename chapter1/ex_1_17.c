#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int get_line(char line[], int maxline);

/* print all input lines that are longer than 80 characters. */
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        // printf("read line: %s len %d\n", line, len);
        if (len > 80)
            printf("%s", line);

    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != EOF && c != '\n')
            ++i;
    }
    return i;
}
