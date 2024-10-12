---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 17 - Allocating Memory"
size: 16:9
paginate: true
---

# Allocating Memory

> :brain: biasaynya kita harus mendeklarasikan ukuran dari suatu array atau compiler mencari tau dari unsized array.
> :zap: Kita akan belajar mengalokasikan memory secara dinamis saat runtime menggunakan

- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

---

# `malloc()`

> :zap: Mengalokasikan spesifik memory size

- `void *malloc(size_t size);`
- malloc return void pointer
- jika fail return null pointer, biasanya karena memory tidak cukup
- **selalu check return dari malloc != NULL**
  `if (ptr_str != NULL){}`

---

```c
/* 17L01. Using the malloc function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* function declaration */
void StrCopy(char *str1, char *str2);
/* main() function */
int main()
{
    char str[] = "Use malloc() to allocate memory.";
    char *ptr_str;
    int result;
    /* call malloc() */
    ptr_str = malloc(strlen(str) + 1);
    if (ptr_str != NULL)
    {
        StrCopy(str, ptr_str);
        printf("The string pointed to by ptr_str i\n%s\n",
               ptr_str);
        result = 0;
    }
    else
    {
        printf("malloc() function failed.\n");
        result = 1;
    }
    return result;
}
/* function definition */
void StrCopy(char *str1, char *str2)
{
    int i;

    for (i = 0; str1[i]; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}

/* function definition */
void StrCopy(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i]; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}
```

---

# free()

> :brain: Program terus bertambah dan semakin kompleks akan membutuhkkan memory yg banyak. Jika hanya mengalokasikan memory tanpa merelease kita akan kehabisan memory.

- Pakai free() untuk merelease memory yang sudah tidak dibutuhkan lagi

---
