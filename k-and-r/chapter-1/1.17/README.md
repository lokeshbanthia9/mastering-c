
# Exercise 1.17

> Write a program to print all input lines that are longer than 80 characters.

# Solution

- ### Approach

I made a `get_line` function to read the input characters until new line or end-of-file signal is passed, and store the contents in an array until `MAXLINE` buffer limit.

In the `main` function, I use a `while` loop to call `get_line` function in each iteration, and print the line as-is if the number of characters in it exceed 80. If no characters is passed in the input line (only end-of-file signal), the loop stops and the program ends with exit status `0`.

- ### Code (see `copy.c`)

```c
# include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int limit);

int main()
{
    int len;
    char line[MAXLINE];

    while (1)
    {
        len = get_line(line, MAXLINE);

        if (len == 0)
        {
            return 0;
        }

        if (len <= 80)
        {
            continue;
        }

        printf("%s\n", line);
    }
}

int get_line(char s[], int limit)
{
    int i;

    for (i = 0; i < limit - 1; i++)
    {
        int c = getchar();

        if (c == EOF)
        {
            s[i] = '\0';
            return i;
        }

        s[i] = c;

        if (c == '\n')
        {
            i++;
            s[i] = '\0';
            return i;
        }
    }

    s[i] = '\0';

    while (1)
    {
        int c = getchar();

        if (c == EOF)
        {
            return i;
        }

        i++;

        if (c == '\n')
        {
            return i;
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

#### 1. No Input

```console
$ ./copy
^Z
```

#### 2. New Line Input

```console
$ ./copy

^Z
```

#### 3. Single Line Input less than 80 characters

```console
$ ./copy
hello, world
^Z
```

#### 4. Single Line Input more than 80 characters

```console
$ ./copy
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi porta id erat ac venenatis. Donec ac.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi porta id erat ac venenatis. Donec ac.

^Z
```

#### 5. Multiple Lines Input

```console
$ ./copy
Lorem dui.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sit amet dapibus libero. Donec vulputate, mi at elementum faucibus, nunc dui nisi.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sit amet dapibus libero. Donec vulputate, mi at elementum faucibus, nunc dui nisi.

Lorem ipsum dolor sit amet, consectetur cras amet.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam ac mattis leo. Sed quis consequat libero. Vivamus in risus libero. Proin et nunc interdum, eleifend risus at, pharetra neque. Nulla volutpat a est id ultricies. Integer ac libero sagittis, tincidunt nunc vulputate, aliquam nisl. Ut a tristique massa, id feugiat mauris. Maecenas lacinia erat vulputate ipsum pharetra efficitur. Praesent finibus metus vel ipsum sagittis, vitae efficitur lacus scelerisque. Aliquam felis eros vestibulum.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam ac mattis leo. Sed quis consequat libero. Vivamus in risus libero. Proin et nunc interdum, eleifend risus at, pharetra neque. Nulla volutpat a est id ultricies. Integer ac libero sagittis, tincidunt nunc vulputate, aliquam nisl. Ut a tristique massa, id feugiat mauris. Maecenas lacinia erat vulputate ipsum pharetra efficitur. Praesent finibus metus vel ipsum sagittis, vitae efficitur lacus scelerisque. Aliquam felis eros vestibulum.

^Z
```

#### 6. Buffer Exceeded Input

```console
$ ./copy
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc vel enim et lorem sollicitudin bibendum et sed lacus. Ut a magna non augue convallis ornare. Pellentesque leo metus, dictum sit amet finibus eget, rhoncus ac magna. Curabitur ut varius sapien, eu suscipit arcu. Proin molestie bibendum arcu et consequat. Mauris ac interdum neque. Nunc commodo purus vel sapien porttitor, a cursus turpis placerat. Nullam nec quam sodales, sodales lacus eget, convallis est.Nullam egestas gravida diam vitae mattis. Morbi non erat euismod tortor commodo auctor sit amet et turpis. Vivamus scelerisque libero vel imperdiet tristique. Suspendisse a ex eu nibh accumsan accumsan. Cras id ultrices neque, eget lacinia mi. Mauris ac tincidunt sem. Nullam tristique eros erat, eget maximus dolor sodales eget. Duis a mi mollis, convallis arcu at, elementum risus.Fusce venenatis euismod orci vitae posuere. Vestibulum sed fermentum diam. Suspendisse quis tellus vel justo faucibus placerat id a nisi. Aliquam laoreet 
id orci quis iaculis. Proin et lectus vitae dolor maximus placerat id non lectus. Curabitur id ipsum orci. Vestibulum sit amet ligula vehicula, maximus ligula non, imperdiet ligula. Curabitur sem urna, volutpat eget malesuada nec, viverra vel turpis. Nam a augue consequat, viverra magna ut, imperdiet est. Etiam eu ultricies mi. Pellentesque pretium vulputate leo, in dictum mauris posuere quis. Curabitur ut maximus nulla. Integer fringilla eleifend ex et pulvinar. In rutrum vestibulum metus.
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc vel enim et lorem sollicitudin bibendum et sed lacus. Ut a magna non augue convallis ornare. Pellentesque leo metus, dictum sit amet finibus eget, rhoncus ac magna. Curabitur ut varius sapien, eu suscipit arcu. Proin molestie bibendum arcu et consequat. Mauris ac interdum neque. Nunc commodo purus vel sapien porttitor, a cursus turpis placerat. Nullam nec quam sodales, sodales lacus eget, convallis est.Nullam egestas gravida diam vitae mattis. Morbi non erat euismod tortor commodo auctor sit amet et turpis. Vivamus scelerisque libero vel imperdiet tristique. Suspendisse a ex eu nibh accumsan accumsan. Cras id ultrices neque, eget lacinia mi. Mauris ac tincidunt sem. Nullam tristique eros erat, eget maximus dolor sodales eget. Duis a mi mollis, convallis arcu at, elementum risus.Fusce venenatis euismod orci vitae posuere. Vestibulum sed fermentum diam. Suspendisse quis tellus vel justo faucibus placerat id a nisi. Aliquam la      
^Z
```

Only the first 1000 characters were printed, which was the set `MAXLINE` buffer.

---