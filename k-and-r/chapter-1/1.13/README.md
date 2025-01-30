
# Exercise 1.13

> Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

# Solution

- ### Approach

To calculate the length of words in the input, I make a `word_lengths` integer array, size of a pre-defined `WORD_BUFFER`, and initialise all values to `0`. The ` do while` loop reads the input characters one by one and the length of the words are calculated. For this program, I have assumed words to be separated by blank space (`' '`), tab space (`\t`) and new line (`\n`).

I then find the highest length of any word. I print the output histogram in two different ways, horizontal and vertical. For both histograms, I print the output lines using the character `#`.

For horizontal histogram, I run a `for` loop to print length of each word one by one, along with the y-label being word number. For vertical histogram, I run a `for` loop to print all those characters greater than a certain length one by one, along with the y-label being the length.

- ### Code (see `histogram.c`)

```c
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
```

- ### Compilation Output

```console
$ gcc -o histogram histogram.c

```

No warnings or errors.

- ### Execution Result

#### 1. Simple Input

```console
$ ./histogram

Input Text: hello world
^Z


Horizontal Histogram   
-----------------------

                |      
     word   1 - | #### 
     word   2 - | #### 
                |______

Vertical Histogram     
-----------------------

            6 - |      
            5 - | # #  
            4 - | # #  
            3 - | # #  
            2 - | # #  
            1 - | # #  
                |______

```

#### 2. Paragraph Input

```console

$ ./histogram

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. In ac tempus ex. Nullam vitae mattis enim, nec placerat nibh. Suspendisse vel mauris maximus, venenatis turpis ac, luctus purus. Maecenas et tempus odio. Maecenas ullamcorper est ut dui maximus finibus. Donec facilisis orci in mollis imperdiet. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Quisque sodales aliquam ex id iaculis. Pellentesque suscipit magna id commodo varius. Fusce cursus tincidunt metus, sed interdum tellus ultricies eget. Etiam id dui eu neque mollis commodo. Morbi eleifend mauris sapien. Vestibulum.
^Z


Horizontal Histogram
-----------------------

                |
     word   1 - | ######
     word   2 - | ######
     word   3 - | ######
     word   4 - | ####
     word   5 - | ######
     word   6 - | ############
     word   7 - | ###########
     word   8 - | ######
     word   9 - | ###
     word  10 - | ###
     word  11 - | #######
     word  12 - | ####
     word  13 - | #######
     word  14 - | ######
     word  15 - | #######
     word  16 - | ######
     word  17 - | ####
     word  18 - | #########
     word  19 - | ######
     word  20 - | ############
     word  21 - | ####
     word  22 - | #######
     word  23 - | #########
     word  24 - | ##########
     word  25 - | #######
     word  26 - | ####
     word  27 - | #######
     word  28 - | #######
     word  29 - | #########
     word  30 - | ###
     word  31 - | #######
     word  32 - | ######
     word  33 - | #########
     word  34 - | ############
     word  35 - | ####
     word  36 - | ###
     word  37 - | ####
     word  38 - | ########
     word  39 - | #########
     word  40 - | ######
     word  41 - | ##########
     word  42 - | #####
     word  43 - | ###
     word  44 - | #######
     word  45 - | ###########
     word  46 - | #####
     word  47 - | #######
     word  48 - | ########
     word  49 - | ##########
     word  50 - | ###
     word  51 - | #######
     word  52 - | ####
     word  53 - | ###########
     word  54 - | ########
     word  55 - | #########
     word  56 - | ##########
     word  57 - | #####
     word  58 - | ########
     word  59 - | ########
     word  60 - | ########
     word  61 - | ###
     word  62 - | ###
     word  63 - | #########
     word  64 - | ############
     word  65 - | #########
     word  66 - | ######
     word  67 - | ###
     word  68 - | ########
     word  69 - | ########
     word  70 - | ######
     word  71 - | #######
     word  72 - | ##########
     word  73 - | #######
     word  74 - | ####
     word  75 - | #########
     word  76 - | #######
     word  77 - | ##########
     word  78 - | ######
     word  79 - | ######
     word  80 - | ###
     word  81 - | ####
     word  82 - | ###
     word  83 - | ######
     word  84 - | #######
     word  85 - | #########
     word  86 - | ######
     word  87 - | #########
     word  88 - | #######
     word  89 - | ########
     word  90 - | ############
                |_____________

Vertical Histogram
-----------------------

           13 - |
           12 - |                                                                                                                               #
           11 - |           #                           #                           #                                                           #                                                   #    
           10 - |           # #                         #                           #                     #               #                     #                                                   #    
            9 - |           # #                         #       #                   #             #       #       #       #     #               #               #         #                         #    
            8 - |           # #                     #   #     # #         #       # #         #   #       #       #       #   # #             # # #             #     #   #               #   #     #    
            7 - |           # #                     #   #     # #         #       # #       # #   #       #     # #       # # # #   # # #     # # #     # #     #     #   #               #   #   # #    
            6 - |           # #       #   #   #     #   #   # # # #   # # #   #   # #       # #   #     # #   # # #   #   # # # #   # # #     # # #     # #   # # #   # # #             # #   # # # #    
            5 - | # # #   # # # #     #   # # # #   # # #   # # # #   # # #   # # # #       # # # #     # #   # # #   #   # # # #   # # #     # # # #   # # # # # #   # # # # #       # # # # # # # #    
            4 - | # # #   # # # #     #   # # # #   # # #   # # # #   # # #   # # # #       # # # # #   # # # # # #   #   # # # # # # # #     # # # #   # # # # # #   # # # # #       # # # # # # # #    
            3 - | # # # # # # # #     # # # # # # # # # # # # # # # # # # #   # # # # #   # # # # # #   # # # # # #   # # # # # # # # # #     # # # #   # # # # # # # # # # # #   #   # # # # # # # #    
            2 - | # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #    
            1 - | # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #    
                |______________________________________________________________________________________________________________________________________________________________________________________  

```

