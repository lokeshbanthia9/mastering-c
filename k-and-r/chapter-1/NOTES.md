
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

- - ### `while` or `for`

    - The choice between using `while` and `for` loop is arbitary, based on which seems clearer.

    - The `for` is usally appropriate for loops in which initialization and increment are single statements and logically related, since it is more compact that `while` and keep the loop control statements in one place.