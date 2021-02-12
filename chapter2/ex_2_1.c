#include <stdio.h>
#include <limits.h>
#include <float.h>

#define FMT_LIM "%14s %4s %14d %14d"
#define FMT_MIN "%4s %14d"
#define FMT_MAX "%14d\n"

#define FMT_LIM_U "%14s %4s %14u %14u"
#define FMT_MAX_U "%14u\n"

#define FMT_LIM_LD "%14s %4s %21ld %21ld"
#define FMT_MIN_LD "%4s %21ld"
#define FMT_MAX_LD "%21ld\n"

#define FMT_LIM_UL "%14s %4s %21lu %21lu"
#define FMT_MIN_UL "%4s %21lu"
#define FMT_MAX_UL "%21lu\n"

#define FMT_LIM_F "%14s %4s %e %e"
#define FMT_MIN_F "%4s %e"
#define FMT_MAX_F "%e\n"

#define FMT_LIM_LE "%14s %4s %Le %Le"
#define FMT_MIN_LE "%4s %Le"
#define FMT_MAX_LE "%Le\n"


void check_char()
{
    char i, t;
    printf(FMT_LIM, "char", "lim", CHAR_MIN, CHAR_MAX);
    for(i = 0, t = -1; t < i; --i, t = i - 1);
    printf(FMT_MIN, "cmp", i);
    for(i = 0, t = 1; t > i; ++i, t = i + 1);
    printf(FMT_MAX, i);
}

void check_signed_char()
{
    signed char i, t;
    printf(FMT_LIM, "signed char", "lim", SCHAR_MIN, SCHAR_MAX);
    for(i = 0, t = -1; t < i; --i, t = i - 1);
    printf(FMT_MIN, "cmp", i);
    for(i = 0, t = 1; t > i; ++i, t = i + 1);
    printf(FMT_MAX, i);
}

void check_unsigned_char()
{
    unsigned char i, t;
    printf(FMT_LIM, "unsigned char", "lim", 0, UCHAR_MAX);
    for(i = 0, t = -1; t < i; --i, t = i - 1);
    printf(FMT_MIN, "cmp", i);
    for(i = 0, t = 1; t > i; ++i, t = i + 1);
    printf(FMT_MAX, i);
}

void check_int()
{
    int i, next, delta, n;
    printf(FMT_LIM, "int", "lim", INT_MIN, INT_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX, i);
}

void check_signed_int()
{
    signed int i, next, delta, n;
    printf(FMT_LIM, "signed int", "lim", INT_MIN, INT_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX, i);
}

void check_unsigned_int()
{
    unsigned int i, next, delta, n;
    printf(FMT_LIM_U, "unsigned int", "lim", 0, UINT_MAX);
    printf(FMT_MIN, "cmp", 0);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX_U, i);
}

void check_short()
{
    short i, next, delta, n;
    printf(FMT_LIM, "short int", "lim", SHRT_MIN, SHRT_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX, i);
}

void check_signed_short()
{
    signed short i, next, delta, n;
    printf(FMT_LIM, "short int", "lim", SHRT_MIN, SHRT_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX, i);
}

void check_unsigned_short()
{
    unsigned short i, next, delta, n;
    printf(FMT_LIM, "unsigned short", "lim", 0, USHRT_MAX);
    printf(FMT_MIN, "cmp", 0);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX, i);
}

void check_long()
{
    long int i, next, delta, n;
    printf(FMT_LIM_LD, "long int", "lim", LONG_MIN, LONG_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN_LD, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX_LD, i);
}

void check_signed_long()
{
    signed long i, next, delta, n;
    printf(FMT_LIM_LD, "signed long", "lim", LONG_MIN, LONG_MAX);
    
    i = 1; next = -1; delta = 10; n = 10;
    while (n) {
        if (next < i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i - delta;
    }
    printf(FMT_MIN_LD, "cmp", i);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX_LD, i);
}

void check_unsigned_long()
{
    unsigned long i, next, delta, n;
    printf(FMT_LIM_UL, "unsigned long", "lim", 0l, ULONG_MAX);
    printf(FMT_MIN_UL, "cmp", 0l);

    i = 1; next = 2; delta = 10; n = 10;
    while (n) {
        if (next > i) {
            i = next;
            delta = delta * 1.5;
        } else {
            if (delta == 1)
                --n;
            else
                delta = delta / 2;
        }
        next = i + delta;
    }
    printf(FMT_MAX_UL, i);
}

void check_float()
{
    float inf = 1/0.0;
    float minus_inf = -1/0.0;
    float i, next, delta;

    printf(FMT_LIM_F, "float", "lim", FLT_MIN, FLT_MAX);

    i = 1.0; next = -2.0; delta = 10.0;

    while(next > minus_inf) {
        i = next;
        next = i - (delta = delta * 1.1);
    }
    while(next < i) {
        if (next > minus_inf)
            i = next;
        else
            delta = delta / 2;
        next = i - delta;
    }

    printf(FMT_MIN_F, "cmp", i);
    printf(" ");

    i = 1.0; next = 2.0; delta = 10.0;

    while(next < inf) {
        i = next;
        next = i + (delta = delta * 1.1);
    }
    while(next > i) {
        if (next < inf)
            i = next;
        else
            delta = delta / 2;
        next = i + delta;
    }

    printf(FMT_MAX_F, i);
}

void check_double()
{
    double inf = 1/0.0;
    double minus_inf = -1/0.0;
    double i, next, delta;

    printf(FMT_LIM_F, "double", "lim", DBL_MIN, DBL_MAX);

    i = 1.0; next = -2.0; delta = 10.0;

    while(next > minus_inf) {
        i = next;
        next = i - (delta = delta * 1.1);
    }
    while(next < i) {
        if (next > minus_inf)
            i = next;
        else
            delta = delta / 2;
        next = i - delta;
    }

    printf(FMT_MIN_F, "cmp", i);
    printf(" ");

    i = 1.0; next = 2.0; delta = 10.0;

    while(next < inf) {
        i = next;
        next = i + (delta = delta * 1.1);
    }
    while(next > i) {
        if (next < inf)
            i = next;
        else
            delta = delta / 2;
        next = i + delta;
    }

    printf(FMT_MAX_F, i);
}

void check_long_double()
{
    long double inf = 1/0.0;
    long double minus_inf = -1/0.0;
    long double i, next, delta;

    printf(FMT_LIM_LE, "long double", "lim", LDBL_MIN, LDBL_MAX);

    i = 1.0; next = -2.0; delta = 10.0;

    while(next > minus_inf) {
        i = next;
        next = i - (delta = delta * 1.1);
    }
    while(next < i) {
        if (next > minus_inf)
            i = next;
        else
            delta = delta / 2;
        next = i - delta;
    }

    printf(FMT_MIN_LE, "cmp", i);
    printf(" ");

    i = 1.0; next = 2.0; delta = 10.0;

    while(next < inf) {
        i = next;
        next = i + (delta = delta * 1.1);
    }
    while(next > i) {
        if (next < inf)
            i = next;
        else
            delta = delta / 2;
        next = i + delta;
    }

    printf(FMT_MAX_LE, i);
}

int main()
{
    check_char();
    check_signed_char();
    check_unsigned_char();

    check_int();
    check_signed_int();
    check_unsigned_int();

    check_short();
    check_signed_short();
    check_unsigned_short();

    check_long();
    check_signed_long();
    check_unsigned_long();

    check_float();
    check_double();
    check_long_double();

    return 0;
}