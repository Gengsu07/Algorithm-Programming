Global vs Local
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

Bagaimana cara variabel global dan local pada program tersebut?

Global variable adalah variabel yang dilakukan deklarasi di luar dari suatu function termasuk main function. Global variabel juga disebut dengan Program Scope karena dapat diakses dalam seluruh source files yang digunakan untuk membuat suatu program

Sedangkan Local variable atau bisa disebut dengan Block Scope adalah variabel yang aktif dan dapat diakses hanya dalam block tersebut yang berada diantara curly braces atau {}

dalam konteks program seperti dalam soal tersebut,

```c
int num = 50;
```

pada baris pertama adalah global variable dan bisa diakses di seluruh program namun

```c
void func1() {
  num = 100;
  printf("%d",num);
}
```

num = 100 dalam function1() tersebut adalah local variable atau block scope sehingga variable num yang akandigunakann dalam function tersebut adalah 100.

Oleh karena itu, hasil dari program tersebut adalah melakukan pencetakan nilai num 100 dari dalam function func1 dan num 50 dari global variabel.

terima kasih
