# Forum

## 1. Text Analysis

Buat program untuk menghitung frekuensi huruf pada input string
Contoh:
Input: Bina Nusantara
Output: a=4, b=1, c=0, d=0, etc.
##Jawaban:
Berikut adalah penjelasan sederhana untuk menyelesaikan soal diatas:

- menerima input berupa character string
- Melakukan pengecekan untuk setiap karakter dalam string sampai sebelum null terminator
- Increment array yang digunakan untuk mencatat jumlah kemunculan
- Tampilkan ke layar yang memiliki kemunculan lebih dari 0

```c
#include <stdio.h>

void TextAnalyser(const char *str, int *count)
{

    while (*str) // check selagi belum null terminator
    {
        if (*str != ' ' && *str != '\n') // cek jika bukan character spasi
            count[*str]++;               // increment jumlah kemunculan character

        str++; // increment ke character selanjutnya
    };
}

int main()
{
    char input[256];      // asumsi jumlah input maximal 255 character
    int count[256] = {0}; // asumsi counter untuk semua huruf

    printf("Input: ");
    fgets(input, 300, stdin); // read input maksimal 300 character

    TextAnalyser(input, count);
    printf("Output: ");
    for (int i = 1; i < 256; i++)
        if (count[i] > 0 && i != ' ')
            printf(" %c=%d ", i, count[i]);
    printf("\n");
    return 0;
}
```

![alt text](<Screenshot 2024-09-28 at 14.59.38.png>)

## 2. Removing Particular Word

Buat program yang menerima input kalimat serta kata. Gunakan fungsi dari string.h seperti strcmp dan strcpy untuk membuang kata tertentu dalam suatu kalimat. Gunakan fungsi strok untuk menghitung jumlah kata pada awal kalimat dan jumlah kata setelah kata tertentu dibuang dalam kalimat.

Untuk menyelesaikan masalah tersebut, berikut adalah langkah sederhana yang harus dilakukan:

- Menerima input kalimat dan kata yang ingin dihilangkan
- Melakukan tokenisasi terhadap kalimat
- Melakukan pengecekan tiap token apakah sama dengan yang akan dihilangkan
- Jika tidak sama maka concat token ke hasil dan tambahkan spasi
- Tampilkan hasil ke layar

```c
#include <stdio.h>
#include <string.h>

void remove_word(char *words, const char *toremove, char *result, int *count, int *count_aftr)
{
    char *token;
    token = strtok(words, " "); // split kalimat sesuai kata yg ingin dihilangkan

    while (token != NULL) // cek jika token tidak null

    {
        (*count)++; // increment jmlh kata sebelum dihilangkan
        // cek token selanjutnya apakah null yg berarti terakhir
        char *next_token = strtok(NULL, " ");
        // bandingkan token dengan kata yg ingin dihilangkan. jika tidak sama dengan 0 alias beda
        if (strcmp(token, toremove) != 0)
        {
            // concat ke array result
            strcat(result, token);
            (*count_aftr)++;
            if (next_token != NULL)
                strcat(result, " ");
        }
        token = next_token;
    }
}

int main()
{
    // deklarasi untuk menampung kalimat, kata, hasil, dan count dari kata sebelum dan sesudah
    char kalimat[300], kata[50], result[300];
    int charsum_bfr = 0, charsum_aftr = 0;
    result[0] = '\0'; // inisialisasi hasil sementara

    // menerima input kalimat dan kata
    printf("Masukkan kalimat anda: \n");
    fgets(kalimat, sizeof(kalimat), stdin);
    printf("Masukkan kata yg ingin dihilangkan: ");
    fgets(kata, sizeof(kata), stdin);

    // menghilangkan newline dari kata
    kata[strcspn(kata, "\n")] = '\0';

    // melakukan proses penghilangan kata
    remove_word(kalimat, kata, result, &charsum_bfr, &charsum_aftr);

    // menampilkan hasil
    printf("Jumlah kata sebelum %s dihilangkan: %d\n", kata, charsum_bfr);
    printf("Jumlah kata setelah %s dihilangkan: %d\n", kata, charsum_aftr);
    printf("Setelah %s dihilangkan: \n%s", kata, result);

    return 0;
}
```

## ![alt text](<Screenshot 2024-09-28 at 16.45.19.png>)

# FAQ Fitten

# Question

explain me strcmp and strok in c

# Answer

Certainly! Let's break down the functions `strcmp` and `strtok` in C:

### `strcmp`

The `strcmp` function is used to compare two strings. It is declared in the `<string.h>` header file.

**Syntax:**

```c
int strcmp(const char *str1, const char *str2);
```

**Parameters:**

- `str1`: A pointer to the first string.
- `str2`: A pointer to the second string.

**Return Value:**

- It returns an integer value:
  - **Less than 0**: If `str1` is less than `str2`.
  - **0**: If `str1` is equal to `str2`.
  - **Greater than 0**: If `str1` is greater than `str2`.

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "banana";

    int result = strcmp(str1, str2);
    if (result < 0) {
        printf("'%s' is less than '%s'\n", str1, str2);
    } else if (result > 0) {
        printf("'%s' is greater than '%s'\n", str1, str2);
    } else {
        printf("'%s' is equal to '%s'\n", str1, str2);
    }

    return 0;
}
```

'apple' is less than 'banana'

### `strtok`

The `strtok` function is used to tokenize a string into smaller segments or tokens based on specified delimiters. It is also declared in the `<string.h>` header file.

**Syntax:**

```c
char *strtok(char *str, const char *delim);
```

**Parameters:**

- `str`: The string to be tokenized. On subsequent calls, it should be `NULL`.
- `delim`: A string containing all delimiter characters.

**Return Value:**

- It returns a pointer to the first token found in the string. If there are no more tokens, it returns `NULL`.

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! Welcome to C programming.";
    char *token;

    // Get the first token
    token = strtok(str, " ,.!");

    // Walk through the tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.!"); // Get the next token
    }

    return 0;
}
```

Result: `Hello
world
Welcome
to
C
programming
`

---

This example tokenizes the string `str` using delimiters like space, comma, period, and exclamation mark, and prints each token on a new line.

I hope this helps you understand `strcmp` and `strtok` in C! Let me know if you have any further questions.
