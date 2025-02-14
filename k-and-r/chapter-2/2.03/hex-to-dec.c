/**
 * Program to convert hexadecimal string into its equivalent integer value. 
 * 
 * Exercise 2.3 
 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#define INVALID_CHARACTER -1
#define RANGE_OUT_OF_BOUND -2
#define UNKNOWN_ERRORS -3

int remove_space(char s[], int counter);
int is_overflow(int num, char digit);
int htoi(char hex[]);

int main(void)
{
    char hex[] = "0x7FFFFFFFFFFFFFFF";
    int result = htoi(hex);

    if (result > 0)
    {
        int sign_index = remove_space(hex, 0);
        if (hex[sign_index] == '\0')
        {
            printf("[WARNING] Hex string does not contain any digit.\n");
            return 0;
        }

        result = hex[sign_index] == '-' ? -result : result;

        printf("Hexadecimal Input: %s\nDecimal Output: %i\n", hex, result);
        return 0;
    }
    else if (result == 0)
    {
        if ((hex[0] == '0' && hex[1] == '\0') || (hex[0] == '0' && toupper(hex[1]) == 'X' && hex[2] == '0' && hex[3] == '\0'))
        {
            printf("Hexadecimal Input: 0\nDecimal Output: 0\n");
        }
        else if (hex[0] == '-' && hex[1] == '0')
        {
            if (hex[2] == '\0' || (toupper(hex[1]) == 'X' && hex[2] == '0' && hex[3] == '\0'))
            {
                printf("[WARNING] -0 is same as 0.\nDecimal Output: 0\n");
            }
            else
            {
                printf("[WARNING] Hex string does not contain any digit.\n");
            }
        }
        else
        {
            printf("[WARNING] Hex string does not contain any digit.\n");
        }

        return 0;
    }
    else if (result == INVALID_CHARACTER)
    {
        printf("[ERROR] Inavlid hexadecimal character.\n");
        return INVALID_CHARACTER;
    }
    else if (result == RANGE_OUT_OF_BOUND)
    {
        printf("[ERROR] Hexadecimal number out of range for 32-bit signed int.\n");
        return RANGE_OUT_OF_BOUND;
    }
    else
    {
        printf("[ERROR] Unkown error occured! (%d)\n", result);
        return UNKNOWN_ERRORS;
    }
}

int remove_space(char s[], int counter)
{
    while (isspace(s[counter]) && counter <= INT_MAX)
    {
        counter++;
    }

    return counter;
}

int is_overflow(int num, char digit)
{
    return num > (INT_MAX - digit) / 16;
}

int htoi(char hex[])
{
    int shift = 0;

    shift = remove_space(hex, shift);
    if (hex[shift] == '-')
    {
        shift++;
    }

    shift = remove_space(hex, shift);
    if (hex[shift] == '0' && toupper(hex[shift + 1]) == 'X')
    {
        shift += 2;
    }

    int num = 0;
    for (int i = shift; hex[i] != '\0'; i++)
    {
        int digit;

        if (isdigit(hex[i]))
        {
            digit = hex[i] - '0';
        }
        else if (toupper(hex[i]) >= 'A' && toupper(hex[i]) <= 'F')
        {
            digit = toupper(hex[i]) - 'A' + 10;
        }
        else if (isspace(hex[i]))
        {
            continue;
        }
        else
        {
            return INVALID_CHARACTER;
        }

        if (is_overflow(num, digit))
        {
            return RANGE_OUT_OF_BOUND;
        }

        num = num * 16 + digit;
    }

    return num;
}