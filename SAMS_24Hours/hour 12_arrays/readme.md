---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 12 -Arrays"
size: 16:9
paginate: true
---

# Arrays

- collection variabel with same data type
- deklarasi
  tipe data arrayname[array size]
- index dari 0

---

# Inisialisasi

- Satu per Satu

```c
    day[0] = ‘S’;
```

- Semuanya sekaligus

```c
    int arInteger[5] = {100, 8, 3, 365, 16};
```

---

## Without Initizalization

```c
    int arInteger[5];
```

## Partial Initizalization

> The elements will contain garbage values unless it's a global or static array, where elements will be initialized to 0.

```c
    int arInteger[5] = {100, 8};
```

## Full Initizalization

```c
    int arInteger[5] = {100, 8, 3, 365, 16};
```

---

# Size of Array

```c
 sizeof(int) *arraysize;
```

---

# Array and Pointers

---

# Mutlidimensional Arrays

> data-type arrayname[array size1][array size2]...[array sizen];

```c
 int array_int[2][3] = {1, 2, 3, 4, 5, 6};
 // equivalent to
 array_int[0][0] = 1;
 array_int[0][1] = 2;
 array_int[0][2] = 3;
 array_int[1][0] = 4;
 array_int[1][1] = 5;
```

---

# Unsized Arrays

> :bulb:mendeklarasikan arrays tanpa array size di dimensi pertama

```c
// 1 dimensional
int list_int[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};

// 2 dimesional
char list_ch[][2] = {
‘a’, ‘A’,
‘b’, ‘B’,
‘c’, ‘C’,
‘d’, ‘D’,
‘e’, ‘E’,
‘f’, ‘F’,
‘g’, ‘G’};
```

---

## Ingat HANYA DIMENSI PERTAMA YANG BISA UNSIZED

```c
char list_ch[][2][3]
```

---

# Summary

- An array is a collection of variables that are of the same data type.
- In C, the index to an array starts at 0.
- You can initialize each individual element of an array after the declaration of the
  array, or you can place all initial values into a data block surrounded by { and }
  during the declaration of an array.
- The memory storage taken by an array is determined by multiplying the size of the
  data type and the dimensions of the array.
- A pointer is said to refer to an array when the address of the first element in the
  array is assigned to the pointer. The address of the first element in an array is also
  called the start address of the array.

---

- To assign the start address of an array to a pointer, you can put either the combina-
  tion of the address-of operator (&) and the first element name of the array, or sim-
  ply use the array name on the right side of an assignment operator (=).
- The null character (‘\0’) marks the end of a string. C functions, such as printf(),
  will stop processing the string when the null character is encountered.
- C supports multidimensional arrays, too. An empty pair of brackets (the array sub-
  script operator—[ and ]) indicates a dimension.
- The compiler can automatically calculate the memory space needed by an unsized
  array.
