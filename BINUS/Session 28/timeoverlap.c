/*
Check if any two intervals intersect in a given set
Buat program C untuk mencari apakah ada overlap antara input interval waktu.
Gunakan struct Interval yang memiliki elemen start dan end.

Contoh:
Input: arr[] = {{1, 3}, {5, 7}, {2, 4}, {8, 10}}
Output: Overlap = {1, 3} and {2, 4}

Input: arr[] = {{1, 3}, {7, 9}, {4, 6}, {10, 13}}
Output: Overlap = None
Jawab:
Pada intinya program mencari dari array of struct start dan end apakah ada waktu yang overlap. Misalkan elemen pertama a dan elemen kedua b maka overlap terjadi
jika a.start <= b.end && b.start <= a.end
atau dengan kata lain elemen kedua mulai terjadi saat elemenpertama belum selesai
*/

#include <stdio.h>
#include <stdbool.h>

// buat Struct
typedef struct
{
    int start;
    int end;
} Interval;

// Fungsi mengecek dua interval overlap
bool cekOverlap(Interval a, Interval b)
{
    return (a.start <= b.end && b.start <= a.end);
}

// Fungsi untuk loop semua interval dan cek overlap
void cariOverlap(Interval arr[], int n)
{
    bool foundOverlap = false;

    // Check all possible pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cekOverlap(arr[i], arr[j]))
            {
                printf("Overlap = {%d, %d} and {%d, %d}\n",
                       arr[i].start, arr[i].end,
                       arr[j].start, arr[j].end);
                foundOverlap = true;
            }
        }
    }

    if (!foundOverlap)
    {
        printf("Overlap: None\n");
    }
}

int main(void)
{
    // array pertama
    Interval arr1[] = {{1, 3}, {5, 7}, {2, 4}, {8, 10}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cariOverlap(arr1, n1);

    // array kedua
    Interval arr2[] = {{1, 3}, {7, 9}, {4, 6}, {10, 13}};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cariOverlap(arr2, n2);

    return 0;
}
