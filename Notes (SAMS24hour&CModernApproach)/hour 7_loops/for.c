#include <stdio.h>
int main()
{
    int counter;
    for (counter = 0; counter < 16; counter++)
        printf("counter = %d, Hex= %X , hex = %x\n", counter, counter, counter);
    return 0;
}