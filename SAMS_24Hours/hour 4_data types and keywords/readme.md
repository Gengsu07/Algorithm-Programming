---
marp: true
theme: default
paginate: true
header: "**C Programming Language**"
footer: "_hour 4_"
---

<!--
_paginate: false
-->

![w:200](../../media/logo.png)

# Tipe Data dan Keywords

> :bulb: Sugeng Wahyudi

---

<!-- _backgroundColor: white -->

# Tipe data dalam C

• char
• int
• float  
• double

---

# Reserve Keyword

|          |        |        |        |        |          |         |       |          |        |
| -------- | ------ | ------ | ------ | ------ | -------- | ------- | ----- | -------- | ------ |
| auto     | break  | case   | char   | const  | continue | default | do    | double   | else   |
| enum     | extern | float  | for    | goto   | if       | int     | long  | register | return |
| short    | signed | sizeof | static | struct | switch   | typedef | union | unsigned | void   |
| volatile | while  |

---

# Tipe data Char

> :bulb: Char merupakan representasi dari angka ASCII sehingga dapat dicetak ke dalam tipe data lain seperti angka

- char merupakan tipe data untuk 1 karakter.
- gunakan char untuk deklarasi variabel
- gunakan single quote untuk membuat char
- format specifier %c untuk menampilkan karakter
- contoh:

```c
char c = 'a'; // a adalah karakter
printf("variabel c adalah char: %c", c) //ouput a
printf("huruf a adalah sama dengan angka: %d", c)
//the output is 97
```

---

# String

> Pada dasarnya tidak ada tipe data string, namun kita bisa menggunakan array dari character misal char[40]

- untuk mendapatkan input menggunakan fungsi seperti scanf kita dapat menggunakan format specifier %s

---

# Tipe Data Integer

- format specifier %d

```c
int x,y=10;
x=20;
printf("nilai dari x adalah: %d\n", x); //output 20
```

---

# Tipe Data Float

- biasanya 4 bytes : 32bits
- format specifier %f
- default 6 angka dibelakang koma
- hasil perhitungan secara default akan sesuai tipe data awal sehingga untuk mendapatkan hasil perhitungan pecahan/float harus melakukan casting implicit ataupun explicit

```c
float x,y=10.5;
x=20;
printf("nilai dari x adalah: %f\n", x); //output 20.000000
```

---

### Integer VS Float Division

```c
#include <stdio.h>

int main(){
    int int_num1, int_num2, int_num3; /* Declare integer variables */
    float flt_num1, flt_num2, flt_num3; /* Declare floating -point variables */

    int_num1 = 32 / 10; /* Both divisor and dividend are integers */
    flt_num1 = 32 / 10;
    int_num2 = 32.0 / 10; /* The divisor is an integer */
    flt_num2 = 32.0 / 10;
    int_num3 = 32 / 10.0; /* The dividend is an integer */
    flt_num3 = 32 / 10.0;

    printf("The integer divis. of 32/10 is: %d\n", int_num1);
    printf("The floating-point divis. of 32/10 is: %f\n", flt_num1);
    printf("The integer divis. of 32.0/10 is: %d\n", int_num2);
    printf("The floating-point divis. of 32.0/10 is: %f\n", flt_num2);
    printf("The integer divis. of 32/10.0 is: %d\n", int_num3);
    printf("The floating-point divis. of 32/10.0 is: %f\n", flt_num3);
    return 0;
}
```

---

> :bulb: jadi perhitunhan terhadap integer secara default akan menghasilkan integer juga, oleh karena itu untuk membuat menjadi float kita harus men casting minimal salh satu dari variable dan menyimpannya ke variable float

---

# Tipe Data Double

> :bulb: memiliki ukuran 2x dari float

- format specifier %lf atau %zu untuk unsigned long

---

# Scientific Notation

- format specifier "%e" atau "%E"
- terdiri atas mantisaeexponent
- contoh
  500 => 5e2
  -300 => -3e2
