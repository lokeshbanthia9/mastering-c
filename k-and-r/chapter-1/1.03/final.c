/**
 * Prints the table heading along with the original program output of Fahrenheit to Celsius table.
 * 
 * Exercise 1.3
 */

#include <stdio.h>

int main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  // Table header
  printf("Fahrenheit \t Celsius\n");
  printf("------------------------\n");

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%6.0f \t\t %6.1f\n", fahr, celsius); // Change print format to match the table header
    fahr = fahr + step;
  }
  
  return 0;
}