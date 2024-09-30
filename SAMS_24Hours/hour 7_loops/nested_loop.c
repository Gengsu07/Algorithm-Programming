#include <stdio.h>

int main()
{
    int rows = 5;
    int columns = 4;

    for (int i = 1; i <= rows; i++)
    {
        printf("outer loop: %d \n", i);
        for (int j = 1; j <= columns; j++)
        {
            printf("inner loop: %d/%d\n", i * j, rows * columns);
        }
    }

    return 0;
}
