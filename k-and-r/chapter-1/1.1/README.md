
# Exercise 1-1

> Run the `hello, world` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.

```c
#include <stdio.h>

main()
{
  printf("hello, world\n");
}
```

# Solution

- ### Compilation Output

Running this code as-is gives a compiler warning.

```console
$ gcc hello.c
hello.c:3:1: warning: return type defaults to 'int' [-Wimplicit-int]
    3 | main()
      | ^~~~
```

**Explanation:** Missing return type for the function `main`. The compiler defaults the return type in such a case to `int`.

- ### Execution Result

```console
$ ./a
hello, world
```


## Leaving out parts of the program

### 1. Remove `#include <stdio.h>`

- #### Code

```c
main()
{
  printf("hello, world\n");
}
```

- #### Compilation Output

The compiler shows the following warnings, in addition to `[-Wimplicit-int]`

  - `warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]`
  - `warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]`

**Explanation:** Missing the appropriate header files for the function being used. In this case, missing the standard input/output library `<stdio.h>` declaration for `printf`.

- #### Execution Result

Running the executable gives the expected string output `hello, world`.

### 2. Remove `main()`

- #### Code

```c
#include <stdio.h>

printf("hello, world");
```

- #### Compilation Output

Program not compiled due to the error.

- `error: expected declaration specifiers or '...' before string constant`

**Explanation:** `printf` cannot be used outside of a function.

### 3. Remove `\n` in `printf`

- #### Code

```c
#include <stdio.h>

main()
{
  printf("hello, world");
}
```

- #### Compilation Output

No additional compiler warnings apart from `[-Wimplicit-int]`.

- #### Execution Result

Running the executable still prints the string, but does not move cursor to a new line.


## Improving the Program

We can include the return type of the function as `int` to remove `[-Wimplicit-int]` warning. (see `hello-2.c`)

- ### Code

```c
#include <stdio.h>

int main()
{
  printf("hello, world\n");
}
```

- ### Compilation Output & Execution Result

The version compiles cleanly without any warnings, and runs as expected.

```console
$ gcc hello-2.c
(no output, no warnings, no errors)

$ ./a
hello, world
```

---