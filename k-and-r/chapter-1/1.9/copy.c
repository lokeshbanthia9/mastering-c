/**
 * Program to copy its input to its output, replacing each string of one more blanks by a single blank.
 * 
 * Excercise 1.9
 */

#include <stdio.h>

int main()
{
  char c;
  int previous_blank = 0;

  printf("Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)\n");

  while ((c = getchar()) != EOF)
  {

    if (c == ' ')
    {
      if (!previous_blank)
      {
        putchar(c);
        previous_blank = 1;
      }
    }
    else
    {
      putchar(c);
      previous_blank = 0;
    }
  }

  return 0;
}