
# Exercise 1.12

> Write a program that prints its input one word per line.

# Solution

- ### Approach

For the purpose of this program, I am assuming words to be separated by blank space (`' '`), tab space (`\t`) or new line (`\n`). 

To copy the program's input to its output one word per line, I am running a `while` loop to read the input characters one by one, until end-of-file signal is passed.

In each iteration, if the input character is either blank space (`' '`) or tab space (`\t`), a new line (`\n`) is printed as long as the input is not a consecutive space. For any other character input, the character is printed as-is. 

(see Exercise `1.19` for information on terminal behaviour)

- ### Code (see `copy.c`)

```c
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
```

- ### Compilation Output

```console
$ gcc -o copy copy.c

```

No warnings or errors.

- ### Execution Result

Note: Tab spaces are entered directly from the keyboaord without any visual representation.

Note: `^Z` represents `Ctrl + Z` which signals end-of-file (`EOF`) on windows.

  #### 1. Simple Input

  Input: `hello, world`
  Expected Output: `hello,\nworld`

  ```console
  $ ./copy
  hello, world
  hello,
  world 
  ^Z
  ```

  #### 2. Multiple Spaces

  Input: `hello, \t\t world`
  Expected Output: `hello,\nworld`

  ```console
  $ ./copy
  hello,           world
  hello,
  world 
  ^Z
  ```

  #### 3. Mixed Input

  Input: `\tlet's do @ \t mixed input   test \t (0) \t`
  Expected Output: `let's\ndo\n@\nmixed\ninput\ntest\n(0)\n`

  ```console
  $ ./copy
          let's do @       mixed input   test      (0) 
  let's
  do   
  @    
  mixed
  input
  test 
  (0)  

  ^Z
  ```

  #### 4. Multiple Lines

  Input: `this \t is test \t 1!\ntest  @2\ntime for \t\t\t test 3?`
  Expected Output: `this\nis\ntest\n1!\ntest\n@2\ntime\nfor\ntest\n3?`

  ```console
  $ ./copy
  this     is test         1!
  this
  is  
  test
  1!  
  test  @2
  test
  @2  
  time for                         test 3?
  time
  for 
  test
  3?  
  ^Z
  ```

  #### 5. Empty Input

  Input: `\n`
  Expected Output: `\n`

  ```console
  $ ./copy


  ^Z
  ```

---