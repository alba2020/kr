#include <stdio.h>

// замена каждой последовательности пробелом одним пробелом

#define SPACE ' '

int main()
{
    int c, prev;
    
    c = prev = 0;

    while((c = getchar()) != EOF) {
      if (prev == SPACE) {
          if (c != SPACE)
            putchar(c);
      } else {
          putchar(c);
      }
      prev = c;
    }
}
