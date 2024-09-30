/*
Text Analysis
Buat program untuk menghitung frekuensi huruf pada input string
Contoh:
Input: Bina Nusantara
Output: a=4, b=1, c=0, d=0, etc.
*/

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

/*
Berikut adalah penjelasan sederhana untuk menyelesaikan soal diatas:
menerima input berupa character string
Melakukan pengecekan untuk setiap karakter dalam string sampai sebelum null terminator
Increment array yang digunakan untuk mencatat jumlah kemunculan
Tampilkan ke layar yang memiliki kemunculan lebih dari 0
*/