
# Exercise 1.8

> Write a program to count blanks, tabs, and newlines.

# Solution

- ### Approach

To count the number of blank spaces, tab spaces, and new lines, I created three variable counters `blanks`, `tabs` and `lines` respectively. I first print an `Enter Text` message to prompt the user to start writing their characters.

I have used a `while` loop to keep the incremented variable in each iteration flexible. The loop reads a character until `EOF` is passed, which if run in terminal, will be a special key combination to signal end-of-file (`Ctrl + Z` on windows). The loop checks if the character is any of the characters we are counting, and increments their respective counter.

After completing the loop, I print out the summary of all the character counts, and end the program by returning `0`.

- ### Code

```c
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
```

- ### Compilation Output

```console
$ gcc -o count count.c

```

No warnings or errors.

- ### Execution Result

  Note: All tabs were entered in the console directly without visual respresentation.

  #### 1. Test Case `1`: Simple Input

  ```console
  $ ./count

  Enter Text
  hello, world 
  ^Z

  Summary of Counts
  Blanks: 1        
  Tabs: 0
  New Lines: 1 
  ```

  #### 2. Test Case `2`: Multiple Lines

  ```console
  $ ./count

  Enter Text
  Line one
  Line two 
  Line three
  ^Z

  Summary of Counts
  Blanks: 3
  Tabs: 0
  New Lines: 3
  ```

  #### 3. Test Case `3`: Tabs Only

  (input: `\t\t\t`)

  ```console
  $ ./count

  Enter Text

  ^Z

  Summary of Counts
  Blanks: 0
  Tabs: 3
  New Lines: 1
  ```

  4. Test Case `4`: Mixed Input

  (input: ` \t\n\t  \nt e s t\t\n`)

  ```console
  $ ./count

  Enter Text
  
            
  t e s t 
  ^Z

  Summary of Counts
  Blanks: 6
  Tabs: 3
  New Lines: 3
  ```

---