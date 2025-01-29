/**
 * Program to copy its input to its output one word per line.
 * 
 * Exercise 1.12
 */

#include <stdio.h>

int main()
{
  char c;
  int previous_blank = 1;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t')
    {
      if (!previous_blank)
      {
        putchar('\n');
        previous_blank = 1;
      }
    }
    else
    {
      putchar(c);
      previous_blank = 0;
    }
  }
}