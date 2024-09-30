#include <stdio.h>

int main()
{
    int n = 5, i, largest;
    int array_int[5];
    int *ptr = array_int;

    for (i = 0; i < n; i++)
    {
        printf("Masukkan elemen[%d] dari array: ", i + 1);
        scanf("%d", (ptr + i));
    }

    largest = *ptr;
    for (i = 1; i < n; i++)
    {
        if (*(ptr + i) > largest)
            largest = *(ptr + i);
    }

    printf("nilai maksimum dari array: %d\n", largest);

    return 0;
}