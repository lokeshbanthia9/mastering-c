
# Exercise 1.6

> Verify that the expression getchar() != EOF is 0 or 1.

# Solution

- ### Approach

To test if the expression `getchar() != EOF` is `0` or `1`, we can print the result of the expression as an integer value.

When the program is executed, `getchar()` will expect a character input first before the expression is checked. For this, I will input multiple characters to test if the output of the expression remains consistent across different characters.

- ### Code

```c
#include <stdio.h>

int main()
{
  printf("getchar() != EOF: %d\n", getchar() != EOF);
  return 0;
}
```

- ### Compilation Output

```console
$ gcc -o validate validate.c

```

No warnings or errors.

- ### Execution Result

  #### 1. Input `a`

  ```console
  $ ./validate
  a
  getchar() != EOF: 1
  ```

  #### 2. Input `0`

  ```console
  $ ./validate
  0
  getchar() != EOF: 1
  ```

  #### 3. Input `1`

  ```console
  $ ./validate
  1
  getchar() != EOF: 1
  ```

  #### 4. Input `!`

  ```console
  $ ./validate
  !
  getchar() != EOF: 1
  ```

  #### 5. Input blankspace

  ```console
  $ ./validate
  
  getchar() != EOF: 1
  ```

In all different input cases, the ouput of the expression remains `1`.

- ### Explanation

`EOF` refers to End Of File, which is a special integer in C. It contains a value different from any of the values that can be stored in the type `char`. Hence, irrespective of the input we give in `getchar()`, the input character will never be equal to `EOF`, and the expression `getchar() != EOF` will always result in true.

Since C uses `0` for false and `1` (or any non-zero value) for true, the output of the expression will always result in `1`.

- ### Special Case

There is one case however, where the expression `getchar() != EOF` will output `0`.

The expression will result in false (or `0`) only if we explicity signal an end-of-file condition trigerred by a special key combination (`Ctrl + D` for Linux/Mac or `Ctrl + Z` for Windows).

```console
$ ./validate
^Z
getchar() != EOF: 0
```

`^Z` (`Ctrl + Z`) signals end-of-file on windows, which is equal to `EOF`, hence the expression results in false or `0`.

---