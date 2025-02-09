
# Exercise 1.23: Remove Comments from a C Program

## Problem Statement

> Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.

## Comments in C

Comments are certain text lines in C which are ignored during the program's compilation, they are commonly used for explaining the program or a specific section of code, or to prevent execution of a section of code.

There are 2 types of comments in C:

- Single Line Comment: Starts with two forward slashes (`//`), ends with new-line (`\n`).

- Multi Line Comment: Starts with a forward slash and an asterisk (`/*`), ends with an asterisk and a forward slash (`*/`).

## Approach

- Run a `while` loop to read each character in input till `EOF` is encountered.

- In each iteration,

    - If the current character is single quote (`'`) and it is not escaped (preceded by a backslash), toggle `open_single_quote`.

    - If the current character is double quote (`"`) and it is not escaped (preceded by a backslash), toggle `open_double_quote`.

    - If the current character is forward slash (`/`) and both quotes are closed, read the next character,

        - If the next character is also forward slash (`/`), discard all characters till new-line (`\n`) is encountered (single line comment).

        - If the next character is asterisk (`*`), discard all characters till asterisk (`*`) and forward slash (`/`) occur together (multi line comment).

        - Otherwise, print both forward slash (`/`) and the next character.

    - Otherwise (current character not forward slash (`/`) and not in quotes), print the character.

(see `uncomment.c` for full code)

## Output

All input and output results are stored in `tests` directory

### 1. No Input

```console
$ ./uncomment < tests/no-input/input.c > tests/no-input/output.c
```

Empty input and output. (see `tests/no-input`)

### 2. Simple Comments

```console
$ ./uncomment < tests/simple-comments/input.c > tests/simple-comments/output.c
```

(see `tests/simple-comments`)

### 3. Complex Comments

```console
$ ./uncomment < tests/complex-comments/input.c > tests/complex-comments/output.c
```

(see `tests/complex-comments`)

### 4. Comment-like Syntax in Quotes

```console
$ ./uncomment < tests/in-quotes/input.c > tests/in-quotes/output.c
```

(see `tests/in-quotes`)

## Learning

- How comments are processed in C

---