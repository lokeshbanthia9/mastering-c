
# Exercise 2.1: Alternate Relational Test

## Problem Statement

> Exercise 2-2. Write a loop equivalent to the `for` loop above without using `&&` or `||`.

```c
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 s[i] = c; 
```

## Approach

Instead of using `&&` in the `for` loop conditional test to for three relational tests, we can write seperate statements for each relational test inside the `for` loop body using `if` statement. If any of the condition does not satisfy, we `break` the loop as would happen if the `for` loop conditional test fails.

If the relation tests were in `for` loop conditinal statement, a truthy value would result in executing one iteration of the loop. In the updated code, since we are terminating the loop if the relational test results in true, we need to invert the logic to check for equality (`==`) instead of inequality (`!=`).

The updated `for` loop uses the *guard clause* design pattern; it stops the loop from running if the condition is not met. In complex programs, this technique helps us to avoid deeply nested code, and improves readabilty by seperating preconditions from the main logic. 

## Code

```c
for (i = 0; i < lim - 1; i++)
{
    if ((c = getchar()) == '\n')
    {
        break;
    }

    if (c == EOF)
    {
        break;
    }

    s[i] = c;
}
```

---