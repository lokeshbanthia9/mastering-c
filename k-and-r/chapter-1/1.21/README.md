
# Exercise 1.12: Entab

## Problem Statement

> Write a program `entab` that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for `detab`. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

## Approach

1. Take the user input for tab-width size.

2. Define input and output strings (arrays) with size set to `MAXLINE` buffer.

3. Read a line of text and store in the `input` string.

4. In the `entab` function, initialise index counters for both `input` and `output` strings to `0`.

5. Run a `while` loop till the output char matches `\0`. In each iteration,

    - If the input char is not blank space, copy the char to output string and move to the next iteration.

    - If the input char is blank space, calculate the number of tabs required based on the number of trailing blanks. Store the tabs and remaining blanks in the output string.

6. At the end of the loop, add `\0` in the output string.

7. Print the output string.

## Code Explanation

- `clear_input` reads all the characters until `EOF` or new-line (`\n`) is passed. It is used to clear the terminal for the next input or output operation.

- `get_line` reads the input characters until,

    - `EOF` is passed at the start of the line.

    - new-line (`\n`) is entered.

    - `MAXLINE` character limit is reached.

- In the `entab` function,

    - `i` is the input string counter.

    - `j` is the output string counter.

    - `space_count` is the number of trailing blank spaces.

    - `start_pos` is the current position in the output string, used to calculate the next tab stop.

    - `spaces_to_first_tab_stop` is the number of spaces needed to reach the first tab stop from the current position of the cursor.

    - `tabs_needed` is the number of tabs that can be substituted in places of the blanks, to be added in the output string.

    - `spaces_needed` is the number of blanks that will be added in the output string at the end of tabs to complete the initial space count.

- In the `entab` function, whenever a blank is encountered in the `input` string, the `start_pos` is calculated based on the `output` string index counter and a pre-defined int `pre-output-chars`, which represents the number of characters in the output line being printed before the `output` string. Doing this allows the output to match the input line visually in the terminal with the correct tab stops.

See `entab.c` for the full program.

## Edge Cases

- No input characters

    - Prints the appropriate message.

    - Ends the program with exit status `1`.

- Input characters execeeding `MAXLINE` limit

    - Characters till the `MAXLINE` limit is stored in the input array.

    - Any character afterwards is not stored silently.

## Output

To make the tabs and blanks visible in the output string, I replaced each tab with the letter `t` and blank with the letter `b`. I provide both outputs, one with actuals tabs and blanks, and one with `t` and `b` letters.

- ### Input 1

```console
$ ./entab

Enter the tab width size (0 - 9): 8

Enter Text: hello,                      world

Entab Text: hello,tttworld
```

```console
$ ./entab

Enter the tab width size (0 - 9): 8

Enter Text: hello,                      world

Entab Text: hello,                      world
```

- ### Input 2

```console
$ ./entab

Enter the tab width size (0 - 9): 8

Enter Text: The     quick  brown      fox     jumps      over    the lazy dog

Entab Text: Thetbbbbquickbbbrownbbbbbbfoxbbbbbjumpstboverbbbbtheblazybdog
```

```console
$ ./entab

Enter the tab width size (0 - 9): 8

Enter Text: The     quick  brown      fox     jumps      over    the lazy dog

Entab Text: The     quick  brown      fox     jumps      over    the lazy dog
```

## When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

A tab should be given preference over a single blank space even when a single blank would be enough to reach the tab stop, to be consistent acorss different editors and tab width settings. The number of blanks required to reach the next tab stop may change for different configuration.

## Learnings

- Understanding tabs and tab stops.

---