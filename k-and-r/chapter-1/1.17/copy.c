/**
 * Program to print all input lines that are longer than 80 characters. 
 * 
 * Exercise 1.17
 */

# include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int limit);

int main()
{
    int len;
    char line[MAXLINE];

    while (1)
    {
        len = get_line(line, MAXLINE);

        if (len == 0)
        {
            return 0;
        }

        if (len <= 80)
        {
            continue;
        }

        printf("%s\n", line);
    }
}

int get_line(char s[], int limit)
{
    int i;

    for (i = 0; i < limit - 1; i++)
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

        if (c == '\n')
        {
            return i;
        }
    }
}