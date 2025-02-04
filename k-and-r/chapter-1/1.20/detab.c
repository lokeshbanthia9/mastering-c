/**
 * Program to replace tabs in the input with a set number of blanks. 
 * 
 * Exercise 1.20 
 */

#include <stdio.h>

#define MAXLINE 1000

int get_tab_width(void);
void get_line(char s[], int limit);
void detab(char tabs[], char blanks[], int tab_width);

int main(void)
{
    int tab_width = get_tab_width();
    
    char input_line[MAXLINE];
    get_line(input_line, MAXLINE);

    if (input_line[0] == '\0')
    {
        printf("\nNo characters were input.\n");
        return 0;
    }

    char output_line[MAXLINE * tab_width];
    detab(input_line, output_line, tab_width);

    printf("\nDetab Text: %s\n", output_line);
    return 0;
}

void clear_input(void)
{
    while (1)
    {
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            return;
        }
    }
}

int get_tab_width(void)
{
    int tab_width;

    while (1)
    {
        printf("\nEnter the tab width size (0 - 9): ");
        tab_width = getchar();

        if (tab_width >= '0' && tab_width <= '9')
        {
            clear_input();
            break;
        }
        else
        {
            if (tab_width != '\n' && tab_width != EOF)
            {
                clear_input();
            }
            printf("\nInvalid Input!\n");
        }
    }

    return tab_width - '0';
}

void get_line(char s[], int limit)
{
    printf("\nEnter Text: ");

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

    clear_input();
}

void detab(char tabs[], char blanks[], int tab_width)
{
    int b_index = 0;

    for (int i = 0; tabs[i] != '\0'; i++)
    {
        if (tabs[i] == '\t')
        {
            int spaces = tab_width - (b_index % tab_width);
            for (int t = 0; t < spaces; t++)
            {
                blanks[b_index] = ' ';
                b_index++;
            }
        }
        else
        {
            blanks[b_index] = tabs[i];
            b_index++;
        }
    }

    blanks[b_index] = '\0';
}