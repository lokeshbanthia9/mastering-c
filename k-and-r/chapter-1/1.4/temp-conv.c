/**
 * Temperature conversion program for printing a Celsius to Fahrenheit table.
 * 
 * Exercise 1.4
 */

#include <stdio.h>

int main()
{
  int lower = 0;
  int upper = 100;
  int step = 10;

  int celsius = lower;
  float fahr;

  printf("Celsius \t Fahrenheit\n");
  printf("---------------------------\n");

  while (celsius <= upper)
  {
    fahr = (celsius * 9.0 / 5.0) + 32;
    printf("%4d \t\t %7.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}