#### 3. No Input

```console
$ ./histogram

Input Text: ^Z
No words were entered.
```

#### 4. Empty Input

```console
$ ./histogram

Input Text:
^Z
No words were entered.
```

#### 5. Buffer Exceeded Input


```console
$ ./histogram

Input Text: Morbi dapibus turpis at nulla consectetur, vitae imperdiet nulla bibendum. Phasellus malesuada sapien et lectus iaculis, eget bibendum justo efficitur. Nam bibendum dictum ante, eget congue purus pharetra non. Donec a odio lacinia, feugiat est vel, ornare eros. Suspendisse imperdiet dapibus mi sit amet condimentum. Nunc molestie justo rutrum, euismod erat ac, tincidunt nisi. Cras porttitor orci sit amet mauris tincidunt, in vehicula nisi consequat. Aenean lorem elit, placerat non ipsum eget, varius scelerisque sem. Ut eu ligula ligula. Sed facilisis volutpat molestie. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi et tortor ac dui ornare congue. Morbi condimentum, lorem nec ornare tempor, velit felis finibus leo, ac convallis purus diam vel diam. Sed enim diam, consectetur aliquam scelerisque ac, vehicula vel velit. Nulla consequat erat sit amet laoreet aliquet. Maecenas eget facilisis felis.


Horizontal Histogram
-----------------------       

                |
     word   1 - | ######      
     word   2 - | ########    
     word   3 - | #######     
     word   4 - | ###
     word   5 - | ######      
     word   6 - | ############
     word   7 - | ######      
     word   8 - | ##########  
     word   9 - | ######      
     word  10 - | ##########  
     word  11 - | ##########  
     word  12 - | ##########  
     word  13 - | #######     
     word  14 - | ###
     word  15 - | #######     
     word  16 - | #########
     word  17 - | #####    
     word  18 - | #########  
     word  19 - | ######     
     word  20 - | ###########
     word  21 - | ####       
     word  22 - | #########  
     word  23 - | #######    
     word  24 - | ######     
     word  25 - | #####      
     word  26 - | #######
     word  27 - | ######
     word  28 - | #########
     word  29 - | #####
     word  30 - | ######
     word  31 - | ##
     word  32 - | #####
     word  33 - | #########
     word  34 - | ########
     word  35 - | ####
     word  36 - | #####
     word  37 - | #######
     word  38 - | ######
     word  39 - | ############
     word  40 - | ##########
     word  41 - | ########
     word  42 - | ###
     word  43 - | ####
     word  44 - | #####
     word  45 - | ############
     word  46 - | #####
     word  47 - | #########
     word  48 - | ######
     word  49 - | ########
     word  50 - | ########
     word  51 - | #####
     word  52 - | ####
     word  53 - | ##########
     word  54 - | ######
     word  55 - | #####
     word  56 - | ##########
     word  57 - | #####
     word  58 - | ####
     word  59 - | #####
     word  60 - | #######
     word  61 - | ###########
     word  62 - | ###
     word  63 - | #########
     word  64 - | #####
     word  65 - | ###########
     word  66 - | #######
     word  67 - | ######
     word  68 - | ######
     word  69 - | #########
     word  70 - | ####
     word  71 - | ######
     word  72 - | ######
     word  73 - | #######
     word  74 - | ############
     word  75 - | #####
     word  76 - | ###
     word  77 - | ###
     word  78 - | #######
     word  79 - | ########
     word  80 - | ####
     word  81 - | ##########
     word  82 - | #########
     word  83 - | ##########
     word  84 - | ######
     word  85 - | ######
     word  86 - | ######
     word  87 - | ####
     word  88 - | ######
     word  89 - | ############
     word  90 - | ###########
     word  91 - | ######
     word  92 - | ######
     word  93 - | ###
     word  94 - | #######
     word  95 - | ###
     word  96 - | ####
     word  97 - | #######
     word  98 - | ########
     word  99 - | ######
     word 100 - | ############
                |_____________

Vertical Histogram
-----------------------

           13 - |

           12 - |           #                                                                             #
               #
           11 - |           #                                                                 #           #                                                         #                             #      
               #
           10 - |           #                           #                                     #           #                               #       #                 #                             # #    
               #
            9 - |           #   #   # # #               #                                     # #         #               #     #         #       #                 #             #   #           # #    
               #
            8 - |           #   #   # # #       #   #   #   #           #         #           # #         #   #           #     #         #   #   #       #         #             # # #           # #    
               #
            7 - |   #       #   #   # # #       #   #   #   #           #         # #         # # #       #   #   # #     #     #         #   #   #       #         #         #   # # #           # #    
           #   #
            6 - |   # #     #   #   # # # #   # #   #   #   # #     #   #         # #     #   # # #       #   #   # #     #     #       # #   #   # #     #       # #       # #   # # #           # #    
   #     # #   #
            5 - | # # #   # # # # # # # # #   # #   # # #   # # #   # # #   #     # #     # # # # #       #   # # # #     # #   #       # #   #   # # # # #   # # # #       # #   # # # # # #   # # # # #   #     # # # #
            4 - | # # #   # # # # # # # # #   # # # # # #   # # # # # # # # #   # # #   # # # # # #     # # # # # # # #   # # # # #   # # #   # # # # # # #   # # # # #     # #   # # # # # #   # # # # #   #     # # # #
            3 - | # # #   # # # # # # # # #   # # # # # # # # # # # # # # # #   # # # # # # # # # #   # # # # # # # # # # # # # # # # # # #   # # # # # # # # # # # # #     # # # # # # # # # # # # # # #   #   # # # # #
            2 - | # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #   # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
            1 - | # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                |__________________________________________________________________________________________________________________________________________________________________________________________________________

```

Only the first 100 words were taken for input, which was the set `WORD_BUFFER` size. The program stopped taking input once the input reached `WORD_BUFFER` size, without waiting for `EOF` signal.

---