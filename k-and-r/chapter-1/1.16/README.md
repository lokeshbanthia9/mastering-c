
# Exercise 1.16

> Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.

- ### Original Code (see `initial.c`)

```c
#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
```

# Solution

- ### Approach

To print the length of the longest line in the input, we need to read the characters from the input even after the `MAXLINE` buffer has been reached. I keep on reading the characters after the buffer limit and increment the length by one, but do not store the character in the line array. If a line is input longer than the set `MAXLINE` buffer, the length of the line is printed accurately (until integer maximum value is reached), but the string printed only shows the first `MAXLINE` characters.

- ### Code (see `final.c`)

```c
#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("Longest Line length - %d\n%s\n", len, longest);
    }
    else
    {
        printf("No characters were input.\n");
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i;

    for (i = 0; i < lim - 1; i++)
    {
        int c = getchar();

        if (c == EOF)
        {
            s[i] = '\0';
            return i;
        }

        s[i] = c;

        if (c == '\n')
        {
            i++;
            s[i] = '\0';
            return i;
        }
    }

    s[i] = '\0';

    while (1)
    {
        int c = getchar();

        if (c == EOF)
        {
            return i;
        }

        i++;

        if (c == '\n' || i == INT_MAX)
        {
            return i;
        }
    }
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
```

- ### Compilation Output

```console
$ gcc -o final final.c

```

No warnings or errors.

- ### Execution Result

#### 1. No Input

```console
$ ./final
^Z
No characters were input.
```

#### 2. New Line Input

```console
$ ./final
    
^Z
Longest Line length - 1

```

#### 3. Simple Input

```console
$ ./final
hello, world
^Z
Longest Line length - 13
hello, world
```

#### 4. Multiple Lines

```console
$ ./final
hello,
my name is
Lokesh Banthia
^Z
Longest Line length - 15
Lokesh Banthia
```

#### 5. Paragraph Input

```console
$ ./final
In the vast and ever-evolving world of technology, the role of computer science continues to expand, shaping industries, economies, and societies in unprecedented ways. From artificial intelligence to 
cybersecurity, from software development to data analytics, the field offers endless opportunities for innovation and problem-solving. As businesses and organizations increasingly rely on digital infrastructure, the demand for skilled professionals who can design, optimize, and maintain complex systems grows exponentially. Programming languages like Python, JavaScript, C++, and Java have become fundamental tools for developers, enabling them to build applications, automate tasks, and analyze vast amounts of data efficiently. Meanwhile, advancements in machine learning and artificial intelligence 
have paved the way for smart applications that can recognize patterns, predict outcomes, and enhance decision-making processes across various sectors, including healthcare, finance, and entertainment. 
The gaming industry, too, has seen a significant transformation, with esports becoming a global phenomenon, attracting millions of players and spectators worldwide. Games like Rocket League and Valorant exemplify how technology has revolutionized entertainment, blending high-speed action with strategic gameplay and fostering competitive communities. As students dive into computer science, practical 
learning through projects proves to be one of the most effective methods of mastering concepts. Building applications, developing algorithms, and solving real-world problems not only reinforce theoretical knowledge but also enhance problem-solving skills. Data structures and algorithms (DSA) play a crucial role in writing efficient code, allowing programmers to optimize performance and scalability. 
Mastery of fundamental structures such as arrays, linked lists, stacks, queues, trees, and graphs enables developers to tackle complex challenges, whether in software engineering, artificial intelligence, or game development. With an Intel i3 10th generation processor, aspiring developers can still experiment with coding, run simulations, and engage in various programming exercises, although more demanding tasks like machine learning training might require more powerful hardware. However, with cloud computing and remote servers, even high-performance computing tasks can be executed without the need for expensive local machines. Open-source platforms like GitHub have further democratized software development, allowing individuals to collaborate, share code, and contribute to global projects. By uploading code repositories and engaging with the community, developers can gain valuable feedback, improve their skills, and participate in real-world projects. Discord bots, for instance, provide a 
practical way to apply programming skills, automate server tasks, and create interactive experiences for users. The accessibility of online resources, tutorials, and coding platforms has made it easier than ever for students to embark on their coding journey, whether through structured courses or self-paced learning. The future of computer science is boundless, with emerging fields such as quantum computing, blockchain, and the Internet of Things (IoT) promising new breakthroughs that could redefine the way humans interact with technology. As the digital landscape continues to expand, those who embrace lifelong learning and adapt to evolving technologies will be best positioned to drive innovation and shape the future.
^Z
Longest Line length - 3543
In the vast and ever-evolving world of technology, the role of computer science continues to expand, shaping industries, economies, and societies in unprecedented ways. From artificial intelligence to 
cybersecurity, from software development to data analytics, the field offers endless opportunities for innovation and problem-solving. As businesses and organizations increasingly rely on digital infrastructure, the demand for skilled professionals who can design, optimize, and maintain complex systems grows exponentially. Programming languages like Python, JavaScript, C++, and Java have become fundamental tools for developers, enabling them to build applications, automate tasks, and analyze vast amounts of data efficiently. Meanwhile, advancements in machine learning and artificial intelligence 
have paved the way for smart applications that can recognize patterns, predict outcomes, and enhance decision-making processes across various sectors, including healthcare, finance, and entertain
```

