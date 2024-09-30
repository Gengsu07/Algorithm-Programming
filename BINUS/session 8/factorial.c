/*
 Factorial merupakan perkalian angka positif dari 1 sampai n. Buat program untuk menghitung factorial dengan input integer n dan output hasil factorial.
Contoh:
Input: n=5
Output: 120 (5x4x3x2x1)
*/

#include <stdio.h>

int main()
{
    int n, base, factchain, idx_posisi;
    double output;

    // get input n
    printf("Input: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid Number, please input number greater than 0");
        return 1;
    }
    // estimate total character for storing faktorial chain like (5x4x3x2x1)
    // dan gunakan untuk menentukan ukuran array char
    factchain = n + (n - 1) + 2;
    char docs[factchain];

    docs[0] = '(';
    // inisialisasi angka awal untuk perhitungan
    output = n;

    // inisialisasi index posisi pada array docs
    idx_posisi = 1;

    // loop perkalian n ke n-1 dst sampai n == 1
    for (base = n; base > 0; base--)
    {
        if ((base - 1) > 0)
        {
            // append character faktorial saat ini dan x ke string docs
            idx_posisi += sprintf(&docs[idx_posisi], "%d", base);
            docs[idx_posisi] = 'x';

            // operasi faktorial
            output *= base - 1;
            idx_posisi++;
        }
        // menambahkan 1 di string docs
        else
            idx_posisi += sprintf(&docs[idx_posisi], "%d", base);
    }
    docs[idx_posisi] = ')';
    printf("Output: %.0lf %s", output, docs);
    return 0;
}

/*
Dapatkan input dari user
Cek input jika <=0 maka invalid
Loop menggunakan for untuk setiap angka dalam range yg diperbolehkan
Handle perkalian dan simpan di variable tpi jangan sampai perkalian dengan 0
Menggunakan array untuk menyimpan dokumentasi perkalian faktorial 5x4x3 dst
*/