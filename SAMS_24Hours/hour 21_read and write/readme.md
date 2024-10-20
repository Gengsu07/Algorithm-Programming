---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 21 -  Reading and Writing with Files"
size: 16:9
paginate: true

style: |
  .columns {
    display: grid;
    grid-template-columns: repeat(2, minmax(0, 1fr));
    gap: 1rem;
  }
---

# Reading and Writing with Files

- Files and streams
- Opening a file with fopen()
- Closing a file with fclose()
- The fgetc() and fputc() functions
- The fgets() and fputs() functions
- The fread() and fwrite() functions
- The feof() function

---

# File vs Streams

###### File

> perangkat konkret yang akan diajak bertukar informasi seperti disk file, terminal, printer, etc

###### Stream

> adalah aliran data yang akan di transfer dari program ke file dan sebaliknya

- device independent
- two type = textual and binary stream

---

# Buffered I/O

> memory area yang sementara digunakan untuk menyimpan data sebelum di kirim ke tujuan

- data keep in memory until time to save or commit (flushing)
- stream are buffered : hight level I/O(menyimpan data ke disk saat save atau commit)
- unbuffered I/O /low level I/O --selalu menyimpan ke disk

---

# Basic File I/O

- FILE adalah pointer ke sebuah file yg di definisikan di stdio.h
- FILE pointer digunakan stream untuk melakukan operasi I/O
  `FILE *fptr;`

## Open a File

`FILE *fopen(const char *filename, const char \*mode)'
-filename : string nama file yang akan dibuka
-mode : string mode yang menentukan akses file, yaitu:

---

- “r” opens an existing text file for reading.
- “w” creates a text file for writing.
- “a” opens an existing text file for appending.
- “r+” opens an existing text file for reading or writing.
- “w+” creates a text file for reading or writing.
- “a+” opens or create a text file for appending.
- “rb” opens an existing binary file for reading.
- “wb” creates a binary file for writing.
- “ab” opens an existing binary file for appending.
- “r+b” opens an existing binary file for reading or writing.
- “w+b” creates a binary file for reading or writing.
- “a+b” opens or creates a binary file for appending.

---

```c
FILE *fptr;
if ((fptr = fopen(“test.txt”, “r”)) == NULL){
    printf(“Cannot open test.txt file.\n”);
    exit(1);
}
```

`read mode jika file tidak ada akan error dan return null pointer`

---

# Closing a File

- setelah kita selesai melakukan operasi I/O, kita harus menutup stream tersebut dengan `fclose()`

- fclose memastikan data yg ada/tertinggal dalam buffer disimpan dengan melakukan **`flush`** ke data

`int fclose(FILE *stream)`

- stream : pointer ke file yang akan di tutup

---

```c
#include <stdio.h>

enum
{
    SUCCESS,
    FAILED
};
int main(void)
{
    FILE *fptr;
    char filename[] = "test.txt";
    int status = SUCCESS;

    if ((fptr = fopen(filename, "r")) != NULL)
    {
        printf("File opened successfully\n");
        printf("Content dalam fptr: 0x%p\n", (void *)fptr);
        printf("Ready to close the file\n");
        fclose(fptr);
    }
    else
    {
        printf("Error! Could not open file %s\n", filename);
        status = FAILED; // Program exits if file opening fails.
    }

    return status;
}
```

---

# Reading and Writing Disk Files

- one character at a time
- one line of text at a time
- one block of characters at a time

---

<h2 align="center">One Character at a Time</h2>
<div class="columns" style="margin-top: 2rem;">
<div >

`int fgetc(FILE *stream)`

- read the next character from the file stream
- return the character as an integer value
- return EOF if end of file is reached
</div>
<div>
`int fputc(int c, FILE *stream )`

- c adalah integer dari character yang akan disimpan
- integer di konvert ke unsigned char terlebih dlu
- jika berhasil return karakter yg di write, jika false return EOF
- otomatis menuju character selanjutnya

## </div>

---

###### onecharattime.c

```c
void OneCharAtTime(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {
        putc(c, fout);
        putchar(c);
    };

    printf("Ready to close the file\n");
}

