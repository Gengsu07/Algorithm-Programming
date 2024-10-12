---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 19 -  Understanding Structure"
size: 16:9
paginate: true
---

# Understanding Structure

- Deklarasi dan Mendefinisikan Struct
- Referen Struct Members
- Struct dan Pointers
- Struct dan Function
- Arrays of Structs

---

# Declaring structures

> :brain: array adalah kumpulan data dengan tipe data sejenis, Bagaimana jika tipe datanya berbeda? .Nahh, Structure adalah jawabanya. Kita bisa menyimpan data dengan tipe data yg berbeda dalam struct.

- variabel1,2,3 adalah member dari struct
- deklarasi member harus dalam {}
- harus diakhiri semicolon (;)

```c
struct struct_tag {
data_type1 variable1;
data_type2 variable2;
data_type3 variable3;
...
};
```

---

# Contoh

```c
struct automobile {
    int year;
    char model[8];
    int engine_power;
    float weight;
};
```

---

# Mendefinisikan Struct Variables

> Setelah mendeklarasi struct, kita membuat variable dari struct yg sudah dibuat

```c
struct automobile sedan, pick_up, sport_utility;

// deklarasi dan definisi struct in one go
struct automobile {
    int year;
    char model[8];
    int engine_power;
    float weight;
    } sedan, pick_up, sport_utility;
```

---

# Referen ke Struct member dengan dot (.)

menggunakan data diatas kita bisa mereference seperti
`sedan.year = 2024`

---

```c
#include <stdio.h>

int main(void)
{
    struct computer
    {
        float cost;
        int year;
        int cpu_speed;
        char cpu_type[16];
    } model;

    printf("The type of the CPU inside your computer?\n");
    fgets(model.cpu_type, sizeof(model.cpu_type), stdin);

    printf("The speed (MHz) of the CPU?\n");
    scanf("%d", &model.cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &model.year);

    printf("How much you paid for the computer?\n");
    scanf("%f", &model.cost);

    printf("Here are what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU type: %s", model.cpu_type); // fgets includes the newline character
    printf("CPU speed: %d MHz\n", model.cpu_speed);

    return 0;
}
```

---

`saat model.cpu_type tidak pakai & karena model.cpu_type array sehingga cukup menggunakan nama array untuk merujuk first memory address`

# Output:

```bash
The type of the CPU inside your computer?
Pentium
The speed(MHz) of the CPU?
100
The year your computer was made?
1996
How much you paid for the computer?
1234.56
Here are what you entered:
Year: 1996
Cost: $1234.56
CPU type: Pentium
CPU speed: 100 MHz
```

---

# Initialize Struct

```c
/* 19L02.c Initializing a structure */
#include <stdio.h>

int main(void)
{
    struct employee
    {
        int id;
        char name[32];
    };

    /* structure initialization */
    struct employee info = {
        1,
        "B. Smith"};

    printf("Here is a sample:\n");
    printf("Employee Name: %s\n", info.name);
    printf("Employee ID #: %04d\n\n", info.id);

    printf("What's your name?\n");
    fgets(info.name, sizeof(info.name), stdin);

    printf("What's your ID number?\n");
    scanf("%d", &info.id);

    printf("\nHere are what you entered:\n");
    printf("Name: %s\n", info.name);
    printf("ID #: %04d\n", info.id);

    return 0;
}
```

---

# Dapat dibuat sekalian saat deklarasi dan definisi diikuti langsung inisialisasi

```c
 struct employee
    {
        int id;
        char name[32];
    } info = {
        1,
        "B. Smith"
        };
```

---

# Struct dan Function Call

> :brain: Kita bisa pass struct ke function dan bisa di return dalam bentuk struct juga

---

#### Contoh

```c
#include <stdio.h>

struct computer
{
    float cost;
    int year;
    int cpu_speed;
    char cpu_type[16];
};

typedef struct computer SC;

SC DataReceive(SC s);

int main(void)
{

    SC model;

    model = DataReceive(model);
    printf("Here are what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU type: %s\n", model.cpu_type);
    printf("CPU speed: %d MHz\n", model.cpu_speed);

    return 0;
}

SC DataReceive(SC s)
{

    printf("The type of the CPU inside your computer?\n");
    fgets(s.cpu_type, sizeof(s.cpu_type), stdin);

    printf("The speed (MHz) of the CPU\n");
    scanf("%d", &s.cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &s.year);

    printf("How much you paid for the computer?\n");
    scanf("%f", &s.cost);

    return s;
}

```

---

`SC DataReceive(SC s)`

- return dari function adalah struct
- argument yg di pass ke function jga struct

###### Output:

```bash
The type of the CPU inside your computer?
Pentium
The speed(MHz) of the CPU?
100
The year your computer was made?
1996
How much you paid for the computer?
1234.56
Here are what you entered:
Year: 1996
Cost: $1234.56
CPU type: Pentium
CPU speed: 100 MHz
```

---

# Refer Structs dengan Pointer

> :brain: Jadi daripada kita mengirimkan semua isi dari struct dan mencopy di dalam suatu function ke struct varibel lain, **KITA BISA REFERENCE/POINTER KE STRUCT ASLINYA**

---

###### Contoh:

