// Write a program to check a C program for rudimentary syntax
// errors like unbalanced parentheses, brackets and braces. Don’t forget about
// quotes, both single and double, escape sequences, and comments. (This pro-
// gram is hard if you do it in full generality.)

#include <stdio.h>

#define OK 0

#define E_WRONG_PAR 1
#define E_UNBALANCED_PAR 2
#define E_WRONG_BRA 3
#define E_UNBALANCED_BRA 4
#define E_WRONG_CUR 5
#define E_UNBALANCED_CUR 6

#define E_BRACKETS 7
#define E_BAD_ARGUMENT 8

#define E_MISSING_SINGLE 9
#define E_MISSING_DOUBLE 10
#define E_STRING 11
#define E_NEWLINE 12

#define E_COMMENT 13

#define TRACE 0

int root();
int brackets(int open);
int string(int q);
void comment();
int check(int c);

int get_char();
int cur_line, cur_pos;

int main()
{
    int code;
    extern int cur_line, cur_pos;

    cur_line = 1;
    cur_pos = 0;

    code = root();

    if (code == OK)
        printf("Ok.\n");

    else if (code == E_WRONG_PAR)
        printf("Wrong parentheses ). %d:%d\n", cur_line, cur_pos);
    else if (code == E_UNBALANCED_PAR)
        printf("Unbalanced parentheses (. %d:%d\n", cur_line, cur_pos);
    else if (code == E_WRONG_BRA)
        printf("Wrong bracket ]. %d:%d\n", cur_line, cur_pos);
    else if (code == E_UNBALANCED_BRA)
        printf("Unbalanced brackets [. %d:%d\n", cur_line, cur_pos);
    else if (code == E_WRONG_CUR)
        printf("Wrong curly }. %d:%d\n", cur_line, cur_pos);
    else if (code == E_UNBALANCED_CUR)
        printf("Unbalanced curly {. %d:%d\n", cur_line, cur_pos);
    else if (code == E_BRACKETS)
        printf("Brackets error. %d:%d\n", cur_line, cur_pos);

    else if (code == E_MISSING_SINGLE)
        printf("Missing single quote. %d:%d\n", cur_line, cur_pos);
    else if (code == E_MISSING_DOUBLE)
        printf("Missing double quote. %d:%d\n", cur_line, cur_pos);
    else if (code == E_STRING)
        printf("String error. %d:%d\n", cur_line, cur_pos);
    else if (code == E_NEWLINE)
        printf("Unexpected newline. %d:%d\n", cur_line, cur_pos);

    else if (code == E_COMMENT)
        printf("Probably nested comment. %d:%d\n", cur_line, cur_pos);

    else if (code == E_BAD_ARGUMENT)
        printf("Bad argument. %d:%d\n", cur_line, cur_pos);
    else
        printf("Unknown error. %d %d:%d\n", code, cur_line, cur_pos);

    return 0;
}

int check(int c)
{
    int code, next;

    if (c == ')')
        return E_WRONG_PAR;
    else if (c == ']')
        return E_WRONG_BRA;
    else if (c == '}')
        return E_WRONG_CUR;
    else if (c == '(' || c == '[' || c == '{') {
        if ((code = brackets(c)) != OK)
            return code;
    } else if ((c == '\'') || (c == '"')) {
        if ((code = string(c)) != OK)
            return code;
    } else if (c == '/') {
        next = get_char();
        if (next == '*')
            comment();
    } else if (c == '*') {
        next = get_char();
        if (next == '/')
            return E_COMMENT;
    }

    return OK;
}

int root()
{
    int c, code;
    
    if (TRACE)
        printf("root()\n");

    while ((c = get_char()) != EOF) {
        if ((code = check(c)) != OK)
            return code;
    }
    // EOF
    return OK;
}

int brackets(int open)
{
    int c, code, close, next;

    if (TRACE)
        printf("brackets %c\n", open);

    if (open == '(')
        close = ')';
    else if (open == '[')
        close = ']';
    else if (open == '{')
        close = '}';
    else
        return E_BAD_ARGUMENT;
        
    while ((c = get_char()) != EOF) {
        if (c == close) {
            if (TRACE)
                printf("close %c\n", c);
            return OK;
        } else if ((code = check(c)) != OK) {
            return code;
        }
    }
    // EOF
    if (close == ')')
        return E_UNBALANCED_PAR;
    else if (close == ']')
        return E_UNBALANCED_BRA;
    else if (close == '}')
        return E_UNBALANCED_CUR;
    else
        return E_BRACKETS;
}

int get_char()
{
    extern int cur_line, cur_pos;
    int c;
    
    c = getchar();
    
    if (c == '\n') {
        ++cur_line;
        cur_pos = 0;
    }
    ++cur_pos;
    
    return c;
}

int string(int q)
{
    int c;

    if (TRACE)
        printf("string %c\n", q);

    while ((c = get_char()) != EOF) {
        if (c == '\\')
            get_char();
        else if (c == q) {
            if (TRACE)
                printf("close %c\n", c);
            return OK;
        }
        else if (c == '\n')
            return E_NEWLINE;
    }
    // EOF
    if (q == '\'')
        return E_MISSING_SINGLE;
    else if (q == '"')
        return E_MISSING_DOUBLE;
    else
        return E_STRING;
}

void comment()
{
    int c, prev;
    c = prev = 0;

    if (TRACE)
        printf("comment start\n");
    while (1) {
        c = get_char();
        if (prev == '*' && c == '/') {
            if (TRACE)
                printf("comment end\n");
            return; 
        }
        prev = c;
    }
}
