/**
 * Program to print a histogram of the frequencies of different characters in its input.
 * 
 * Exercise 1.13
 */

#include <stdio.h>

#define ASCII_CHARS 128

int main()
{
  char *ascii_labels[ASCII_CHARS] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS", "TAB", "LF", "VT", "FF", "CR", "SO", "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US",
    "SPC", "!", "\"", "#", "$", "%", "&", "'",
    "(", ")", "*", "+", ",", "-", ".", "/",
    "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", ":", ";", "<", "=", ">", "?",
    "@", "A", "B", "C", "D", "E", "F", "G",
    "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W",
    "X", "Y", "Z", "[", "\\", "]", "^", "_",
    "`", "a", "b", "c", "d", "e", "f", "g",
    "h", "i", "j", "k", "l", "m", "n", "o",
    "p", "q", "r", "s", "t", "u", "v", "w",
    "x", "y", "z", "{", "|", "}", "~", "DEL"
  };

  // Initialise all character counts to 0
  int character_count[ASCII_CHARS];
  for (int i = 0; i < ASCII_CHARS; i++)
  {
    character_count[i] = 0;
  }

  // Count all the input characters
  char c;
  do
  {
    c = getchar();
    character_count[c]++;
  } while (c != EOF);

  int highest_count = 0;
  for (int i = 0; i < ASCII_CHARS; i++)
  {
    highest_count = character_count[i] > highest_count ? character_count[i] : highest_count;
  }

  // Exit if no characters were input
  if (highest_count == 0)
  {
    printf("No characters were input.\n");
    return 1;
  }

  // Print horizontal histogram
  printf("Horizontal Histogram\n");
  printf("-----------------------\n\n");

  int no_of_chars = 0;
  for (int i = 0; i < ASCII_CHARS; i++)
  {
    if (character_count[i] == 0)
    {
      continue;
    }

    no_of_chars++;

    printf("\t%5s - |  ", ascii_labels[i]);

    for (int j = 0; j < character_count[i]; j++)
    {
      printf ("#  ");
    }

    putchar('\n');
  }

  printf("\t\t\t|__");
  for (int i = 0; i <= highest_count; i++)
  {
    printf("__");
  }

  if (highest_count < 100)
  {
    printf("\n\t\t\t  ");
    for (int i = 1; i <= highest_count; i++)
    {
      printf("%2d ", i);
    }
  }

  // Print vertical histogram
  printf("\n\nVertical Histogram\n");
  printf("-----------------------\n\n");

  for (int i = highest_count + 1; i > 0; i--)
  {
    printf("\t%5d - |   ", i);

    for (int j = 0; j < ASCII_CHARS; j++)
    {
      if (character_count[j] == 0)
      {
        continue;
      }

      if (character_count[j] >= i)
      {
        putchar('#');
      }
      else
      {
        putchar(' ');
      }

      printf("   ");
    }

    putchar('\n');
  }

  printf("\t\t\t|_");
  for (int i = 0; i <= no_of_chars; i++)
  {
    printf("____");
  }

  printf("\n\t\t\t ");
  int j = 0;
  for (int i = 0; i <= no_of_chars; i++)
  {
    while (j < ASCII_CHARS)
    {
      if (character_count[j] != 0)
      {
        printf("%4s", ascii_labels[j]);
        j++;
        break;
      }
      else
      {
        j++;
      }
    }
  }

  return 0;
}