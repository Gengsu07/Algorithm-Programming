/*
Buat implementasi binary search dengan program C pada input arr[] = {3, 4, 6, 12, 15, 18, 20, 33, 47, 59, 85} dan target = 33.
Anda dapat mengunakan metode iterative ataupun recursive.
*/

#include <stdio.h>

int BinarySearch(int numbers[], int const size, int goal)
{
    int left = 0, right = (size - 1);
    int FoundIndex = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (numbers[mid] == goal)
        {
            FoundIndex = mid;
            break;
        }
        else if (numbers[mid] < goal)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1; // search in the left half of the array
        }
    }
    return FoundIndex;
}

void SortArray(int numbers[], int const size)

{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp; // swap elements
            }
        }
}

int main(void)
{

    int arr[] = {3, 4, 6, 12, 15, 18, 20, 33, 47, 59, 85};
    int target = 33;
    int size = sizeof(arr) / sizeof(arr[0]);

    SortArray(arr, size);
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Target: %d Ditemukan pada Index: %d\n", target, BinarySearch(arr, size, target));
    return 0;
}
