
# Exercise 1.7

> Write a program to print the value of EOF.

# Solution

- ### `EOF` Behaviour

`EOF` stands for End Of File. It is a special value that indicates the end of a file has been reached. It is an integer defined in the standard input/output library. The numeric value of `EOF` is not equal to any of the values that can be stored in `char`. It's exact numeric value is implemented by the specific compiler.

- ### Approach

For compiling this program, I am using GNU C compiler `GCC`. I am printing the value of `EOF` as an integer.

- ### Code

```c
#include <stdio.h>

int main()
{
  printf("EOF: %d\n", EOF);
}
```

- ### Compilation Output

```console
$ gcc -o print-eof print-eof.c

```

No warnings or errors.

- ### Execution Result

```console
$ ./print-eof
EOF: -1
```

Thus, the value of EOF in the GNU C library is set to `-1`.

The value of `EOF` in other libraries is guaranteed to be some negative value, since it needs to be distinct from any of the `char` values, which ranges from 0 to 255 in extended ASCII system. It is commonly set to `-1`.

---