#include <stdio.h>

int factorial(int n);
int faktorial(int n);
int main(void)
{
    int n = 5;
    printf("%d", factorial(n));
    printf("%d", faktorial(n));
    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int faktorial(int n)
{
    int total = 1;

    if (n == 1)
        return 1;

    for (int i = 2; i <= n; i++)
    {
        total *= i;
    };
    return total;
}
