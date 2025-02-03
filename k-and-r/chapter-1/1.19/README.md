
# Exercise 1.19

> Write a function `reverse(s)` that reverses the character string `s`. Use it to write a program that reverses its input a line at a time.

# Solution

- ### Approach

I made a `get_line` function to read all the characters and store in an array until new-line or end-of-file signal is passed, or until the number of characters reaches the set `MAXLINE` buffer limit.

The `reverse` function has two char arrays (strings) as parameter, and copies all the characters of original string to the reversed string, the only exception being new-line. If the orginal string contains new-line (`\n`) as the last character, the reversed string also contains new-line as its last character instead of its first character.

In the `main` function I run a `while` loop and call `get_line` in each iteration. If the length of the string is 0 i.e. the end-of-file signal was passed, the loop breaks and the program ends with an exit status of `0`. Otherwise, the `reverse` function is called and the reversed string is printed as the output.

- ### Code (see `rev-str.c`)

```c
#include <stdio.h>

#define MAXLINE 1000

void get_line(char s[], int limit);
void reverse(char o[], char r[]);

int main()
{
    char input_line[MAXLINE];
    char reversed_line[MAXLINE];

    while (1)
    {
        get_line(input_line, MAXLINE);

        if (input_line[0] == '\0')
        {
            return 0;
        }

        reverse(input_line, reversed_line);
        printf("\nReversed Text: %s", reversed_line);
    }
}

void get_line(char s[], int limit)
{
    printf("\nInput Text: ");

    for (int i = 0; i < limit - 1; i++)
    {
        int c = getchar();

        if (c == EOF)
        {
            s[i] = '\0';
            return;
        }

        s[i] = c;

        if (c == '\n')
        {
            i++;
            s[i] = '\0';
            return;
        }
    }

    s[limit - 1] = '\0';

    while (1)
    {
        int c = getchar();

        if (c == EOF || c == '\n')
        {
            break;
        }
    }
}

void reverse(char o[], char r[])
{
    int o_index = 0;
    while (o[o_index] != '\0')
    {
        o_index++;
    }

    o_index--;

    int new_line = 0;
    if (o[o_index] == '\n')
    {
        o_index--;
        new_line = 1;
    }

    int r_index = 0;
    while (o_index >= 0)
    {
        r[r_index] = o[o_index];
        r_index++;
        o_index--;
    }

    if (new_line)
    {
        r[r_index] = '\n';
        r_index++;
    }

    r[r_index] = '\0';
}
```

- ### Compilation Output

```console
$ gcc -o rev-str rev-str.c

```

No warnings or errors.

- ### Execution Result

#### 1. No Input

```console
$ ./rev-str

Input Text: ^Z
```

#### 2. New Line Input

```console
$ ./rev-str

Input Text: 

Reversed Text: 

Input Text: ^Z
```

#### 3. Simple Input

```console
$ ./rev-str

Input Text: hello, world

Reversed Text: dlrow ,olleh

Input Text: ^Z
```

#### 4. Paragraph Input

```console
$ ./rev-str

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce ac aliquet lectus. Etiam pellentesque feugiat libero non consectetur. Fusce quis consectetur ipsum. Nulla et commodo massa, eget tincidunt nisi. Ut aliquam metus odio, at sagittis dolor tristique non. Vivamus ornare libero turpis, id commodo ante porta a. Duis facilisis, velit nec viverra porttitor, erat turpis tincidunt justo, nec scelerisque turpis augue in metus. Donec risus eros, varius at augue ut, tempus porttitor dolor. Integer mattis odio a suscipit faucibus. Integer laoreet enim at sagittis feugiat. Aliquam id porttitor enim.

Reversed Text: .mine rotittrop di mauqilA .taiguef sittigas ta mine teeroal regetnI .subicuaf tipicsus a oido sittam regetnI .rolod rotittrop supmet ,tu eugua ta suirav ,sore susir cenoD .sutem ni eugua siprut euqsirelecs cen ,otsuj tnudicnit siprut tare ,rotittrop arreviv cen tilev ,sisilicaf siuD .a atrop etna odommoc di ,siprut orebil eranro sumaviV .non euqitsirt rolod sittigas ta ,oido sutem mauqila tU .isin tnudicnit tege ,assam odommoc te alluN .muspi rutetcesnoc siuq ecsuF .rutetcesnoc non orebil taiguef euqsetnellep maitE .sutcel teuqila ca ecsuF .tile gnicsipida rutetcesnoc ,tema tis rolod muspi meroL

Input Text: ^Z
```

#### 5. Multiple Lines Input

