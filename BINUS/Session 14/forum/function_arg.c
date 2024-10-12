#include <stdio.h>

int sumOfElements(int *A, int size)
{
    int i, sum = 0;
    printf("SOE - size of A = %d, size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));
    for (i = 0; i < size; i++)
    {
        sum += A[i];
    }
    return sum;
}

// int main()
// {
// int *pint;
// printf("integer pointer: %d bytes\n", (int)sizeof(pint));
// printf("integer : %d bytes", (int)sizeof(4));

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sumOfElements(A, size);
    printf("Sum of elements = %d\n", total);
    printf("Main - size of A = %d, size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));

    return 0;
}