#include <stdio.h>
#include <stdlib.h>

int main() {
    float panjang, lebar, keliling;
    printf("Program Hitung Keliling Persegi Panjang");
    printf("Masukkan panjang :\n");
    scanf("%f", &panjang);
    printf("Masukkan lebar: \n");
    scanf("%f", &lebar);
    keliling = 2 * (panjang + lebar);
    printf("Keliling Persegi Panjang = %f\n", keliling);
    return 0;
}