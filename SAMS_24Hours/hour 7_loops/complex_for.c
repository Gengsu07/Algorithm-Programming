#include <stdio.h>
int main()
{
    int i, j;
    for (i = 0, j = 8; i < 8; i++, j--)
    {
        printf("idx:%d| %d + %d = %d \n", i, i, j, i + j);
    }
    return 0;
}