Only the first 1000 characters were printed in the output, which was the set `MAXLINE`.

#### 6. Multiple Paragraph Input

```console
$ ./final
In the vast and ever-evolving world of technology, the role of computer science continues to expand, shaping industries, economies, and societies in unprecedented ways. From artificial intelligence to 
cybersecurity, from software development to data analytics, the field offers endless opportunities for innovation and problem-solving. As businesses and organizations increasingly rely on digital infrastructure, the demand for skilled professionals who can design, optimize, and maintain complex systems grows exponentially. Programming languages like Python, JavaScript, C++, and Java have become fundamental tools for developers, enabling them to build applications, automate tasks, and analyze vast amounts of data efficiently. Meanwhile, advancements in machine learning and artificial intelligence 
have paved the way for smart applications that can recognize patterns, predict outcomes, and enhance decision-making processes across various sectors, including healthcare, finance, and entertainment. 
The gaming industry, too, has seen a significant transformation, with esports becoming a global phenomenon, attracting millions of players and spectators worldwide. Games like Rocket League and Valorant exemplify how technology has revolutionized entertainment, blending high-speed action with strategic gameplay and fostering competitive communities. As students dive into computer science, practical 
learning through projects proves to be one of the most effective methods of mastering concepts. Building applications, developing algorithms, and solving real-world problems not only reinforce theoretical knowledge but also enhance problem-solving skills. Data structures and algorithms (DSA) play a crucial role in writing efficient code, allowing programmers to optimize performance and scalability. 
Mastery of fundamental structures such as arrays, linked lists, stacks, queues, trees, and graphs enables developers to tackle complex challenges, whether in software engineering, artificial intelligen

banth@LAPTOP-2CH4GD63 MINGW64 /c/personal/dev/mastering-c/k-and-r/chapter-1/1.16 (main)
$ ./final
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum quis pellentesque quam. Proin at nisl eget quam ornare ornare ac ac ipsum. Integer mollis mi vel dui mattis, quis sodales elit suscipit. Duis in elementum libero. Integer a varius ante, id lobortis purus. Etiam id consequat ex, non venenatis magna. Nulla at odio semper, scelerisque ipsum vitae, iaculis diam. Suspendisse pellentesque massa dolor, quis convallis lacus volutpat eu. Duis venenatis congue est, vitae aliquam urna eleifend vel. Cras dignissim dolor et diam tempus, quis ultrices lacus aliquet. Quisque vel nunc sem. Fusce enim ante, porttitor a ex a, tempor consectetur leo. Praesent lacinia a tortor ac pharetra.

Sed maximus, tortor accumsan tristique vehicula, mauris purus pulvinar mauris, a sodales eros lorem at erat. Sed posuere placerat magna ac pellentesque. Nunc faucibus dolor sit amet diam mollis vulputate vitae quis tortor. Mauris volutpat urna id purus congue, vitae fermentum elit viverra. Vivamus at placerat quam. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis 
egestas. In convallis arcu vel condimentum faucibus. Praesent a leo nec tellus egestas lacinia a non ante. Sed non ante gravida, congue mauris eget, lobortis neque.

Duis fringilla tellus sed massa maximus, elementum elementum nisl euismod. Quisque dictum, nisl ac varius dapibus, sem dolor convallis tellus, nec feugiat augue ex vitae nibh. Integer luctus gravida tellus, nec aliquam nunc aliquet a. Integer condimentum a urna at mollis. Nunc eget mauris eget massa gravida porta sit amet id mauris. Integer dignissim efficitur neque, vitae faucibus dui tempor a. Quisque eget ipsum fringilla, ultrices mi eu, luctus ligula. Vivamus volutpat diam ac mi vehicula, at accumsan lorem molestie.

Suspendisse rhoncus, lectus ac mattis mollis, lorem nulla maximus urna, nec laoreet enim mauris nec erat. Duis et pharetra nunc. Etiam vitae pellentesque felis. Sed porta dui consequat, commodo neque eu, feugiat urna. Duis laoreet aliquam sem vitae cursus. Aenean urna nulla, laoreet semper nibh eget, facilisis blandit libero. Praesent tempor efficitur turpis, a venenatis metus ornare tincidunt.

Vestibulum venenatis odio dolor, sit amet ornare sem tristique sed. Nam auctor, eros non posuere tempor, velit dui efficitur lorem, sed feugiat odio massa vitae ipsum. Donec nec rutrum enim, at pellentesque nunc. Suspendisse potenti. Fusce elementum tellus vitae dui ultrices, vitae convallis metus luctus. Sed a erat ac augue fringilla volutpat. Aenean scelerisque mi id diam fermentum varius. Suspendisse potenti. Aenean ultrices nisl vitae euismod varius. Nulla vel porttitor nibh, congue sodales nunc. Aenean et tristique erat. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec scelerisque placerat enim, non congue turpis vehicula at.

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque non auctor nunc. Nam in aliquam arcu, ut fermentum nisi. Aenean at urna rutrum, ornare arcu ornare, semper nibh. Vivamus convallis 
sed libero nec tincidunt. Maecenas quis feugiat nisi. Praesent nec sem dolor. Suspendisse potenti. Morbi dapibus, enim et gravida posuere, justo augue faucibus nisl, malesuada vehicula libero elit at arcu. Mauris tincidunt malesuada nisi, et rhoncus nisi dictum quis. Phasellus ipsum tortor, sodales eu velit at, vestibulum viverra massa. Nullam pellentesque at lacus nec interdum. Vivamus eget elit sagittis, dictum turpis tempor, rhoncus quam. Etiam hendrerit nisl semper sollicitudin posuere. Aliquam ut aliquam neque. Morbi erat libero, laoreet in fringilla sed, varius sit amet metus.

Maecenas sollicitudin, erat vel semper pellentesque, odio ipsum ultrices ligula, in ullamcorper massa quam vel libero. Sed a augue viverra, ultricies lorem a, maximus elit. Cras imperdiet tincidunt neque, eu imperdiet lacus pharetra non. Nullam aliquam diam mauris, id imperdiet erat placerat et. Proin et nibh tempus, maximus ante quis, ultrices justo. Nullam sed blandit eros. Morbi dictum metus quis diam molestie imperdiet. Suspendisse viverra dolor sapien, quis congue elit rhoncus et. Nullam rutrum viverra augue, at tincidunt nunc suscipit sit amet. Suspendisse efficitur justo a mi egestas dictum. Phasellus tempor tincidunt justo, ac condimentum sapien iaculis sed. Donec vitae congue enim, vel pulvinar orci. Phasellus placerat venenatis magna nec dictum. Vestibulum consequat dignissim lectus 
id ullamcorper. Cras eu cursus erat, a pulvinar turpis.

Vivamus auctor aliquet risus id sollicitudin. In velit elit, vulputate sed sagittis vitae, congue ac leo. Nam faucibus imperdiet felis eu posuere. Aliquam at ligula a tellus tempor sagittis ac eget urna. Fusce ut risus est. Nam orci est, iaculis ac vulputate ac, finibus ut nulla. Quisque finibus nisi turpis, a semper elit semper quis. Donec pretium placerat nunc, a pharetra magna luctus at. Praesent finibus tortor non tincidunt luctus. Duis nec velit semper, porta augue eget, tempus sapien. Mauris sed ultricies orci, vel semper justo. Pellentesque odio turpis, congue et felis ac, interdum feugiat arcu. Integer bibendum sem nec vestibulum scelerisque.

Proin non ultrices leo, ac finibus velit. Duis egestas pretium eleifend. Pellentesque ultrices sagittis euismod. Suspendisse vitae augue leo. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nulla laoreet tortor at arcu lacinia, et consectetur turpis vestibulum. Nullam non dui consectetur, fermentum nibh posuere, sagittis ante. Nulla vitae pretium diam. Vivamus quam tellus, tempus et ligula vitae, fermentum ultrices sem. Quisque non dictum tellus, eget vulputate lectus. Etiam nec enim at lorem tempus blandit. Quisque semper eros augue, at hendrerit nulla pharetra lobortis. Fusce pretium justo vitae mauris vulputate, ac vestibulum nulla lobortis. Nam posuere in sem eget cursus. Ut vulputate est vitae pulvinar maximus.

Cras maximus lorem sed eros elementum, semper dignissim ipsum ultrices. Etiam imperdiet ipsum nunc, non rhoncus magna egestas sit amet. Donec eget dignissim dui. Vestibulum efficitur ultrices est, a aliquam arcu posuere eget. Phasellus vehicula ullamcorper dapibus. Aliquam tempus, odio at euismod ullamcorper, orci erat pretium nulla, id hendrerit elit nisi non nibh. Aliquam est ligula, laoreet in interdum et, varius a purus. Cras velit quam, volutpat nec felis et, venenatis bibendum lorem. Praesent ut ex fermentum, efficitur nunc hendrerit, sodales nibh. Proin odio libero, sodales sit amet tortor quis, auctor feugiat eros. Phasellus in dignissim nulla. Sed sagittis lacinia justo dictum porta. Nullam cursus, ligula id ornare cursus, ante justo mollis quam, ac suscipit tortor erat eu erat. Fusce at pretium justo, in rutrum nisi. Cras accumsan facilisis malesuada. In commodo consequat nisl sit amet interdum.

^Z
Longest Line length - 919
Cras maximus lorem sed eros elementum, semper dignissim ipsum ultrices. Etiam imperdiet ipsum nunc, non rhoncus magna egestas sit amet. Donec eget dignissim dui. Vestibulum efficitur ultrices est, a aliquam arcu posuere eget. Phasellus vehicula ullamcorper dapibus. Aliquam tempus, odio at euismod ullamcorper, orci erat pretium nulla, id hendrerit elit nisi non nibh. Aliquam est ligula, laoreet in interdum et, varius a purus. Cras velit quam, volutpat nec felis et, venenatis bibendum lorem. Praesent ut ex fermentum, efficitur nunc hendrerit, sodales nibh. Proin odio libero, sodales sit amet tortor quis, auctor feugiat eros. Phasellus in dignissim nulla. Sed sagittis lacinia justo dictum porta. Nullam cursus, ligula id ornare cursus, ante justo mollis quam, ac suscipit tortor erat eu erat. Fusce at pretium justo, in rutrum nisi. Cras accumsan facilisis malesuada. In commodo consequat nisl sit amet interdum.
```

---