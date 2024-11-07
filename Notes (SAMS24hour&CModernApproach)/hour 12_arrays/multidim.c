#include <stdio.h>

int main()

{
    int rows, cols;
    int ndim2[2][2] = {
        {1, 2},
        {3, 4}};
    for (rows = 0; rows < 2; rows++)
    {
        printf("\n");
        for (cols = 0; cols < 2; cols++)
        {
            printf("%6d ", ndim2[rows][cols]);
        }
    }

    return 0;
}