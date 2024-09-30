---
marp: true
theme: uncover
header: "**C Programming Language**"
footer: "hour 7 - Loops"
size: 16:9
paginate: true
style: |
  .pink {
      background-color: #f0f;
      }
---

# Loops

> :computer: GengsuDev

---

<!-- _class: pink -->

# While

> Melakukan Loop ketika kondisi masih terpenuhi.

```c
    while (expression)
    {
        statement1;
        statement2;
    }
```

---

##### Contoh:

```c
int c = 1
while (counter < 10)
    {
        printf("%d\n", counter);
        counter++;
    }
```

###### Menampilkan angka 1 s.d. 9

---

<!-- _class: gaia -->

# Do While

> Lakukan 1 kali operasi dulu sebelum pengecekan. Harus di ikuti ; setelahnya

```c

do {
    statement1;
    statement2;
} while(expression);
```

---

##### Contoh:

```c
int counter = 0;
do {
    printf("number: %d",counter);
    counter ++;

} while(counter < 10);
```

###### print angka 0 s.d. 9 (diikuti semicolon)

---

# For

> :bulb: Perulangan untuk jumlah yng sudah diketahui.
>
> - ada 3 expression
> - tiap expression dibatasi semicolon ;

```c
for (exp1; exp2; exp3){
    statement1;
    statement2;
}
```

---

<!-- -->

- expresi 1 : inisialisasi nilai awal
- expresi 2 : conditional expression checking
- expresi 3 : yang dilakukan setelah statement dijalankan

---

###### Contoh

```c
#include <stdio.h>

int main () {
int counter;
for (counter = 1; counter < 10; counter++){
    if (counter%2==0)
        printf("%d: bilangan genap\n", counter);
    else
        printf("%d: bilangan ganjil\n", counter);
}
}
```

###### progran akan mencetak angka 1 s.d. 9 beserta bilangan ganjil atau genap

---

# Complex & Nested For

> di dalam tiap expresi dari 3 komponen expresi bisa terdiri lebih dari satu dengan menambahkan koma (,) sebagai pembatas

```c
for (i = 1, j=10; i<10, j>0; i++, j++)
{
    statement1;
    statement2;
    ...
}
```

---

```c
#include <stdio.h>
int main()
{
    int idx_rows, idx_cols, rows = 9, cols = 9;

    for (idx_rows = 0; idx_rows < rows; idx_rows++)
    {
        if ((idx_rows == 0) || (idx_rows == rows - 1))
        {
            for (idx_cols = 0; idx_cols < cols; idx_cols++)
                printf("*");
        }
        else
            for (idx_cols = 0; idx_cols < cols; idx_cols++)
                if ((idx_cols == 0) || (idx_cols == cols - 1))
                    printf("*");
                else
                    printf(" ");
        printf("\n");
    }
    return 0;
}
```

---

# Null Statement

> :bulb: adalah statement dengan no statement

```c
for (c=0; c<5; c++);
```

Dalam kondisi true pun tidak melakukan apa pun
