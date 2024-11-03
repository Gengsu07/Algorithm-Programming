// Constant Pointer and Pointer to a Constant

#include <stdio.h>
int main(void)
{
    int x = 5;
    int *const ptr = &x;
    ++(*ptr);
    printf("%d", x);

    getchar();
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int x = 5;
//     int const *ptr = &x;
//     ++(*ptr);
//     printf("%d", x);

//     getchar();
//     return 0;
// }

/*
Selamat malam bu Novi, izin menjawab terkait perbedaan constant pointer dan pointer to constant dan implementasinya
 Constant Pointer (const setelah *)  Merupakan constant pointer sehingga memory address yang telah di assign tidak bisa dirubah. Namun nilai/content dari alamat yang dituju pointer dapat dirubah. Implementasi ini terdapat dalam kode A sehingga nilai x bisa beruah menjadi 6 #include int main(){
    int x = 5;
    int * const ptr = &x;
    ++(*ptr);
    printf("%d", x);

    getchar();
    return 0;
}
  Pointer to Constant (const sebelum *) Merupakan pointer yang merefer ke constant variabel sehingga nilai/content dari constant tersebut tidak bisa dirubah namun memory address yang dituju dapat dirubah. Implementasi ini terdapat dalam kode B sehingga nilai dari x tidak bisa dirubah tetap 5 #include int main(){
    int x = 5;
    int const * ptr = &x;
    ++(*ptr);
    printf("%d", x);

    getchar();
    return 0;
}Terima kasih
*/

/*
The selected code demonstrates the concept of a constant pointer and a pointer to a constant in C programming.

In this code snippet:

```c
int main()
{
    int x = 5;
    int const *ptr = &x;
    ++(*ptr);
    printf("%d", x);

    getchar();
    return 0;
}
```

- `int x = 5;` declares an integer variable `x` and initializes it with the value 5.
- `int const *ptr = &x;` declares a pointer `ptr` that points to a constant integer. The `const` keyword is used to specify that the value pointed to by `ptr` cannot be modified. The pointer `ptr` is initialized to point to the address of `x` using the address-of operator `&`.
- `++(*ptr);` attempts to increment the value pointed to by `ptr`. However, since `ptr` is a pointer to a constant integer, this operation is not allowed and will result in a compilation error.
- `printf("%d", x);` prints the value of `x`, which remains unchanged since the increment operation failed.

The purpose of this code snippet is to illustrate the difference between a constant pointer and a pointer to a constant in C programming. It demonstrates that a constant pointer cannot be used to modify the value it points to, while a pointer to a constant can be used to point to a constant value.
*/