
# Chapter 1: A Tutorial Introduction

## Table of Contents

- [Getting Started](#getting-started)
    - [`hello, world` program](#hello-world-program)
    - [`main`](#main)
    - [`#include <stdio.h>`](#include-stdioh)
    - [Arguments](#arguments)
    - [`printf`](#printf)
    - [Escape Sequences](#escape-sequences)
- [Variables and Arithmetic Expressions](#variables-and-arithmetic-expressions)

## Getting Started

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

    - Compile the C program. The command of GNU C compiler is

    ```console
    $ gcc hello.c
    ```

    - Compiling the program creates an executable file named `a`. To run on windows, type the command `./a` in terminal in the same path.

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

## Variables and Arithmetic Expressions 