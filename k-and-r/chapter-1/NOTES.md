
# Chapter 1: A Tutorial Introduction

## Table of Contents

1. [Getting Started](#11-getting-started)

    - [`hello, world` program](#hello-world-program)

    - [Compilation & Execution](#compilation--execution)

    - [`main`](#main)

    - [`#include <stdio.h>`](#include-stdioh)

    - [Arguments](#arguments)

    - [`printf`](#printf)

    - [Escape Sequences](#escape-sequences)

2. [Variables and Arithmetic Expressions](#12-variables-and-arithmetic-expressions)

    - [Fahrenheit-Celsius Table](#fahrenheit-celsius-table)

    - [Comments](#comments)

    - [Variables](#variables)

    - [`while` Loop](#while-loop)

    - [Arithmetic Expression: Integer](#arithmetic-expression-integer)

    - [Formatted Output: Integer](#formatted-output-integer)

    - [Arithmetic Expression: Floating Point](#arithmetic-expression-floating-point)

    - [Formatted Output: Floating Point](#formatted-output-floating-point)

    - [Formatted Output: Width, Precision and More](#formatted-output-width-precision-and-more)

3. [The `for` Statement](#13-the-for-statement)

    - [Revised Fahrenheit-Celsius Table](#revised-fahrenheit-celsius-table)

    - [The `for` Loop](#the-for-loop)

    - [`while` or `for`](#while-or-for)

4. [Symbolic Constants](#14-symbolic-constants)

    - [Magic Numbers](#magic-numbers)

    - [`#define`](#define)

5. [Character Input and Output](#15-character-input-and-output)

    - [Input / Output Model](#input--output-model)

    - [File Copying](#file-copying)

    - [Character Counting](#character-counting)

    - [Line Counting](#line-counting)

    - [Word Counting](#word-counting)

6. [Arrays](#16-arrays)

    - [Array Definition](#array-definition)

    - [Specfic Character Count](#specfic-character-count)

## 1.1 Getting Started

- ### `hello, world` program

    - Code
        
    ```c
    #include <stdio.h>

    main()
    {
        printf("hello, world\n");
    }
    ```

- ### Compilation & Execution

    - Save the C program in a file, whose name ends with `.c`, such as `hello.c`.

    - Compile the C program. The command for GNU C compiler is

    ```console
    $ gcc hello.c
    ```

    - Compiling the program creates an executable file named `a.out` (Linux/MacOS) or `a.exe` (Windows). To run the program on windows, type the command `./a` in the same path in terminal.

    ```console
    $ ./a
    hello, world
    ```

- ### `main`

    - A C program, whatever its size, consists of *functions* or *variables*.

    - A function contains statements that specify the computing operations to be done and the values to be stored.

    - `hello, world` program contains the function `main`.

    - Normally we can name our function anything, but the `main` function is special, the program execution starts from the `main` function. Hence, each program must have a `main` function.

- ### `#include <stdio.h>`

    - Tells the compiler to include information about the standard input/output library (`stdio`).

    - No semicolon at the end of `#include` statement.

- ### Arguments

    - Used to communicate data between functions.

    - The parentheses after the function name surround the argument list.

    - `main()` is defined as a function expecting no arguments, as indicated by the empty list.

- ### `printf`

    - A function is called by naming it, followed by a parenthesized list of arguments.

    - `printf` function (included in `stdio`) is called with the argument `"hello, world\n"`.

    - `"hello, world\n"` indicates a string literal or string constant, which is a sequence of characters between double quotes.

    - `\n` in the string literal is the C notation for the newline character, which advances the output cursor to the left margin on the next line.

- ### Escape Sequences

    - `\n` represents a single characters in C, despite containing two separate characters.
    
    - Literals that contain backslash (`\`) followed by some character, are known as escape sequences.
    
    - These have special meaning in character or string constants, and provide a general and extensible way for representing hard-to-type or invisible characters.
    
    - Among others include `\t` for tab, `\b` for backspace, `\"` for double quotes, `\\` for backslash itself, etc.

    - Not all characters after backslash (`\`) are valid escape sequences. Example - `\c` is not a valid escape sequence. The compiler will warn in such a case.

## 1.2 Variables and Arithmetic Expressions 

- ### Fahrenheit-Celsius Table

    - Code

    ```c
    #include <stdio.h>

    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
    main()
    {
        int fahr, celsius;
        int lower, upper, step;

        lower = 0; /* lower limit of temperature scale */
        upper = 300; /* upper limit */
        step = 20; /* step size */

        fahr = lower;
        while (fahr <= upper)
        {
            celsius = 5 * (fahr-32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr = fahr + step;
        }
    }
    ```

    - This program introduces several new ideas, including comments, declarations, variables, arithmetic expressions, loops, and formatted output.

- ### Comments

    - The two lines,

    ```c
    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
    ```

    are a comment, which in this cases explains what the program does.
    
    - Any character between `/*` and `*/` are ignored by the compiler, and may be used freely for code explanation or to prevent execution of a section of code.

    - Comments can appear anywhere a blank, tab or newline can.

- ### Variables

    - In C, all variables must be declared before they are used.

    - A declaration announces the properties of a variable; it consists of the variable data type and its name.

    ```c
    int fahr, celsius;
    int lower, upper, step;
    ```

    - `int` is a data type for integer values. There are multiple data types in C,

    | Data Type | Description |
    | :-------- | :---------- |
    | `char`    | character - a single byte |
    | `short`   | short integer |
    | `int`     | integer |
    | `long`    | long integer |
    | `float`   | floating point (numbers with fractional part) |
    | `double`  | double-precision floating point |

    - The size and range of these data types are machine-dependent.

    - There are also *arrays*, *structures*, and *unions* of these basic types, *pointers* to them, and *functions* that return them.

    - Assignment statements set the variables to their initial values.

    ```c
    lower = 0;
    upper = 300;
    step = 20;
    ```

- ### `while` Loop

    - Since each line of the Fahrenheit-Celsius table is computed and printed in the same way, we can use a loop to repeat statements.

    ```c
    while (fahr <= upper)
    ```

    - The `while` loop operates as follows:

        - The condition in the paretheses is tested.

        - If it is true (`fahr` is less than or equal to `upper`), the body of the loop (the statements enclosed in the curly braces below) is executed. After executing all the statements in the body, the condition is retested.

        - If it becomes false (`fahr` becomes greater than `upper`), the loop ends and the execution continues at the statement that follows the loop.

    - The body of the loop can be one ore more statements, enclosed in braces.

    ```c
    {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    ```

- ### Arithmetic Expression: Integer

    - The Celsius temperature is computed and assigned to the `celsius` variable by the statement,

    ```c
    celsius = 5 * (fahr-32) / 9;
    ```

    - The reason for multiplying by `5` first and then dividing by `9` (instead of directly multipying by `5/9`) is that in C, integer division truncates, any fraction part is discarded. Since `5` and `9` are integers, `5/9` would be truncated to `0`, resulting in all `celsius` values to be `0`.

- ### Formatted Output: Integer

    - `printf` is a general purpose output formatting function. Its first argument is a string of characters to be printed, with each `%` indicating where one argument (inside `printf` paratheses) is to be substituted, and in what form is to be printed.

    - For instance, `%d` specifies an integer argument. The statement,

    ```c
    printf("%d\t%d\n", fahr, celsius);
    ```

    causes the two integer values `fahr` and `celsius` to be printed in place of `%d` in the same order they appear inside parantheses.

    - Each `%` inside `printf` string must be paired and with the correct data type, to avoid errors.

    - Another formatted alternative, to make the output visually appealing, would be,

    ```c
    printf("%3d %6d\n", fahr, celsius); 
    ```

    This prints the first integer with a minimum width of 3 digits, and the second integer with a minimum width of 6 digits.

- ### Arithmetic Expression: Floating Point

    - Since we are using integer arithmetic in this statement,

    ```c
    celsius = 5 * (fahr-32) / 9;
    ```

    the result will not be very accurate; for instance, 0^o^F is about -17.8^o^C, but this results in -17^o^C.
    
    - To get more accurate answers, we can use floating point arithemetic. We need to change the variable data types of a floating point type instead of integer type.

    ```c
    float fahr, celsius;
    float lower, upper, step;
    ```

    - The fahrenheit-to-celsius formula can be written in a much more natural way this time,

    ```c
    celsius = (5.0/9.0) * (fahr-32.0);
    ```

    A decimal point in `5.0` and `9.0` indicates that it is floating point, so the division would not be truncated to 0, as was the case for integer division.

    - If an arithmetic expression has two integer operands, an integer operation is performed. However, if the expression has one floating point operand and one integer operand, the integer will be converted to a floating point, and a floating point operation is performed.

- ### Formatted Output: Floating Point

    - To print floating point values instead of integer values, we can use `%f` specification.

    ```c
    printf("%3.0f %6.1f\n", fahr, celsius);
    ```

    - `%3.0f` indicates that a floating point value is to be printed, being at least three characters wide, and with no fraction / decimal digits. `%6.1f` describes another floating poinnt number is to be printed, being at least 6 characters wide, and with 1 digit after decimal point.

- ### Formatted Output: Width, Precision and More

    - `%6f` says that the floating-point number printed must be at least 6 characters wide. `.2f` says that the floating-point number printed must contain two characters after decimal point, but the width is not constrained. `%f` just says to print the floating-point number with no constrain on width or precision.

    - We can create different format specifications by changing the width and precision parameters.

    | Specifier | Description |
    | :-------- | :---------- |
    | `%d`      | print as integer |
    | `%6d`     | print as integer, at least 6 characters wide |
    | `%f`      | print as floating point |
    | `%6f`     | print as floating point, at least 6 characters wide |
    | `%.2f`    | print as floating point, 2 characters after decimal point |
    | `%6.2f`   | print as floating point, at least 6 characters wide and 2 characters after decimal point |

    - Among other format specifications include,

    | Specifier | Used For |
    | :-------- | :---------- |
    | `%o`      | octal (base-8) integer |
    | `%x`      | hexadecimal (base-16) integer |
    | `%c`      | single character |
    | `%s`      | character string |
    | `%%`      | `%` itself |

## 1.3 The `for` Statement

- ### Revised Fahrenheit-Celsius Table

    - Instead of using `while` loop in the fahrenehit-to-celsius program, we can use the `for` loop.

    ```c
    #include <stdio.h>

    /* print Fahrenheit-Celsius table */
    main()
    {
        int fahr;

        for (fahr = 0; fahr <= 300; fahr = fahr + 20)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    ```

    - Apart from changing `while` to `for`, another major change is the elimination of most of the variables.

        - The `lower` and `upper` limits, and the `step` size are being used directly as constants in the `for` statement.

        - The expression that computes Celsius value is now being used as the third argument of `printf` instead of assigning a separate variable.

- ### The `for` Loop

    - The `for` statement is a loop, a generalization of the `while`. Within the parantheses, there are three parts, separated by semicolons.

        - Initialization

        ```c
        fahr = 0
        ```

        It is done once, before the loop is entered. 

        - Condition

        ```c
        fahr <= 300
        ```

        If the condition is true, the body of the loop is executed. Otherwise, the loop ends.

        - Increment

        ```c
        fahr = fahr + 20
        ```

        After executing the loop body, the increment step is executed, and the condition is re-evaluated.

    - As with the `while` loop, the body of a `for` loop can be a single statement, or multiple statements enclosed in braces.

- ### `while` or `for`

    - The choice between using `while` and `for` loop is arbitary, based on which seems clearer.

    - The `for` is usally appropriate for loops in which initialization and increment are single statements and logically related, since it is more compact that `while` and keep the loop control statements in one place.

## 1.4 Symbolic Constants

- ### Magic Numbers

    - Its bad practice to bury constants or *magic numbers* in a program; they convey little information to someone who will read the program later, and are hard to change in a systematic way later on.

    - For instance, in the fahrenheit-to-celsius program, the values `300` and `20` are considered magic numbers.

    - One way to deal with magic numbers is to give them meaningful names.

- ### `#define`

    - A `#define` line defines a *symbolic name* or *symbolic constant* to be a particular string of characters.

    `#define` *name* *replacement_list*

    - Thereafter, any occurrence of *name* (not in quotes) will be replaced by the corresponding *replacement_text*.

    - The *replacement_text* cab be any sequence of characters; not limited to just numbers.

    - In the fahrenehit-to-celsius program,

    ```c
    #define LOWER 0 /* lower limit of table */
    #define UPPER 300 /* upper limit */
    #define STEP 20 /* step size */ 
    ```

    The quantities `LOWER`, `UPPER` and `STEP` are symbolic constants, not variables, they do not appear in declarations.

    - Symbolic constants names has the same form as variables: a sequence of letters and digits that begins with a letter. Symbolic constants name are conventionally written in upper case to easily distinguish them from variables.

    - No semicolon at the end of `#define` statement.

## 1.5 Character Input and Output

- ### Input / Output Model

    - The model of I/O supported by standard library is very simple. Text input or output, regardless of where it originates or where it goes, is handled as streams of characters.

    - A *text stream* is a sequence of characters divided into lines. Each line consists of zero or more characters, followed by a newline (`\n`) character.

    - The simplest input and output functions provided by the standard library are `getchar` and `putchar` respectively.

        - `getchar` reads the *next input character* from the input text stream and return that as its value.

        ```c
        c = getchar();
        ```

        - `putchar` prints the character content of the integer passed as the argument to the function.

        ```c
        putchar(c);
        ```

- ### File Copying

    - Program to copy its input to its output one character at a time.

    ```c
    #include <stdio.h>

    /* copy input to output; 1st version */
    main()
    {
        int c;

        c = getchar();
        while (c != EOF)
        {
            putchar(c);
            c = getchar();
        }
    } 
    ```

    - The relational operator `!=` means *not equal to*.

    - The type `char` is meant to store single character data, but any integer type can be used alternatively.

    - `EOF`

        - This program uses `int` instead of `char` primarily because `getchar` return a distinctive value when there is no more input, a value that is different from any real character, called `EOF`, for end-of-file.

        - The variable storing `getchar` values must be big enough to hold any value that `getchar` returns.

        - `EOF` is an integer defined in `stdio` library. The specific numeric value of `EOF` is not defined in the language itself, and its implementation is left to the library, however it will not be equal to any of the values that can be stored in `char`. Hence, we use `int` in the copy program.

    - A concise way of writing the same program is to include `getchar` function in the loop condition.

    ```c
    while ((c = getchar()) != EOF)
        putchar(c); 
    ```

    This version centralizes the input, now there is only version of `getchar`. The parentheses around the assignment is necessary, because the *precedence* of `!=` is higher than of `=`, which means in the absence of parentheses, the relation test would be done first and then the assignment.

- ### Character Counting

    - Program to count the number of characters in the input text stream.

    ```c
    #include <stdio.h>
    /* count characters in input; 1st version */
    main()
    {
        long nc;

        nc = 0;
        while (getchar() != EOF)
            ++nc;
        
        printf("%ld\n", nc);
    } 
    ```

    - The expression `++nc` presents a new operator `++` which increments the value store by one. Its equivalent to `nc = nc + 1` but more concise and often more efficient. Similiarly, there is an operator `--` for decrement by one. These operators can be either prefix (`++nc`) or postfix (`nc++`).

    - The variable `nc` is defined as the `long` type instead of `int` to prevent overflow on relatively small text stream. `%ld` is the format specifier for `long` type variables, being used in the `printf` string literal.

    - An alternative approach would be to use `double` type instead of `long` to store the character count (to allow for even bigger text streams), and to use `for` loop instead of `while` to keep all the loop control statements together and the program concise.

    ```c
    #include <stdio.h>

    /* count characters in input; 2nd version */
    main()
    {
        double nc;

        for (nc = 0; gechar() != EOF; ++nc);

        printf("%.0f\n", nc);
    } 
    ``` 

    `%.0f` is used to represent floating point numbers (`float` and `double`), printed with no fractional part.

    - The body of this `for` loop is empty because all the work is being done in the test and increment parts in the `for` statement. The semicolon after `for` statement is used to indicate the empty body of the loop (also called a *null statement*).

    - Even if the text stream input is empty, and the loop condition fails in the first test itself, the program still prints the correct result, which will be `0`.

- ### Line Counting

    - Program to count the number of lines in the input text stream.

    ```c
    #include <stdio.h>

    /* count lines in input */
    main()
    {
        int c, nl;

        nl = 0;
        while ((c = getchar()) != EOF)
            if (c == '\n')
                ++nl;

        printf("%d\n", nl);
    }
    ```

    - The double equal sign (`==`) is the C notation to check for *equality*. Double equal sign is used to distinguish from the equal sign used for assignment.

    - A character between single quotes (for instance: `'a'`) represents an integer value equal to the numerical value of the character in the machine's character set. It is also known as *character constant*, although its just another way to write small integer. If we want to use a particular character, we should prefer using the character constant instead of its numerical value, one because it improves readability, and secondly because its independent of the character set used.

    - Escape sequences used in string constants is also a legal character constant. For instance, `\n` stands for newline character, which has the numerical value `10` in ASCII character set.

- ### Word Counting

    - Program to count lines, words and characters. (a word has been assumed to be any sequence of characters not containing blank, tab or newline)

    ```c
    #include <stdio.h>

    #define IN 1 /* inside a word */
    #define OUT 0 /* outside a word */

    /* count lines, words, and characters in input */
    main()
    {
        int c, nl, nw, nc, state;

        state = OUT;
        nl = nw = nc = 0;

        while ((c = getchar()) != EOF)
        {
            ++nc;

            if (c == '\n')
                ++nl;
            if (c == ' ' || c == '\n' || c = '\t')
                state = OUT;
            else if (state == OUT)
            {
                state = IN;
                ++nw;
            }
        }

        printf("%d %d %d\n", nl, nw, nc);
    }
    ```

    Every time the program encounters the first characters of a word, it increases the word counter by one. The variable `STATE`  records whether the program is currently in a word or not. Symbolic constants `IN` and `OUT` are used to increase readability.

    - The assignment line sets all three variables to `0`.

    ```c
    nl = nw = nc = 0;
    ```

    Assignment expression are executed from right to left, which makes this statement similiar to,

    ```c
    nl = (nw = (nc = 0));
    ```

    - The operator `||` means *OR*, used to represent the logical OR in relational expressions.

    ```c
    if (c == ' ' || c == '\n' || c = '\t') 
    ```

    This statement will return true if any of the condition separated by OR satisfies. 

    - There is a corresponding operator `&&` for AND, whose precedence is higher than `||`.

    - Expressions connected by `&&` or `||` are evaluated left to right, and it is guaranteed that evaluation will stop as soon as the truth or falsehood of the expression is known. For instance, in this `if` statement, if `c` is a blank, there is no need to test whether it is a newline or a tab since the result of the expression willbe true regardless.

    - `else` specifies an alternative action if the condition of `if` statement is false. The general form is,

    ```
    if (expression)
        statement_1;
    else
        statement_2;
    ```

    If *expression* is true, *statement_1* is executed, otherwise *statement_2* is executed. Each *statement* can be a single statement or several in braces.

## 1.6 Arrays

- ### Array Definition

    - An array is a data structure that stores a fixed-size, sequential collection of elements of the same data type.
    
    - It provides a way to group multiple values under the same variable name, allowing them to be accessed and manipulated easily and efficiently using index.

- ### Specfic Character Count

    - Program to count the number of occurences of each digit, white space characters (blank, tab or newline), and all other characters.

    ```c
    #include <stdio.h>

    /* count digits, white space, others */
    main()
    {
        int c, i, nwhite, nother;
        int ndigit[10];

        nwhite = nother = 0;

        for (i = 0; i < 10; ++i)
            ndigit[i] = 0;

        while ((c = getchar()) != EOF)
            if (c >= '0' && c <= '9')
                ++ndigit[c-'0'];
            else if (c == ' ' || c == '\n' || c == '\t')
                ++nwhite;
            else
                ++nother;
        
        printf("digits =");

        for (i = 0; i < 10; ++i)
            printf(" %d", ndigit[i]);

        printf(", white space = %d, other = %d\n",nwhite, nother);
    } 
    ```

    - The declaration `int ndigit[10]` declares `ndigit` to be an array of `10` integers. Array subscripts or indexes always start from `0` in C. The subscript or index can be an integer expression.
    
    - By definition, chars are just small integers, so `char` variables and constants are identical to `int` in arithmetic expression. For instance, `c - '0'` is an integer expression.

    - The `if-elseif-else` pattern occurs frequently in programs as a way to express a multi-way decision. 

    ```
    if (condition_1)
        statement_1
    else if (condition_2)
        statement_2
    ...
        ...
    else
        statement_n
    ```

    The conditions are evaluated in order from the top until some *condition* is satisfied, at that point the corresponding *statement* is executed, and the entire construction is finised. If none of the condition satisfies, the *statement* after the final *else* is executed if present. There can be any number of `else if` conditions between the initial `if` and the final `else`.

    - The `switch` statement provides another way to write a multi-way branch that is particularly suitable when the condition is some integer or character expression matching one of a set of constants.