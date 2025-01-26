/**
 * Original temperature conversion program to convert Fahrenheit to Celsius, as given in the book.
 * 
 * Exercise 1.3
 */

#include <stdio.h>

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  
}