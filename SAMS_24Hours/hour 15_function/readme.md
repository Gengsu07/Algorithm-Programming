---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 15 - Working with Functions"
size: 16:9
paginate: true
---

# Working with Functions

- Function declarations
- Prototyping
- Values returned from functions
- Arguments to functions
- Structured programming

---

# Deklarasi Fungsi

> :brain: Deklarasi fungsi dan definisi fungsi adalah hal yang berbeda.
> :zap: Deklarasi fungsi cukup dengan bagian kepala fungsi seperti return type nama fungsi dan parameter
> :zap: Sedangkan definisi fungsi adalah detail cara kerja dari suatu fungsi
> Jika definisi fungsi ada sebelum main function maka tidak perlu mendeklarisikan fungsi tersebut.
> Jika function di definisikan tidak diatas main maka perlu buat declaration function di bagian atas

---

# Function Declaration termasuk prototype

```c
data_type_specifier function_name(
data_type_specifier argument_name1,
data_type_specifier argument_name2,
data_type_specifier argument_name3,
.
.
);
```

---

# Contoh

```c
#include <stdio.h>

int function_1(int x, int y);

double function_2(double x, double y)
{
    printf("Inside function 2.\n");
    return x - y;
}
int main()
{
    int x1 = 80;
    int y1 = 10;
    double x2 = 100.123456;
    double y2 = 10.123456;
    printf("Pass function_1 %d and %d.\n", x1, y1);
    printf("function 1 returns %d \n", function_1(x1, y1));
    printf("Pass function_2 %f and %f \n", x2, y2);
    printf("function 2 returns %f \n", function_2(x2, y2));
    return 0;
}

int function_1(int x, int y)
{
    printf("Inside function_1.\n");
    return x + y;
}
```

---

# Prototyping Function

- function with no arguments
- function with fixed number of arguments
- function with variable number of arguments

---

# Function with no arguments

> :brain: fungsi yang tidak membutuhkan input argument
> :zap: void digunakan jika fungsi tidak membutuhkan argument

```c
char x = getchar();
```

---

```c
#include <stdio.h>
#include <time.h>

void GetDateTime(void);
int main()
{
    printf("Before the GetDateTime() function is called.\n");
    GetDateTime();
    printf("After the GetDateTime() function is called.\n");
    return 0;
}
void GetDateTime(void)
{
    time_t now;
    printf("Within GetDateTime().\n");
    time(&now);
    printf("Current date and time is: %s\n", asctime(localtime(&now)));
}
```

---

# time(), localtime(), and asctime()

- The time() function returns the calendar time.

```c
#include <time.h>
time_t time(time_t *timer);
```

- The localtime() function returns the local time converted from the calendar time.

```c
struct tm *localtime(const time_t *timer);
```

- The asctime() function converts the date and time represented
  by tm into a character string..

```c
char *asctime(const struct tm *timeptr);
```

---
