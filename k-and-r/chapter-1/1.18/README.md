
# Exercise 1.18

> Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

# Solution

- ### Approach

I first make a `get_line` function to take the input of all characters and store it in an array until new-line or end-of-line signal is passed, or the number of characters reaches the `MAXLINE` buffer limit.

I also make a `put_line` function which removes all the trailings blanks and tabs, and prints all the characters in the line. If all the characters in the line are blanks, tabs or new-line, the line is not printed.

In the `main` function, I run a `while` loop calling `get_line` function in each iteration. If the input line contains no characters (on end-of-file signal), the loop stops and the program ends with exit code `0`. Otherwise, the line is printed using the `put_line` function.

- ### Code (see `rm-space.c`)

```c
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXLINE 1000

void get_line(char s[], int limit);
void put_line(char s[]);

int main()
{
    char line[MAXLINE];

    while (TRUE)
    {
        get_line(line, MAXLINE);

        if (line[0] == '\0')
        {
            return 0;
        }

        put_line(line);
    }
}

void get_line(char s[], int limit)
{
    printf("\nInput Text: ");

    for (int i = 0; i < limit - 1; i++)
    {
        int c = getchar();

        if (c == EOF)
        {
            s[i] = '\0';
            return;
        }

        s[i] = c;

        if (c == '\n')
        {
            i++;
            s[i] = '\0';
            return;
        }
    }

    s[limit - 1] = '\0';

    while (TRUE)
    {
        int c = getchar();

        if (c == EOF || c == '\n')
        {
            break;
        }
    }
}

void put_line(char s[])
{    
    int i = 0;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            break;
        }
    }

    if (s[i] == '\0')
    {
        return;
    }

    int in_space = FALSE;

    printf("\nOutput Text: ");

    for (; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' || s[i] == '\t')
        {
            if (!in_space)
            {
                putchar(s[i]);
                in_space = TRUE;
            }
        }
        else
        {
            putchar(s[i]);
            in_space = FALSE;
        }
    }
}
```

- ### Compilation Output

```console
$ gcc -o rm-space rm-space.c

```

No warnings or errors.

- ### Execution Result

#### 1. No Input

```console
$ ./rm-space

Input Text: ^Z
```

#### 2. New Line Input

```console
$ ./rm-space

Input Text: 

Input Text: ^Z
```

#### 3. Only Spaces Input

```console
$ ./rm-space

Input Text:           

Input Text: ^Z
```

#### 4. Simple Input

```console
$ ./rm-space

Input Text: hello, world

Output Text: hello, world

Input Text: ^Z
```

#### 5. Multiple Lines Input

```console
$ ./rm-space

Input Text:     hello

Output Text: hello

Input Text: my    name    is

Output Text: my name is

Input Text: Lokesh Banthia

Output Text: Lokesh Banthia

Input Text: ^Z
```

#### 6. Buffer Exceeded Input

```console
$ ./rm-space

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras quis sodales odio. Morbi ac lorem interdum ligula interdum pretium. Aliquam eget gravida quam. Aliquam interdum, felis vitae semper commodo, enim ante imperdiet tortor, vel tempor dui nisl quis est. Cras in sem at odio pellentesque sagittis vel vitae ex. Fusce accumsan erat a ex fringilla posuere. Cras accumsan vehicula vehicula. Duis cursus porttitor condimentum. Praesent at metus et neque facilisis sagittis sed sed felis. Fusce ac suscipit sem, vitae malesuada erat. Morbi dapibus nibh lectus, eget sollicitudin ligula sodales sit amet. Mauris eu nulla imperdiet, viverra est vitae, placerat quam. Aliquam erat volutpat. Donec nec diam ligula.Aenean hendrerit, nunc non finibus venenatis, ex tellus venenatis tortor, a vulputate magna nisi vel mi. Donec blandit non lectus eu congue. Curabitur feugiat faucibus porttitor. Morbi dictum, ipsum sit amet malesuada semper, erat tellus pulvinar ante, id vehicula nisl elit eget leo. Nunc pellentesque vestibulum orci. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam tempor pulvinar sem eget convallis. Cras cursus lacinia est non tristique. Aenean vel risus augue. Phasellus quis efficitur quam. Maecenas eu massa semper, consectetur diam id, dapibus sapien. Mauris venenatis, quam ac auctor tempus, quam metus dapibus elit, sed consequat nunc dui non elit. Proin imperdiet turpis a pulvinar pulvinar. Proin massa orci, ornare sed accumsan dictum, feugiat ut nulla eleifend.

Output Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras quis sodales odio. Morbi ac lorem interdum ligula interdum pretium. Aliquam eget gravida quam. Aliquam interdum, felis vitae semper commodo, enim ante imperdiet tortor, vel tempor dui nisl quis est. Cras in sem at odio pellentesque sagittis vel vitae ex. Fusce accumsan erat a ex fringilla posuere. Cras accumsan vehicula vehicula. Duis cursus porttitor condimentum. Praesent at metus et neque facilisis sagittis sed sed felis. Fusce ac suscipit sem, vitae malesuada erat. Morbi dapibus nibh lectus, eget sollicitudin ligula sodales sit amet. Mauris eu nulla imperdiet, viverra est vitae, placerat quam. Aliquam erat volutpat. Donec nec diam ligula.Aenean hendrerit, nunc non finibus venenatis, ex tellus venenatis tortor, a vulputate magna nisi vel mi. Donec blandit non lectus eu congue. Curabitur feugiat faucibus porttitor. Morbi dictum, ipsum sit amet malesuada semper, erat tellus pulvinar ante, id vehicula nisl elit eget leo. Nun
Input Text: ^Z
```

Only the first 1000 characters were printed, which was the set `MAXLINE` buffer.

---