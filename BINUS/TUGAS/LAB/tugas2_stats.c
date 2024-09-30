#include <stdio.h>

int main()
{
    // deklarasi variabel
    int n = 5, i, largest, lowest, sumscore = 0;
    int array_int[5];
    int *ptr = array_int;

    // menerima 5 input nilai ujian
    for (i = 0; i < n; i++)
    {
        printf("Masukkan nilai ujian ke-[%d]: ", i + 1);
        // menyimpan dalam array_int
        scanf("%d", (ptr + i));
    }

    // inisialisasi largest,lowest, dan jumlah total nilai ujian dengan nilai pertama dalam array_int
    largest = *ptr;
    lowest = *ptr;
    sumscore = *ptr;
    for (i = 1; i < n; i++)
    {
        // mencari nilai maksimum di array_int
        if (*(ptr + i) > largest)
            largest = *(ptr + i);

        // mencari nilai terendah dari array_int
        if (*(ptr + i) < lowest)
            lowest = *(ptr + i);

        // menghitung jumlah total nilai ujian
        sumscore += *(ptr + i);
    }

    // menampilkan statistik sederhana dari nilai ujian
    printf("nilai ujian maksimal : %d\n", largest);
    printf("nilai ujian minimal : %d\n", lowest);
    // perhitungan rata-rata dengan membagi total dengan float 5.0 agar hasil menjadi float jga.
    printf("nilai ujian rata-rata : %.2f\n", sumscore / 5.0);

    return 0;
}