/**
 * Program to fold long input lines into two or more shorter lines.
 *
 * Exercise 1.22
 */

#include <stdio.h>

#define STRING_LIMIT 10000
#define LINE_LIMIT 25

void get_line(char s[], int limit);
void put_folded_lines(char input[], char output[], int string_limit, int line_limit);

int main(void)
{
    char input[STRING_LIMIT];
    char output[STRING_LIMIT + (STRING_LIMIT / LINE_LIMIT)];

    get_line(input, STRING_LIMIT);

    // Exit if the input string is empty or contains only spaces
    for (int i = 0; ; i++)
    {
        if (input[i] == '\0')
        {
            printf("\nNo characters were entered.\n");
            return 1;
        }
        else if (input[i] == ' ' || input[i] == '\t')
        {
            continue;
        }
        else
        {
            break;
        }
    }

    put_folded_lines(input, output, STRING_LIMIT, LINE_LIMIT);
    printf("\nFolded Text:\n%s\n", output);

    return 0;
}

void get_line(char s[], int limit)
{
    printf("\nInput Text: ");

    for (int i = 0; i < limit - 1; i++)
    {
        int c = getchar();

        if (c == '\n')
        {
            s[i] = '\0';
            return;
        }

        s[i] = c;
    }

    s[limit - 1] = '\0';

    while (1)
    {
        char c = getchar();

        if (c == '\n')
        {
            break;
        }
    }

    printf("\nOnly the first %d characters were read.\nProcessed Input Text: %s\n", limit, s);
}

void calculate_word_lengths(char str[], int count[])
{
    int s = 0;
    int c = 0;

    int in_word = 0;

    while (str[s] != '\0')
    {
        if (str[s] == ' ' || str[s] == '\t')
        {
            if (in_word)
            {
                c++;
                in_word = 0;
            }
        }
        else
        {
            in_word = 1;
            count[c]++;
        }
        s++;
    }

    if (count[c] == 0)
    {
        count[c] = -1;
    }
    else
    {
        c++;
        count[c] = -1;
    }
}

void copy(char from[], char to[], int from_index, int to_index, int last_index)
{
    while (from_index <= last_index)
    {
        to[to_index] = from[from_index];
        from_index++;
        to_index++;
    }
}

void put_folded_lines(char input[], char output[], int string_limit, int line_limit)
{
    int i = 0; // input string counter
    int o = 0; // output string counter

    int len = (string_limit / 2) + 1;
    int word_lengths[len];

    for (int d = 0; d < len; d++)
    {
        word_lengths[d] = 0;
    }

    calculate_word_lengths(input, word_lengths);
    int w = 0; // word length array counter

    int line_length = 0;
    int length_added = 0;
    int words_in_line = 0;

    while (word_lengths[w] != -1)
    {
        while (input[i] == ' ' || input[i] == '\t')
        {
            i++;
        }

        if (word_lengths[w] > line_limit - line_length)
        {
            if (words_in_line)
            {
                line_length = 0;
                words_in_line = 0;

                output[o] = '\n';
                o++;

                continue;
            }
            else
            {
                copy(input, output, i, o, i + line_limit - 2);

                o += line_limit - 1;

                output[o] = '-';
                o++;

                output[o] = '\n';
                o++;

                copy(input, output, i + line_limit - 1, o, i + word_lengths[w] - 1);
                
                length_added = word_lengths[w] - line_limit + 1;
                line_length = length_added;
                words_in_line = 1;
            }
        }
        else 
        {
            copy(input, output, i, o, i + word_lengths[w] - 1);

            length_added = word_lengths[w];
            line_length += length_added;
            words_in_line += 1;
        }

        i += word_lengths[w];
        o += length_added;

        output[o] = input[i] == '\t' ? '\t' : ' ';
        o++;
        line_length++;

        w++;
    }

    output[o] = '\0';
}