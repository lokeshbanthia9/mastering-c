
# Exercise 2.1: Range

## Problem Statement

> Write a program to determine the ranges of `char`, `short`, `int`, and `long` variables, both `signed` and `unsigned`, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

## Integer Representation

- Integers are stored in binary format as a sequence of bits in groups of 8, 16, 32, or 64 bits.

- The number of bits determines how many integers can be stored.

- Integers can be signed or unsigned.

- ### Signed Integers

    - Signed integer types can store positive, zero or negative values.

    - The most common representation for storing signed integers is *two's complement*, which uses the first bit (MSB) to represent sign (`0` for positive and `1` for negative) and rest of the bits representing magnitude in two's complement form.

    - The minimum value for signed integral type of *n* bits will be -2^(n-1)^, and can be represented (in two's complement form) by setting the sign bit to `1` (negative) and all other bits to `0`.

    - The maximum value for signed integral type of *n* bits will be 2^(n-1)^ - 1, and can be represented by setting the sign bit to `0` (positive) and all other bits to `1`.

- ### Unsigned Integers

    - Unsigned integer types can only store positive or zero values.

    - Unsigned integers are represented in ordinary binary representation, with all bits representing the magnitude of the number.

    - The minimum value for unsigned integral types will always be `0`, which is represented by setting all the bits to `0`.

    - The maximum value for unsigned integral type of *n* bits will be 2^n^ - 1, and can be represented by setting all bits to `1`.

## Floating-Point Representation

- Floating-point representation is a way to store real numbers, represented in scientific notation.

- The IEEE 754 standard is the most common way of representing floating-point numbers in computers. It is represented by three components:

    - the sign of the mantissa (`0` for positive and `1` for negative number).

    - the biased exponent

    - the normalised mantissa

- The number of bits in the floating-point data type determines the bits used for exponent and mantissa.

- For numbers with an exponent in the normal range (the exponent field being neither all ones nor all zeros), the leading bit of the significant (mantissa) will always be `1`, which allows the binary format to have an extra bit of precision (leading or implicit bit convention).

- IEEE 754 standard also contains some reserved values:

    - Zero: denoted with exponent and mantissa of all zeros.

    - Subnormal / Denormalized: denoted with exponent of all zeros and mantissa of any non zero value.

    - Infinity denoted with exponent of all ones and mantissa of all zeros.

    - Not a Number (NaN): denoted with exponent of all ones and mantissa of any non zero value.

- For the maximum positive value for floating-point types, the sign bit will be set to `0` (positive), the exponent bits will be set to one less than its maximum value (all ones except last exponent bit, to avoid inf), and the mantissa set to its maximum value (all ones).

- For the minimum positive value of floating-point types in normal range, the sign bit will be set to `1` (positive), the exponent bits will be set to `1` (all ones except last exponent bit, to avoid zero), and the mantissa set to its minimum value (all zeros)

- For the minimum positive value of floating-point types in subnormal range, the sign bit will be set to `0` (positive), the exponents bits to all zeros, and the mantissa to `1` (all zeros except last mantissa bit, to avoid zero).

- The negative range is the mirror of the positive range: the maximum positive value corresponds to the minimum negative value, and the minimum positive value corresponds to the maximum negative value, with the sign bit set to `1` (negative).

## Approach

I decided to print the output in a tabular format, one for integral types and one for floating-point types; the tables containing a side-by-side comparison of *actual* values (from standard headers) and *computed* values.

1. Import the necessary standard libraries

    - `limits.h` for integral types range.

    - `float.h` for floating-point range and other constants (radix, exponent, etc).

    - `math.h` for `pow` to calculate floating point ranges.

    - `stdio.h` for `printf`.

2. Define a symbolic constant for the number of bits in a byte, or use `CHAR_BIT` from `limits.h` alternatively.

3. In the `main` function, print the integral table's headers, divided in six columns, *data type*, *size*, *actual minimum value*, *actual maximum value*, *computed minimum value* and *computed maximum value*.

4. Compute the minimum and maximum values for each data type (unsigned integral types minimum value is `0`) and print the values in a row aligned correctly with the table.

5. After calculating and printing the range of all integral types, print a line divider at the end of the table.

6. Print the floating-point table's headers, divided in eight columns, *data type*, *size*, *actual minimum subnormal value*, *actual minimum normal value*, *actual maximum value*, *computed minimum subnormal value*, *computed minimum normal value* and *computed maximum value*.

7. Compute the true minimum (subnormal), minimum (normal) and maximum values of all floating-point types and print the values in a row aligned correctly with the table.

8. After calculating and printing the range of all floating-point types, print a line divider at the end of the table, and end the program with exit status `0`.

Note: I am only printing the positive range for floating-point types.

## Value Calculations

### Integral Types

- Minimum: `1` left shifted by the n-1, where n is the number of bits in the data type. This gives `1` as the MSB with n-1 leading zeros. For `long` and `long long`, we can use their literals to avoid `int` operation (`1L` and `1LL` respectively)

```c
type min = 1 << (sizeof(type) * BITS - 1);
```

- Maximum: Invert all bits of the minimum value (negating the minimum number).

```c
type max = ~min;
```

### Floating-Point Types

- We can find range by converting the binary representation of floating-point to decimal base-10, by multiplying the mantissa component in base-10 to exponent component in base-10.

- Subnormal Minimum: Multiplying `2` (or radix) to the power of (negative of total mantissa bits) + 1 (mantissa component) by `2` (or radix) to the power of minimum possible exponent + 1 (exponent component).

```c
type true_min = pow(FLT_RADIX, -type_MANT_DIG + 1) * pow(FLT_RADIX, type_MIN_EXP - 1);
```

- Normal Minimum: `2` (or radix) to the power of minimum possible exponent + 1 (exponent component). Mantissa is set to `1`, so we can skip its multiplication.

```c
type min = pow(FLT_RADIX, type_MIN_EXP - 1);
```

- Maximum: The mantissa component for maximu value will be set to all ones. Converting this to decimal base-10 gives a geometric series of 2 (or radix) minus 2 (or radix) to the power of (negative of total mantissa bits) + 1 (mantissa component). Multiplying this mantissa component with `2` (or radix) to the power of maximum possible exponent - 1 (exponent component).

```c
type max = (FLT_RADIX - pow(FLT_RADIX, -type_MANT_DIG + 1)) * pow(FLT_RADIX, type_MAX_EXP - 1);
```

## Output

```console
$ ./range

+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                 INTEGER DATA TYPE RANGES (C Language)                                                                 |
+---------------------------+---------------------------+-------------------------------------------------------+-------------------------------------------------------+
|                           |                           |                        ACTUAL                         |                       COMPUTED                        |
| Data Type                 | Size (bytes)              |---------------------------+---------------------------|---------------------------+---------------------------|
|                           |                           | Minimum                   | Maximum                   | Minimum                   | Maximum                   |
+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+
| char                      | 1                         | -128                      | 127                       | -128                      | 127                       |
| unsigned char             | 1                         | 0                         | 255                       | 0                         | 255                       |
| short                     | 2                         | -32768                    | 32767                     | -32768                    | 32767                     |
| unsigned short            | 2                         | 0                         | 65535                     | 0                         | 65535                     |
| int                       | 4                         | -2147483648               | 2147483647                | -2147483648               | 2147483647                |
| unsigned int              | 4                         | 0                         | 4294967295                | 0                         | 4294967295                |
| long                      | 4                         | -2147483648               | 2147483647                | -2147483648               | 2147483647                |
| unsigned long             | 4                         | 0                         | 4294967295                | 0                         | 4294967295                |
| long long                 | 8                         | -9223372036854775808      | 9223372036854775807       | -9223372036854775808      | 9223372036854775807       |
| unsigned long long        | 8                         | 0                         | 18446744073709551615      | 0                         | 18446744073709551615      |
+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+

+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                         FLOATING-POINT DATA TYPE RANGES (C Language)                                                                                          |
+---------------------------+---------------------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
|                           |                           |                                      ACTUAL                                       |                                     COMPUTED                                      |
| Data Type                 | Size (bytes)              |---------------------------+---------------------------+---------------------------|---------------------------+---------------------------+---------------------------|
|                           |                           | Minimum (subnormal)       | Minimum (normal)          | Maximum                   | Minimum (subnormal)       | Minimum (normal)          | Maximum                   |
+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+
| float                     | 4                         | 1.4013e-45                | 1.17549e-38               | 3.40282e+38               | 1.4013e-45                | 1.17549e-38               | 3.40282e+38               |
| double                    | 8                         | 4.94066e-324              | 2.22507e-308              | 1.79769e+308              | 4.94066e-324              | 2.22507e-308              | 1.79769e+308              |
+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+
```

Note: This program was executed on a x64-based PC. Some ranges may vary based on the size of each data type if executed on a different architecture.

## Learnings

- How bit manipulation and truncation work for different integral data types.

- How floating-point numbers are stored and represented in computers.

---