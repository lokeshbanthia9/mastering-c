/**
 * Program to print a temperature conversion table from Fahrenheit to Celsius.
 * 
 * Exercise 1.15
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_cel(float fahr);

int main()
{
    float fahr, celsius;
    fahr = LOWER;

    while (fahr <= UPPER)
    {
        celsius = fahr_to_cel(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    return 0;
}

float fahr_to_cel(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}