```console
$ ./rev-str

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum imperdiet lacinia leo, id facilisis ex. Integer id ex ut augue pretium convallis. Nam pulvinar laoreet lectus eu pharetra. Integer at pretium leo. Quisque consequat massa quis felis ultricies, id porta eros scelerisque. Etiam scelerisque sagittis metus, ut vulputate sapien venenatis eget. Maecenas accumsan condimentum egestas. Aenean in tempor nulla, non posuere ligula.

Reversed Text: .alugil ereusop non ,allun ropmet ni naeneA .satsege mutnemidnoc nasmucca saneceaM .tege sitanenev neipas etatupluv tu ,sutem sittigas euqsirelecs maitE .euqsirelecs sore atrop di ,seicirtlu silef siuq assam tauqesnoc euqsiuQ .oel muiterp ta regetnI .arterahp ue sutcel teeroal ranivlup maN .sillavnoc muiterp eugua tu xe di regetnI .xe sisilicaf di ,oel ainical teidrepmi mulubitseV .tile gnicsipida rutetcesnoc ,tema tis rolod muspi meroL

Input Text: Duis laoreet vehicula felis, vel tincidunt nisl aliquet in. Vivamus ut felis purus. Curabitur sagittis diam vel suscipit lacinia. Fusce eleifend, elit sed rutrum facilisis, risus augue rutrum nisl, quis sodales mi nulla vel turpis. In sed felis pretium, gravida dui nec, malesuada purus. Proin auctor dolor mattis augue tempor varius. Aliquam erat volutpat. Quisque ut magna varius, semper 
libero eu, vehicula mi. In ultricies dictum quam in tincidunt. Vestibulum mattis eleifend ullamcorper. Ut porta quam vitae sollicitudin sollicitudin. Sed tortor elit, porttitor in magna non, cursus ultricies nisi. Aliquam non justo vitae mauris hendrerit pellentesque.

Reversed Text: .euqsetnellep tirerdneh siruam eativ otsuj non mauqilA .isin seicirtlu susruc ,non angam ni rotittrop ,tile rotrot deS .niduticillos niduticillos eativ mauq atrop tU .reprocmallu dnefiele sittam mulubitseV .tnudicnit ni mauq mutcid seicirtlu nI .im alucihev ,ue orebil repmes ,suirav angam tu euqsiuQ .taptulov tare mauqilA .suirav ropmet eugua sittam rolod rotcua niorP .surup adauselam ,cen iud adivarg ,muiterp silef des nI .siprut lev allun im selados siuq ,lsin murtur eugua susir ,sisilicaf murtur des tile ,dnefiele ecsuF .ainical tipicsus lev maid sittigas rutibaruC .surup silef 
tu sumaviV .ni teuqila lsin tnudicnit lev ,silef alucihev teeroal siuD

Input Text: Donec in aliquet ligula, vitae tristique augue. Quisque nisl neque, fermentum id sapien in, scelerisque aliquam odio. Suspendisse felis orci, pharetra ac odio ut, dapibus bibendum purus. Proin quam mi, bibendum accumsan sem nec, fringilla lacinia velit. Sed pharetra dignissim dui faucibus laoreet. Donec fringilla, elit in convallis imperdiet, diam libero ultricies ante, nec gravida risus justo vel nibh. Aenean tristique viverra urna, non dictum mauris. Morbi ac elit felis. Donec id tellus augue. Nulla iaculis, augue sit amet consectetur cursus, mi orci lacinia justo, vel pulvinar quam lacus quis justo. Vivamus imperdiet in justo et pharetra. Fusce arcu diam, egestas eu risus a, eleifend tincidunt lacus. Nunc dictum massa nulla, vitae sagittis risus rhoncus ut. Mauris dignissim, risus in commodo tristique, magna arcu ornare odio, pellentesque vehicula ipsum elit id augue.

Reversed Text: .eugua di tile muspi alucihev euqsetnellep ,oido eranro ucra angam ,euqitsirt odommoc ni susir ,missingid siruaM .tu sucnohr susir sittigas eativ ,allun assam mutcid cnuN .sucal tnudicnit dnefiele ,a susir ue satsege ,maid ucra ecsuF .arterahp te otsuj ni teidrepmi sumaviV .otsuj siuq sucal mauq ranivlup lev ,otsuj ainical icro im ,susruc rutetcesnoc tema tis eugua ,silucai alluN .eugua sullet di cenoD .silef tile ca ibroM .siruam mutcid non ,anru arreviv euqitsirt naeneA .hbin lev otsuj susir adivarg cen ,etna seicirtlu orebil maid ,teidrepmi sillavnoc ni tile ,allignirf cenoD .teeroal subicuaf iud missingid arterahp deS .tilev ainical allignirf ,cen mes nasmucca mudnebib ,im mauq niorP .surup mudnebib subipad ,tu oido ca arterahp ,icro silef essidnepsuS .oido mauqila euqsirelecs ,ni neipas di mutnemref ,euqen lsin euqsiuQ .eugua euqitsirt eativ ,alugil teuqila ni cenoD

Input Text: Nulla in tristique sapien, sit amet lacinia ex. Integer nec dapibus velit, at suscipit nisi. Vestibulum consequat pulvinar magna, sed ullamcorper augue condimentum eu. Curabitur aliquet mollis neque, consectetur tempus eros posuere at. Integer eget scelerisque augue. Praesent ac varius erat, ac pulvinar justo. Vestibulum sollicitudin enim felis. Integer vitae ex nibh. Nulla interdum felis risus.

Reversed Text: .susir silef mudretni alluN .hbin xe eativ regetnI .silef mine niduticillos mulubitseV .otsuj ranivlup ca ,tare suirav ca tnesearP .eugua euqsirelecs tege regetnI .ta ereusop sore supmet rutetcesnoc ,euqen sillom teuqila rutibaruC .ue mutnemidnoc eugua reprocmallu des ,angam ranivlup tauqesnoc mulubitseV .isin tipicsus ta ,tilev subipad cen regetnI .xe ainical tema tis ,neipas euqitsirt ni alluN

Input Text: ^Z
```

