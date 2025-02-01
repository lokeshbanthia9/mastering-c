
# Exercise 1.15

> Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

- ### Original Code (see `initial.c`)

```c
#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

# Solution

- ### Approach

To convert the temperature conversion expression of Fahrenheit to Celsius to a function, I created `fahr_to_cel` with the parameter taking the value of `fahr`. It returns the value of celsius in float using the same expression used in the original code.

I have also created preprocessor directives (macros) for `LOWER`, `UPPER` and `STEP` values of Fahrenheit to increase readability. The rest of the program is similiar to the original code.

- ### Code (see `final.c`)

```c
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
```

- ### Compilation Output

```console
$ gcc -o final final.c

```

No warnings or errors.

- ### Execution Result

```console
$ ./final
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

---