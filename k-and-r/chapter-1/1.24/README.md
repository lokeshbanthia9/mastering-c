
# Exercise 1.24: Check for Rudimentary Syntax Errors

## Problem Statement

> Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality)

## Approach

- Define `int` counters for each error type to be checked.

- Run a `while` loop to read character one by one till it reaches end-of-file (`EOF`). In each iteration,

    - If the character is parenthesis (`()`), brace (`{}`) or bracket (`[]`), update its respective counter.

    - If the character is single (`'`) or double (`"`) quotes, skip all succeeding characters till the same quote type is read again. If a backslash (`\`) is encountered, check for valid escape sequence in the following character.

    - If the current and previous character are forward slash (`/`), skip all succeeding characters till a new-line (`\n`) is encountered. (single line comment)

    - If the current characters is asterisk (`*`), and the previous character was forward slash (`/`), skip all succeeding characters till an asterisk (`*`), followed by a forward slash (`/`) is encountered. (multi-line comment)

    - If end-of-file (`EOF`) is reached in any of string / character literal, or single line / multi-line comment, `break` the loop.

    - Update the previous character to the current character.

- Check all the counters for any error encountered, print each error simultaneously, and count the total number of errors.

- If the total number of errors is `0`, print an appropriate message.

## Output

All input files are in `tests` directory.

### 1. No Input

Empty input (see `tests/no-input.c`)

```console
$ ./checker < tests/no-input.c

Errors Summary
-----------------
No errors found!
```

### 2. Hello, World Program

(see `tests/hello-world.c` for input)

```console
$ ./checker < tests/hello-world.c

Errors Summary   
-----------------
No errors found!
```

### 3. Same Program

(see `tests/checker-copy.c` for input)

```console
$ ./checker < tests/checker-copy.c

Errors Summary   
-----------------
No errors found!
```

### 4. Unclosed Quotes

(see `tests/unclosed-quotes.c` for input)

```console
$ ./checker < tests/unclosed-quotes.c

Errors Summary   
-----------------
1 unclosed braces.
Unclosed double quotes.
Total Errors Found: 2.
```

### 5. Invalid Escape Sequence

(see `tests/invalid-escape-sequence.c` for input)

```console
$ ./checker < tests/invalid-escape-sequence.c

Errors Summary
-----------------
1 invalid escape sequences inside single quotes.
1 invalid escape sequences inside double quotes.
Total Errors Found: 2.
```

### 6. Comment-like Syntax in String

(see `tests/comment-in-quotes.c` for input)

```console
$ ./checker < tests/comment-in-quotes.c

Errors Summary
-----------------
No errors found!
```

### 7. Unclosed Multi-Line Comment

(see `tests/unclosed-comment.c` for input)

```console
$ ./checker < tests/unclosed-comment.c

Errors Summary
-----------------
1 unclosed braces.
Unclosed multiline comment.
Total Errors Found: 2.
```

### 8. Extra Closing Brace

(see `tests/extra-brace.c` for input)

```console
$ ./checker < tests/extra-brace.c

Errors Summary
-----------------
1 unopened braces.
Total Errors Found: 1.
```

### 9. Complex Syntax

(see `tests/complex-syntax.c` for input)

```console
$ ./checker < tests/complex-syntax.c

Errors Summary
-----------------
No errors found!
```

## Learnings

- Edge cases for parenthesis, brace, bracket, single quote, double quote, escape sequence, single line comment, and multi-line comment, where they might not work as intended.

---