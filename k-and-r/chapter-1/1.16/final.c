/**
 * Program to print the longest line of the input, along with its length.
 * 
 * Exercise 1.16
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("Longest Line length - %d\n%s\n", max, longest);
    }
    else
    {
        printf("No characters were input.\n");
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i;

    for (i = 0; i < lim - 1; i++)
    {
        int c = getchar();

        if (c == EOF)
        {
            s[i] = '\0';
            return i;
        }

        s[i] = c;

        if (c == '\n')
        {
            i++;
            s[i] = '\0';
            return i;
        }
    }

    s[i] = '\0';

    while (1)
    {
        int c = getchar();

        if (c == EOF)
        {
            return i;
        }

        i++;

        if (c == '\n' || i == INT_MAX)
        {
            return i;
        }
    }
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}