#include <stdio.h>
int main()
{
    int x;
    for (x = 0; x <= 100; x++)
    {
        while (x % 5 == 0 && x % 3 == 0)
        {
            printf("x=%d divisible by 5 and 3\n", x);
            break;
        }
        while (x % 5 == 0 || x % 3 == 0)
        {
            printf("x=%d divisible by 5 or 3\n", x);
            break;
        }
    }
    return 0;
}