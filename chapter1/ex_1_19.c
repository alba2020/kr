#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_word(char line[], int maxline);
void reverse(char s[]);
int get_len(char s[]);

// Write a function reverse(s) that reverses the character
// string s. Use it to write a program that reverses its input a line at a time.
int main()
{
    int len;
    char line[MAXLINE];    /* current input line */

    while ((len = get_word(line, MAXLINE)) > 0) {
        printf("%s", line);
        reverse(line);
        printf("%s", line);
        printf("\n");
    }
    return 0;
}

void reverse(char s[])
{
    int i, len, t;
    len = get_len(s);
    for (i = 0; i < len / 2; ++i) {
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}

int get_len(char s[])
{
    int i = 0;
    while(s[i] != '\0')
        ++i;
    return i;
}

/* getline: read a line into s, return length */
// returns number of symbols, not size
// size = len + 1
int get_word(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c !='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}
