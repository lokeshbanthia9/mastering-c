/**
 * Program to check a C program for rundiementary syntax errors. 
 * 
 * Exercise 1.24 
 */

#include <stdio.h>

int skip_quotes(char quote);
int skip_single_line_comment(void);
int skip_multi_line_comment(void);

int main(void)
{
    int unclosed_parantheses = 0;
    int unclosed_braces = 0;
    int unclosed_brackets = 0;

    int single_quote_errors = 0;
    int double_quote_errors = 0;

    int comment_errors = 0;
    int eof_reached = 0;

    int curr = '\0';
    int prev = '\0';

    int result = 0;

    while ((curr = getchar()) != EOF)
    {
        switch (curr)
        {
            case '(':
                unclosed_parantheses++;
                break;

            case ')':
                unclosed_parantheses--;
                break;

            case '{':
                unclosed_braces++;
                break;

            case '}':
                unclosed_braces--;
                break;

            case '[':
                unclosed_brackets++;
                break;

            case ']':
                unclosed_brackets--;
                break;

            case '\'':
                result = skip_quotes('\'');
                if (result == -1)
                {
                    eof_reached = 1;
                }
                else
                {
                    single_quote_errors += result;
                }
                break;

            case '\"':
                result = skip_quotes('\"');
                if (result == -1)
                {
                    eof_reached = 1;
                }
                else
                {
                    double_quote_errors += result;
                }
                break;

            case '/':
                if (prev == '/')
                {
                    result = skip_single_line_comment();
                    if (result == -1)
                    {
                        eof_reached = 1;
                    }
                    else
                    {
                        comment_errors += result;
                    }
                }
                break;

            case '*':
                if (prev == '/')
                {
                    result = skip_multi_line_comment();
                    if (result == -1)
                    {
                        eof_reached = 1;
                    }
                    else
                    {
                        comment_errors += result;
                    }
                }
                break;
        }

        if (eof_reached)
        {
            break;
        }

        prev = curr;
    }

    printf("\nErrors Summary\n-----------------\n");
    int errors_found = 0;
    
    if (unclosed_parantheses > 0)
    {
        printf("%d unclosed parantheses.\n", unclosed_parantheses);
        errors_found += unclosed_parantheses;
    }
    else if (unclosed_parantheses < 0)
    {
        int errors = -1 * unclosed_parantheses;
        printf("%d unopened parantheses.\n", errors);
        errors_found += errors;
    }

    if (unclosed_braces > 0)
    {
        printf("%d unclosed braces.\n", unclosed_braces);
        errors_found += unclosed_braces;
    }
    else if(unclosed_braces < 0)
    {
        int errors = -1 * unclosed_braces;
        printf("%d unopened braces.\n", errors);
        errors_found += errors;
    }

    if (unclosed_brackets > 0)
    {
        printf("%d unclosed brackets.\n", unclosed_brackets);
        errors_found += unclosed_brackets;
    }
    else if (unclosed_brackets < 0)
    {
        int errors = -1 * unclosed_brackets;
        printf("%d unopened brackets.\n", errors);
        errors_found += errors;
    }

    if (single_quote_errors)
    {
        printf("%d invalid escape sequences inside single quotes.\n", single_quote_errors);
        errors_found += single_quote_errors;
    }

    if (double_quote_errors)
    {
        printf("%d invalid escape sequences inside double quotes.\n", double_quote_errors);
        errors_found += double_quote_errors;
    }
    
    if (comment_errors)
    {
        printf("%d errors insided comments.\n", comment_errors);
        errors_found += comment_errors;
    }

    if (eof_reached)
    {
        if (curr == '\'')
        {
            printf("Unclosed single quotes.\n");
            errors_found++;
        }
        else if (curr == '\"')
        {
            printf("Unclosed double quotes.\n");
            errors_found++;
        }
        else if (prev == '/' && curr == '*')
        {
            printf("Unclosed multiline comment.\n");
            errors_found++;
        }
    }

    if (errors_found)
    {
        printf("Total Errors Found: %d.\n", errors_found);
        return 1;
    }
    else
    {
        printf("No errors found!\n");
        return 0;
    }
}

int validate_escape_sequence(char c)
{
    char valid_escape_sequences[] = {'a', 'b', 'f', 'n', 'r', 't', 'v', '\\', '\'', '\"', '?', '0'};
    int valid_escape_sequences_count = 12;

    for (int i = 0; i < valid_escape_sequences_count; i++)
    {
        if (c == valid_escape_sequences[i])
        {
            return 0;
        }
    }

    return 1;
}

int skip_quotes(char quote)
{
    int c;
    int errors = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == quote)
        {
            return errors;
        }
        else if (c == '\\')
        {
            int next = getchar();

            if (next == EOF)
            {
                break;
            }

            errors += validate_escape_sequence(next);
        }
    }

    return -1;
}

int skip_single_line_comment(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            return 0;
        }
    }

    return -1;
}

int skip_multi_line_comment(void)
{
    int prev = '\0';
    int curr;

    while ((curr = getchar()) != EOF)
    {
        if (prev == '*' && curr == '/')
        {
            return 0;
        }

        prev = curr;
    }

    return -1;
}