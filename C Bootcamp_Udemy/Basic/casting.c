#include <stdio.h>
#include <stdlib.h>

int main () {
    int num1 , num2; 
    float num3, result;
    printf("-------------Program rata-rata 3 angka---------------\n");
    printf("Masukkan angka pertama :\n");
    scanf("%d", & num1);
    printf("Masukkan angka kedua :\n");
    scanf("%d", & num2);
    printf("Masukkan angka ketiga :\n");
    scanf("%f", & num3);
    result = (num1 + num2 + num3) / 3;
    printf("Rata-rata = %f\n", result);
    return 0;
}