/**
 * Program to remove all comments from a C program. 
 * 
 * Exercise 1.23 
 */

#include <stdio.h>

void skip_single_line_comment(void);
void skip_multi_line_comment(void);

int main(void)
{
    int prev = '\0';
    int curr;

    int open_single_quote = 0;
    int open_double_quote = 0;

    while ((curr = getchar()) != EOF)
    {
        if (curr == '\'' && prev != '\\')
        {
            open_single_quote = !open_single_quote;
        }
        else if (curr == '\"' && prev != '\\')
        {
            open_double_quote = !open_double_quote;
        }

        if (curr == '/' && !open_single_quote && !open_double_quote)
        {
            int next = getchar();
            
            if (next == '/')
            {
                skip_single_line_comment();
            }
            else if (next == '*')
            {
                skip_multi_line_comment();
            }
            else
            {
                putchar(curr);
                putchar(next);
            }
        }
        else
        {
            putchar(curr);
        }

        prev = curr;
    }

    return 0;
}

void skip_single_line_comment(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            return;
        }
    }
}

void skip_multi_line_comment(void)
{
    int prev = '\0';
    int curr;

    while ((curr = getchar()) != EOF)
    {
        if (prev == '*' && curr == '/')
        {
            return;
        }

        prev = curr;
    }
}