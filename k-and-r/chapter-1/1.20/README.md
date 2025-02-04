
# Exercise 1.20

> Write a program `detab` that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

# Solution

- ### Tab Stops

A tab stop is a fixed position in text where the cursor moves when a tab character (`\t`) is encountered. Instead of advancing by a fixed number of spaces, the tab moves the cursor to the next tab stop, which is a multiple of predefined tab width. For example, if tab stops are set to every `4` columns, a tab character should be repaced with enough spaces to move the cursor to the next multiple of `4`.

- ### Should n be a variable or a symbolic parameter?

Generally variables are preferred insetad of symbolic constants because of their type safety, scope and block rules, and efficient memory usage. Symbolic constants are better suited for scenarios where we need a text replacement, in place of some value or code.

In my program, I have used a variable, primarily due to tab width being user-defined. Since the value of tab width is getting stored at run-time, using a variable becomes necessary. However, if the tab width is fixed at compile-time, a symbolic constant can be an efficient choice.

- ### Approach

I take the input for the value of `tab_width` from the user and the text input line. After each input, the `clear_input` function clears all the input, until new-line or end-of-file signal is passed.

I call the `detab` function which replaces all the tabs in the input, with appropriate number of spaces based on their relative position to the next tab stop. I store the new string, with spaces, in a new output array.

Lastly, I print the output string, and end the program with exit status `0`.

- ### Code (see `detab.c`)

```c
#include <stdio.h>

#define MAXLINE 1000

int get_tab_width(void);
void get_line(char s[], int limit);
void detab(char tabs[], char blanks[], int tab_width);

int main(void)
{
    int tab_width = get_tab_width();
    
    char input_line[MAXLINE];
    get_line(input_line, MAXLINE);

    if (input_line[0] == '\0')
    {
        printf("\nNo characters were input.\n");
        return 0;
    }

    char output_line[MAXLINE * tab_width];
    detab(input_line, output_line, tab_width);

    printf("\nDetab Text: %s\n", output_line);
    return 0;
}

void clear_input(void)
{
    while (1)
    {
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            return;
        }
    }
}

int get_tab_width(void)
{
    int tab_width;

    while (1)
    {
        printf("\nEnter the tab width size (0 - 9): ");
        tab_width = getchar();

        if (tab_width >= '0' && tab_width <= '9')
        {
            clear_input();
            break;
        }
        else
        {
            if (tab_width != '\n' && tab_width != EOF)
            {
                clear_input();
            }
            printf("\nInvalid Input!\n");
        }
    }

    return tab_width - '0';
}

void get_line(char s[], int limit)
{
    printf("\nEnter Text: ");

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

    clear_input();
}

void detab(char tabs[], char blanks[], int tab_width)
{
    int b_index = 0;

    for (int i = 0; tabs[i] != '\0'; i++)
    {
        if (tabs[i] == '\t')
        {
            int spaces = tab_width - (b_index % tab_width);
            for (int t = 0; t < spaces; t++)
            {
                blanks[b_index] = ' ';
                b_index++;
            }
        }
        else
        {
            blanks[b_index] = tabs[i];
            b_index++;
        }
    }

    blanks[b_index] = '\0';
}
```

- ### Compilation Output

```console
$ gcc -o detab detab.c

```

No warnings or errors.

- ### Execution Result

Note: All tabs were entered directly from keyboard, without any visual representation.

#### 1. Invalid Tab Width Input

```console
$ ./detab

Enter the tab width size (0 - 9):

Invalid Input!

Enter the tab width size (0 - 9): ^Z

Invalid Input!

Enter the tab width size (0 - 9): -1

Invalid Input!

Enter the tab width size (0 - 9): five

Invalid Input!

Enter the tab width size (0 - 9): @2

Invalid Input!

Enter the tab width size (0 - 9): hello, world

Invalid Input!

Enter the tab width size (0 - 9): 4

Enter Text:
No characters were input.
```

#### 2. No Input Text

```console
$ ./detab

Enter the tab width size (0 - 9): 4 

Enter Text: ^Z

No characters were input.
```

#### 3. New Line Input Text

```console
$ ./detab

Enter the tab width size (0 - 9): 4

Enter Text: 

Detab Text: 
```

#### 4. Simple Input Text

```console
$ ./detab

Enter the tab width size (0 - 9): 4

Enter Text: hello,      world

Detab Text: hello,  world
```

#### 5. Digit Input Text

```console
$ ./detab

Enter the tab width size (0 - 9): 4

Enter Text: 123 456     789      

Detab Text: 123 456 789
```

#### 6. Consecutive Tabs Input Text

```console
$ ./detab

Enter the tab width size (0 - 9): 4

Enter Text: hello,              world           !

Detab Text: hello,      world       !
```

#### 7. Input Text starting / ending with Tab

```console
$ ./detab

Enter the tab width size (0 - 9): 4

Enter Text:     hello, world

Detab Text:     hello, world    
```

---