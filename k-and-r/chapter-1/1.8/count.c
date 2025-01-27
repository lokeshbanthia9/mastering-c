/**
 * Program to count the number of blanks, tabs, and new lines.
 * 
 * Exercise 1.8
 */

#include <stdio.h>

int main()
{
  int blanks = 0;
  int tabs = 0;
  int lines = 0;

  printf("\nEnter Text\n");

  char c;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++blanks;
    }
    else if (c == '\t')
    {
      ++tabs;
    }
    else if (c == '\n')
    {
      ++lines;
    }
  }

  printf("\nSummary of Counts\n");
  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("New Lines: %d\n", lines);

  return 0;
}