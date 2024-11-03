#include <stdio.h>

void bubbleSort(int arr[], int const n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - (i + 1); j++)
        {
            // printf("arr[%d]: %d , arr[%d]: %d \n", j, arr[j], j + 1, arr[j + 1]);
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    };
}
void bubbleSortPointer(int *arr, int const n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - (i + 1); j++)
        {
            // printf("arr[%d]: %d , arr[%d]: %d \n", j, arr[j], j + 1, arr[j + 1]);
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    };
}
int main(void)
{
    int arr[] = {0, 5, 2, 3, 4, 1, 7, 9, 8, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    // bubbleSort(arr, n);
    bubbleSortPointer(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

// poin kunci bubble sort
// elemen di kiri akan dibandingkan dengan kanannya,
// elemen terakhir tidak akan dibandingkan karena ngga ada elemen di kanannya
// jika lebih besar daripada kanannya maka swap
// shingga pada akhir outerloop (i) pertama akan ada 1 angka terbesar/terkecil dari array yg sudah terurut
// sehingga tidak perlu mengurukan lagi elemen terakhir diloop selanjutnya
