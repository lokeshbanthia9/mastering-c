
# Exercise 1.22: Fold Long Input Lines

## Problem Statement

> Write a program to `fold` long input lines into two or more shorter lines after the last non-blank character that occurs before the *n*-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

## Approach

1. Define the limits

    - `STRING_LIMIT`: maximum number of characters to be read from the input.

    - `LINE_LIMIT`: maximum number of characters in each line in the output string.

2. Define two char arrays as `input` and `output` strings of size `STRING_LIMIT`.

3. Read the input from the user until new-line (`\n`) is passed, or `STRING_LIMIT` is reached.

4. If the input string is empty or contains only spaces (blanks or tabs), print the appropriate message and end the program.

5. Calculate the length of each word in the input string and store in an array. (assume words to be separated by either blank or tab)

6. Run a `while` loop to store each word in the output array.

    - `line_length` keeps track of the number of characters in the current line.

    - If the word length is greater than the space left in the line (`LINE_LIMIT` - `line_length`), move to a new line (by adding `\n` in the output string)

    - If the word length is less than the space left in the line, add the word to the output string.

    - If the word length is greater than the `LINE_LIMIT`, the word is printed in two lines, separated by a hyphen (`-`) at the end of first line.

7. Print the folded output string.

(see `fold.c` for the code)

## Output

`STRING_LIMIT` set to `10000` and `LINE_LIMIT` to `25` for all cases.

### 1. No Input

```console
$ ./fold

Input Text:

No characters were entered.
```

### 2. Trailing Spaces

```console
$ ./fold

Input Text:                              

No characters were entered.
```

### 3. Input string length less than `LINE_LIMIT`

```console
$ ./fold

Input Text: hello, world

Folded Text:
hello, world
```

### 4. Input string length more than `LINE_LIMIT`

```console
$ ./fold

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. In eget.

Folded Text:
Lorem ipsum dolor sit
amet, consectetur
adipiscing elit. In eget.
```

### 5. Paragraph Input

```console
$ ./fold

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris sed faucibus lorem. Integer iaculis neque tellus, non accumsan velit malesuada lacinia. Vivamus quis tempus est. Curabitur fermentum elit at aliquet porta. Curabitur vel dapibus turpis, sit amet mollis libero. Aenean sit amet blandit nisl. Proin tempor ex vitae enim condimentum ornare. Aenean viverra quam et blandit fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque cursus at urna at feugiat.

Folded Text:
Lorem ipsum dolor sit
amet, consectetur
adipiscing elit. Mauris
sed faucibus lorem.
Integer iaculis neque
tellus, non accumsan
velit malesuada lacinia.
Vivamus quis tempus est.
Curabitur fermentum elit
at aliquet porta.
Curabitur vel dapibus
turpis, sit amet mollis
libero. Aenean sit amet
blandit nisl. Proin
tempor ex vitae enim
condimentum ornare.
Aenean viverra quam et
blandit fermentum. Lorem
ipsum dolor sit amet,
consectetur adipiscing
elit. Quisque cursus at
urna at feugiat.
```

### 6. Input string word length more than `LINE_LIMIT`

(For this test case, I am changing `LINE_LIMIT` to 5)

```console
$ ./fold

Input Text: hello my name is lokesh banthia

Folded Text:
hello
my
name
is
loke-
sh
bant-
hia
```

### 7. Long input string

