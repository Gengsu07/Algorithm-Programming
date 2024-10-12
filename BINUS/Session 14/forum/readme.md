# Global vs Local

Diberikan program berikut

```c
int num = 50;
void func1() {
  num = 100;
  printf("%d\n",num);
}

int main(int argc, char **argv) {
  func1();
  printf("%d\n",num);
}
```

### Bagaimana cara variabel global dan local pada program tersebut?

Global variable adalah variabel yang dilakukan deklarasi di luar dari suatu function termasuk main function. Global variabel juga disebut dengan Program Scope karena dapat diakses dalam seluruh source files yang digunakan untuk membuat suatu program

Sedangkan Local variable atau bisa disebut dengan Block Scope adalah variabel yang aktif dan dapat diakses hanya dalam block tersebut yang berada diantara curly braces atau {}

dalam konteks program seperti dalam soal tersebut,
`int num = 50;`
pada baris pertama adalah global variable dan bisa diakses di seluruh program namun

```c
void func1() {
  num = 100;
  printf("%d",num);
}
```

num = 100 dalam function1() tersebut adalah local variable atau block scope sehingga variable num yang akandigunakann dalam function tersebut adalah 100.

Oleh karena itu, hasil dari program tersebut adalah melakukan pencetakan nilai num 100 dari dalam function func1 dan num 50 dari global variabel.

## terima kasih

# Function Arguments

Diberikan program untuk penjumlahan berikut

```c
#include <stdio.h>int sumOfElements(int* A, int size) {
   int i, sum=0;
   printf("SOE - size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
   for (i=0; i<size, i++) {
      sum+=A[i];
   }
   return sum;
}

int main() {
   int A[] = {1,2,3,4,5};
   int size = sizeof(A)/sizeof(A[0]);
   int total = sumOfElements(A,size);
   printf("Sum of elements = %d\n", total);
   printf("Main - size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
}
```

# Output:

`SOE - size of A = 4, size of A[0] = 4`

`Sum of elements = 15`

`Main - size of A = 20, size of A[0] = 4`

### Menurut Anda mengapa terjadi perbedaan nilai size of A antara fungsi sumOfEleemts dengan main?

Menurut saya terjadinya perbedaan antara sizeof(A) pada main function dengan sizeof(A) dalam function sumOfElements() adalah terkait dengan **block scope/ local variabel A**.

- Local variable A dalam main function hanya bisa aktif dan diakses di dalam main function, tidak bisa diakses dalam function yang lain.- pada main function, variabel A adalah array integer dengan 5 elemen sehingga sesuai dengan architecture atau komputer yang digunakan dalam contoh sizenya didapatkan dari
  `size 1 integer= 4 bytes dikalikan 5 elemen sehingga total 20 byte`
- pada function sumOfElements() memiliki argumen `int* A` yang merupakan pointer call by reference ke array A di dalam main function. Oleh karena itu, sizeof(A) dalam function sumOfElements() adalah size dari left value pointer atau ukuran dari pointer itu sendiri yaitu 4 bytes biasanya untuk architecure 32bit seperti pada contoh diatas. Terima kasih
