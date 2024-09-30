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
};

int main()
{
    int n, fact, result, power, denom;

    // get input untuk n dan faktorial
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input fact: ");
    scanf("%d", &fact);

    // cek apakah n bilangan prima
    if (cek_prime(n))
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
    }
    printf("Output: %d", result);
    return 0;
}