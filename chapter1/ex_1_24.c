// Write a program to check a C program for rudimentary syntax
// errors like unbalanced parentheses, brackets and braces. Don’t forget about

// quotes, both single and double, escape sequences, and comments. (This pro-
// gram is hard if you do it in full generality.)

#include <stdio.h>

int root();

int main()
{
    if (root()) {
        printf("ok\n");
        return 0;
    } else {
        printf("error\n");
        return -1;
    }
}

int root()
{

}