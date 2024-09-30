#include <stdio.h>
#include <stdlib.h>

int cek_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    // Check divisibility up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int faktorisasi(int n)
{
    int size = 0;      // Array size
    int *array = NULL; // Dynamic array to hold factors

    // Loop from 2 up to sqrt(n) to find factors
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {           // While `i` is a factor
            n /= i; // Reduce `n`

            // Check if factor is prime
            if (cek_prime(i))
            {
                int *temp = realloc(array, (size + 1) * sizeof(int));
                if (temp == NULL)
                {
                    free(array); // Memory cleanup in case of failure
                    return 1;    // Indicate failure
                }
                array = temp;
                array[size++] = i;
            }
        }
    }

    // If any factor remains larger than 1, it must be prime
    if (n > 1)
    {
        int *temp = realloc(array, (size + 1) * sizeof(int));
        if (temp == NULL)
        {
            free(array);
            return 1;
        }
        array = temp;
        array[size++] = n;
    }

    // Print and return result
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array); // Free allocated memory
    return 0;
}
int main()
{
    int n = 30;
    faktorisasi(n); // Should print: 2 3 5
    return 0;
}
