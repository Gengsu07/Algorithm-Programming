---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 11 -Pointers"
size: 16:9
paginate: true
---

# Pointers

> :brain: Pointer adalah variabel yang menyimpan alamat memori dari suatu variabel lain.
> :zap: Pointer memiliki left value (memory address pointer itu sendiri) dan right value (content yg merupakan memory addres variabel lain)

1. Deklarasi \*ptr
2. Inisiasi ptr = &variablelain
3. dereference(akses) \*ptr

---

# Deklarasi \*ptr

> :zap: & -> address-of operator, untuk mendapatkan alamat memori dari suatu variabel

###### multiple pointer dapat merujuk e memory location yng sama

```c
int x = 10;
int *ptr = &x;
int *ptr2;
ptr2 = &x;
```

---

# Dereference(akses) \*ptr

###### update _ptr == merubah nilai variabel yg direferensikan karena _ merujuk ke yg memory addresnya sudah di assignment

> :point_right: \* -> dereference operator, untuk mengakses nilai dari alamat memori yang di-point ke

```c
int x = 10;
int *ptr = &x;
int y = *ptr; // y = 10
*ptr = 20; // x,y = 20
```

---

# Pointer as Argument

> :point_right: Pointer dapat dijadikan sebagai argumen pada fungsi untuk membuat fungsi yang dapat mengubah nilai variabel lain atau melakukan perubahan tanpa menyalin nilai dari variabel asal (call by reference)

```c
void functionx(int *ptr) {
    *ptr = *ptr + 100;
}

int main(void) {
    int i = 100;
    int *p = &i;

    printf("i = %d\n", i); // Outputs: i = 100
    functionx(p);
    printf("i = %d\n", i); // Still outputs: i = 100
    return 0;
}
```

---

```c
*ptr = *ptr + 100;
```

**Explanation:**

- \*ptr di kanan untuk men dereferen nilai dari alamat memori yang di-point ke yaitu p yang mana berisi memory address dari i sehingga bernilai 100
- \*ptr berfungsi untuk assingment bahwa nilai di alamat memori yang di-point ke yaitu p ke nilai i ditambah 100

---

## Find Largest and Smaller Numbers

```c
#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min);
int main(void)
{
    int b[N], i, big, small;
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);
    max_min(b, N, &big, &small);
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);
    return 0;
}
void max_min(int a[], int n, int *max, int *min)
{
    int i;
    *max = *min = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > *max)
            *max = a[i];
        else if (a[i] < *min)
            *min = a[i];
    }
}
```

---

## Constant Pointers

Constant Pointer (const setelah \*)  Merupakan constant pointer sehingga memory address yang telah di assign tidak bisa dirubah. Namun nilai/content dari alamat yang dituju pointer dapat dirubah. Implementasi ini terdapat dalam kode A sehingga nilai x bisa beruah menjadi 6

```c
#include int main(){
    int x = 5;
    int * const ptr = &x;
    ++(*ptr); // not error because the value pointed to can be changed but the memory address cannot be changed
    printf("%d", x);

    getchar();
    return 0;
}
```

---

Pointer to Constant (const sebelum \*) Merupakan pointer yang **merefer ke constant variabel** sehingga **nilai/content dari constant tersebut tidak bisa dirubah** namun **memory address yang dituju dapat dirubah**. Implementasi ini terdapat dalam kode B sehingga nilai dari x tidak bisa dirubah tetap 5

```c
#include int main(){
  int x = 5, y=10;
  int const * ptr = &x;
  ++(*ptr); // error: incrementing constant value
  ptr = &y; // not error because the memory address can be changed, but the value pointed to cannot be changed
  printf("%d", x);

  getchar();
  return 0;
}
```

---

# Pointer Decays

> :point_right: Pointer decay adalah ketika array dijadikan pointer.

```c
int main() {

    int arr[10];
    for (int i = 0; i < 10; i++) {
      scanf("%d", &arr[i])
    }
  return 0;
}

```

---

- didalam array, **nama array adalah pointer ke memory address elemen pertama dari array.**
  sehingga arr adalah pointer ke memory address arr[0].
- untuk menuju elemen array bisa menggunakan arrayname[index elemen].
- Tapi untuk mendapatkan memory address dari elemen array, harus dengan **&arrayname[index elemen]**.
  Tidak bisa dnegan arrayname[index elemen] karena
  `arrayname[index elemen] = *(arrayname + index elemen)`
- &arraynama adalah memori address dari array itu sendiri, bukan elemen array pertama.

---

```c
while (*a != 0) // Valid dereference of the first element.
    a++; // Attempting to increment the array name 'a'.
```

However, you cannot increment an array name directly because it is not a modifiable lvalue. An array name itself represents a constant pointer to the first element of the array. You cannot change it as you would with a pointer.

Correct Approach with a Pointer: If you want to traverse the array, you should use a pointer pointing to the array. Increment this pointer to move through the array, not the array name itself.

```c
char *p = a; // Use a pointer to traverse the array
    while (*p != 0) { // Dereference the pointer
        printf("%c", *p); // Print the character pointed to by p
        p++; // Move to the next character
    }
```

---

# Pointer Return as Values

> :point_right: Pointer dapat dijadikan return value dari fungsi.

```c
int *max(int *a, int *b){
if (*a > *b)
  return a;
else
  return b;
}
```

**JANGAN RETURN POINTER KE lOCAL VARIABLE FUNCTION**

```c
int *f(void){
int i;
• • •
return &i; // Error: returning pointer to local variable
}
```

---

# Pointer poin to Array Element

```c
int *find_middle(int a[], int n) {
return &a[n/2];
}
```

---

- A pointer is a variable whose value points to another variable.
- A variable declared in C has two values: the left value and the right value.
- The left value of a variable is the address; the right value is the content of
  the variable.
- The address-of operator (&) can be used to obtain the left value (address) of
  a variable.
- The asterisk (\*) in a pointer declaration tells the compiler that the variable is a
  pointer variable.

---

- The dereference operator (\*) is a unary operator; as such, it requires only
  one operand.
- The \*ptr_name expression evaluates to the value pointed to by the pointer variable
  ptr_name, where ptr_name can be any valid variable name in C.
- If the pointer variable’s right value has been assigned the value 0, the pointer is a
  null pointer. A null pointer cannot point to valid data.
- You can update the value of a variable referred by a pointer variable.
- Several pointers can point to the same location of a variable in the memory.
