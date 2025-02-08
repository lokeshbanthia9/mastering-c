/**
 * Program to replace strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. 
 * 
 * Exercise 1.21 
 */

#include <stdio.h>

#define MAXLINE 1000

int get_tab_width(void);
void get_line(char s[], int limit);
void entab(char input[], char output[], int tab_width, int pre_output_chars);

int main(void)
{
    int tab_width = get_tab_width();

    char input_line[MAXLINE];
    char output_line[MAXLINE];

    get_line(input_line, MAXLINE);

    if (input_line[0] == '\0')
    {
        printf("\nNo characters were input.\n");
        return 1;
    }

    int pre_output_chars = 12;
    entab(input_line, output_line, tab_width, pre_output_chars);
    printf("\nEntab Text: %s\n", output_line);

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

void entab(char input[], char output[], int tab_width, int pre_output_chars)
{
    int i = 0;
    int j = 0;

    while (input[i] != '\0')
    {
        if (input[i] != ' ')
        {
            output[j] = input[i];
            i++;
            j++;
            continue;
        }

        int space_count = 0;
        int start_pos = j + pre_output_chars;

        while (input[i] == ' ')
        {
            space_count++;
            i++;
        }

        int spaces_to_first_tab_stop = tab_width - (start_pos % tab_width);
        int remaining_spaces = space_count - spaces_to_first_tab_stop;

        int tabs_needed = remaining_spaces >= 0 ? (remaining_spaces / tab_width) + 1 : 0;
        int spaces_needed = remaining_spaces >= 0 ? remaining_spaces % tab_width : space_count;

        while (tabs_needed > 0)
        {
            output[j] = '\t';
            j++;
            tabs_needed--;
        }

        while (spaces_needed > 0)
        {
            output[j] = ' ';
            j++;
            spaces_needed--;
        }
    }

    output[j] = '\0';
}