```console
$ ./fold

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris sed faucibus lorem. Integer iaculis neque tellus, non accumsan velit malesuada lacinia. Vivamus quis tempus est. Curabitur fermentum elit at aliquet porta. Curabitur vel dapibus turpis, sit amet mollis libero. Aenean sit amet blandit nisl. Proin tempor ex vitae enim condimentum ornare. Aenean viverra quam et blandit fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque cursus at urna at feugiat.

Folded Text:
Lorem ipsum dolor sit
amet, consectetur
adipiscing elit. Mauris
sed faucibus lorem.
Integer iaculis neque
tellus, non accumsan
velit malesuada lacinia.
Vivamus quis tempus est.
Curabitur fermentum elit
at aliquet porta.
Curabitur vel dapibus
turpis, sit amet mollis
libero. Aenean sit amet
blandit nisl. Proin
tempor ex vitae enim
condimentum ornare.
Aenean viverra quam et
blandit fermentum. Lorem
ipsum dolor sit amet,
consectetur adipiscing
elit. Quisque cursus at
urna at feugiat.

banth@LAPTOP-2CH4GD63 MINGW64 /c/personal/dev/mastering-c/k-and-r/chapter-1/1.22 (main)
$ ./fold

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc purus dui, tempor ac suscipit ut, suscipit at elit. Etiam consequat, odio quis sagittis sagittis, ligula sapien facilisis odio, vitae mattis felis leo non leo. Vivamus eget felis felis. Sed felis quam, semper in eleifend imperdiet, pharetra a magna. In vel arcu ex. Nulla nec est nec tortor congue iaculis. Vivamus id purus in magna gravida porta. Ut quis leo et ligula imperdiet eleifend. Nullam sem urna, euismod ut eros sed, scelerisque tincidunt risus. Suspendisse maximus purus vitae luctus porttitor. Etiam euismod ex diam, at hendrerit neque aliquet ut. Aliquam felis augue, lobortis ut lectus id, pellentesque pulvinar ipsum. In elit felis, congue sit amet mauris non, varius bibendum nulla. Phasellus diam erat, faucibus 
quis sapien eu, interdum maximus nulla.Aenean ornare, lectus sit amet sodales egestas, urna risus pulvinar lectus, sit amet volutpat augue enim sit amet tortor. Sed viverra interdum diam, vitae ultrices ligula auctor ut. Ut posuere, urna quis rhoncus elementum, urna urna maximus ligula, venenatis fringilla libero nisi quis augue. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Suspendisse posuere, magna et commodo faucibus, enim odio rhoncus nunc, ultrices faucibus diam lectus in diam. Maecenas ut mi diam. Duis volutpat est imperdiet dictum venenatis. Praesent quis dolor lectus. Praesent a turpis at felis dictum sodales quis sit amet risus.Morbi tincidunt, dui non euismod dignissim, nunc orci rhoncus lacus, a volutpat dui nulla at nisi. Integer ac orci a 
mi commodo feugiat quis in erat. Duis in mollis mi. Sed sit amet feugiat nulla. Integer et varius turpis, et vulputate lectus. Curabitur imperdiet ex sed nibh tincidunt consequat. Nullam a mauris eget 
augue dignissim congue. Ut a vestibulum nisl, vel molestie justo. In ac urna nibh. Nullam semper elit vel molestie ultricies. Nulla cursus aliquam tortor, eu mattis tortor tempus in. Suspendisse sapien lacus, bibendum nec nibh nec, ornare gravida neque. Aliquam erat volutpat. Sed elementum mi id justo dignissim, nec ullamcorper nisi convallis. Fusce placerat mi diam, pretium pellentesque lacus fringilla ornare. Vestibulum id risus ut nunc aliquet egestas.Praesent consequat mi sed ex mattis luctus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Ut sagittis augue at nunc pharetra sollicitudin. Praesent non sem ut nisl scelerisque iaculis. Integer ut mi ac eros elementum maximus eget at diam. Fusce porttitor feugiat lectus, et iaculis metus iaculis et. Integer sed sapien lacus. Ut 
imperdiet ac risus a pulvinar.Nunc laoreet vitae urna ut pulvinar. Ut porta tempor congue. Aenean ante turpis, mollis ut lectus nec, ultrices dignissim turpis. Nullam at porttitor quam. Praesent et nulla ullamcorper, venenatis tellus et, lobortis leo. Aliquam in interdum sapien. Nunc sit amet nisl ligula. Suspendisse quis neque vel risus dictum fringilla. Ut euismod ex libero, at ultricies nisl gravida id. Aliquam nec luctus mauris. Mauris ac orci mauris. Ut fringilla dictum tellus sit amet laoreet. Nam neque odio, semper non consequat vitae, molestie eget lectus. Curabitur massa erat, consectetur sit amet viverra non, pellentesque quis dolor. Etiam nisi turpis, vulputate a augue id, venenatis gravida turpis.Morbi rutrum vehicula nisi, id hendrerit justo hendrerit quis. Ut dictum mauris ut neque ornare luctus. Praesent non sollicitudin ipsum, ac ullamcorper lectus. Vestibulum finibus ipsum nec leo gravida auctor. Donec in magna dolor. Vestibulum mattis efficitur nisi, at mattis nisi tempus 
quis. Lorem ipsum dolor sit amet, consectetur adipiscing elit.Praesent sed justo ac odio aliquam posuere ut sed neque. Nunc iaculis arcu non velit viverra consectetur vel eu odio. Cras sed aliquet est. Cras laoreet id orci vitae pellentesque. In ipsum augue, commodo sit amet bibendum non, convallis non libero. Nunc ultricies nunc vulputate, dictum tortor vel, commodo ligula. Quisque ornare justo sed neque rhoncus feugiat.Curabitur sed lacus tellus. Praesent eu malesuada sem.         

Folded Text:
Lorem ipsum dolor sit
amet, consectetur
adipiscing elit. Nunc
purus dui, tempor ac
suscipit ut, suscipit at
elit. Etiam consequat,
odio quis sagittis
sagittis, ligula sapien
facilisis odio, vitae
mattis felis leo non leo.
Vivamus eget felis felis.
Sed felis quam, semper in
eleifend imperdiet,
pharetra a magna. In vel
arcu ex. Nulla nec est
nec tortor congue
iaculis. Vivamus id purus
in magna gravida porta.
Ut quis leo et ligula
imperdiet eleifend.
Nullam sem urna, euismod
ut eros sed, scelerisque
tincidunt risus.
Suspendisse maximus purus
vitae luctus porttitor.
Etiam euismod ex diam, at
hendrerit neque aliquet
ut. Aliquam felis augue,
lobortis ut lectus id,
pellentesque pulvinar
ipsum. In elit felis,
congue sit amet mauris
non, varius bibendum
nulla. Phasellus diam
erat, faucibus quis
sapien eu, interdum
maximus nulla.Aenean
ornare, lectus sit amet
sodales egestas, urna
risus pulvinar lectus,
sit amet volutpat augue
enim sit amet tortor. Sed
viverra interdum diam,
vitae ultrices ligula
auctor ut. Ut posuere,
urna quis rhoncus
elementum, urna urna
maximus ligula, venenatis
fringilla libero nisi
quis augue. Orci varius
natoque penatibus et
magnis dis parturient
montes, nascetur
ridiculus mus.
Suspendisse posuere,
magna et commodo
faucibus, enim odio
rhoncus nunc, ultrices
faucibus diam lectus in
diam. Maecenas ut mi
diam. Duis volutpat est
imperdiet dictum
venenatis. Praesent quis
dolor lectus. Praesent a
turpis at felis dictum
sodales quis sit amet
risus.Morbi tincidunt,
dui non euismod
dignissim, nunc orci
rhoncus lacus, a volutpat
dui nulla at nisi.
Integer ac orci a mi
commodo feugiat quis in
erat. Duis in mollis mi.
Sed sit amet feugiat
nulla. Integer et varius
turpis, et vulputate
lectus. Curabitur
imperdiet ex sed nibh
tincidunt consequat.
Nullam a mauris eget
augue dignissim congue.
Ut a vestibulum nisl, vel
molestie justo. In ac
urna nibh. Nullam semper
elit vel molestie
ultricies. Nulla cursus
aliquam tortor, eu mattis
tortor tempus in.
Suspendisse sapien lacus,
bibendum nec nibh nec,
ornare gravida neque.
Aliquam erat volutpat.
Sed elementum mi id justo
dignissim, nec
ullamcorper nisi
convallis. Fusce placerat
mi diam, pretium
pellentesque lacus
fringilla ornare.
Vestibulum id risus ut
nunc aliquet
egestas.Praesent
consequat mi sed ex
mattis luctus. Interdum
et malesuada fames ac
ante ipsum primis in
faucibus. Ut sagittis
augue at nunc pharetra
sollicitudin. Praesent
non sem ut nisl
scelerisque iaculis.
Integer ut mi ac eros
elementum maximus eget at
diam. Fusce porttitor
feugiat lectus, et
iaculis metus iaculis et.
Integer sed sapien lacus.
Ut imperdiet ac risus a
pulvinar.Nunc laoreet
vitae urna ut pulvinar.
Ut porta tempor congue.
Aenean ante turpis,
mollis ut lectus nec,
ultrices dignissim
turpis. Nullam at
porttitor quam. Praesent
et nulla ullamcorper,
venenatis tellus et,
lobortis leo. Aliquam in
interdum sapien. Nunc sit
amet nisl ligula.
Suspendisse quis neque
vel risus dictum
fringilla. Ut euismod ex
libero, at ultricies nisl
gravida id. Aliquam nec
luctus mauris. Mauris ac
orci mauris. Ut fringilla
dictum tellus sit amet
laoreet. Nam neque odio,
semper non consequat
vitae, molestie eget
lectus. Curabitur massa
erat, consectetur sit
amet viverra non,
pellentesque quis dolor.
Etiam nisi turpis,
vulputate a augue id,
venenatis gravida
turpis.Morbi rutrum
vehicula nisi, id
hendrerit justo hendrerit
quis. Ut dictum mauris ut
neque ornare luctus.
Praesent non sollicitudin
ipsum, ac ullamcorper
lectus. Vestibulum
finibus ipsum nec leo
gravida auctor. Donec in
magna dolor. Vestibulum
mattis efficitur nisi, at
mattis nisi tempus quis.
Lorem ipsum dolor sit
amet, consectetur
adipiscing elit.Praesent
sed justo ac odio aliquam
posuere ut sed neque.
Nunc iaculis arcu non
velit viverra consectetur
vel eu odio. Cras sed
aliquet est. Cras laoreet
id orci vitae
pellentesque. In ipsum
augue, commodo sit amet
bibendum non, convallis
non libero. Nunc 
ultricies nunc vulputate,
dictum tortor vel,
commodo ligula. Quisque
ornare justo sed neque
rhoncus feugiat.Curabitur
sed lacus tellus.
Praesent eu malesuada
sem.
```

---