```

---

# One Line at a Time

`int fgets(char *s, int n, FILE *stream)`

- read the next line of chunk character from the file stream
- s : character array untuk menyimpan characters dari file yg dibuka
- n : jumlah maksimum elemen dari array
- jika berhasil return pointer s, jika false return NULL
- jika ada `newline` terbaca makan newline tsb akan termasuk
- append nul character at the end of the string

---

`int fputs(const char *, FILE *stream )`

- s adalah character array yang akan ditulis/simpan
- const agar pointer char tidak bisa dirubah oleh fputs
- jika berhasil return zero, jika false return nonzero
- membutuhkan null character at the end of the string agar berhenti (jika input dari fread maka sudah otomatis ditambahkan)
- does not insert newline di akhir, tapi jika ditengah tetap di insert newline

---

###### onelineattime.c

```c
void OneLineAtTime(FILE *fin, FILE *fout)
{
    char charbuffer[90];
    int counter = 1;
    while (fgets(charbuffer, sizeof(charbuffer), fin) != NULL)
    {
        fputs(charbuffer, fout);
        printf("%d| %s\n", counter, charbuffer);
        counter++;
    };

    printf("Ready to close the file\n");
}
```

---

Terlihat bahwa program memproses file chunk by chunk. Namun hasil akhir akan tetap sama dengan file sumber karena newline dll akan semuanya tercopy

```bash
File test.txt opened successfully
1| lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed euismod, sapien ve
2| l malesuada malesuada, velit velit tincidunt sapien, ut luctus velit sapien vel
3|  velit. Donec euismod, sapien vel malesuada malesuada, velit velit tincidunt sa
4| pien, ut luctus velit sapien vel velit. Donec euismod, sapien vel malesuada mal
5| esuada, velit velit tincidunt sapien, ut luctus velit sapien vel velit. Donec e
6| uismod, sapien vel malesuada malesuada, velit velit tincidunt sapien, ut luctus
7|  velit sapien vel velit. Donec euismod, sapien vel malesuada malesuada, velit v
8| elit tincidunt sapien, ut luctus velit sapien vel velit. Donec euismod, sapien
9| vel malesuada malesuada, velit velit tincidunt sapien, ut luctus velit sapien v
10| el velit. Donec euismod, sapien vel malesuada malesuada, velit velit tincidunt
11| sapien, ut luctus velit sapien vel velit. Donec euismod, sapien vel malesuada m
12| alesuada,
Ready to close the file
```

---

# One Block of Characters at a Time

`size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)`

- ptr : pointer ke memory area untuk menyimpan data
- size : ukuran setiap elemen dalam array
- nmemb : jumlah elemen yang akan di read
- jika berhasil return jumlah elemen yang di read, jika false return 0
- jika file pointer berada di akhir file, fread() akan mengembalikan 0
- pastikan memory array yg cukup untuk menyimpan data yg di read

---

`size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)`

- ptr : pointer ke memory area yang akan disimpan
- size : ukuran setiap elemen dalam array
- nmemb : jumlah elemen yang akan di write
- jika berhasil return jumlah elemen yang di write, jika false return 0
- pastikan memory yg cukup untuk menyimpan data yg di write
- tidak menambahkan null character di akhir

`feof`

- mengecek apakah file pointer sudah berada di akhir file
- return true jika sudah berada di akhir file, false jika belum

---

###### oneblockofchars.c

```c
void OneLineAtTime(FILE *fin, FILE *fout)
{

    char charbuffer[MAX_LEN + 1];
    int counter = 1;
    size_t numread;
    while (!feof(fin))
    {
        numread = fread(charbuffer, sizeof(charbuffer), MAX_LEN, fin);

        printf("%d| %s\n", counter, charbuffer);
        fwrite(charbuffer, sizeof(charbuffer), MAX_LEN, fout);
        counter++;
    };
    if (feof(fin))
        charbuffer[numread * sizeof(charbuffer)] = '\0'; // append null character at the end of the string
    fflush(fout);                                        // Ensure all data is written to the file before closing it.

    printf("Ready to close the file\n");
}

```

---

# Summary:

- In C, a file can refer to a disk file, a terminal, a printer, or a tape drive.
- The data flow you transfer from your program to a file, or vice versa, is called a
  stream.
- A stream is a series of ordered bytes.
- Unlike a file, a stream is device independent.
- There are two stream formats: text stream and binary stream.
- The file position indicator in the FILE structure points to the position in a file
  where data will next be read from or written to.
- The fopen() function is used to open a file and associate a stream to the opened
  file.

---

- You can specify different modes for opening a file.
- The fclose() function is responsible for closing an opened file and disassociating
  a stream with the file.
- The fgetc() and fputc() functions read or write one character at a time.
- The fgets() and fputs() functions read or write one line at a time.
- The fread() and fwrite() functions read or write one block of data at a time.
- The feof() function can determine when the end of a file has been reached.
- In a binary file, the feof() function should be used to detect EOF.
  In the next lesson you’ll learn more about disk file I/O in C.
