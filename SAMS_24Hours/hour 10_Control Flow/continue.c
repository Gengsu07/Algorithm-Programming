#include <stdio.h>

int main()
{
    int i, sum = 0, sum1 = 0;
    for (i = 0; i < 8; i++)
    {
        if (i == 3 || i == 5)
            continue;

        sum += i; // ini menjumlah semua 0-7
    }
    printf("total:%d\n", sum);
    printf("total kecuali 3 dan 5:%d", sum1);
    return 0;
}