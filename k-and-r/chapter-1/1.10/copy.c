/**
 * Program to copy its input to its output, replacing all tabs, backspace and backslash.
 * 
 * Exercise 1.10
 */

#include <stdio.h>

int main()
{
  char c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      printf("\\t");
    }
    else if (c == '\b')
    {
      printf("\\b");
    }
    else if (c == '\\')
    {
      printf("\\\\");
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}