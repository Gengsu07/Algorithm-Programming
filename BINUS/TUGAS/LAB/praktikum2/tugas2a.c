#include <stdio.h>

/*
Case pada soal jika diatas 100.000 mendapat 1 kupon diskon 5% dan kelipatanya.
Contoh dalam soal jika 100.000 diskon 5% . jika 250.000 menjadi tinggal bayar 225.000
---
Asumsi sesuai contoh soal maka jumlah diskon 5% dikali jumlah kupon yg didapatkan dari nominal pembelian dibagi 100.000
*/

void hitungdiskon(int *ptr_beli)
{
    int base = 100000;

    //  cek pembelian>100.000
    if (*(ptr_beli) >= base)
    {
        // hitung jumlah kupon yang didapatkan
        int kelipatan = *(ptr_beli) / base;
        // hitung total diskon yg didapatkan
        double discount = (0.05 * kelipatan) * *(ptr_beli);
        // hitung jumlah total yang harus dibayar
        double jmlbayar = *(ptr_beli)-discount;

        // tampilkan hasil
        printf("Selamat anda mendapatkan %d lembar kupon\n", kelipatan);
        printf("Total Diskon: %.0lf\n", discount);
        printf("Jumlah yang harus dibayar : %.0lf\n", jmlbayar);
    }
}

int main()
{
    // deklarasi variabel pembelian(tidak mungkin pecahan)
    int pembelian;

    printf("Masukkan Total Pembelian:\n");
    // inisialisasi nominal pembelian
    scanf("%d", &pembelian);
    // panggil fungsi hitung diskon dengan pointer ke pembelian
    hitungdiskon(&pembelian);

    return 0;
}