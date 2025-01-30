/**
 * Program to print a historgram of the length of words in the input.
 * 
 * Exercise 1.13
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define WORD_BUFFER 100

int main()
{
  // Create an array to store length of the words
  int word_lengths[WORD_BUFFER];
  for (int i = 0; i < WORD_BUFFER; i++)
  {
    word_lengths[i] = 0;
  }

  printf("\nInput Text: ");

  // Read the input characters and count length of each word
  char c;
  int word_index = 0;
  int in_word = FALSE;
  do
  {
    c = getchar();

    if (c == ' ' || c == '\t' || c == '\n')
    {
      if (in_word)
      {
        word_index++;
        in_word = FALSE;
      }

      if (word_index == WORD_BUFFER)
      {
        break;
      }
    }
    else
    {
      word_lengths[word_index]++;
      in_word = TRUE;
    }
  } while (c != EOF);

  // Exit if no words were input
  int number_of_words = word_index;
  if (number_of_words < 1)
  {
    printf("No words were entered.\n");
    return 1;
  }

  // Calculate the highest word length
  int max_word_length = 0;
  for (int i = 0; i < number_of_words; i++)
  {
    if (max_word_length < word_lengths[i])
    {
      max_word_length = word_lengths[i];
    }
  }

  // Print horizontal histogram
  printf("\n\nHorizontal Histogram\n");
  printf("-----------------------\n\n");

  printf("\t\t|\n");
  for (int i = 0; i < number_of_words; i++)
  {
    printf("     word %3d - | ", i + 1);

    for (int j = 0; j < max_word_length; j++)
    {
      if (word_lengths[i] >= j)
      {
        putchar('#');
      }
    }

    putchar('\n');
  }

  printf("\t\t|");
  for (int i = 0; i <=max_word_length; i++)
  {
    putchar('_');
  }
  

  // Print vertical histogram
  printf("\n\nVertical Histogram\n");
  printf("-----------------------\n\n");

  for (int i = max_word_length + 1; i > 0; i--)
  {
    printf("\t%5d - | ", i);
    
    for (int j = 0; j < number_of_words; j++)
    {
      if (word_lengths[j] >= i)
      {
        putchar('#');
      }
      else
      {
        putchar(' ');
      }

      putchar(' ');
    }

    putchar('\n');
  }

  printf("\t\t|");
  for (int i = 0; i <= number_of_words; i++)
  {
    printf("__");
  }

  printf("\n\n");

  return 0;
}