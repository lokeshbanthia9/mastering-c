/**
 * Final temperature conversion program for printing Fahrenheit to Celsius table in reverse order.
 * 
 * Exercise 1.5
 */

#include <stdio.h>

int main()
{
  printf("Fahrenheit \t Celsius\n");
  printf("------------------------\n");

  for (int fahr = 300; fahr >= 0; fahr -= 20)
  {
    float cel = (fahr - 32) * 5.0 / 9.0;
    printf("%6d \t\t %6.1f\n", fahr, cel);
  }

  return 0;
}