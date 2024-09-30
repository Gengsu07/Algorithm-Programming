#include <stdio.h>
#include <stdlib.h>

int cek_prime(int n)
{
    int nfaktor = 1;
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2)
    {

        if ((n % i) == 0)
            return 0;
        // nfaktor++;

        // if (nfaktor > 2)
        //     break;
    }
    return 1;
}

int faktorisasi(int n)
{
    int totalfaktorprima = 1, size = 0, counter = 1, resultgenap;
    int *array = NULL;
    for (int i = 2; (i * i <= n); i++)
    {

        while (n % i == 0)
        {
            int faktor = n / i;
            // printf("faktor %d: %d\n", i, faktor_1);
            if (cek_prime(i))
            {
                // printf("prima : %d\n", i);
                int *temp = realloc(array, (size + 1) * sizeof(int));
                if (temp == NULL)
                {
                    free(array);
                    return 1;
                }
                array = temp;
                array[size] = i;
                size++;
            }

            // printf("faktor %d: %d\n", faktor, faktor_2);
            if (cek_prime(faktor))
            {
                // printf("prima2 : %d\n", faktor);
                int *temp = realloc(array, (size + 1) * sizeof(int));
                if (temp == NULL)
                {
                    free(array);
                    return 1;
                }
                array = temp;
                array[size] = faktor;
                size++;
            }
            n /= i;
        }
    }

    return array;
}
int main()
{
    int n = 60;
    faktorisasi(n);
    return 0;
}