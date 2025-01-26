
# Exercise 1.5

> Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

- ### Initial Code (see `initial.c`)

```c
#include <stdio.h>

int main()
{
  int fahr;

  for (fahr = 0; fahr <= 300; fahr = fahr + 20)
  {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
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

To print the Fahrenheit to Celsius table in reverse order, we need to invert the `for loop` logic. Instead of starting from lowest value `0`, going till highest value `300` and incrementing `20` in each iteration, we need to start from highest value `300`, go till the lowest value `0` and decrement `20` in each iteration.

I have added separate vaiable for celsius to make the code easy to read. Additionally, I have added table headers and line divider to make the ouput visually clean.

After the loop completion, I am terminating the program with `0` to imply sucessfull completion.

- ### Code (see `final.c`)

```c
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
   300            148.9 
   280            137.8 
   260            126.7 
   240            115.6 
   220            104.4 
   200             93.3 
   180             82.2 
   160             71.1 
   140             60.0 
   120             48.9 
   100             37.8 
    80             26.7
    60             15.6
    40              4.4
    20             -6.7
     0            -17.8
```

The program prints the complete Fahrenheit to Celsius table in reverse order.

---