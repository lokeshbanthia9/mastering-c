/**
 * Program to remove trailing blanks and tabs from all input lines, and to delete entirely blank lines. 
 * 
 * Excercise 1.18 
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXLINE 1000

void get_line(char s[], int limit);
void put_line(char s[]);

int main()
{
    char line[MAXLINE];

    while (TRUE)
    {
        get_line(line, MAXLINE);

        if (line[0] == '\0')
        {
            return 0;
        }

        put_line(line);
    }
}

void get_line(char s[], int limit)
{
    printf("\nInput Text: ");

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

    while (TRUE)
    {
        int c = getchar();

        if (c == EOF || c == '\n')
        {
            break;
        }
    }
}

void put_line(char s[])
{    
    int i = 0;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            break;
        }
    }

    if (s[i] == '\0')
    {
        return;
    }

    int in_space = FALSE;

    printf("\nOutput Text: ");

    for (; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' || s[i] == '\t')
        {
            if (!in_space)
            {
                putchar(s[i]);
                in_space = TRUE;
            }
        }
        else
        {
            putchar(s[i]);
            in_space = FALSE;
        }
    }
}