#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_word(char line[], int maxline);
int remove_trailing(char line[], int len);

// write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.
int main()
{
    int len;
    char line[MAXLINE];    /* current input line */

    while ((len = get_word(line, MAXLINE)) > 0) {
        // printf("read line %s len %d\n", line, len);
        len = remove_trailing(line, len);
        // printf("stripped line %s len %d\n", line, len);
        if (len > 1)
            printf("%s", line);
    }
    return 0;
}

// int remove_trailing(char line[], int len)
// {
//     int i;
//     i = len - 1; // '\n'
//     while (line[i] == '\n' || line[i] == '\t' || line[i] = ' ') {

//     }
// }

int remove_trailing(char line[], int len)
{
    for (; len >= 2 && (line[len-2] == ' ' || line[len-2] == '\t'); --len) {
        line[len - 2] = line[len - 1]; // \n
        line[len - 1] = line[len]; // \0
    }
    return len;
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
