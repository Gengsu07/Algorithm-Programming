#include <stdio.h>

int main()
{
    // deklarasi variabel
    int array_int[3], penjumlahan, pengurangan, perkalian;
    float pembagian, ratarata;

    // menerima input 3 buah integer
    for (int i = 0; i < 3; i++)
    {
        printf("Masukkan angka ke-[%d]: ", i + 1);
        // menyimpan dalam array_int
        scanf("%d", &array_int[i]);
    }

    /* di dalam soal tidak disebutkan dengan jelas bagaimana operasi matematika dilakukan, terhadap bilangan mana yang dilakukan operasi apa oleh bilangan mana. Oleh karena itu, saya berasumsi melakukan operasi terhadap semua angka yang ada.
     */
    penjumlahan = pengurangan = perkalian = pembagian = array_int[0];

    // operasi matematika
    for (int i = 1; i < 3; i++)
    {
        penjumlahan += array_int[i]; // penjumlahan
        pengurangan -= array_int[i]; // pengurangan
        perkalian *= array_int[i];   // perkalian
        pembagian /= array_int[i];   // pembagian
    }
    ratarata = penjumlahan / 3.0; // hitung ratarata

    // menampilkan hasil operasi matematika dengan detailnya
    printf("Jumlah dari 3 bilangan (%d+%d+%d) :%d\n", array_int[0], array_int[1], array_int[2], penjumlahan);
    printf("Pengurangan dari 3 bilangan (%d-%d-%d) :%d\n", array_int[0], array_int[1], array_int[2], pengurangan);
    printf("Perkalian dari 3 bilangan (%dx%dx%d) :%d\n", array_int[0], array_int[1], array_int[2], perkalian);
    printf("Pembagian dari 3 bilangan ((%d:%d)/%d) :%.2f\n", array_int[0], array_int[1], array_int[2], pembagian);
    printf("Rata-Rata dari 3 bilangan (%d+%d+%d)/3 :%.2f\n", array_int[0], array_int[1], array_int[2], ratarata);

    return 0;
}