```c
/* 19L04.c Pointing to a structure */
#include <stdio.h>

struct computer
{
    float cost;
    int year;
    int cpu_speed;
    char cpu_type[16];
};

typedef struct computer SC;

void DataReceive(SC *ptr_s);

int main(void)
{
    SC model;

    DataReceive(&model);
    printf("Here are what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU type: %s\n", model.cpu_type);
    printf("CPU speed: %d MHz\n", model.cpu_speed);

    return 0;
}

/* function definition */
void DataReceive(SC *ptr_s)
{
    printf("The type of the CPU inside your computer?\n");
    fgets((*ptr_s).cpu_type, sizeof((*ptr_s).cpu_type), stdin);

    printf("The speed (MHz) of the CPU?\n");
    scanf("%d", &(*ptr_s).cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &(*ptr_s).year);

    printf("How much you paid for the computer?\n");
    scanf("%f", &(*ptr_s).cost);
}
```

---

`void DataReceive(SC *ptr_s)`

- argumen function adalah pointer ke struct SC

`DataReceive(&model);`

- passing memory address dari variable struct ke function

`&(*ptr_s).cpu_speed`

- precedence dari member cpu_speed dlu makanya dereference di dalam kurung biar engga error.

---

# Refer Struct Member dengan ->

Khusus Pointer Refer ke Struct maka bisa pakai ->

contoh:

- `(*ptr_s).cpu_type` menjadi `(ptr_s ->cpu_type)`
- `&(*ptr_s).cpu_speed` menjadi `&(ptr_s ->cpu_speed)`
- karena precedence operator -> lebih tinggi dari pada & maka bisa tanpa pakai kurung
- `&(*ptr_s).cpu_speed` menjadi `&ptr_s->cpu_speed`

---

# Array of Structures

> :brain: Kita bisa menyimpan banyak struct ke dalam array

###### deklarasi:

`struct tag_name array_name[array_size];`
`struct MPN penerimaan[1000];`
`typedef struct MPN MPN_data;`

---

```c
/* 19L05.c Arrays of structures */
#include <stdio.h>

struct haiku
{
    int start_year;
    int end_year;
    char author[16];
    char str1[32];
    char str2[32];
    char str3[32];
};

typedef struct haiku HK;

void DataDisplay(HK *ptr_s);

int main(void)
{
    HK poem[2] = {
        {1641, 1716, "Sodo", "Leading me along", "my shadow goes back home", "from looking at the moon"},
        {1729, 1781, "Chora", "A storm wind blows", "out from among the grasses", "the full moon grows"}};

    int i;

    for (i = 0; i < 2; i++)
    {
        DataDisplay(&poem[i]);
    }

    return 0;
}

void DataDisplay(HK *ptr_s)
{
    printf("%s\n", ptr_s->str1);
    printf("%s\n", ptr_s->str2);
    printf("%s\n", ptr_s->str3);
    printf("--- %s\n", ptr_s->author);
    printf("(%d-%d)\n\n", ptr_s->start_year, ptr_s->end_year);
}

```

---

# Nested Structures

> :brain: Kita bisa memasukkab suatu struct ke dalam struct lain

```c
struct y {
    int i;
    char ch[8];
    struct x nested;
};
```

---

```c
/* 19L06.c Using nested structures */
#include <stdio.h>

struct department
{
    int code;
    char name[32];
    char position[15];
};

typedef struct department DPT;

struct employees
{
    DPT dept;
    char name[32];
};

typedef struct employees EMPLY;

void InfoDisplay(EMPLY *ptr);
void InfoEnter(EMPLY *ptr);

int main()
{
    EMPLY info = {
        {1,
        “Marketing”,
        “Manager”},
        1,
        “B.Smith”};
    printf("Here is a sample:\n");
    InfoDisplay(&info);

    InfoEnter(&info);

    printf("\nHere are what you entered:\n");
    InfoDisplay(&info);

    return 0;
}

void InfoDisplay(EMPLY *ptr)
{
    printf("Name: %s\n", ptr->name);
    printf("Dept. Code: %d\n", ptr->dept.code);
    printf("Your position: %s\n", ptr->dept.position);
}

void InfoEnter(EMPLY *ptr)
{
    printf("\nPlease enter your information:\n");
    printf("Your name:\n");
    fgets(ptr->name, sizeof(ptr->name), stdin);

    printf("Your position:\n");
    fgets(ptr->dept.position, sizeof(ptr->dept.position), stdin);

    printf("Dept name:\n");
    fgets(ptr->dept.name, sizeof(ptr->dept.name), stdin);

    printf("Dept code:\n");
    scanf("%d", &(ptr->dept.code));

    printf("Your employee ID #:\n");
    scanf("%d", &(ptr->code));
}


```

---

# Summary

-You can group variables of different types with a data type called a structure.
-The data items in a structure are called members of the structure.

- The struct keyword is used to start a structure declaration or
  a structure variable definition.
- The dot operator(.) is used to separate a structure name and a member name in referencing the structure member.
- The arrow operator(->) is commonly used to reference a structure member using a pointer to the structure.

---

-A structure can be passed to a function, and a function can return a structure back to the caller.

- Passing a pointer that points to a structure when calling a function is more efficient than passing the entire structure as an argument.Also, if a pointer is used, the function can modify the structure’s contents directly.
- Arrays of structures are permitted in C.- You can enclose a structure within another structure.This is called a nested struc - ture
