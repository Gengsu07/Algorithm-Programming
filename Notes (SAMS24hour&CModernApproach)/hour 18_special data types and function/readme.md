---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 18 -  Using Special Data Types and Functions"
size: 16:9
paginate: true
---

# Enum

> An enum is a user-defined data type in C that consists of a set of named integer constants.

##### Penggunanaan

```c
    enum tag_name {enumeration list} variable_list;
```

```c
// deklarasi
enum automobile {sedan, pick_up, sport_utility};

// membuat variable dari enum
enum automobile domestic, foreign;

// bisa juga sekalian dalam satu baris
enum automobile {sedan, pick_up, sport_utility} domestic, foreign;
```

---

# Inisialisasi

> :brain: perinsipnya nilai dari enum adalah integer mulai dari paling kiri 0 dan bertambah satu berurutan ke kanan 0,1,2,3
> :brain: tapi nilai bisa di lakukan inisialisasi dan jika ada nilai yg tidak di iniliasasi maka scr otomatis **akan +1 dari nilai kirinya**

```c
enum automobile {sedan = 60, pick_up = 30, sport_utility = 10};
```

---

Using Enum

```c
#include <stdio.h>
/* main() function */
int main()
{
    enum language
    {
        human = 100,
        animal = 50,
        computer
    };

    enum days
    {
        SUN,
        MON,
        TUE,
        WED,
        THU,
        FRI,
        SAT
    };

    printf("human: %d, animal: %d, computer: %d\n",
           human, animal, computer);
    printf("SUN: %d\n", SUN);
    printf("MON: %d\n", MON);
    printf("TUE: %d\n", TUE);
    printf("WED: %d\n", WED);
    printf("THU: %d\n", THU);
    printf("FRI: %d\n", FRI);
    printf("SAT: %d\n", SAT);
    return 0;
}
```

---

```bash
human: 100, animal: 50, computer: 51
SUN: 0
MON: 1
TUE: 2
WED: 3
THU: 4
FRI: 5
SAT: 6
```

---

```c
#include <stdio.h>

int main()
{
    enum units
    {
        penny = 1,
        nickel = 5,
        dime = 10,
        quarter = 25,
        dollar = 100
    };

    int money_units[5] = {dollar, quarter, dime, nickel, penny};

    char unit_name[5][20] = {
        "dollar (s)",
        "quarter (s)",
        "dime(s)",
        "nickel(s)",
        "penny (s)"};

    int cent, tmp, i;
    printf("Enter a monetary value in cents:\n");
    scanf("%d", &cent); /* get input from the user */
    printf("Which is equivalent to:\n");
    tmp = 0;
    for (i = 0; i < 5; i++)
    {
        tmp = cent / money_units[i];
        cent -= tmp * money_units[i];
        if (tmp)
            printf("%d %s", tmp, unit_name[i]);
    }
    printf("\n");
    return 0;
}
```

---

# typedef

> :brain: typedef adalah sebuah keyword yang digunakan untuk mendefinisikan sebuah tipe data baru berdasarkan tipe data lainnya.

- typedef harus di definisikan sebelum digunakan

```c
typedef data_type sinonym_type;
typedef int two_byte;
// bisa kitaa gunakan
two_byte i,j;
```

##### Why?

- menyederhanakan tipe data kompleks ke yg lebih sederhana sehingga lebih mudah dipahami dan dibaca
- Tidak perlu mengubah setiap line code jika terjadi error, tinggal edit bagian typedef nya saja

---

---

# Recursive Function

---

# Command Line Arguments
