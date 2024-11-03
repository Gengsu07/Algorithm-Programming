#include <stdio.h>
#include "mathio.h"

int main(void)
{
    double x, y;

    printf("Masukkan 2 angka dengan jarak spasi: ");
    scanf("%lf %lf", &x, &y);
    printf("Penjumlahan :%.2f\n", sum(x, y));
    printf("Penjumlahan :%.2f\n", multiply(x, y));
    return 0;
}
