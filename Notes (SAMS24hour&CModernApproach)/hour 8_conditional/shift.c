#include <stdio.h>

void printBinary(unsigned int num)
{
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1; // Get the ith bit
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    int x, y, z;
    x = 255;
    y = 5;

    printf("x = %d | 0X%X | \n", x, x);
    printBinary(x);
    printf("\n");
    printf("y = %d | 0X%X \n", y, y);
    printBinary(y);
    printf("\n");

    z = x >> y;
    printf("x >> y : %d | 0X%X \n", z, z);
    printBinary(z);
    printf("\n");

    z = x << y;
    printf("x << y : %d | 0X%X \n", z, z);
    printBinary(z);
    printf("\n");

      return 0;
}