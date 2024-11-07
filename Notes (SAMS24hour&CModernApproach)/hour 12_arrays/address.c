#include <stdio.h>

int main()
{
    int fib[10];
    int *ptr = fib;
    *ptr = 0;
    *(ptr + 1) = 1;

    // printf("%p\n", ptr);

    *(ptr + 2) = *(1 + ptr - 2); // array fib[2]=0
    printf("%d\n", *(ptr + 2));
    printf("arrray index 3: %d\n", fib[2]);

    // for (int i = 2; i < 10; i++)
    // {
    //     *(ptr + i) = *(i + ptr - 1) + *(i + ptr - 2); // Kesalahan di sini
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", *(ptr + i));
    // }

    return 0;
}
