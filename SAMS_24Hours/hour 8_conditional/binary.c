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
    printBinary(5040);
    return 0;
}