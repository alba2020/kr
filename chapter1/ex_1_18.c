#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

// write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.
int main()
{

}

/* print longest input line */
int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0)
        // printf("read line: %s len %d\n", line, len);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) { /* there was a line */
        printf("max = %d\n", max);
        printf("%s\n", longest);
    }
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

/* copy: copy ’from’ into ’to’; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
