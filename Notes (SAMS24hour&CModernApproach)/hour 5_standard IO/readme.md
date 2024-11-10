---
marp: true
header: "**C Programming Language**"
footer: "hour 5"
---

# Format Input Output

> :computer: GengsuDev

---

# Standart I/O

> :bulb: all characters and numbers are represented in bits on computers, and a byte is a series of bits. C language treats a file as a series of bytes also called a stream and all file streams equally

- stdin
- stdout
- stderr

> biasanya stdin file stream ke keyboard
> stdout dan stderr file stram ke terminal atau screen

---

# 2 Jenis Input Output

- Formatted I/O
  printf(), scanf()
- Unformatted I/O
  getc(), getch (), getche (), getChar (), gets (),puts (), putchar () dll

---

# Input

- getc(stdin)
  Read 1 char kemudian return as integer. Bisa ditampilkan ke screen atau stdout sesuai format specifier
- getchar()
  Sama seperti getc(stdin) sehingga tidak perlu menspecify argumen
- getch() ---> no echoed, conio.h
- getche() ---> echoed, tidak butuh enter, conio.h

---

# Ouput

- putc(stdout)
  write 1 char ke file stream seperti standart output
- putch
  conio.h
- putchar()
  Sama seperti putc(stdout) sehingga tidak perlu menspecify argumen

---

# Hex Number

> :bulb: base16 terdiri dari angka 0-9 dan a-f

---

Minimum Field Width

> Minimal kolom tampilan jika specifier > len angka

- notasi specifier

---

# Align

> - secara default akan alin ke kanan sehingga menambahkan pad atau space di kiri.
> - gunakan minus untuk membuat menjadi align left atau menambhakan pad atau space di kanan

# Precision

> untuk menspecify presisi/jumlah koma dalam float

---

```c
int main()
{
    int num1 = 12;
    // float f = 3.141593;
    float f = 3.14;

    printf("%6d %-6d \n", num1, num1);
    printf("%06d %-6.3d \n", num1, num1); //.precision tidak berguna buat integer

    printf("%6.2f %-6f \n", f, f);
    printf("%06.2f %-6.2f \n", f, f);
    return 0;
}
```

```bash

    12 12
000012 012
  3.14 3.140000
003.14 3.14

```
