#include <stdio.h>

// buat macro untuk menghitung luas lingkaran (pi x r x r)
#define luasLingkaran(r) (3.14 * r * r)

int main(void)
{
    double r;

    // input jari-jari lingkaran
    printf("Jari jari: ");
    scanf("%lf", &r);

    // tampilkan luas lingkaran
    printf("Luas lingkaran: %.2f\n", luasLingkaran(r));
    return 0;
}
