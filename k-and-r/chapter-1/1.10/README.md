
# Exercise 1.10

> Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`. This makes tabs and backspaces visible in an unambiguous way.

# Solution

- ### Approach

To copy the program's input to its output, I am using `getchar` function to read the input, and `printf` and `putchar` functions to print the character.

I make a `char` variable `c` to store the current charater, and use a while loop to read characters one by one using `getchar`.

In each iteration, I check if the character in `c` is tab (`\t`), backspace (`\b`) or backslash (`\`), replace the characters respectively, and output using `printf`. If the character is not any of these three, I print the character as-is using `putchar`.

If the first character of any new line is end-of-file signal (`Ctrl + Z` on windows or `Ctrl + D` on mac/linux), the loop ends and the program terminates with exit status `0`.

- ### Terminal Behaviour

Although I am checking for any backspace characters matching `\b`, pressing backspace during input will not have any effect on the output. This is because of the way terminal works in windows, which uses line-buffer for the input stream, meaning the input will only be processed and sent to the program once we press `Enter` as the final input. Pressing backspace while writing input will be handled by the terminal itself, and will not be recorded in the final stream sent to the program, and hence the input character `c` will never match the backspace character `\b`.

If we try to input `\b` on the terminal instead of pressing backspace, the terminal reads it as two separate characters of `\` and `b`, which means the output will be `\\b` (single backslash `\` are replaced by double backslash `\\`).

- ### Code (see `copy.c`)

```c
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
```

- ### Compilation Output

```console
$ gcc -o copy copy.c

```

No warnings or errors.

- ### Execution Result

Note: Tab spaces are entered directly on the keyboard without any visual representation.

Note: `^Z` represent `Ctrl + Z` which signals end-of-file (`EOF`) on windows.

  #### 1. Test Case `1`: Simple Input

  ```console
  $ ./copy
  hello, world
  hello, world
  ^Z
  ```

  #### 2. Test Case `2`: Tab Input

  ```console
  $ ./copy
  hello,          world
  hello,\t\tworld
  ^Z
  ```

  #### 3. Test Case `3`: Backslash Input

  ```console
  $ ./copy
  hello, \\ world
  hello, \\\\ world
  ^Z
  ```

  #### 4. Test Case `4`: Mixed Input

  ```console
  $ ./copy
  this    tests   for     \b
  this\ttests\tfor\t\\b
  ^Z
  ```

  #### 5. Test Case `5`: Multiple Lines

  ```console
  $ ./copy
          this is test    \1
  \tthis is test\t\\1
  @  test 2\
  @  test 2\\
  this is test\b  \3\!
  this is test\\b\t\\3\\!
  ^Z
  ```

  #### 6. Test Case `6`: No Input

  ```console
  $ ./copy


  ^Z
  ```

---