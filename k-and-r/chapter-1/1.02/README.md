
# Exercise 1.2

> Experiment to find out what happens when prints's argument string contains \c, where c is some character not listed above.

# Solution

In `printf`, backslash (`\`) is used to introduce escape sequences, special characters that cannot be easily typed in a string literal.

Some of the common escape sequences include:

| Escape Sequence | Name | Description |
| - | - | - |
| `\n` | New Line | Moves the cursor to the start of the next line |
| `\t` | Horizontal Tab | Inserts tab space |
| `\\` | Backslash | Inserts backslash character |
| `\'` | Single Quote | Inserts single quotation marks |
| `\"` | Double Quote | Inserts double quotation marks |
| `\0` | NULL | Represents the NULL character |

## Unknown Escape Sequences

Not all characters are assigned as an escape sequence. The compiler generally warns us on using an unknown escape sequence.

For example: `\c` is an unknown escape sequence.

### Implementing `\c`

- #### Code (see `invalid.c`)

```c
#include <stdio.h>

int main()
{
  printf("Implementing \\c: \c\n");
}
```

- #### Compilation Output

```console
$ gcc -o invalid invalid.c
invalid.c: In function 'main':
invalid.c:11:34: warning: unknown escape sequence: '\c'
   11 |   printf("Implementing \\c: \c\n");
      |                                  ^
```

The compiler gives us a warning for using an unknown escape sequence inside `printf`, but it does not treat the usage as a fatal error.

- #### Execution Result

```console
$ ./invalid
Implementing \c: c
```

During execution, the backslash (`\`) is ignored and the character (`c`) is printed as-is.

- #### Explanation

On unknown escape sequence, the compiler warns about an unknown escape sequence and treats `\` as a literal character, followed by the character. The backslash is ignored and the character following it is treated as a normal character to be printed.

---