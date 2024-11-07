---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 13 - Manipulating String"
size: 16:9
paginate: true
---

# Manipuasi String

- Deklarasi string
- Ukuran dari String
- Mencopy Strings
- Membaca string dengan scanf()
- gets() and puts() functions

---

# Apa itu String?

> String adalah array karakter dengan akhiran \0 yang menandakan akhir dari string

---

# Deklarasi String

- character array

```c
char arr_str[6] = {
    'H', 'e', 'l', 'l', 'o','!'};
```

- character string -> terdapat \0 di akhir character array

```c
char arr_str[6] = {
    'H', 'e', 'l', 'l', 'o','!','\0'};
```

- character array from string constant
  string constan adalah karakter-karakter di dalam "" dimana \0 akan ditambahkan secara otomatis di akhir string

```c
char arr_str[7] = {"hello!"};
\\ \0 diakhir sehingga array sizenya 7
```

---

- unsized array -> kita bisa menambahkan string constant ke array tanpa menulis ukuranya. compiler akan menentukan ukuran array secara otomatis

```c
char str[]= "Hello gengsu!";
```

- Char pointer with string constant

```c
char *ptr_str= "Hello gengsu!";
```

> inisialisasi pointer char dengan first memory address dari string

##### Tidak Boleh Assign Character constant ke pointer, karena character constant bukan array

```c
char *ptr_str;
ptr_str = 'x'
// tapi kalau dereferencenya boleh
*ptr_str = 'x'
```

---

# Inisialisasi

```c
#include <stdio.h>

int main()
{
    char str1[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'};

    char str2[] = "Hello, World!";
    char *ptr_str;

    for (int i = 0; str1[i]; i++)
        printf("%c", str1[i]);
    printf("\n");

    for (int i = 0; str2[i]; i++)
        printf("%c", str2[i]);
    printf("\n");

    ptr_str = str2;
    for (int i = 0; *ptr_str; i++)
        printf("%c", *ptr_str++);

    return 0;
}
```

---

# strlen()

:pushpin: Menghitung panjang dari suatu string tanpa null terminator(\0)

> strlen(const char \*s);

---

# Contoh

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'};

    char str2[] = "Hello, World!";
    char *ptr_str;

    printf("%zu", strlen(str1));
    printf("\n");

    printf("%zu", strlen(str2));
    printf("\n");

    ptr_str = str2;
    printf("%zu", strlen(ptr_str));

    return 0;
}
/*
17
13
13%                                                             */
```

---

# strcpy()

:pushpin: Memcopy string dari satu array ke array lain termasuk null terminator(\0)

> strcpy(char \*dest, const char \*src);

---

# Example

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "Gengsuishere";
    char dest[sizeof(src) + 1];
    strcpy(dest, src);

    printf("Copied using strcpy: %s\n", dest);

    for (int i = 0; src[i]; i++)
        dest[i] = src[i];

    printf("Copied using for loop: %s\n", dest);
    return 0;
}
```

---

# gets() and puts()

- gets() untuk menerima input string/banyak karakter dari input stream dgn menambahkan null terminator di akhir.

- puts() untuk menulis/mengirim output string/banyak karakter ke output stream dgn mereplace newline dgn null karakter.
- menggunakan library studio.h

#### gets() dan puts() **tidak aman** karena panjang dari buffer tidak dikontrolsehingga lebih disarankan pakai **fgets** dan **fputs**

---

# Example

```c
#include <stdio.h>

int main()
{
    int i;
    int selisih = 'a' - 'A';
    char str[100];

    gets(str);
    printf("Inputted string: %s\n", str);

    // convert to uppercase string
    for (i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - selisih;
    }
    printf("Uppercase string: \n");
    puts(str);
    return 0;
}
```

---

# Scanf

> :pushpin: scanf() digunakan untuk membaca input dari user sesuai dengan format yang diberikan.

- %d untuk membaca integer
- %f untuk membaca float
- %s untuk membaca string
- %c untuk membaca karakter

---

# Example

```c
#include <stdio.h>

int main()
{
    int x, y;
    char str[100];

    printf("Enter two integers: ");
    scanf("%d"
          "%d",
          &x, &y);

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Your data are:\n");
    printf("Integers: %d %d \n", x, y);
    printf("String: %s \n", str);

    return 0;
}
```

---

# Summary

- A string is a character array with a null character marking the end of the string.
- A string constant is a series of characters enclosed by double quotes.
- The C compiler automatically appends a null character to a string constant that has
  been used to initialize an array.
- You cannot assign a string constant to a dereferenced char pointer.
- The strlen() function can be used to measure the length of a string. This function
  does not count the null character.
- You can copy a string from one array to another by calling the C function
  strcpy().

---

- The gets() function can be used to read a series of characters. This function stops
  reading when the newline character or end-of-file (EOF) is encountered. The func-
  tion adds a null character to the end of the string

- The puts() function sends all characters, except the null character, in a string to
  the stdout, and appends a newline character to the output.
- You can read different data items with the scanf() function by using various format specifiers.
