/*
Diberikan input suatu angka dan factorial, buat program untuk mencari pangkat terbesar dari pembagi suatu factorial.
Contoh:
Input: n=2, fact=5
Output: 3
Penjelasan: Factorial 5!=120, pangkat terbesar dari angka 2 sebagai pembagi 120 adalah 3 (2^3=8). Sisa bagi harus sama dengan 0, 120/8=15.

Input: n=15, fact=146
Output: 35
*/

#include <stdio.h>
#include <stdlib.h>

int largestfaktor(int n, int fact)
{
    int power = 0;
    int denom = n;
    // printf("denom: %d , fact: %d\n", denom, fact);

    // cek jika faktorial dibagi n masih lebih besar dari 0
    while (fact / denom > 0)
    {
        power += fact / denom;
        denom *= n;
    }
    return power;
}

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

int nonprime_ganjil(int n, int fact)
{
    int resultganjil, counter = 1, result_temp1, result_temp2;
    for (int i = 3; i * i <= n; i += 2) // angka ganjil tidak memiliki faktor genap
    {

        if (n % i == 0)
        {
            int anotherdivisor = n / i;
            result_temp1 = largestfaktor(i, fact);
            result_temp2 = largestfaktor(anotherdivisor, fact);
            if (counter == 1)
                resultganjil = result_temp1 < result_temp2 ? result_temp1 : result_temp2;
            else
            {
                if ((result_temp1 < resultganjil) | (result_temp2 < resultganjil))
                    resultganjil = result_temp1 < result_temp2 ? result_temp1 : result_temp2;
            }

            counter++;
        }
    }
    return resultganjil;
}

int faktorisasi(int n, int *length)
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
int n_genap(int n, int fact)
{
    int length;
    int *factors = faktorisasi(n, &length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", factors[i]);
    }

    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         int result_temp1 = largestfaktor(array[i], fact);
    //         if (counter == 1)
    //             resultgenap = result_temp1;
    //         else
    //         {
    //             if (result_temp1 < resultgenap)
    //                 resultgenap = result_temp1;
    //         }
    //     }
    // }
    return 1;
}

int main()
{
    int n, fact, result, power, denom;

    // get input untuk n dan faktorial
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input fact: ");
    scanf("%d", &fact);

    // cek apakah n bilangan prima
    int prime = cek_prime(n);
    if (prime)
    {
        // jika nilai faktorial tidak 1 dan faktorial dibagi n lebih besar dari 0
        result = largestfaktor(n, fact);
    }
    else
    {
        // jika faktornya ganjil, maka cek
        if ((n % 2) != 0)
        {
            result = nonprime_ganjil(n, fact);
        }
        else
        {
            // jika genap
            result = n_genap(n, fact);
        }
    }
    printf("Output: %d", result);
    return 0;
}