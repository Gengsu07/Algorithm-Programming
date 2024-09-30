#include <stdio.h>

int main()
{
    int c;
    c = 65;
    printf("Berikut adalah karakter dari ASCII 65:");
    putc(c, stdout);

    printf("\nPutchar :");
    printf("\n65:A = ");
    putchar(65);
    printf("\n10:New Line = ");
    putchar(10);
    printf("66:B = ");
    putchar(66);
    printf("\n10: New Line = ");
    putchar(10);
    printf("67:C = ");
    putchar(67);

    return 0;
}