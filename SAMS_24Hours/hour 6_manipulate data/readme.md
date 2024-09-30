---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 6 - Manipulasi Data"
size: 16:9
style: |
  :root {
    --color-background: #fff;
    --color-foreground: #333;
    --color-highlight: #f96;
    --color-dimmed: #888;
    }
---

<!-- _class: lead -->

# Manipulating Data

> :computer: GengsuDev

---

# Operator

- adalah tanda operasi yang dilakukan terhdapa operand misal +, -,\*,%,/, dst

# Operand

- Object yang dikenai atau dioperaikan seperti 5,4, dst

---

## Operator by jumlah operand

1. unary
   hanya membutuhkan 1 operand (pre/post increment or decrement)
   ```c
    ++x, --x;
    x++, x++;
   ```
1. binary
   membutuhkan 2 operand
   ```c
   hitung = x+y;
   ```
1. ternary
   membutuhkan 3 operand (if else)
   ```c
   hitung = nilai>80?'Lulus':'Tidak Lulus';
   ```

---

<!-- _class: gaia -->

## Operator by Jenis Operasi

1. **assignment (=)**
   mensubmit nilai dari operand kanan operator ke operand kiri operator
   ```c
   x = 10;
   ```
2. **arithmetic**=> melakukan operasi aritmatika
   ```c
   hitung = x+y;
   ```
   ##### _Contoh Kombinasi / shorthand_
   ```c
   x *= x+y; // x = x(x+y)
   X %= y; // x = x%y
   ```

---

3. **relation** => greater than or less than, equal not equal, negasi

   | operator |                     arti |
   | -------: | -----------------------: |
   |       == |                 Equal to |
   |   != Not |                 equal to |
   |        > |             Greater than |
   |        < |                Less than |
   |       >= | Greater than or equal to |
   |       <= |    Less than or equal to |

---

4. **logical**
   AND (&&), OR (||), Negasi (!=)

- And true if true with true
- Or always true except false with false
- negasi lawan dari nilai saat ini

5. **bitwise**
6. **pointer**

---

# Pre/Post Decrement and Increment by One

- Pre
  operator sebelum operand, melakukan operasi terlebih dulu baru assignment.
- Post
  operator setelah operand, operasi dilakukan terakhir.

##### _Konsekuensi_

> Jika terdapat assigmnet (=) maka Pre akan mmengassign nilai baru setelah operasi Sedangkan Post akan mengassign nilai sebelum operasi

```c
int x=10, y,z;
y = ++x; // y=11
z = x++; // y = 10
```

---

# Cast Operator

> melakukan konversi tipe data suatu variable, constant, atau expresi ke tipe data yg diiginkan

```c
int num1=3, num2=2;
float flt1, flt2;

flt1 = float(num1)/num2 // explicit casting
flt2 = num1/1.5 //implicit casting
```
