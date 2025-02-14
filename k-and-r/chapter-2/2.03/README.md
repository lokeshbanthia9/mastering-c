
# Exercise 2.3: Hex to Decimal

## Problem Statement

> Write a function `htoi(s)`, which converts a string of hexadecimal digits (including an optional `0x` or `0X`) into its equivalent integer value. The allowable digits are `0` through `9`, `a` through `f`, and `A` through `F`.

## Hexadecimal to Decimal Conversion

- Sum of each hexadecimal digit multiplied with powers of 16, starting with 0 from the right and moving towards left.

- For example, converting `2B` hex to decimal: 2 * 16^1^ + 11 (for B) * 16^0^ = 43.

## Approach

- Define and initialize a `char` array containing the hexadecimal value. Initialize the array counter variable to `0`.

- Check for negative sign, `0x`, `0X` or spaces at the start of the hex string and shift the array counter accordingly.

- Define a variable to store the decimal converted value and initialise it to `0`.

- Run a loop to traverse through the hex string. In each iteration,

    - If the character is a valid hexadecimal digit, add the digit to 16 times of the current output and save as the new output.

    - If the character is any space, move to the next iteration.

    - If the character is neither a valid hex digit nor a space, end the program with invalid hex character error.

    - If the number of hex digits in the input string exceed `8`, or is `8` but the value of first digit of hex string is more than `7`, end the program with range out of bound error. (the decimal value to be stored for that hex string will be bigger than the range of `int`)

- Print the converted decimal output.

See [hex-to-dec.c](/k-and-r/chapter-2/2.03/hex-to-dec.c) for the code.

## Output

### 1. Empty String

```console
$ ./hex-to-dec
[WARNING] Hex string does not contain any digit.
```

### 2. White Space String

```console
$ ./hex-to-dec
[WARNING] Hex string does not contain any digit.
```

### 3. Invalid Characters

Input: `hexadecimal`
Expected Output: Error

```console
$ ./hex-to-dec
[ERROR] Inavlid hexadecimal character.
```

### 4. Only Hex Literal

Input: `0x`
Expected Output: Warning

```console
$ ./hex-to-dec
[WARNING] Hex string does not contain any digit.
```

### 5. Only Negative Hex Literal

Input: `-0X`
Expected Output: Warning

```console
$ ./hex-to-dec
[WARNING] Hex string does not contain any digit.
```

### 6. Simple Hex Input

Input: `0x1A`
Expected Output: `26`

```console
$ ./hex-to-dec
Hexadecimal Input: 0x1A
Decimal Output: 26
```

### 7. Simple Hex Input #2

Input: `7f`
Expected Output: `127`

```console
$ ./hex-to-dec
Hexadecimal Input: 7f
Decimal Output: 127
```

### 8. Zero

Input: `0`
Expected Output: `0`

```console
$ ./hex-to-dec
Hexadecimal Input: 0
Decimal Output: 0
```

### 9. Maximum 32-bit signed int value

Input: `0x7FFFFFFF`
Exptected Output: `2147483647`

```console
$ ./hex-to-dec
Hexadecimal Input: 0x7FFFFFFF
Decimal Output: 2147483647
```

### 10. Minimum 32-bit signed int value

Input: `-0x7FFFFFFF`
Expected Output: `-2147483647`

```console
$ ./hex-to-dec
Hexadecimal Input: -0x7FFFFFFF
Decimal Output: -2147483647
```

Note: Minimum value of 32-bit int is `-2147483648`, but the `htoi` function was designed to be the same for positive and negative numbers, thus the minimum negative value will be mirror of the maximum positive value.

### 11. Mixed Case Inputs

Input: `0xAbC123`
Expected Output: `11256099`

```console
$ ./hex-to-dec
Hexadecimal Input: 0xAbC123
Decimal Output: 11256099
```

### 12. Leading Zeros

Input: `0x0000FF`
Expected Output: `255`

```console
Hexadecimal Input: 0x0000FF
Decimal Output: 255
```

### 13. Range out of bound for 32-bit signed int

Input: 0x7FFFFFFFFFFFFFFF
Expected Output: Error

```console
$ ./hex-to-dec
[ERROR] Hexadecimal number out of range for 32-bit signed int.
```

---