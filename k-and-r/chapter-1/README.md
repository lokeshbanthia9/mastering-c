
# Chapter 1: A Tutorial Introduction

This chapter introduces the essential elements of the C language: variables and constants, arithmetic, control flow, functions, and the rudiments of input and output.

### [Chapter 1 Notes](/k-and-r/chapter-1/NOTES.md)

### Exercises and Solutions:

1. [Run the `hello, world` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.](/k-and-r/chapter-1/1.01/README.md)

2. [Experiment to find out what happens when prints's argument string contains \c, where c is some character not listed above.](/k-and-r/chapter-1/1.02/README.md)

3. [Modify the temperature conversion program to print a heading above the table.](/k-and-r/chapter-1/1.03/README.md)

4. [Write a program to print the corresponding Celsius to Fahrenheit table.](/k-and-r/chapter-1/1.04/README.md)

5. [Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.](/k-and-r/chapter-1/1.05/README.md)

6. [Verify that the expression getchar() != EOF is 0 or 1.](/k-and-r/chapter-1/1.06/README.md)

7. [Write a program to print the value of EOF.](/k-and-r/chapter-1/1.07/README.md)

8. [Write a program to count blanks, tabs, and newlines.](/k-and-r/chapter-1/1.08/README.md)

9. [Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.](/k-and-r/chapter-1/1.09/README.md)

10. [Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.](/k-and-r/chapter-1/1.10/README.md)

11. [How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?](/k-and-r/chapter-1/1.11/README.md)

12. [Write a program that prints its input one word per line.](/k-and-r/chapter-1/1.12/README.md)

13. [Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.](/k-and-r/chapter-1/1.13/README.md)

14. [Write a program to print a histogram of the frequencies of different characters in its input.](/k-and-r/chapter-1/1.14/README.md)

15. [Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.](/k-and-r/chapter-1/1.15/README.md)

16. [Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.](/k-and-r/chapter-1/1.16/README.md)

17. [Write a program to print all input lines that are longer than 80 characters.](/k-and-r/chapter-1/1.17/README.md)

18. [Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.](/k-and-r/chapter-1/1.18/README.md)

19. [Write a function `reverse(s)` that reverses the character string s. Use it to write a program that reverses its input a line at a time.](/k-and-r/chapter-1/1.19/README.md)

20. [Write a program `detab` that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?](/k-and-r/chapter-1/1.20/README.md)

21. [Write a program `entab` that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?](/k-and-r/chapter-1/1.21/README.md)

22. [Write a program to `fold` long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.](/k-and-r/chapter-1/1.22/README.md)

23. [Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.](/k-and-r/chapter-1/1.23/README.md)

24. [Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)](/k-and-r/chapter-1/1.24/README.md)