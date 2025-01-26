
# Exercise 1.3

> Modify the temperature conversion program to print a heading above the table. 

- ### Initial Code

(see `initial.c`)

```c
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
```

- ### Initial Output Table

```console
$ ./initial
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

# Solution

- ### Approach

For adding the table header, we need to print the header string before the while loop. I am choosing `Fahrenheit` and `Celsius` as the column names. Additionally, I am also including a tab space between the columns, and a line divider after the header to make the output visually better.

We also need to align the values printing format with the header, to ensure they are under their respective header columns. To do this, I am changing fahrenhiet values print format from `%3.0f` to `%6.0f` and adding two tab spaces (`\t`) between fahrenheit and celsius values. This ensures the ouput table is visually clear and easy to read.

I have also added `int` as the return type for main function to address the compiler warning for `[-Wimplicit-int]`, and subsequently, returning 0 at the end of main function.

- ### Final Code

(see `final.c`)

```c
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
```

- ### Compilation Output

```console
$ gcc -o final final.c

```

No warnings or errors.

- ### Execution Result

```console
$ ./final
Fahrenheit       Celsius
------------------------
     0            -17.8
    20             -6.7
    40              4.4
    60             15.6
    80             26.7
   100             37.8
   120             48.9
   140             60.0
   160             71.1
   180             82.2
   200             93.3
   220            104.4
   240            115.6
   260            126.7
   280            137.8
   300            148.9
```

The final result prints the table column headers as `Fahrenheit` and `Celsius` and all their respective values aligned below.

---