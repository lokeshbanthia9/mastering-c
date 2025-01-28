
# Exercise 1.11

> How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

- ### Original Code (see `count.c`)

```c
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  while ((c = getchar()) != EOF)
  {
    ++nc;

    if (c == '\n')
    {
      ++nl;
    }

    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
    }
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}
```

- ### Compilation Output

```console
$ gcc -o count count.c

```

No warnings or errors.

# Solution

- ### Approach

One way to go about testing the program is making sure it can handle all the edge cases. We need to find those inputs for which the program is unable to count either lines, words or characters properly.

Some of these edge cases include:
1. Empty input
2. Character definitions input (`\t` and `\n`).
3. Long continuos input
4. Trailing new lines
5. Adding end-of-file signal in the middle of input line.

- ### Test Cases

  #### 1. Empty Input

  Note: `^Z` represent `Ctrl + Z`, which signals end-of-file on windows.
  Note: Tabs are entered directly in the terminal without any visual representation.

  Input: `^Z`
  Expected Output: `0 0 0`

  ```console
  $ ./count
  ^Z
  0 0 0
  ```

  #### 2. Character Definitions Input (`\t` and `\n`)

  Input: `\\t\\n\n^Z`
  Expected Output: `1 1 5`

  Note: Double backslash in the above input is used to indicate the literal use of `\t` and `\n` characters, instead of entering tabs and new lines.

  ```console
  $ ./count
  \t\n
  ^Z
  1 1 5
  ```

  #### 3. Long Continuos Input

  Input: `aaa...`
  Expected Output: `1 1 1601` (1600 `a`'s and 1 new line)

  ```console
  $ ./count
  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ^Z
  1 1 1601
  ```

  #### 4. Trailing New Lines

  Input: `start\n\n\n\nend\n^Z`
  Expected Output: `5 2 13`

  ```console
  $ ./count
  start



  end
  ^Z
  5 2 13
  ```

  #### 5. End-Of-File Signal

  Adding end-of-file signal (`Ctrl + Z` on windows) in the middle of the input line.

  Input: `hello, ^Z world\n`
  Expected Output: `0 2 8`

  (`^Z` is counted as a literal character, and any character after it are ignored entirely until new line)

  ```console
  $ ./count
  hello, ^Z world
  ^Z
  0 2 8
  ```

---