#### 6. Buffer Exceeded Input

```console
$ ./rev-str

Input Text: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum efficitur, sapien mollis pharetra aliquam, turpis nibh varius risus, ut accumsan est neque sit amet sapien. In molestie eros neque, at malesuada justo ornare non. Curabitur vel pharetra orci, eget pulvinar ante. Morbi quam massa, lobortis eget mi in, cursus varius libero. Vivamus venenatis ullamcorper augue, et dictum ante porttitor ut. Fusce in cursus ipsum, sed venenatis velit. Sed pulvinar fringilla volutpat. Donec non nisi risus. Maecenas rhoncus fermentum interdum. Integer nibh nibh, fermentum fermentum tortor et, ornare fermentum nibh. In elementum metus in eleifend elementum.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Aenean suscipit tempor tristique. Praesent mollis vitae leo et semper. In sit amet augue et lacus congue pellentesque id in leo. Duis mauris mauris, tempus sed mi nec, sollicitudin malesuada neque. Praesent condimentum diam id ante pulvinar, id tristique sapien tempus. Cras scelerisque leo pellentesque arcu semper hendrerit. Donec id ex et orci dignissim tincidunt. Duis gravida, enim in mollis hendrerit, metus turpis lacinia eros, in cursus ligula eros nec libero. Suspendisse quis enim non purus ullamcorper consequat. Duis cursus, ipsum pulvinar lacinia sagittis, eros elit lobortis ante, at varius risus nunc eget felis. Proin faucibus suscipit turpis. Suspendisse ante tellus, vestibulum id lectus quis, interdum imperdiet turpis. Vestibulum orci.

Reversed Text: euqitsirt di ,ranivlup etna di maid mutnemidnoc tnesearP .euqen adauselam niduticillos ,cen im des supmet ,siruam siruam siuD .oel ni di euqsetnellep eugnoc sucal te eugua tema tis nI .repmes te oel eativ sillom tnesearP .euqitsirt ropmet tipicsus naeneA ;earuc ailibuc ereusop secirtlu te sutcul icro subicuaf ni simirp muspi etna mulubitseV.mutnemele dnefiele ni sutem mutnemele nI .hbin mutnemref eranro ,te rotrot mutnemref mutnemref ,hbin hbin regetnI .mudretni mutnemref sucnohr saneceaM .susir isin non cenoD .taptulov allignirf ranivlup deS .tilev sitanenev des ,muspi susruc ni ecsuF .tu rotittrop etna mutcid te ,eugua reprocmallu sitanenev sumaviV .orebil suirav susruc ,ni im tege sitrobol ,assam mauq ibroM .etna ranivlup tege ,icro arterahp lev rutibaruC .non eranro otsuj adauselam ta ,euqen sore eitselom nI .neipas tema tis euqen tse nasmucca tu ,susir suirav hbin siprut ,mauqila arterahp sillom neipas ,ruticiffe mulubitseV .tile gnicsipida rutetcesnoc ,tema tis rolod muspi meroL
Input Text: ^Z
```

Only the first 1000 characters were reversed and printed, which was the set `MAXLINE` limit.

---