
# Exercise 1.4

> Write a program to print the corresponding Celsius to Fahrenheit table. 

- ### Original Problem Table

(see Exercise 1.3)

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

# Solution

- ### Approach

To print the Celsius to Fahrenheit table, we can take fixed values of celsius, incrementing it gradually, and calculate the corresponding fahreneit values, similiar to the approach used in Exercise 1.3.

I took the starting celsius value (`lower`) as `0` and the final value (`upper`) as `100`, incrementing each iteration (`step`) by `10`. The initial value of `celsius` is initialised as `lower`. Fahrenheit is declared as float data type to make the calculated value more precise than it would be as an integer.

The table headers are printed first followed by a line divider to make it visually cleaner and easy to read.

The loop runs till the value of celsius does not exceed the value of`upper`. In each iteration, the fahrenheit value is calculated corresponding to the current celsius value, and both the values are printed. Additionally, the value of `celsius` is increased by `step` in each iteration.

After completing the loop, the program ends with a return value of 0, implying successfull completion.

- ### Code

```c
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
```

- ### Compilation Output

```console
$ gcc -o temp-conv temp-conv.c

```

No warnings or errors.

- ### Execution Result

```console
$ ./temp-conv
Celsius          Fahrenheit
---------------------------
   0                32.0
  10                50.0
  20                68.0
  30                86.0
  40               104.0
  50               122.0
  60               140.0
  70               158.0
  80               176.0
  90               194.0
 100               212.0
```

The program prints the complete Celsius to Fahrenheit table.

---