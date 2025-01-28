
# Exercise 1.9

> Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

# Solution

- ### Approach

To copy the program's input to its output, I will be using `getchar()` and `putchar()` methods. I first created two variables, `c` for stroring the current character, and `prevous_blank` for storing `0` or `1` based on whether the immediate last character was blank space or not.

I use a `while` loop because of the absence of any loop counter. In each iteration, `getchar()` is called and the character is stored in `c`.

If the character in `c` is not end-of-file signal, the character is printed unless its a consecutive blank checked by `previous_blank` variable.

If the character in `c` was an end-of-file signal (`Ctrl + Z` on windows or `Ctrl + D` on mac/linux), the loop stops and the program ends with an exit status of 0.

- ### Terminal Behaviour

On Windows, when reading input from the terminal, the input is usually line-buffered. This means the program waits to read the input stream until we press `Enter` to process the entire line.

When running this program, the input characters should be written in a single line. After pressing `Enter`, the program will read the line and print all the characters one by one in the next line. The program will keep running as alternate input and output lines, until the end-of-file signal is passed.

Note: It is due to the same terminal behaviour, that the end-of-file signal must be sent at the beginning of a new line to terminate the program. Any end-of-file signal sent in the middle or end of a line is not interpreted by the terminal to be `EOF`. Doing so however, will only output the characters before the end-of-file signal, and start to read the next input from the same line as output.

- ### Code

```c
#include <stdio.h>

int main()
{
  char c;
  int previous_blank = 0;

  printf("Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)\n");

  while ((c = getchar()) != EOF)
  {
    if (!previous_blank)
    {
      putchar(c);
    }

    if (c == ' ')
    {
      previous_blank = 1;
    }
    else
    {
      previous_blank = 0;
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

(Note: `^Z` represents `Ctrl + Z` which acts as the end-of-file signal on windows)

  #### 1. Test Case `1`: Simple Input

  ```console
  $ ./copy
  Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)
  hello, world
  hello, world
  ^Z
  ```

  #### 2. Test Case `2`: Multiple Spaces

  ```console
  $ ./copy
  Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)
  hello,      world
  hello, world
  ^Z
  ```

  #### 3. Test Case `3`: Multiple Lines

  ```console
  $ ./copy
  Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)
      hello,    world
  hello, world
  this    is    @    test   
  this is @ test
      this is  ...   C 
  this is ... C
  ^Z
  ```

  #### 4. Test Case `4`: No Input

  ```console
  $ ./copy
  Enter Text (To stop, Ctrl + Z on windows, Ctrl + D on mac/linux)
  ^Z
  ```

---