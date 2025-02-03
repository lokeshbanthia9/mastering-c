/**
 * Program to to reverse the characters of the input line. 
 * 
 * Exercise 1.19 
 */

#include <stdio.h>

#define MAXLINE 1000

void get_line(char s[], int limit);
void reverse(char o[], char r[]);

int main()
{
    char input_line[MAXLINE];
    char reversed_line[MAXLINE];

    while (1)
    {
        get_line(input_line, MAXLINE);

        if (input_line[0] == '\0')
        {
            return 0;
        }

        reverse(input_line, reversed_line);
        printf("\nReversed Text: %s", reversed_line);
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

    while (1)
    {
        int c = getchar();

        if (c == EOF || c == '\n')
        {
            break;
        }
    }
}

void reverse(char o[], char r[])
{
    int o_index = 0;
    while (o[o_index] != '\0')
    {
        o_index++;
    }

    o_index--;

    int new_line = 0;
    if (o[o_index] == '\n')
    {
        o_index--;
        new_line = 1;
    }

    int r_index = 0;
    while (o_index >= 0)
    {
        r[r_index] = o[o_index];
        r_index++;
        o_index--;
    }

    if (new_line)
    {
        r[r_index] = '\n';
        r_index++;
    }

    r[r_index] = '\0';
}